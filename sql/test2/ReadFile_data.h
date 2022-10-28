#pragma once
#include"stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include"targetver.h"

using namespace std;
int  * Readtxt_data(string &rtd,int p[])
{
	//FILE *fp = NULL;
	char filename[50];
	string file1 = rtd;
	strcpy(filename, file1.c_str());
	FILE *fp = fopen(filename, "r");
	int t = 0;

	while (!feof(fp))
	{
		fscanf_s(fp, "%d", (p + t));
		t++;
	}
	fclose(fp);
	return p;
}


