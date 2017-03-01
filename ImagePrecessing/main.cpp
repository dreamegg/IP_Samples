#include "opencv2/opencv.hpp"  
#include <iostream>  

using namespace cv;
using namespace std;



int main(int, char**)
{
	//웹캡으로 부터 데이터 읽어오기 위해 준비  
	VideoCapture capture(0);
	if (!capture.isOpened())
	{
		cout << "웹캠을 열수 없습니다." << endl;
		return 1;
	}

	//캡처 영상을 320x240으로 지정  
	capture.set(CAP_PROP_FRAME_WIDTH, 320);
	capture.set(CAP_PROP_FRAME_HEIGHT, 240);


	Mat frame;
	namedWindow("input", 1);


	while (1)
	{
		//웹캡으로부터 한 프레임을 읽어옴  
		capture >> frame;

		//화면에 영상을 보여줌
		imshow("input", frame);

		//ESC키 누르면 종료
		if (waitKey(1) == 27) break;
	}

	return 0;
}
