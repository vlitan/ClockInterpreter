#include "ConvolutionFilter.hpp"
#include "utils.hpp"
ConvolutionFilter::ConvolutionFilter(){}

ConvolutionFilter::~ConvolutionFilter(){
}

int isInside(Mat img, int i, int j){
  if (i >= img.rows) return 0;
  if (i < 0) return 0;
  if (j >= img.cols) return 0;
  if (j < 0) return 0;
  return 1;
}

uchar applyKernel(Mat_<uchar> img, Mat_<float> kernel, int centerI, int centerJ, float normFactor){
  float auxResult = 0;
  uchar result;
  for (int i = 0; i < kernel.rows; i++){
    for (int j = 0; j < kernel.cols; j++){
      int selectedI = centerI + i - kernel.rows / 2;
      int selectedJ = centerJ + j - kernel.cols / 2;
      if (isInside(img, selectedI, selectedJ)){
          auxResult += img(selectedI, selectedJ) * kernel(i, j);
      }
    }
  }
  auxResult /= normFactor;
  result = (uchar)abs(round(auxResult));
  if (result < 0 || result > 255){
    printf("ERROR in applyKernel, result out of bounds");
  }
  return result;
}

float computeNormFactor(Mat_<float> kernel){
  int neg = 0;
  int pos = 0;
  for (int i = 0; i < kernel.rows; i++){
    for (int j = 0; j < kernel.cols; j++){
      if (kernel(i, j) < 0){
        neg += kernel(i,j);
      }
      else{
        pos += kernel(i,j);
      }
    }
  }
  if (pos > abs(neg)){
    return pos;
  }
  else {
    return abs(neg);
  }
}

Mat_<uchar> convolution(Mat_<uchar> img, Mat_<float> kernel){
  Mat_<uchar> dst(img.rows, img.cols);
  float normFactor = computeNormFactor(kernel);

  for (int i = 0; i < dst.rows; i++){
    for (int j = 0; j < dst.cols; j++){
      dst(i,j) = applyKernel(img, kernel, i, j, normFactor);
    }
  }
  return dst;
}

cv::Mat ConvolutionFilter::do_apply(const cv::Mat in){
  return convolution(in, this->kernel);
}
