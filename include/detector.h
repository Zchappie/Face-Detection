//
// Created by ZeeKAir on 07.05.22.
//

#ifndef FACE_DETECTION_DETECTOR_H
#define FACE_DETECTION_DETECTOR_H

#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/opencv.hpp>

/**
 * Detector of face, input a frame, output a bbox.
 * Ref.:
 * https://docs.opencv.org/3.4/db/d28/tutorial_cascade_classifier.html
 * https://bewagner.net/programming/2020/04/12/building-a-face-detector-with-opencv-in-cpp/
 */
class Detector
{
	public:
	Detector();
	~Detector();
	
	std::vector<cv::Rect> FindFaceLocation(cv::Mat &frame);
	
	private:
	int _method = 1;
	std::vector<cv::Rect> _faces_rect;
	
	// haar cascade method
	cv::CascadeClassifier _face_cascade;
	std::string _data_dir_path = "../data/";
	std::string _face_cascade_file = "haarcascade_frontalface_alt.xml";
	void LoadFaceCascade();
	std::string FindFaceCascade();
	void FindFaceLocationUseHaarDetector(cv::Mat &frame);
	
	// DNN method
	cv::dnn::Net _resNet;
	std::string _dnn_configurations_file = "deploy.prototxt";
	std::string _dnn_weights_file = "res10_300x300_ssd_iter_140000_fp16.caffemodel";
	float _scale_factor = 1.0;
	int _input_image_width = 300;
	int _input_image_height = 300;
	float _confidence_threshold = 0.5;
	cv::Scalar _mean_values = {104., 177.0, 123.0};
	void LoadDNNModel();
	void FindFaceLocationUseDNNDetector(cv::Mat &frame);
};


#endif //FACE_DETECTION_DETECTOR_H
