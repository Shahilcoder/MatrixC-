//test_matrix_h
#include <Matrix.h>
using namespace std;

int main()
{
	Matrix m1;
	m1.GetData();
	
	Matrix m2;
	m2.GetData();
	
	Matrix m3;
	m3 = m1*m2;
	
	m3.ShowData();
	
	return 0;
	
}
