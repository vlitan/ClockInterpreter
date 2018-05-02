#pragma once
#include <opencv2/opencv.hpp>
#include <vector>
#include "Filter.hpp"

using namespace std;
using namespace cv;

//
//  result = for_each<uchar, Vec3b>(image, [](Vec3b in){return (1.0f/4*in[0] + 1.0f/2*in[1] + 1.0f/4*in[2]);});
template<class outT, class inT>
Mat_<outT> for_each(Mat_<inT> input, function<outT (inT)> func){
  Mat_<outT> result(input.rows, input.cols);
  for(int i = 0; i < input.rows; i++){
    for (int j = 0; j < input.cols; j++){
      result(i,j) = func(input(i,j));
    }
  }
  return result;
}
