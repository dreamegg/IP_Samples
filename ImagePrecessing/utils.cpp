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

	/*for (i = 0; i<size; i++) { // i�� R[][]�� �� M[][]�� ���� ��Ÿ����.
		for (k = 0; k<size; k++) { // j�� { R[][]�� �� T[][]�� ���� ��Ÿ����.
			for (j = 0; j<size; j++) { // k�� M[][]�� ���� T[][]�� ���� ��Ÿ����
				MTM = MTM + (M[i][j] * T[k][j]); //M[][]�� ���� T[][]�� ���� ���� MTM������ ����
			}
			out[i][k] = MTM;
			MTM = 0;
			printf("%5d", R[i][k]);
		}
		*/
}
#endif
