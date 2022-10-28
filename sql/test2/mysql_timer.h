#pragma once
#include<string>
#include<iostream>
using namespace std;
class mysql_timer
{
public:
	void set_datetime(string mysql_datetime);
	string get_frame_datetime(double frame,double FPS);
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	double seconds;
};