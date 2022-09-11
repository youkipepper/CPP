#include <iostream>
#include <vector>
#include <string>
#include "opencv2/opencv.hpp"
#include "opencv2/highgui.hpp"

using namespace std;
using namespace cv;

int main (){

Mat img = imread("/Users/youkipepper/Desktop/Cpp/CV/D6218BB03F8D3AFDE5037E5CE0DF09D6.jpg");
if(!img.data) {
    cout<<"couldn't load the image";
    return -1;
}
else{
    cout<<"loaded the image";
    imshow("img",img);
} 

while(true)
{
    int c = waitKey(20);
    if(27==(char) c)
    break;
}
    return 0;
}       
