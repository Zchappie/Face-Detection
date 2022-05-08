//
// Created by ZeeKAir on 07.05.22.
//

#include <iostream>
#include <vector>
#include "detector.h"

Detector::Detector()
{
	this->LoadFaceCascade();
}

Detector::~Detector()
= default;

std::vector<cv::Rect> Detector::FindFaceLocation(cv::Mat &frame)
{
	// preprocessing
	cv::Mat frame_gray;
	cv::cvtColor(frame, frame_gray, cv::COLOR_RGB2GRAY);
	cv::equalizeHist(frame_gray, frame_gray);
	
	// detect faces
	_face_cascade.detectMultiScale(frame_gray, _faces_rect);
	return _faces_rect;
}

std::string Detector::FindFaceCascade()
{
	std::cout << "File path to the face cascade is " + _data_dir_path + _face_cascade_file + "\n";
	return cv::samples::findFile(_data_dir_path + _face_cascade_file);
}

void Detector::LoadFaceCascade()
{
	if (!_face_cascade.load(FindFaceCascade()))
	{
		std::cout << "--(!)Error loading face cascade\n";
	}
}

// TODO
std::string Detector::FindEyeCascade()
{
	return std::string();
}

// TODO
void Detector::LoadEyeCascade()
{

}


