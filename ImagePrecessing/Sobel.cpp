#include "Sobel.h"
#include <iostream>
#include "utils.h"

void onMouse(int event, int x, int y, int flag, void* params)
{
	Mat *img = (Mat *)params;
	char out_text[256];
	Mat TextWindow;
		
	if (event == CV_EVENT_LBUTTONDOWN || (event == CV_EVENT_MOUSEMOVE && flag == EVENT_FLAG_LBUTTON))
	{
		TextWindow = Mat::zeros(250, 640, CV_8U);
		cout << "Mouse Pos X|Y =" << x << "|" << y << endl;
		for (int j = -10; j < 10; j++)
		{
			memset(out_text, 0, 256);
			for (int i = -10; i < 10; i++)
			{
				char value_text[256] = { 0. };
				if (((x + i) > 0 && (x + i)< img->cols) && ((y + j) > 0 && (y + j) < img->rows))
					sprintf(value_text, ("%4d"), img->at<uchar>(y + j, x + i));
				else
					sprintf(value_text, ("----"));

				strcat(out_text, value_text);
			}
			putText(TextWindow, out_text, Point(0, 120 + j * 10), CV_FONT_HERSHEY_SIMPLEX, 0.3, Scalar(255), 1, 8, false);
		}
		imshow("Text", TextWindow);
	}
	if (event == CV_EVENT_LBUTTONUP)
	{
		destroyWindow("Text");
	}
}

Filter_action::Filter_action()
{
}


Filter_action::~Filter_action()
{
}

int Filter_action::image_Normalize(Mat& src)
{
	int Max = 0;
	int Min = 256;

	for (int j = 0; j < src.rows; j++)
	{
		for (int i = 0; i < src.cols; i++)
		{
			if (Min > src.at<uchar>(j, i))		Min = src.at<uchar>(j, i);
			if (Max < src.at<uchar>(j, i))		Max = src.at<uchar>(j, i);
		}
	}

	for (int j = 0; j < src.rows; j++)
	{
		for (int i = 0; i < src.cols; i++)
		{
			src.at<uchar>(j, i) = ((src.at<uchar>(j, i) - Min) *(256 / (Max - Min) )/10) *10;
		}
	}
	return 0;

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

int createIntense_Map(Mat& src1, Mat& src2, Mat& out)
{
	int out_sum = 0;
	for (int j = 0; j < src1.rows; j++)
	{
		for (int i = 0; i < src1.cols; i++)
		{
			out_sum = sqrt(src1.at<uchar>(j, i) ^ 2 + src2.at<uchar>(j, i)^2);
			out.at<uchar>(j, i) = out_sum;
		}
	}
	return 0;
}

int createDirection_Map(Mat& src1, Mat& src2, Mat& out)
{
	int out_sum = 0;
	for (int j = 0; j < src1.rows; j++)	{
		for (int i = 0; i < src1.cols; i++)		{
			double direction = 0;
			if (src2.at<uchar>(j, i) != 0)		direction = src1.at<uchar>(j, i)/ src2.at<uchar>(j, i);
			out_sum = (int)(atan(direction) * 90.0 / 3.14) / 8;
			if (out_sum > 255)	out_sum = 255;
			if (out_sum < 0)	out_sum = 0;
			out.at<uchar>(j, i) = out_sum;
		}
	}
	return 0;
}

int Filter_action::do_proc()
{
	Mat mImage;
	Mat mGray;


	mImage = imread("sample3.jpg", CV_LOAD_IMAGE_COLOR);

	if (!mImage.data){
		cout << "Error to load Image"  << endl;
		return -1;
	}
	cvtColor(mImage, mGray, CV_RGBA2GRAY);

	//namedWindow("DisplayImage", CV_WINDOW_AUTOSIZE);
	Mat mBulrOut;
	mBulrOut.create(mGray.size(), mGray.type());
	conv_filter(mGray, mBulrOut, mGaussian5,5);
	image_Normalize(mBulrOut);
	imshow("image_Normalize", mBulrOut);

	/*
	Mat mSOut_y;
	mSOut_y.create(mBulrOut.size(), mBulrOut.type());
	Sobel(mBulrOut, mSOut_y, CV_32F, 0, 1, 3); 
	imshow("mSOut_x", mSOut_y);
	Sobel(mBulrOut, mSOut_y, CV_32F, 1, 0, 3);
	imshow("mSOut_y", mSOut_y);
	*/

	Mat mOut_x;
	mOut_x.create(mBulrOut.size(), mBulrOut.type());
	conv_filter(mBulrOut, mOut_x, mSobelMatrix_x);
	image_Normalize(mOut_x);
	//imshow("Display_Sobelx", mOut_x);

	Mat mOut_y;
	mOut_y.create(mBulrOut.size(), mBulrOut.type());
	conv_filter(mBulrOut, mOut_y, mSobelMatrix_y);
	image_Normalize(mOut_y);
	//imshow("Display_Sobely", mOut_y);

	Mat Intense_Map;
	Intense_Map.create(mBulrOut.size(), mBulrOut.type());
	createIntense_Map(mOut_x, mOut_y, Intense_Map);
	image_Normalize(Intense_Map);
	imshow("Intense_Map", Intense_Map);

	Mat Direction_Map;
	Direction_Map.create(mBulrOut.size(), mBulrOut.type());
	createDirection_Map(mOut_x, mOut_y, Direction_Map);
	image_Normalize(Direction_Map);
	imshow("Direction_Map", Direction_Map);

	setMouseCallback("Direction_Map", onMouse, (void*) &Direction_Map);
	
	waitKey();
	
	return 1;
}