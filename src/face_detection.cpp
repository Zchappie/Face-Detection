#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "detector.h"

int main()
{
	
	cv::Mat image;
	cv::namedWindow("Face Detector");
	cv::VideoCapture cap(0);
	Detector detector;
	
	if (!cap.isOpened())
	{
		std::cout << "cannot open camera" << std::endl;
	}
	
	while (true)
	{
		cap >> image;
		double fps = cap.get(cv::CAP_PROP_FPS);
		cv::Mat dst;
		cv::flip(image, dst, 1);
		imshow("Face Detector, FPS: " + std::to_string((int) fps), dst);
		cv::waitKey(25);
	}
}