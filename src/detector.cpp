//
// Created by ZeeKAir on 07.05.22.
//

#include <iostream>
#include "detector.h"

Detector::Detector()
{
	this->LoadFaceCascade();
}

cv::Rect Detector::FindFaceLocation(cv::Mat &frame)
{
	return cv::Rect();
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

std::string Detector::FindEyeCascade()
{
	return std::string();
}

void Detector::LoadEyeCascade()
{

}

