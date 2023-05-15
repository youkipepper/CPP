//#define _CRT_SECURE_NO_WARNINGS
///�˶������⡪��֡� 
#pragma once
#include"opencv2/opencv.hpp"  
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
// #include "opencv2/imgproc/imgproc.hpp"  
// #include "opencv2/imgproc/imgproc_c.h"
#include <fstream>
#include<iostream>
#include <iomanip>
#include <string>
#include<math.h>
#include<opencv2/xfeatures2d.hpp>
using namespace cv;
using namespace std;

void imcrop(cv::Mat& img_1, cv::Rect& rect, cv::Mat& crop_im1)
{
	cv::Mat destImage = cv::Mat::zeros(rect.height, rect.width, 0);// Ŀ��ͼ��  
										  // ��ȡ�����ͼ��  
	int crop_x1 = cv::max(0, rect.x);
	int crop_y1 = cv::max(0, rect.y);
	int crop_x2 = cv::min(img_1.cols - 1, rect.x + rect.width - 1); // ͼ��Χ 0��cols-1, 0��rows-1  
	int crop_y2 = cv::min(img_1.rows - 1, rect.y + rect.height - 1);

	cv::Mat roiImage = img_1(cv::Range(crop_y1, crop_y2 + 1), cv::Range(crop_x1, crop_x2 + 1));// ��������Ҳ�����  

																							// �����Ҫ���  
	int left_x = (-rect.x);
	int top_y = (-rect.y);
	int right_x = rect.x + rect.width - img_1.cols;
	int down_y = rect.y + rect.height - img_1.rows;
	if (top_y > 0 || down_y > 0 || left_x > 0 || right_x > 0)//ֻҪ���ڱ߽�Խ������������Ҫ�߽����
	{
		left_x = (left_x > 0 ? left_x : 0);
		right_x = (right_x > 0 ? right_x : 0);
		top_y = (top_y > 0 ? top_y : 0);
		down_y = (down_y > 0 ? down_y : 0);
		cv::copyMakeBorder(roiImage, destImage, top_y, down_y, left_x, right_x, cv::BORDER_CONSTANT, cv::Scalar(0, 0, 0));//cv::Scalar(0,0,255)ָ����ɫ���
		// �Դ����߽纯����top_y, down_y, left_x, right_xΪ�Ǹ�����  
		// ����I.cols = roi_img.cols + left_x + right_x, I.rows = roi_img.rows + top_y + down_y  
		crop_im1 = destImage;
	}
	else//�������ڱ߽�Խ������������Ҫ�����
	{
		destImage = roiImage;
		crop_im1 = destImage;
	}
}

