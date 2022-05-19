#include <iostream>
#include <memory>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

#include "detector.h"
#include "draw.h"

int main(int argc, char *argv[])
{
	cv::namedWindow("Face Detector");
	cv::VideoCapture cap(0);
	Detector detector;
	if (argc > 1)
	{
		std::string method(argv[1]);
		detector.setMethod(method);
	}
	
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
		
		// detect face and draw on the frame
		std::shared_ptr<cv::Mat> frame_ptr = std::make_shared<cv::Mat>(flipped);
		std::vector<cv::Rect> faces = detector.FindFaceLocation(flipped);
		Draw::DrawRectsOnFrame(flipped, faces);
		std::string text = "Number of face detected: " + std::to_string(faces.size()) + " using " + detector.getMethod();
		Draw::PutTextOnFrame(flipped, text);
		
		// display the result
		imshow("Face Detector, FPS: " + std::to_string((int) fps), flipped);
		cv::waitKey(25);
	}
}