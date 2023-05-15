#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void videocapture()
{
    VideoCapture capture(0);
    double rate = 25.0; // 视频的帧率
    Size videoSize(1280, 960);
    VideoWriter writer("VideoTest.avi", CAP_OPENCV_MJPEG, rate, videoSize);

    while (1)
    {
        Mat frame;
        capture >> frame; // 读取当前帧
        writer << frame;
        imshow("capture", frame);
        if (waitKey(20) == 27) // 27 是 esc 的 ascii 码值
        {
            break;
        }
    }
}

void captureGet()
{
    VideoCapture capture;
    capture.open("./59_1667472917.mp4");
    if (!capture.isOpened())
    {
        cout << "fail to open !" << endl;
    }
    else
    {
        long frameToStart = 1;
        capture.set(CAP_PROP_POS_FRAMES, frameToStart);
        cout << "从第" << frameToStart << "帧开始读" << endl;
        int frameTostop = 400;
        if (frameTostop < frameToStart)
        {
            cout << "结束帧小于开始帧, 错误" << endl;
        }
        double rate = capture.get(CAP_PROP_FPS); // 获取视频的帧率 FPS
        cout << "帧率为:" << rate << endl;
        while (1)
        {
            Mat frame;
            capture >> frame; // 读取当前帧
            imshow("capture", frame);
            waitKey(10); // 设置两帧之间的时间间隔. 控制帧率, 播放视频的时候越小速度越快
        }
    }
}

int captureGet2()
{
    cv::VideoCapture cap;
    cap.open("./59_1667472917.mp4");

    if (!cap.isOpened())
        return 0;

    int width = cap.get(CAP_PROP_FRAME_WIDTH);       //帧宽度
    int height = cap.get(CAP_PROP_FRAME_HEIGHT);     //帧高度
    int totalFrames = cap.get(CAP_PROP_FRAME_COUNT); //总帧数
    int frameRate = cap.get(CAP_PROP_FPS);           //帧率 x frames/s

    std::cout << "视频宽度： " << width << std::endl;
    std::cout << "视频高度： " << height << std::endl;
    std::cout << "视频总帧数： " << totalFrames << std::endl;
    std::cout << "帧率： " << frameRate << std::endl;

    cv::Mat frame;
    while (1)
    {
        cap >> frame;
        if (frame.empty())
            break;
        cv::imshow("hello", frame);
        cv::waitKey(50);
    }
    cap.release();
}

void videocapture2()
{
    //功能：创建一个VideoCapture类的实例，如果传入对应的参数，可以直接打开视频文件或者要调用的摄像头。
    //参数: filename – 打开的视频文件名。
    // device – 打开的视频捕获设备id ，如果只有一个摄像头可以填0，表示打开默认的摄像头。
    VideoCapture();
    // VideoCapture(const string &filename);
    VideoCapture(0);

    //功能：打开一个视频文件或者打开一个捕获视频的设备(也就是摄像头)
    bool open(const string &filename);
    bool open(int device);

    //功能：判断视频读取或者摄像头调用是否成功，成功则返回true
    bool isOpened();

    //功能：关闭视频文件或者摄像头
    void release();

    //功能：读取视频内容
    bool grab();                                 //若没有视频帧被捕获，返回false
    bool retrieve(Mat & image, int channel = 0); //若没有视频帧被捕获，返回false
    // VideoCapture &VideoCapture::operator>>(Mat &image);        //若没有视频帧被捕获，返回空，即cv::Mat.empty()返回true
    bool read(Mat & image); //若没有视频帧被捕获，返回false

    //功能：获得视频有诸多属性，比如：帧率、总帧数、尺寸、格式等
    //如果查询的视频属性是VideoCapture类不支持的，将会返回0
    double get(int propId);

    //功能：设置VideoCapture类的属性，设置成功返回ture,失败返回false
    //参数：第一个是属性ID，第二个是该属性要设置的值
    bool set(int propertyId, double value);
}

void videoread()
{
    VideoCapture capture;
    capture.open("./59_1667472917.mp4");
    if (!capture.isOpened())
    {
        cout << "could not load video data..." << endl;
    }
    Mat frame;
    namedWindow("video_demo", WINDOW_AUTOSIZE);
    while (capture.read(frame))
    {
        imshow("video_demo", frame);
        if (waitKey(100) == 27)
        {
            break;
        }
    }

    waitKey(0);
}

int main()
{
    videocapture();

    // captureGet();

    // captureGet2();

    // videocapture2();
    
    // videoread();

    return 0;
}