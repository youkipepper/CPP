#pragma once

#include <opencv2/opencv.hpp>

using namespace cv;

class QuickDemo
{
    public:
    void colorSpace_Demo(Mat &image)
        {
            Mat gray,hsv;
            cvtColor(image,hsv,COLOR_BGR2HSV);
            cvtColor(image,gray,COLOR_BGR2GRAY);
            imshow("HSV",hsv);
            imshow("灰度",gray);
            imwrite("./hsv.png",hsv);
            imwrite("./gray.png",gray);

        }

};

