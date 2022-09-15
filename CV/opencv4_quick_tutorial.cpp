#include <opencv2/opencv.hpp>
#include <iostream>
#include "quickopencv.hpp"

using namespace cv;
using namespace std;

int main()
{
    Mat src = imread("test.jpg"); // R, G, R
    if (src.empty())
    {
        printf("could not load image...\n");
        return -1;
    }
    // namedWindow("输入窗口",WINDOW_FREERATIO);
    imshow("input", src);

    QuickDemo qd;

    // qd.colorSpace_Demo(src);

    // qd.mat_creation_demo();

    // qd.pixel_visit_demo(src);

    qd.operators_demo(src);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
