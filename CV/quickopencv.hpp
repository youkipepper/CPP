#pragma once

#include <opencv2/opencv.hpp>

using namespace cv;

class QuickDemo
{
public:
    void colorSpace_Demo(Mat &image)
    {
        Mat gray, hsv;
        cvtColor(image, hsv, COLOR_BGR2HSV);
        // H 0 ~ 180, S、V
        cvtColor(image, gray, COLOR_BGR2GRAY);
        imshow("HSV", hsv);
        imshow("灰度", gray);
        imwrite("./hsv.png", hsv);
        imwrite("./gray.png", gray);
    }

    void mat_creation_demo()
    {
        // Mat m1, m2;
        // m1 = image.clone();
        // image.copyTo(m2);

        //创建空白图像
        Mat m3 = Mat::ones(Size(400, 400), CV_8UC3); // 8\times 8 矩阵, 8位单通道
        m3 = Scalar(255, 0, 0);

        std::cout << "width: " << m3.cols << " height: " << m3.rows << " channels: " << m3.channels() << std::endl;
        std::cout << m3 << std::endl;
        imshow("图像", m3);

        Mat m4;
        m3.copyTo(m4);
        m4 = Scalar(0, 255, 255);
        imshow("图像", m3);
        imshow("图像", m4);
    }

    void pixel_visit_demo(Mat &image)
    {
        int w = image.cols;
        int h = image.rows;
        int dims = image.channels();
        /*
        for (int row = 0; row < h; row++)
        {
            for (int col = 0; col < w; col++)
            {
                if (dims == 1) //单通道 —— 灰度图像
                {
                    int pv = image.at<uchar>(row, col);
                    image.at<uchar>(row, col) = 255 - pv;
                }
                if (dims == 3) // 3通道 —— 彩色图像
                {
                    Vec3b bgr = image.at<Vec3b>(row, col);
                    image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
                    image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
                    image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
                }
            }
        }
        */

        for (int row = 0; row < h; row++)
        {
            uchar *current_row = image.ptr<uchar>(row);
            for (int col = 0; col < w; col++)
            {
                if (dims == 1) //单通道 —— 灰度图像
                {
                    int pv = *current_row;
                    *current_row++ = 255 - pv;
                }
                if (dims == 3) // 3通道 —— 彩色图像
                {
                    *current_row++ = 225 - *current_row;
                    *current_row++ = 225 - *current_row;
                    *current_row++ = 225 - *current_row;
                }
            }
        }

        imshow("像素读写演示", image);
    }

    void operators_demo(Mat &image)
    {
        Mat dst = Mat::zeros(image.size(), image.type());
        Mat m = Mat::zeros(image.size(), image.type());
        m = Scalar(5, 5, 5);

        // 加法
        /*
        int w = image.cols;
        int h = image.rows;
        int dims = image.channels();

        for (int row = 0; row < h; row++)
        {
            for (int col = 0; col < w; col++)
            {
                Vec3b p1 = image.at<Vec3b>(row, col);
                Vec3b p2 = m.at<Vec3b>(row, col);
                dst.at<Vec3b>(row, col)[0] = saturate_cast<uchar>(p1[0] + p2[0]);
                dst.at<Vec3b>(row, col)[1] = saturate_cast<uchar>(p1[1] + p2[1]);
                dst.at<Vec3b>(row, col)[2] = saturate_cast<uchar>(p1[2] + p2[2]);
            }
        }
        */
        // add(image, m, dst);
        // subtract(image, m ,dst);
        divide(image, m, dst); //可以改变图像的亮度

        imshow("加法操作", dst);
    }
};