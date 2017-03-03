#include "ImageLoad.h"
#include "opencv_base.h"
//#include <opencv2/core/core.hpp>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

ImageLoad::ImageLoad()
{
}


ImageLoad::~ImageLoad()
{
}

void th_by_Trackbar(int iTh, void* f)
{
	Mat* i = (Mat*)f;
	Mat bw;
	std::cout << "TH >>>" << iTh << "||";
	threshold(*i, bw, iTh, 255, THRESH_BINARY_INV);
	imshow("Bin", bw);
}

Mat draw_histo_gray(double hist[])
{
	double vmax = 1.0;
	Mat himg(256, 256, CV_8U, Scalar(255));

	for (int i = 0; i < 256; i++)
	{
		if (hist[i] > vmax)
			vmax = hist[i];
	}

	for (int i = 0; i < 256; i++)
	{
		Point p1(i, 256), p2(i, 256 - (int)((hist[i] / vmax)*(0.8 * 256)));
		line(himg, p1, p2, Scalar(0));
		cout << "["<<i << "|" << (int)((hist[i] / vmax)*(0.8 * 256)) << "]";
	}
	cout << endl;

	return himg;
}

int calc_histogram_gray(Mat& src, double histo[])
{
	int i, j;
	int ihist[256] = { 0, };
	int bin = 0;

	for (j=0; j< src.rows; j++)
		for (i = 0; i < src.cols; i++)
		{
			bin = src.at<uchar>(j, i);
			ihist[bin]++;
		}

	for (i = 0; i < 256; i++)
		histo[i] = ihist[i];// / (double)(src.rows*src.cols);

	return 0;
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

	double hist[256];
	calc_histogram_gray(mGray, hist);

	Mat bar = draw_histo_gray(hist);
	namedWindow("HistoG");
	imshow("HistoG", bar);

	int pos = 128;

	namedWindow("Bin");
	createTrackbar("TH", "Bin", &pos, 255, th_by_Trackbar, (void*)&mGray);
	imshow("Bin", mGray);
	waitKey(0);
	
	return 0;
}



