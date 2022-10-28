#include"mysql_timer.h"
void mysql_timer::set_datetime(string time)
{
	this->year = atoi(time.substr(0, 4).c_str());
	this->month = atoi(time.substr(5, 2).c_str());
	this->day= atoi(time.substr(8, 2).c_str());
	this->hour = atoi(time.substr(11, 2).c_str());
	this->minute = atoi(time.substr(14, 2).c_str());
	this->seconds = atof(time.substr(17).c_str());
}

int set_month(int y, int m)
{
	int month_day = 0;
	// 局部变量声明
	switch (m)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		month_day = 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		month_day = 30;
		break;
	case(2):
		if ((y % 4) != 0)
		{
			month_day = 28;
		}
		else
		{
			month_day = 29;
		}
		break;
	}
	return month_day;
}

string mysql_timer::get_frame_datetime(double frame,double n)
{
	string frame_time;
	double using_time = frame/ n;
	this->seconds = this->seconds + using_time;
	this->minute = this->minute+this->seconds / 60;
	this->seconds = this->seconds;
	while (seconds >= 60)
	{
		seconds=seconds - 60;
	}
	//分钟》小时
	this->hour = this->hour+this->minute/ 60;
	minute = minute % 60;
	//小时>>日
	day = day + hour / 24;
	hour = hour % 24;
	//日>>月
	int month_day = set_month(year, month)+1;
	month = month + (day / month_day);
	day = day % (month_day);
	if (day == 0)
	{
		day = 1;
	}
	//月>>年
	year = year + month / 12;
	month = month % 12;
	if (month == 0)
	{
		month = 1;
	}
	string seconds_str;
	seconds_str = to_string(((int)seconds / 10)) + to_string(((int)seconds % 10)) + to_string(seconds).substr(to_string(seconds).rfind("."));
	frame_time = to_string(year) + "-" + to_string(month / 10) + to_string(month % 10) + "-" + to_string(day / 10) + to_string(day % 10) + " " + to_string(hour / 10) + to_string(hour % 10) + ":"
		+ to_string(minute / 10) + to_string(minute % 10) + ":" + seconds_str;
	return frame_time;
}

