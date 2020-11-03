#include <iostream>
#include "MyMatrix.h"


int main()
{
	Vector<Vector<int>> V(5);
	TMatrix <int> A(3), M(A), C;
	C = A + M;
	bool k = M == A;
	cout << k << endl;
	A[1][2] = 3;
	cout << A[1][2];
	return 0;
}