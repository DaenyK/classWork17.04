#include "Header.h"

int main()
{
	Vector v1(10);

	//v1.push_back(15);
	v1.push_insertAt(2, 22);
	v1.at(3) = 5;
	v1.print();

	system("pause");
	return 0;
}