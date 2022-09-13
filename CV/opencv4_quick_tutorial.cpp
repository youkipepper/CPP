#include <opencv2/opencv.hpp>
#include <iostream>
#include "quickopencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat src = imread("test.jpg");
    if (src.empty())
    {
        printf("could not load image...\n");
        return -1;
    }
    // namedWindow("输入窗口",WINDOW_FREERATIO);
    // imshow("input", src);

    QuickDemo qd;
    qd.colorSpace_Demo(src);

    waitKey(0);
    destroyAllWindows();

    return 0;
}
