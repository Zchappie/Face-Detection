//
// Created by ZeeKAir on 08.05.22.
//

#ifndef FACE_DETECTION_DRAW_H
#define FACE_DETECTION_DRAW_H

#include <opencv2/core.hpp>
#include <vector>

class Draw
{
	public:
	static void DrawRectsOnFrame(cv::Mat &frame, std::vector<cv::Rect> &shapes);
	
};


#endif //FACE_DETECTION_DRAW_H
