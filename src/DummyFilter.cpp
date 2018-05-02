#include "DummyFilter.hpp"

Dummy_filter::Dummy_filter(){}

Dummy_filter::~Dummy_filter(){

}

cv::Mat Dummy_filter::do_apply(const cv::Mat in){
  cv::Mat result;
  result = in.clone();

  return result;
}
