#include <opencv2\opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "windows.h"

using namespace cv;
using namespace std;

const int bins = 256;
Mat src;

void drawHistogram(Mat& image) {
	// 定义参数变量
	const int channels[1] = { 0 };
	const int bins[1] = { 256 };
	float hranges[2] = { 0,255 };
	const float* ranges[1] = { hranges };
	int dims = image.channels();
	if (dims == 3) {
		vector<Mat> bgr_plane;
		split(src, bgr_plane);
		Mat b_hist;
		Mat g_hist;
		Mat r_hist;
		// 计算Blue, Green, Red通道的直方图
		calcHist(&bgr_plane[0], 1, 0, Mat(), b_hist, 1, bins, ranges);
		calcHist(&bgr_plane[1], 1, 0, Mat(), g_hist, 1, bins, ranges);
		calcHist(&bgr_plane[2], 1, 0, Mat(), r_hist, 1, bins, ranges);
		// 显示直方图
		int hist_w = 512;
		int hist_h = 400;
		int bin_w = cvRound((double)hist_w / bins[0]);
		Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
		// 归一化直方图数据
		normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		// 绘制直方图曲线
		for (int i = 1; i < bins[0]; i++) {
			line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
				Point(bin_w * (i), hist_h - cvRound(b_hist.at<float>(i))), Scalar(255, 0, 0), 1, 8, 0);
			line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
				Point(bin_w * (i), hist_h - cvRound(g_hist.at<float>(i))), Scalar(0, 255, 0), 1, 8, 0);
			line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
				Point(bin_w * (i), hist_h - cvRound(r_hist.at<float>(i))), Scalar(0, 0, 255), 1, 8, 0);

		}
		// 显示直方图
		namedWindow("直方图_Гистограмма", WINDOW_AUTOSIZE);
		imshow("直方图_Гистограмма", histImage);
	}
	else {
		Mat hist;
		// 计算Blue, Green, Red通道的直方图
		calcHist(&image, 1, 0, Mat(), hist, 1, bins, ranges);
		// 显示直方图
		int hist_w = 512;
		int hist_h = 400;
		int bin_w = cvRound((double)hist_w / bins[0]);
		Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
		// 归一化直方图数据
		normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
		// 绘制直方图曲线
		for (int i = 1; i < bins[0]; i++) {
			line(histImage, Point(bin_w * (i - 1), hist_h - cvRound(hist.at<float>(i - 1))),
				Point(bin_w * (i), hist_h - cvRound(hist.at<float>(i))), Scalar(255, 255, 255), 1, 8, 0);
		}
		// 显示直方图
		namedWindow("直方图_Гистограмма", WINDOW_AUTOSIZE);
		imshow("直方图_Гистограмма", histImage);
	}
}

Mat gray;
int maxCorners = 10;

void SubPixels(int, void*)
{
	if (maxCorners < 5)
	{
		maxCorners = 5;
	}
	vector<Point2f> corners;
	double qualityLevel = 0.01;
	//获取角点
	goodFeaturesToTrack(gray, corners, maxCorners, qualityLevel, 10, Mat(), 3, false, 0.04);
	//清除控制台显示
	Mat result = src.clone();
	for (int i = 0; i < corners.size(); i++)
	{
		circle(result, corners[i], 2, Scalar(0, 255, 0), 2, 8, 0);
	}
	TermCriteria tc = TermCriteria(TermCriteria::EPS + TermCriteria::MAX_ITER, 40, 0.001);
	//计算并打印出亚像素角点
	cornerSubPix(gray, corners, Size(5, 5), Size(-1, -1), tc);
	imshow("点检测_Обнаружение точек", result);
}


Mat roiImg, dst, gray_dst;
int threshold_value = 50;

