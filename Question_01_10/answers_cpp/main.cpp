#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// answer_1: Channel swap  B通道和R通道进行更换
Mat channel_swap(Mat img) {
    // get height and width
    int width = img.cols;
    int height = img.rows;
    // prepare output
    Mat out = Mat::zeros(height, width, CV_8UC3);
    // each y, x
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // R -> B
            out.at<Vec3b>(y, x)[0] = img.at<Vec3b>(y, x)[2];
            // B -> R
            out.at<Vec3b>(y, x)[2] = img.at<Vec3b>(y, x)[0];
            // G -> G
            out.at<Vec3b>(y, x)[1] = img.at<Vec3b>(y, x)[1];
        }
    }
    return out;
}

// answer_2: 将彩色图像转化为灰度图像
Mat BGR2GRAY(const Mat &img) {
    int rows = img.rows;
    int cols = img.cols;
    Mat out = Mat::zeros(rows, cols, CV_8UC1);
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            out.at<uchar>(row, col) = 0.2126 * (float) img.at<Vec3b>(row, col)[2] +
                                      0.7152 * (float) img.at<Vec3b>(row, col)[1] +
                                      0.0722 * (float) img.at<Vec3b>(row, col)[0];
        }
    }
    return out;
}

// answer_3: 将灰度图像二值化
Mat Binary(const Mat &img, const int &thresh) {
    int rows = img.rows;
    int cols = img.cols;
    Mat gray = BGR2GRAY(img);
    Mat out = Mat::zeros(rows, cols, CV_8UC1);
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            if (gray.at<uchar>(row, col) <= thresh) {
                out.at<uchar>(row, col) = 0;
            } else {
                out.at<uchar>(row, col) = 255;
            }
        }
    }
    return out;
}

// answer_4: 获取otsu最优阈值
int GetOtsuThresh(const Mat &img) {
    int rows = img.rows;
    int cols = img.cols;
    double w0 = 0, w1 = 0, m0 = 0, m1 = 0;
    double max_sb = 0, sb = 0;
    int thresh = 0;
    int val = 0;

    for (int temp = 0; temp < 255; ++temp) {
        w0 = 0;
        w1 = 0;
        m0 = 0;
        m1 = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                val = (int) img.at<uchar>(row, col);
                if (val < temp) {
                    ++w0;
                    m0 += val;
                } else {
                    ++w1;
                    m1 += val;
                }
            }
        }
        if (w0 > 0) {
            m0 /= w0;
        }
        if (w1 > 0) {
            m1 /= w1;
        }
        w0 = w0 / (rows * cols);
        w1 = w1 / (rows * cols);
        sb = w0 * w1 * pow((m0 - m1), 2);
        if (sb > max_sb) {
            max_sb = sb;
            thresh = temp;
        }
    }
    return thresh;
}

Mat Otsu(const Mat &img) {
    int thresh = GetOtsuThresh(img);
    cout << "thresh = " << thresh << endl;
    Mat out = Binary(img, thresh);
    return out;
}

int main(int argc, const char *argv[]) {
    // read image
    cv::Mat img = cv::imread("/Users/bessliuqian/Documents/liuqian的个人学习空间/ImageProcessing100Wen/assets/imori.jpg",
                             cv::IMREAD_COLOR);
    cout << "Img width = " << img.cols << endl;
    cout << "Img height = " << img.rows << endl;

//    Mat out = channel_swap(img);
//    Mat out = BGR2GRAY(img);
//    Mat out = Binary(img, 128);
    Mat out = Otsu(img);
    cout << "Out width = " << out.cols << endl;
    cout << "Out height = " << out.rows << endl;

    cv::imwrite("out.jpg", out);
    cv::imshow("origin", img);
    cv::imshow("result", out);
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
