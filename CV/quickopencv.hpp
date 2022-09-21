#pragma once

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

// Mat src, dst, m;
// int lightness = 50;

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

    /*
    static void on_track(int b, void *userdate)
    {
        m = Scalar(lightness, lightness, lightness);
        subtract(src, m, dst);
        imshow("亮度调整", dst);
    }

    void tracking_bar_demo(Mat &image)
    {
        namedWindow("亮度调整", WINDOW_AUTOSIZE);
        dst = Mat::zeros(image.size(), image.type());
        m = Mat::zeros(image.size(), image.type());
        src = image;
        int max_value = 100;
        createTrackbar("Value", "亮度调整", &lightness, 100, on_track); // creaeTrackbar("trackbar_name", "window_name", &value_wanna_change, max_value(from zero))
        on_track(50, 0);
    }
    */

    static void on_lightness(int b, void *userdata)
    {
        Mat image = *((Mat *)userdata);
        Mat dst = Mat::zeros(image.size(), image.type());
        Mat m = Mat::zeros(image.size(), image.type());
        addWeighted(image, 1.0, m, 0, b, dst);
    }

    static void on_track(int b, void *userdata)
    {
        Mat image = *((Mat *)userdata);
        Mat dst = Mat::zeros(image.size(), image.type());
        Mat m = Mat::zeros(image.size(), image.type());
        m = Scalar(b, b, b);
        addWeighted(image, 1.0, m, 1.0, 0, dst);
        imshow("亮度调整与对比度", dst);
    }

    static void on_contrast(int b, void *userdata)
    {
        Mat image = *((Mat *)userdata);
        Mat dst = Mat::zeros(image.size(), image.type());
        Mat m = Mat::zeros(image.size(), image.type());
        double contrast = b / 200.0;
        addWeighted(image, 1.0, m, 0, 0, dst);
        imshow("亮度调整与对比度", dst);
    }

    void tracking_bar_demo(Mat &image)
    {
        namedWindow("亮度与对比度调整", WINDOW_AUTOSIZE);
        int lightness = 50;
        int max_value = 100;
        int contrast_value = 1.2;
        createTrackbar("Value Bar", "亮度调整", &lightness, max_value, on_track, (void *)(&image));
        createTrackbar("Contrast Bar", "亮度与对比度调整", &contrast_value, 200, on_track, (void *)(&image));
        on_lightness(50, &image);
    }

    void key_demo(Mat &image)
    {
        Mat dst;
        while (true)
        {
            int c = waitKey(1000);
            cout << c << endl;
        }
    }
};