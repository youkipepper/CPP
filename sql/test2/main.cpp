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
#include<sstream>
#include <io.h>  
#include <conio.h>
#include <winsock.h>
#include <WinUser.h>
#include"ReadFile_data.h"
#include"ReadFile_num.h"
#include"ReadPara.h"
#include"ResDis.h"
#include"mysql_timer.h"
#define KEYDOWN( vk ) ( 0x8000 & ::GetAsyncKeyState( vk ) ) // 或GetKeyState(vk)
using namespace cv;
using namespace std;
int main()
{
	const char user[] = "root";         //username
	const char pswd[] = "root";       //password(local:111111,byx:root)
	const char host[] = "172.16.20.175";    //or"172.16.20.175"
	const char table[] = "bridge";          //database
	unsigned int port = 3306;           //server port        
	MYSQL myCont;
	MYSQL_RES *result=nullptr;
	MYSQL_RES *result_new=nullptr;
	MYSQL_ROW sql_row;
	MYSQL_FIELD *fd;
	string file_path;
	string t2;
	string time;
	string camera_id;
	char column[32][32];
	int res;
	int res_new;
	int num_row;
	int num_row_new;
	int status=2;
	double FPS = 30;
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, user, pswd, table, port, NULL, 0))
	{
		cout << "connect succeed!" << endl;

		//mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		res = mysql_query(&myCont, "select * from byx_video_record where status = 0");//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result)
			{
				int i, j;
				num_row = mysql_num_rows(result);
				cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;
				//cout << "number of result1: " << (unsigned long)mysql_num_fields(result) << endl;
				for (i = 0; fd = mysql_fetch_field(result); i++)//获取列名
				{
					strcpy_s(column[i], fd->name);
				}
				j = mysql_num_fields(result);
				for (i = 0; i < j; i++)
				{
					printf("%s\t", column[i]);
				}
				printf("\n");
				std::cout << "ok" << endl;
				//char sql[200];
				while (sql_row = mysql_fetch_row(result))//获取具体的数据
				{
					file_path = sql_row[1];
					//时间数据
					time = sql_row[2];
					camera_id = sql_row[4];
					//脏数据清理
					char sqld[400];
					//数据量大了后这一步的功耗很大
					string str1 = "delete from byx_video_data where video_record_file='" + file_path + "'";//Defalte视频地址无法识别
					strcpy_s(sqld, str1.c_str());
					mysql_query(&myCont, sqld);
					cout << file_path << endl;
					//位移结果输入
					status = Res_Dis(file_path, time, camera_id, myCont);
					if (status == 1)
					{
						cout << file_path << "文件计算完成数据输入成功" << endl;
						//运算完更新视频使用状态status=1(ok)
						string str3 = "update byx_video_record set status=1 where file_path ='" + file_path + "'";
						strcpy_s(sqld, str3.c_str());
						mysql_query(&myCont, sqld);
						cout << file_path << "状态已更新" << endl;
					}
					else
					{
						cout << file_path << "状态更新异常,错误代码" <<status<< endl;
						string str3 = "update byx_video_record set status="+to_string(status)+" where file_path ='" + file_path + "'";
						strcpy_s(sqld, str3.c_str());
						mysql_query(&myCont, sqld);
					}
				}
			}

			else
			{
				cout << "query sql failed!" << endl;
			}
		}
	}
	else
	{
		cout << "connect failed!" << endl;
		return 0;
	}	
	if (result != NULL) mysql_free_result(result);//释放结果资源
	//当数据未更新时，数据等待，有更新时，继续计算
	while (1)
	{
		res_new = mysql_query(&myCont, "select * from byx_video_record where status = 0");//查询
		result_new = mysql_store_result(&myCont);
		num_row_new = mysql_num_rows(result_new);
		cout << "number of new data:" << num_row_new << endl;
		if (num_row_new == 0)
		{
			if (result_new!= NULL) mysql_free_result(result_new);
			cout << "等待数据上传" << endl;
			cout << num_row_new<< endl;
			Sleep(20000);
			//设置出口,按ESC键退出程序
			if (KEYDOWN(VK_ESCAPE))
				break;
		}
		else
		{
			while (sql_row = mysql_fetch_row(result_new))
			{
				file_path = sql_row[1];
				string time = sql_row[2];
				camera_id = sql_row[4];
				cout << "data path:" << file_path << endl;
				char sqld[300];
				status = Res_Dis(file_path, time, camera_id, myCont);
				if (status == 1)
				{
					cout << file_path << "文件计算完成数据输入成功" << endl;
					//运算完更新视频使用状态status=1(ok)
					string str3 = "update byx_video_record set status=1 where file_path ='" + file_path + "'";
					strcpy_s(sqld, str3.c_str());
					mysql_query(&myCont, sqld);
					cout << file_path << "状态已更新" << endl;
				}
				else
				{
					cout << file_path << "状态更新异常" << endl;
					string str3 = "update byx_video_record set status="+to_string(status)+" where file_path ='" + file_path + "'";
					strcpy_s(sqld, str3.c_str());
					mysql_query(&myCont, sqld);
				}
			}
			cout << "数据导入完毕" << endl;
		}
	}
	mysql_close(&myCont);//断开连接
	system("pause");
	return 0;
}

	
