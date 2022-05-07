//
// Created by ZeeKAir on 07.05.22.
//

#ifndef FACE_DETECTION_DETECTOR_H
#define FACE_DETECTION_DETECTOR_H

#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

/**
 * Detector of face, input a frame, output a bbox.
 * Ref.: https://docs.opencv.org/3.4/db/d28/tutorial_cascade_classifier.html
 */
class Detector
{
	public:
	Detector();
	cv::Rect FindFaceLocation(cv::Mat &frame);
	
	private:
	std::string FindFaceCascade();
	std::string FindEyeCascade();
	void LoadFaceCascade();
	void LoadEyeCascade();
	
	cv::CascadeClassifier _face_cascade;
	cv::CascadeClassifier _eye_cascade;
	std::string _data_dir_path = "../data/";
	std::string _face_cascade_file = "haarcascade_frontalface_alt.xml";
	std::string _eye_cascade_file = "haarcascade_eye_tree_eyeglasses.xml";
};


#endif //FACE_DETECTION_DETECTOR_H
