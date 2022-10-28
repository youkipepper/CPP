#pragma once
#include "stdafx.h"
#include <iostream>      
#include <cstring>           
#include <io.h>    
#include <fstream>
#include <string>
#include "stdio.h"
#include "stdlib.h"
using namespace std;

float * Para_read(string &s)
{
	static float arr2[10];
	FILE* fp;
	char filename[50];
	string file1 = s;
	strcpy(filename, file1.c_str());
	fp = fopen(filename, "r"); //打开文件
	int i = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%f", &arr2[i]);
		i++;
	}
	fclose(fp);
	return arr2;
}