double PiontDetect(Mat&img_1, Mat&img_2, float& arr1,int *ROI);//�������⺯������  
double PiontDetect(Mat&img_1, Mat&img_2, float& arr1, int *ROI) {
	
	Mat ROI_temp;
	Mat ROI_dst;
	Mat ROI_resize_dst;
	Mat ROI_resize_templ;
	Mat src;
	Mat dst;
	float* arr1_1= &arr1;
	int x = ROI[0];
	int y = ROI[1];
	int width = ROI[2];
	int height = ROI[3];
	float mH  = arr1_1[0];
	float ngm = arr1_1[1];
	float sgm = arr1_1[2];
	float rRT = arr1_1[3];
	float ssn = arr1_1[4];
	float minXY = float(width);
	float maxXY = float(height);
	if (!img_1.data || !img_2.data)
	{
		cout << "ERROR";
		return 0;
	}
	cout << "�����������ݳ�ʼ���ɹ�" << endl;
	cv::Rect Roi_model((x - 2.5 * width), y, 3.5 * width, 3.5 * height);
	//��־�������
	if (Roi_model.x <= 0 || Roi_model.y <= 0 || (Roi_model.x + Roi_model.width) >= img_1.cols || (Roi_model.height + Roi_model.y) >= img_1.rows)
	{
		return 0.0;
	}
	ROI_temp = img_1(Roi_model);
	ROI_dst = img_2(Roi_model);
	cout << "����Ȥ�����ȡ���" << endl;
	cv::resize(ROI_temp, ROI_resize_templ, cv::Size(ROI_temp.cols, ROI_temp.rows), 0, 0, INTER_LINEAR);
	cv::resize(ROI_dst, ROI_resize_dst, cv::Size(ROI_dst.cols, ROI_dst.rows), 0, 0, INTER_LINEAR);
	cv::Rect rect(0, -2.5 * height, 6 * width, 6 * height);
	imcrop(ROI_resize_templ, rect, src);
	imcrop(ROI_resize_dst, rect, dst);
	cout << "�ڱ��������" << endl;
	//SURF���ؼ���
	//AKAZE���ؼ���
	Ptr<AKAZE> detector = AKAZE::create();
	vector<KeyPoint>keypoints_1, keypoints_2;
	Mat  desriptors_1,desriptors_2;
	// �õ�keypoints �� ������
	detector->detect(src, keypoints_1);
	detector->detect(dst, keypoints_2);
	if (keypoints_1.size() < 2 || keypoints_2.size() < 2)
	{
		cout << "δ��⵽������" << endl;
		return 0;

	}
	cout << "��������ɹ���ʼƥ��" << endl;
	Ptr<ORB> orb = ORB::create();
	orb->compute(src, keypoints_1, desriptors_1);
	orb->compute(dst, keypoints_2, desriptors_2);
	//����FLANN�㷨ƥ������������
	FlannBasedMatcher matcher(new flann::LshIndexParams(20, 10, 2));
	vector<DMatch> matches_1;
	matcher.match(desriptors_1, desriptors_2, matches_1);
	//���ټ���ؼ����������С����
	//double max_dist_1 = 0, min_dist_1 = 100;
	//for (int i = 0; i < desriptors_1.rows; ++i)
	//{
	//	double dist_1 = matches_1[i].distance;
	//	if (dist_1 < min_dist_1&& dist_1 != 0)
	//	{
	//		min_dist_1 = dist_1;
	//	}
	//	if (dist_1 > max_dist_1)
	//	{
	//		max_dist_1 = dist_1;
	//	}
	//}
	///*���������Ϣ
	//printf(">�����루max dist��> %f\n", max_dist_1);
	//printf(">��С���루min dist�� > %f\n", min_dist_1);*/
	//����ƥ����С��10*min_dist�ĵ�
	//vector<dmatch> good_matches_1;
	//for (int i = 0; i < desriptors_1.rows; ++i)
	//{
	//	if (matches_1[i].distance < ngm * min_dist_1)
	//	{
	//		good_matches_1.push_back(matches_1[i]);
	//	}
	//}
	//���Ƴ�����������ƥ���
	//Mat img_matches_1;
	//drawMatches(src, keypoints_1,
	//	dst, keypoints_2,
	//	good_matches_1,//1��2��ƥ���
	//	img_matches_1,//���ͼ��
	//	Scalar::all(-1),
	//	Scalar::all(-1),
	//	vector<char>(),
	//	DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	cout << "RANSACǰƥ�����" << "����" << matches_1.size() << endl;
	if (matches_1.size() < sgm) 
	{
		cout << "RANSACδƥ�䵽��" << endl;
		return 0;
	}
	//imshow("ƥ��Ч��ͼ1-2", img_matches_1);
	//����H����ƥ��
	//����ƥ������
	vector<int> queryIdxs(matches_1.size()), trainIdxs(matches_1.size());
	for (size_t i = 0; i < matches_1.size(); i++)
	{
		queryIdxs[i] = matches_1[i].queryIdx;
		trainIdxs[i] = matches_1[i].trainIdx;
	}


	Mat H12;   //�任����

	vector<Point2f> points1; KeyPoint::convert(keypoints_1, points1, queryIdxs);
	vector<Point2f> points2; KeyPoint::convert(keypoints_2, points2, trainIdxs);
	int ransacReprojThreshold = rRT;  //�ܾ���ֵ


	H12 = findHomography(Mat(points1), Mat(points2), RHO, ransacReprojThreshold);
	vector<char> matchesMask(matches_1.size(), 0);
	Mat points1t;
	if (H12.empty())
	{
		return 0;
	}
	perspectiveTransform(Mat(points1), points1t, H12);

	for (size_t p = 0; p < points1.size(); p++)  //���桮�ڵ㡯
	{
		if (norm(points2[p] - points1t.at<Point2f>((int)p, 0)) <= ransacReprojThreshold) //���ڵ������
		{
			matchesMask[p] = 1;
		}
	}
	//����ת��Ϊfloat����
	vector <KeyPoint> RAN_KP1, RAN_KP2;
	//size_t�Ǳ�׼C���ж���ģ�ӦΪunsigned int����64λϵͳ��Ϊlong unsigned int,��C++��Ϊ����Ӧ��ͬ��ƽ̨�����ӿ���ֲ�ԡ�
	for (size_t i = 0; i < matches_1.size(); i++)
	{
		RAN_KP1.push_back(keypoints_1[matches_1[i].queryIdx]);
		RAN_KP2.push_back(keypoints_2[matches_1[i].trainIdx]);
		//RAN_KP1��Ҫ�洢img01������img02ƥ��ĵ�
		//goodMatches�洢����Щƥ���Ե�img01��img02������ֵ
	}
	//���¶���һ����
	vector <KeyPoint> RR_KP1, RR_KP2;
	vector <DMatch> RR_matches;
	vector<char> matchesMask1;
	int index = 0;
	for (size_t i = 0; i < matches_1.size(); i++)
	{
		if (matchesMask[i] != 0)
		{
			RR_KP1.push_back(RAN_KP1[i]);
			RR_KP2.push_back(RAN_KP2[i]);
			matches_1[i].queryIdx = index;
			matches_1[i].trainIdx = index;
			RR_matches.push_back(matches_1[i]);
			matchesMask1.push_back(matchesMask[i]);
			index++;
		}
	}
	Mat match_img2;   //�˳�����㡯��
	drawMatches(src, RR_KP1, dst, RR_KP2, RR_matches, match_img2, Scalar::all(-1), Scalar::all(-1), matchesMask1);


	//imshow("�˳���ƥ���", match_img2);

	cout << "RANSAC��ƥ�����" << "����" << RR_matches.size() << endl;

	//�������С��������
	/*
	RR_matches_ROI_1.assign(RR_matches.begin(), RR_matches.end());
	sort(RR_matches_ROI_1.begin(), RR_matches_ROI_1.end());

	cout << RR_matches_ROI_1.size() << endl;
	vector <DMatch> RR_matches_1;
	int matches_index = 0.8*RR_matches_ROI_1.size();
	for (int p = 0; p < matches_index; ++p)
	{
	RR_matches_1.push_back(RR_matches_ROI_1[p]);
	}
	*/
	//������������ж�λ

	vector <DMatch> RR_matches_ROI;
	for (int p = 0; p < RR_matches.size(); p++)
	{

		Point2f k_1 = RR_KP1[RR_matches[p].queryIdx].pt;
		Point2f k_2 = RR_KP2[RR_matches[p].trainIdx].pt;
		if ((k_1.y > (2.5*maxXY+3)) && (k_1.y < (3.5*maxXY-3)) && (k_2.y > (2.5*maxXY+3)) && (k_2.y < (3.5*maxXY-3))
			&&(k_1.x>(2.5*minXY+3))&&(k_1.x<(3.5*minXY-3))&&(abs(k_2.y-k_1.y)<0.5*maxXY))
		{
			RR_matches_ROI.push_back(RR_matches[p]);
		}
	}
	cout << "�����귶Χɸѡ------" << RR_matches_ROI.size() << endl;
	if (RR_matches_ROI.size() == 0) {
		cout << "δƥ�䵽��" << endl;
		return 0;
	}
	Mat goodMathcesImage1;
	drawMatches(src, RR_KP1, dst, RR_KP2, RR_matches_ROI, goodMathcesImage1, \
		Scalar::all(-1), Scalar::all(-1), vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS);
	imshow("������ɸѡ��", goodMathcesImage1);
	int sort_num = ssn * RR_matches_ROI.size();
	double *diff1 = new double[sort_num];
	//double diff1[100];
	for (int p = 0; p < sort_num; p++)
	{
		Point2f k_1 = RR_KP1[RR_matches_ROI[p].queryIdx].pt;
		Point2f k_2 = RR_KP2[RR_matches_ROI[p].trainIdx].pt;
		diff1[p] = k_2.y - k_1.y;
	}
	//���ѭ���Ա�
	for (int i = 0; i < sort_num - 1; i++)
	{
		//�ڲ�ѭ���Ա�
		for (int j = 0; j < sort_num - i - 1; j++)
		{
			if (abs(diff1[j])>abs(diff1[j + 1]))
			{
				double temp1 = diff1[j];
				diff1[j] = diff1[j + 1];
				diff1[j + 1] = temp1;
			}
		}
	}


	double sum = 0;
	for (int i = 0; i < sort_num; i++) {
		sum += diff1[i];
	}
	double mean = sum / sort_num;
	delete[]diff1;//�ͷ�
	waitKey(10);
	return mean;
}
