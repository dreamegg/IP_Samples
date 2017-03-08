#pragma once

#include "opencv_base.h"
#define FILTER_SIZE	3

class Filter_action
{
public:
	Filter_action();
	~Filter_action();

	int image_Normalize(Mat& src);
	int conv_filter(Mat& src, Mat& out, float* filter, int filter_size = FILTER_SIZE);
	int do_proc();

private:
	float mGaussian[FILTER_SIZE * FILTER_SIZE] = {
		1,2,1 ,
		2,4,2 ,
		1,2,1 
	};
	float mGaussian5[5 * 5] = {
		1,4,7 ,4,1,
		4,16,26,16,4,
		7,26,41,26,7,
		4,16,26,16,4,
		1,4,7,4,1
	};

	float mSobelMatrix_x[FILTER_SIZE * FILTER_SIZE] = {
		-1,0,1,
		-2,0,2,
		-1,0,1
	};

	float mSobelMatrix_y[FILTER_SIZE * FILTER_SIZE] = {
		 -1,-2,-1 ,
		 0,0,0 ,
		 1,2,1 
	};

};