void houghlinedetect(int, void*)
{
	//使用边缘检测将图片二值化
	Canny(roiImg, dst, threshold_value, 2 * threshold_value, 3, false);
	//bitwise_not(dst, dst, Mat());
	vector<Vec4i> lines;//存储直线数据
	HoughLinesP(dst, lines, 1, CV_PI / 180.0, 30, 30, 0); //源图需要是二值图像，HoughLines也是一样

	cvtColor(dst, gray_dst, COLOR_GRAY2BGR); //GRAY2BGR是转化为彩色图像的
	for (size_t i = 0; i < lines.size(); i++)
	{
		Vec4i l = lines[i];
		line(gray_dst, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(186, 88, 255), 1, LINE_AA);
	}
	imshow("线检测_Обнаружение линии", gray_dst);
}
//
//void morphlogy_houghline(int, void*)
//{
//
//	//二值化操作
//	Mat binaryImage, morhpImage, resultImg, dilateImg;
//	cvtColor(roiImg, roiImg, COLOR_BGR2GRAY);
//	threshold(roiImg, binaryImage, 0, 255, THRESH_BINARY | THRESH_OTSU);//THRESH_BINARY|THRESH_OTSU 自动确定阈值
//	bitwise_not(binaryImage, binaryImage, Mat());//当然在threshold中可以使用THRESH_BINARY | THRESH_OTSU直接变成黑色背景
//	//imshow("binary", binaryImage);
//
//
//	//形态学操作，去除除了横线以外的所有字
//	Mat kernel = getStructuringElement(MORPH_RECT, Size(20, 1), Point(-1, -1));//结构元素,这里使用矩形结构元素,Size(30,1)保留横线，point(-1,-1)表示中心
//	morphologyEx(binaryImage, morhpImage, MORPH_OPEN, kernel, Point(-1, -1));
//	//imshow("morphologyEx result", morhpImage);
//
//	//使用膨胀操作把直线变得更明显点
//	kernel = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
//	dilate(morhpImage, dilateImg, kernel, Point(-1, -1));
//	//imshow("dilateimg result", dilateImg);
//
//	//霍夫直线检测
//	vector<Vec4i> lines;
//	resultImg = roiImg.clone();
//
//	HoughLinesP(dilateImg, lines, 1, CV_PI / 180.0, 20, 5, 0);
//	cvtColor(resultImg, resultImg, COLOR_GRAY2RGB);
//	for (size_t i = 0; i < lines.size(); i++)
//	{
//		Vec4i L = lines[i];
//
//		line(resultImg, Point(L[0], L[1]), Point(L[2], L[3]), Scalar(0, 0, 255), 2, 8, 0);
//
//	}
//	imshow("final result", resultImg);
//}
Mat g_dstImage;
int g_nThresholdValue = 100;
int g_nThresholdType = 3;

void on_Threshold(int, void*)
{
	threshold(gray, g_dstImage, g_nThresholdValue, 255, g_nThresholdType);

	imshow("本地阈值处理_Локальная пороговая обработка", g_dstImage);
}

int main(int argc, char** argv)
{
	TCHAR szBuffer[MAX_PATH] = { 0 };
	OPENFILENAME file = { 0 };
	file.hwndOwner = NULL;
	file.lStructSize = sizeof(file);
	file.lpstrFilter = "(*.jpg)\0*.*\0(*.gif)\0*.*\0(*.tif)\0*.*\0(*.bmp)\0*.*\0(*.png)\0*.*\0(*.pcx)";//要选择的文件后缀 
	file.lpstrInitialDir = "";//默认的文件路径 
	file.lpstrFile = szBuffer;//存放文件的缓冲区 
	file.nMaxFile = sizeof(szBuffer) / sizeof(*szBuffer);
	file.nFilterIndex = 0;
	file.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER;//标志如果是多选要加上OFN_ALLOWMULTISELECT
	BOOL bSel = GetOpenFileName(&file);
	printf("file: %s", file.lpstrFile);
	string filePath = file.lpstrFile;

	int start = filePath.find_last_of('\\'); //获取最后一个\\的索引
	int end = filePath.find_last_of('.'); //获取最后一个.的索引
	string filepath = filePath.substr(0, start + 1);
	string fileName = filePath.substr(start + 1, end - start - 1);
	string exten = filePath.substr(end, filePath.length() - end);
	string Ffile = filepath + fileName + exten;

	src = imread(Ffile/*, IMREAD_GRAYSCALE*/);
	//若想处理源图，删掉这里的IMREAD_GRAYSCALE
	if (src.empty()) {
		printf("could not load image...\n");
		return 0;
	}

	namedWindow("原图_Оригинальное изображение", WINDOW_AUTOSIZE);
	imshow("原图_Оригинальное изображение", src);
	drawHistogram(src);

	cvtColor(src, gray, COLOR_RGB2GRAY);
	namedWindow("本地阈值处理_Локальная пороговая обработка", WINDOW_AUTOSIZE);
	createTrackbar("模式_Mode", "本地阈值处理_Локальная пороговая обработка", &g_nThresholdType, 4, on_Threshold);
	createTrackbar("参数值_Parameter Value", "本地阈值处理_Локальная пороговая обработка", &g_nThresholdValue, 255, on_Threshold);
	on_Threshold(0, 0);

	cvtColor(src, gray, COLOR_BGR2GRAY);
	namedWindow("点检测_Обнаружение точек", WINDOW_AUTOSIZE);
	createTrackbar("角度_Angle", "点检测_Обнаружение точек", &maxCorners, 200, SubPixels);

	Mat srcBinary;
	adaptiveThreshold(~gray, srcBinary, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 11, -2);
	namedWindow("自适应阈值处理_Адаптивная пороговая обработка", WINDOW_AUTOSIZE);
	imshow("自适应阈值处理_Адаптивная пороговая обработка", srcBinary);

	Rect roi = Rect(8, 8, src.cols - 10, src.rows - 10);
	roiImg = src(roi);
	namedWindow("线检测_Обнаружение линии", WINDOW_AUTOSIZE);
	createTrackbar("阈值_threshold", "线检测_Обнаружение линии", &threshold_value, 255, houghlinedetect);
	houghlinedetect(0, 0);
	//imshow("roiImg", roiImg);

	waitKey(0);
	return 0;
}
