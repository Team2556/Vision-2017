#pragma once
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>

namespace grip {

/**
* HighGoal class.
* 
* An OpenCV pipeline generated by GRIP.
*/
class HighGoal {
	private:
		std::shared_ptr<NetworkTable> Table;
		cv::Mat rgbThresholdOutput;
		cv::Mat maskOutput;
		cv::Mat hsvThresholdOutput;
		std::vector<std::vector<cv::Point> > findContoursOutput;
		std::vector<std::vector<cv::Point> > filterContoursOutput;
		void rgbThreshold(cv::Mat &, double [], double [], double [], cv::Mat &);
		void mask(cv::Mat &, cv::Mat &, cv::Mat &);
		void hsvThreshold(cv::Mat &, double [], double [], double [], cv::Mat &);
		void findContours(cv::Mat &, bool , std::vector<std::vector<cv::Point> > &);
		void filterContours(std::vector<std::vector<cv::Point> > &, double , double , double , double , double , double , double [], double , double , double , double , std::vector<std::vector<cv::Point> > &);
		cv::Point findBoundingCenter(std::vector<std::vector<cv::Point> > &inputContours);

	public:
		HighGoal();
		void Process(cv::Mat& source0);
		cv::Mat* GetRgbThresholdOutput();
		cv::Mat* GetMaskOutput();
		cv::Mat* GetHsvThresholdOutput();
		std::vector<std::vector<cv::Point> >* GetFindContoursOutput();
		std::vector<std::vector<cv::Point> >* GetFilterContoursOutput();
};


} // end namespace grip


