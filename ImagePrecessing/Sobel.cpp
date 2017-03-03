#include "Sobel.h"
#include "opencv_base.h"
#include "utils.h"

Sobel_byMe::Sobel_byMe()
{
}


Sobel_byMe::~Sobel_byMe()
{
}

int Sobel_byMe::do_proc()
{
	Mat mImage;
	Mat mGray;
	Mat mOut;

	mImage = imread("lenna.png", CV_LOAD_IMAGE_COLOR);

	if (!mImage.data)
	{
		//cout "Error to load Image" >> endl;
		return -1;
	}
	cvtColor(mImage, mGray, CV_RGBA2GRAY);

	//namedWindow("DisplayImage", CV_WINDOW_AUTOSIZE);

	imshow("Display_Gray", mGray);

	int out_sum;
	for (int j = 1; j < mGray.rows - 1; j++)
	{
		for (int i = 1; i < mGray.cols - 1; i++)
		{
			out_sum = 0;
			for (int mj = 0; mj < 3; mj++)
			{
				for (int mi = 0; mi < 3; mi++)
				{
					out_sum = out_sum + (mSobelMatrix_x[mj][mi]) * mGray.at<uchar>(j - 1 + mj, i - 1 + mi);
				}
			}
			out_sum = out_sum / 20;
			mOut.at<uchar>(j, i) = 255; // out_sum;
			
		}
	}
	imshow("Display_Sobel", mOut);

	waitKey();
	return 1;
}