#include "utils.h"
#include <iostream>
using namespace std;


utils::utils()
{
}


utils::~utils()
{
}


#if 0
void utils::MuxMatrix(int a[][], int b[][], int out[][], int size)
{
	int k, j, i;
	int MTM = 0;
	int m1, m2, m3;
	m1 = m2 = m3 = 0;

	m1 = (int)(b[0]);
	cout << "[" << m1 << m2 << m3 << "]" << endl;

	/*for (i = 0; i<size; i++) { // i는 R[][]의 행 M[][]의 행을 나타낸다.
		for (k = 0; k<size; k++) { // j는 { R[][]의 열 T[][]의 열을 나타낸다.
			for (j = 0; j<size; j++) { // k는 M[][]의 열과 T[][]의 행을 나타낸다
				MTM = MTM + (M[i][j] * T[k][j]); //M[][]의 열과 T[][]의 행의 곱을 MTM변수에 저장
			}
			out[i][k] = MTM;
			MTM = 0;
			printf("%5d", R[i][k]);
		}
		*/
}
#endif
