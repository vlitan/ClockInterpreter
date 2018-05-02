#include "Filter.hpp"

Filter::Filter(){

}

Filter::~Filter(){

}

cv::Mat Filter::apply(const cv::Mat in){
  return this->do_apply(in);
}
