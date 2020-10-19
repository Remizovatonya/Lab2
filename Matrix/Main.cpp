#include <iostream>
#include "Matrix.h"
#include "MyVector.h"

int main()
{
	Vector <int> a(3, 3);
	TMatrix <int> A(3);
	TMatrix <int> B = A;
	TMatrix <int> C(3);
	A + B;
	return 0;

}