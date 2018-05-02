#include <stdio.h>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include "Filter.hpp"
#include "DummyFilter.hpp"
#include "ConvolutionFilter.hpp"
#include "utils.hpp"

using namespace std;
using namespace cv;

Mat filterApplyer(vector<Filter*> filters, const Mat input){
  Mat aux = input;
  for(Filter* filter : filters){
    aux = filter->apply(aux);
  }
  return aux;
}


int main(int argc, char** argv )
{
  if ( argc != 2 )
  {
      printf("usage: Lab2.out <Image_Path>\n");
      return -1;
  }
  Mat image;

//  image = imread( argv[1], CV_LOAD_IMAGE_COLOR);

 image = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
  if ( !image.data )
  {
      printf("No image data \n");
      return -1;
  }



    Mat result;
    Mat_<float> kernel = (Mat_<float>(3,3) << 1, 0, -1,
                                              1, 0, -1,
                                              1, 0, -1);
    Dummy_filter f;
    ConvolutionFilter con;
    con.kernel = kernel;
    vector<Filter*> vec;
    vec.push_back(&f);
    vec.push_back(&con);
    // int factor = 10;
    result = filterApplyer(vec, image);

    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", result);
    waitKey(0);
    return 0;
}
