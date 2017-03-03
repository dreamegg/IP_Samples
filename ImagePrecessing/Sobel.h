#pragma once
class Sobel_byMe
{
public:
	Sobel_byMe();
	~Sobel_byMe();

	int do_proc();

private:
	const int mSobelMatrix_x[3][3] = {
		{1,0,1},
		{-2,0,2},
		{-1,0,1}
	};
	const int mSobelMatrix_y[3][3] = {
		{ -1,-2,-1 },
		{ 0,0,0 },
		{ 1,2,1 }
	};

};

