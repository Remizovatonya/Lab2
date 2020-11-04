#include <iostream>
#include "MyMatrix.h"


int main()
{
	Vector<Vector<int> > V(5);
	TMatrix <int> A(5), M(A), C;
	for (int i = 0; i < A.GetLength(); i++)
		for (int j = A[i].GetStartIndex(); j < A.GetLength(); j++)
			A[i][j] = 2;
	M = A;
	C = A + M;
	cout << C << endl;
	bool k = false;
	k = (M == A);
	cout << k << endl;
	A[0][1] = 3;
	cout << A[0][1];
	return 0;
}