#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat srcImage, grayImage;
    srcImage = imread("./test.jpg");
    Mat srcImage1 = srcImage.clone(); // 创建 srcImage 的副本至 srcImage1
    cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
    /* reminder
    void cvtColor(InputArray src, OutputArray dst, int code, int dstCn = 0) 颜色空间转换函数
        - InputArray src: 输入图像
        - OutputArray dst: 输出图像
        - code 颜色空间转化参数 
        - 输出图像的通道数, 默认为0, 与输入图像 src 一致
    */
    Mat dstImage, edge;

    blur(grayImage, grayImage, Size(3, 3));
    /*reminder 使用归一化框滤镜模糊图像
    void blur(InputArray src, OutputArray dst, Size ksize, Point anchor = Point(-1, -1), borderType = 4)
    - ksize: 模糊核的大小
    - anchor: 锚点;Point(-1，-1)表示锚点位于内核中心
    */
    Canny(grayImage, edge, 150, 100, 3);
    /*reminder
    void Canny(InputArray image, OutputArray edges, double threshold1, double threshold2, int apertureSize = 3, bool L2gradient = false)
    - threshod1, threshold2: 高阈值, 低阈值, 两者比值最好是 2:1 和 3:1 之间
    - apertureSize: Sobel 算子的孔径大小
    */

    dstImage.create(srcImage1.size(), srcImage1.type());
    dstImage = Scalar::all(0);
    srcImage1.copyTo(dstImage, edge);
    imwrite("./Canny.jpg", dstImage);

    return 0; 
}