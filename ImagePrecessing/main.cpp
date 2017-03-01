#include <iostream>  
using namespace std;

#include "cam_control.h"

int main(int, char**)
{
	char cIputCase[5];
	cout << "----------------" << endl;
	cout << "[0] Exit" << endl;
	cout << "[1] Web Cam Test" << endl;
	cin >> cIputCase;
	cout << "----------------" << endl;
	
	if (strcmp(cIputCase, "0"))
	{
		return 0;
	}
	else if (strcmp(cIputCase, "1"))
	{
		cam_control cCam;
		cCam.do_cam();
	}

	return 0;
}
