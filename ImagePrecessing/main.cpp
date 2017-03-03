#include <iostream>  
using namespace std;

#include "cam_control.h"
#include "ImageLoad.h"

int main(int, char**)
{
	char chIputCase;

	cout << "----------------" << endl;
	cout << "[0] Exit" << endl;
	cout << "[1] Web Cam Test" << endl;
	cout << "[2] Image Load " << endl;
	cin >> chIputCase;
	cout << "----------------" << endl;
	
	if (chIputCase == '0')
	{
		waitKey();
		return 0;
	}

	else if (chIputCase == '1')
	{
		cam_control cCam;
		cCam.do_cam();
	}

	else if (chIputCase == '2')
	{
		ImageLoad cImage;
		cImage.do_load();
	}

	return 0;
}
