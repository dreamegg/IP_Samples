#include <iostream>  
using namespace std;

#include "cam_control.h"
#include "ImageLoad.h"
#include "Sobel.h"

int main(int, char**)
{
	char chIputCase;

	cout << "----------------" << endl;
	cout << "[0] Exit" << endl;
	cout << "[1] Web Cam Test" << endl;
	cout << "[2] Image Load " << endl;
	cout << "[3] Sobel " << endl;
	cout << "Input =>";
	cin >> chIputCase;
	cout << "----------------" << endl;
	
	if (chIputCase == '0'){
		waitKey();
		return 0;
	}
	else if (chIputCase == '1'){
		cam_control cCam;
		cCam.do_cam();
	}

	else if (chIputCase == '2'){
		ImageLoad cImage;
		cImage.do_load();
	}
	else if (chIputCase == '3') {
		Filter_action cSobel;
		cSobel.do_proc();
	}
	return 0;
}
