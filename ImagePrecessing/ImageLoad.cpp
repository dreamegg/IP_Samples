#include "ImageLoad.h"
#include "opencv_base.h"


ImageLoad::ImageLoad()
{
}


ImageLoad::~ImageLoad()
{
}

int ImageLoad::do_load()
{
	Mat mImage;
	Mat mGray;

	mImage = imread("lenna.png", CV_LOAD_IMAGE_COLOR);

	if (!mImage.data)
	{
		//cout "Error to load Image" >> endl;
		return -1;
	}
	cvtColor(mImage, mGray, CV_RGBA2GRAY);

	namedWindow("DisplayImage", CV_WINDOW_AUTOSIZE);

	imshow("Display", mImage);
	imshow("Display_Gray", mGray);
	waitKey(0);
	
	return 0;
}
