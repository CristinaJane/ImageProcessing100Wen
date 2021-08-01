cmake_minimum_required(VERSION 3.20)
project(ImageProcessing100Wen)

set(CMAKE_CXX_STANDARD 14)

#find_library(OpenCV)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
#target_link_libraries(ImageProcessing100Wen ${OpenCV_LIBS})

add_executable(ImageProcessing100Wen
        Question_01_10/answers_cpp/answer_1.cpp
        Question_01_10/answers_cpp/answer_10.cpp
        Question_01_10/answers_cpp/answer_2.cpp
        Question_01_10/answers_cpp/answer_3.cpp
        Question_01_10/answers_cpp/answer_4.cpp
        Question_01_10/answers_cpp/answer_5.cpp
        Question_01_10/answers_cpp/answer_6.cpp
        Question_01_10/answers_cpp/answer_7.cpp
        Question_01_10/answers_cpp/answer_8.cpp
        Question_01_10/answers_cpp/answer_9.cpp
        Question_11_20/answers_cpp/answer_11.cpp
        Question_11_20/answers_cpp/answer_12.cpp
        Question_11_20/answers_cpp/answer_13.cpp
        Question_11_20/answers_cpp/answer_14.cpp
        Question_11_20/answers_cpp/answer_15.cpp
        Question_11_20/answers_cpp/answer_16.cpp
        Question_11_20/answers_cpp/answer_17.cpp
        Question_11_20/answers_cpp/answer_18.cpp
        Question_11_20/answers_cpp/answer_19.cpp
        Question_21_30/answers_cpp/answer_21.cpp
        Question_21_30/answers_cpp/answer_22.cpp
        Question_21_30/answers_cpp/answer_23.cpp
        Question_21_30/answers_cpp/answer_24.cpp
        Question_21_30/answers_cpp/answer_25.cpp
        Question_21_30/answers_cpp/answer_26.cpp
        Question_21_30/answers_cpp/answer_27.cpp
        Question_21_30/answers_cpp/answer_28.cpp
        Question_21_30/answers_cpp/answer_29.cpp
        Question_21_30/answers_cpp/answer_30.cpp
        Question_31_40/answers_cpp/answer_31.cpp
        Question_31_40/answers_cpp/answer_32.cpp
        Question_31_40/answers_cpp/answer_33.cpp
        Question_31_40/answers_cpp/answer_34.cpp
        Question_31_40/answers_cpp/answer_35.cpp
        Question_31_40/answers_cpp/answer_36.cpp
        Question_31_40/answers_cpp/answer_37.cpp
        Question_31_40/answers_cpp/answer_38.cpp
        Question_31_40/answers_cpp/answer_39.cpp
        Question_31_40/answers_cpp/answer_40.cpp
        Question_41_50/answers_cpp/answer_41.cpp
        Question_41_50/answers_cpp/answer_42.cpp
        Question_41_50/answers_cpp/answer_43.cpp
        Question_41_50/answers_cpp/answer_44.cpp
        Question_41_50/answers_cpp/answer_45.cpp
        Question_41_50/answers_cpp/answer_46.cpp
        Question_41_50/answers_cpp/answer_47.cpp
        Question_41_50/answers_cpp/answer_48.cpp
        Question_41_50/answers_cpp/answer_49.cpp
        Question_41_50/answers_cpp/answer_50.cpp
        Tutorial/answer.cpp
        Tutorial/sample.cpp)
