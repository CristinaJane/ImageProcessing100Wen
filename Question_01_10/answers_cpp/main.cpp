#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace std;

// Channel swap
cv::Mat channel_swap(cv::Mat img) {
    // get height and width
    cout << "A" << endl;
    int width = img.cols;
    int height = img.rows;

    // prepare output
    cv::Mat out = cv::Mat::zeros(height, width, CV_8UC3);

    // each y, x
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // R -> B
            out.at<cv::Vec3b>(y, x)[0] = img.at<cv::Vec3b>(y, x)[2];
            // B -> R
            out.at<cv::Vec3b>(y, x)[2] = img.at<cv::Vec3b>(y, x)[0];
            // G -> G
            out.at<cv::Vec3b>(y, x)[1] = img.at<cv::Vec3b>(y, x)[1];
        }
    }

    return out;
}


int main(int argc, const char *argv[]) {
    // read image
    cout << "In" << endl;
    cv::Mat img = cv::imread("/Users/bessliuqian/Documents/liuqian的个人学习空间/ImageProcessing100Wen/assets/imori.jpg",
                             cv::IMREAD_COLOR);
    cout << "Img width = " << img.cols << endl;
    cout << "Img height = " << img.rows << endl;

    // channel swap
    cv::Mat out = channel_swap(img);
    cout << "Out width = " << out.cols << endl;
    cout << "Out height = " << out.rows << endl;

    cv::imwrite("out.jpg", out);
    cv::imshow("origin", img);
    cv::imshow("sample", out);
    cout << "debug A..." << endl;
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
