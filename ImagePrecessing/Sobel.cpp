#include "Sobel.h"

#include "utils.h"

Filter_action::Filter_action()
{
}


Filter_action::~Filter_action()
{
}

int Filter_action::conv_filter(Mat& src, Mat& out, float* filter, int filter_size )
{
	int out_sum;
	int avr = 0;;

	for (int mj = 0; mj < filter_size; mj++)
	{
		for (int mi = 0; mi < filter_size; mi++)
		{
			avr = avr +(filter[mj*filter_size + mi]);
		}
	}

	int ring_offset = filter_size / 2;

	for (int j = ring_offset; j < src.rows - ring_offset-1; j++)
	{
		for (int i = ring_offset; i < src.cols - ring_offset-1; i++)
		{
			out_sum = 0;
			for (int mj = 0; mj < filter_size; mj++)
			{
				for (int mi = 0; mi < filter_size; mi++)
				{
					out_sum = out_sum +(filter[mj*filter_size + mi]) * src.at<uchar>(j - ring_offset + mj, i - ring_offset + mi
						);
				}
			}
			if (avr != 0)		out_sum = out_sum/avr;
			if (out_sum > 255)	out_sum = 255;

			out.at<uchar>(j, i) = out_sum;

		}
	}
	return 0;
}
int Filter_action::do_proc()
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

	//namedWindow("DisplayImage", CV_WINDOW_AUTOSIZE);
	Mat mBulrOut;
	mBulrOut.create(mGray.size(), mGray.type());
	conv_filter(mGray, mBulrOut, mGaussian5,5);
	imshow("Display_Gray", mBulrOut);

	Mat mOut_x;
	mOut_x.create(mBulrOut.size(), mBulrOut.type());
	conv_filter(mBulrOut, mOut_x, mSobelMatrix_x);
	imshow("Display_Sobelx", mOut_x);

	Mat mOut_y;
	mOut_y.create(mBulrOut.size(), mBulrOut.type());
	conv_filter(mBulrOut, mOut_y, mSobelMatrix_y);
	imshow("Display_Sobely", mOut_y);

	Mat mSOut_y;
	mSOut_y.create(mBulrOut.size(), mBulrOut.type());
	Sobel(mBulrOut, mSOut_y, CV_32F, 0, 1, 3); 
	imshow("mSOut_x", mSOut_y);
	Sobel(mBulrOut, mSOut_y, CV_32F, 1, 0, 3);
	imshow("mSOut_y", mSOut_y);

	waitKey();
	
	return 1;
}