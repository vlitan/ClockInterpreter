#pragma once

#include "Filter.hpp"

class ConvolutionFilter : public Filter{
public:
	ConvolutionFilter();
	virtual ~ConvolutionFilter();

  cv::Mat_<float> kernel;
private:
	cv::Mat do_apply(const cv::Mat in) final;
};
