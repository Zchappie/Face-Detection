//
// Created by ZeeKAir on 08.05.22.
//
#include <opencv2/imgproc.hpp>
#include "draw.h"

void Draw::DrawRectsOnFrame(cv::Mat &frame, std::vector<cv::Rect> &shapes)
{
	if (shapes.empty())
	{
		return;
	}
	for (auto rect: shapes)
	{
		cv::rectangle(frame, cv::Point(rect.x, rect.y), cv::Point(rect.x + rect.width, rect.y + rect.height), cv::Scalar(255, 0, 0));
	}
}

void Draw::PutTextOnFrame(cv::Mat &frame, std::string &s)
{
	cv::putText(frame, s, cv::Point(10, 50), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, cv::Scalar(0, 0, 0), 1);
}
