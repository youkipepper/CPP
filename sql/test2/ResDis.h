#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <mysql.h> 
#include "stdafx.h"  
#include"opencv2/opencv.hpp"  
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include "opencv2/imgproc/imgproc_c.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include<math.h>
#include"PointDetect.h"
#include <cstring>           
#include <io.h>
#include <direct.h> 
#include"ReadFile_data.h"
#include"ReadFile_num.h"
#include"ReadPara.h"
#include <mysql.h> 
#include"mysql_timer.h"
using namespace cv;
using namespace std;
//temp1第一帧，frame放在循环里赋值对比
//读取文件夹中的第一帧

int Res_Dis(string& p1, string& time, string& camera_id, MYSQL myCont)
{
	//初始化变量
	double disyy;
	double minXY;
	double maxXY;
	int query_status;
	int roi[4];
	Mat frame;
	Mat templ;
	MYSQL_ROW sql_row;
	MYSQL_RES* result = nullptr;
	static float Dis_y[10];
	string path = p1;
	Mat ROI_temp;
	Mat ROI_dst;
	Mat ROI_resize_dst;
	Mat ROI_resize_templ;
	Mat crop_im2;
	char sql[400];
	char folder[400];
	//读取视频
	vector<string> src_name;
	vector<string> point_code;
	vector<int> x;
	vector<int> y;
	vector<int> width;
	vector<int> height;
	vector<Mat> crop_im1;
	string para_1 = "data.txt";
	float* arr_para = Para_read(para_1);
	int ret = 0;
	strcpy(folder, path.c_str());
	ret = _access(folder, 0);
	if(ret == 0)
	{
		cerr << "Get in " << path <<endl;
	}
	else
	{

		cerr << "error:failed to" << path << endl;
		return 7;
	}
    glob(path, src_name, false);
	if (src_name.size() == 0)
	{
		cerr << "There's no file in " << path << endl;
		return 2;
	}
	templ = cv::imread(src_name[0]);
	if (time.size() == 0)
	{
		cout << "请输入在表中输入时间" << endl;
		return 3;
	}
	string sql_query = "select * from byx_test_point_info where camera_code = '" + camera_id + "'";
	cout << sql_query << endl;
	strcpy_s(sql, sql_query.c_str());
	//读取测点信息
	query_status=mysql_query(&myCont, sql);
	if (!query_status)
	{
		result = mysql_store_result(&myCont);
		cout << "测点表读取成功" << endl;
		if (result->row_count==0)
		{
			return 4;
		}
	}
	else
	{
		return 4;
	}
	//数据填写不满时没有预警功能
	while (sql_row = mysql_fetch_row(result))
	{
		int i = 0;
		string position = sql_row[2];
		string size = sql_row[8];
		point_code.push_back(sql_row[1]);
		x.push_back(stoi(position.substr(0, position.find(","))));
		y.push_back(stoi(position.substr(position.find(",") + 1, position.length())));
		width.push_back(stoi(size.substr(0, size.find(","))));
		height.push_back(stoi(size.substr(size.find(",") + 1, size.length())));
	}
	cout << "测点数据录入成功" << endl;

	//根据图像数据循环
	for (int f = 0; f < src_name.size() - 1; f++)
	{
		//  读取单帧图片 
		frame = cv::imread(src_name[f]);
		if (frame.empty())
			return 5;
		//  创建图像显示窗口  
		//imshow("实时显示", frame);
		//获得当前帧时间
		mysql_timer Frame_time;
		Frame_time.set_datetime(time);
		string time_now = Frame_time.get_frame_datetime(double(f), 60);
		//后续根据测点实行并行
		for (int i = 0; i < x.size(); i++)
		{
			roi[0] = x[i];
			roi[1] = y[i];
			roi[2] = width[i];
			roi[3] = height[i];
			if (roi[0] <= 0 || (roi[0] + roi[2]) > templ.cols || roi[1] <= 0 || (roi[1] + roi[3]) >= templ.rows)
			{
				cout << "ROI越界" << endl;
				return 5;
			}
			disyy = PiontDetect(templ, frame, *arr_para,roi);
			string str = "insert into byx_video_data (y_offset,test_point_code,video_record_file,frame_num,video_record_time)values('" + to_string(disyy) + "','" + point_code[i] + "','" + path + "','" + to_string(f) + "','" + time_now + "')";
			strcpy(sql, str.c_str());
			mysql_query(&myCont, sql);
			cout << "执行sql语句成功，位移导入" << endl;
		}
		//按TXT循环->按数据库条目数循环
		//释放申请的动态内存(结果集)
	}
	if (result != NULL) mysql_free_result(result);
	return 1;
}

