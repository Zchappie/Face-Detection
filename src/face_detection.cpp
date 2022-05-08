#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "detector.h"
#include "draw.h"

int main()
{
	cv::namedWindow("Face Detector");
	cv::VideoCapture cap(0);
	Detector detector;
	
	if (!cap.isOpened())
	{
		std::cout << "--(!) Cannot open camera" << std::endl;
	}
	
	cv::Mat frame;
	while (cap.read(frame))
	{
		if (frame.empty())
		{
			std::cout << "--(!) No captured frame!\n";
			break;
		}
		
		// flip the image to show it in my used way
		double fps = cap.get(cv::CAP_PROP_FPS);
		cv::Mat flipped;
		cv::flip(frame, flipped, 1);
		
		// detect face
		std::vector<cv::Rect> faces = detector.FindFaceLocation(flipped);
		std::cout << "Found number of faces: " << faces.size() << std::endl;
		Draw::DrawRectsOnFrame(flipped, faces);
		
		// display the result
		imshow("Face Detector, FPS: " + std::to_string((int) fps), flipped);
		cv::waitKey(25);
	}
}