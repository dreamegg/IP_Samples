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

	int src[3][3];
	int out[3][3];
	for (int j = 1; j < mGray.rows - 1; j++)
	{
		for (int i = 1; i < mGray.cols - 1; i++)
		{
			src[0][0] = mGray.at<uchar>(j - 1, i-1);
			src[0][1] = mGray.at<uchar>(j - 1, i);
			src[0][2] = mGray.at<uchar>(j - 1, i + 1);
			src[1][0] = mGray.at<uchar>(j, i-1);
			src[1][1] = mGray.at<uchar>(j, i);
			src[1][2] = mGray.at<uchar>(j, i + 1-1);
			src[2][0] = mGray.at<uchar>(j + 1, i);
			src[2][1] = mGray.at<uchar>(j + 1, i);
			src[2][1] = mGray.at<uchar>(j + 1, i + 1);
		}
	}

	utils cUtils;
	//cUtils.MuxMatrix(src, mSobelMatrix_x, out, 3);

	waitKey();
	return 1;
}