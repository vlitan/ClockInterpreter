#pragma once
#include "Filter.hpp"

class Dummy_filter : public Filter{
public:
	Dummy_filter();
	virtual ~Dummy_filter();
private:
	cv::Mat do_apply(const cv::Mat in) final;
};
