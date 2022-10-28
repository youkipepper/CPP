#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
  Mat img = imread("/home/parallels/Desktop/Parallels Shared Folders/Home/Desktop/Code/Cpp/CV/test/test.jpg");
  imshow("test", img);

  waitKey(0);

  return 0;
}
