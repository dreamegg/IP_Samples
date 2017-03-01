#include "cam_control.h"



cam_control::cam_control()
{
}


cam_control::~cam_control()
{
}

int cam_control::do_cam(void)
{
	//��ĸ���� ���� ������ �о���� ���� �غ�  
	VideoCapture capture(0);
	if (!capture.isOpened())
	{
		cout << "��ķ�� ���� �����ϴ�." << endl;
		return 1;
	}

	//ĸó ������ 320x240���� ����  
	capture.set(CAP_PROP_FRAME_WIDTH, 320);
	capture.set(CAP_PROP_FRAME_HEIGHT, 240);


	Mat frame;
	namedWindow("input", 1);


	while (1)
	{
		//��ĸ���κ��� �� �������� �о��  
		capture >> frame;

		//ȭ�鿡 ������ ������
		imshow("input", frame);

		//ESCŰ ������ ����
		if (waitKey(1) == 27) break;
	}

	return 0;
}