#pragma once
#include <opencv2/opencv.hpp>
class Filter{
public:
  virtual ~Filter();
  cv::Mat apply(const cv::Mat in);

  // forbid copying
	Filter(Filter const &) = delete;
	Filter & operator=(Filter const &) = delete;

protected:
  Filter();
private:
  virtual cv::Mat do_apply(const cv::Mat in) = 0;
};
