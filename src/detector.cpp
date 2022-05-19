//
// Created by ZeeKAir on 07.05.22.
//

#include <iostream>
#include <utility>
#include <vector>
#include <opencv2/opencv.hpp>
#include "detector.h"

Detector::Detector()
{
	this->LoadFaceCascade();
	this->LoadDNNModel();
	this->_method = "dnn";
}

Detector::Detector(std::string method) : _method(std::move(method))
{
	this->LoadFaceCascade();
	this->LoadDNNModel();
}

Detector::~Detector()
= default;

std::vector<cv::Rect> Detector::FindFaceLocation(cv::Mat &frame)
{
	if (_method == "dnn")
	{
		FindFaceLocationUseDNNDetector(frame);
	} else if (_method == "haar")
	{
		FindFaceLocationUseHaarDetector(frame);
	} else
	{
		throw std::invalid_argument("--(!)Unknown method!\n");
	}
	return _faces_rect;
}

void Detector::setMethod(std::string method)
{
	_method = std::move(method);
}

std::string Detector::getMethod()
{
	return _method;
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
		std::ostringstream ss;
		ss << "--(!)Error loading face cascade! \n";
		throw std::invalid_argument(ss.str());
	}
}

void Detector::FindFaceLocationUseHaarDetector(cv::Mat &frame)
{
	// preprocessing
	cv::Mat frame_gray;
	cv::cvtColor(frame, frame_gray, cv::COLOR_RGB2GRAY);
	cv::equalizeHist(frame_gray, frame_gray);
	
	// detect faces
	_face_cascade.detectMultiScale(frame_gray, _faces_rect);
}

void Detector::LoadDNNModel()
{
	_resNet = cv::dnn::readNetFromCaffe(_data_dir_path + _dnn_configurations_file, _data_dir_path + _dnn_weights_file);
	if (_resNet.empty())
	{
		std::ostringstream ss;
		ss << "--(!)Failed to load network! \n";
		throw std::invalid_argument(ss.str());
	}
}

void Detector::FindFaceLocationUseDNNDetector(cv::Mat &frame)
{
	cv::Mat input_blob = cv::dnn::blobFromImage(frame, _scale_factor, cv::Size(_input_image_width, _input_image_height),
	                                            _mean_values, false, false);
	_resNet.setInput(input_blob, "data");
	cv::Mat detection = _resNet.forward("detection_out");
	cv::Mat detection_matrix(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());
	std::vector<cv::Rect> faces; // avoid appending on the same list cross frames
	
	for (int i = 0; i < detection_matrix.rows; i++)
	{
		float confidence = detection_matrix.at<float>(i, 2);
		
		if (confidence < _confidence_threshold)
		{
			continue;
		}
		
		// resize back to real image dimension
		int x_left_bottom = static_cast<int>(detection_matrix.at<float>(i, 3) * frame.cols);
		int y_left_bottom = static_cast<int>(detection_matrix.at<float>(i, 4) * frame.rows);
		int x_right_top = static_cast<int>(detection_matrix.at<float>(i, 5) * frame.cols);
		int y_right_top = static_cast<int>(detection_matrix.at<float>(i, 6) * frame.rows);
		
		faces.emplace_back(x_left_bottom, y_left_bottom, (x_right_top - x_left_bottom), (y_right_top - y_left_bottom));
	}
	_faces_rect = faces;
}





