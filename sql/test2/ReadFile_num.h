#pragma once
#include"stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include"targetver.h"

using namespace std;
int Readtxt_num(string &s)
{
	int ch;
	//���ַ���ת��Ϊchar���ͣ�����fopen��������
	char filename[50];
	string file1 = s;
	strcpy(filename, file1.c_str());
	FILE *fp = fopen(filename, "r");
	int n = 0;
	while (!feof(fp))
	{
		fscanf(fp, "%d", &ch);
		//printf(" %d", ch);
		//printf(" %d", n);
		n++;
	}
	fclose(fp);
	n = n - 1;
	if (n % 8 != 0) return n+1;//��ʱ��������һ�����ֳ������Σ�һ�����һλ��
	return n;
}
