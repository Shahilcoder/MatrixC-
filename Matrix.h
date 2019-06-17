#ifndef _Matrix_h
#define _Matrix_h

#include <iostream>
using namespace std;
#define size 9


//-------------------------------------------------------------------------------------------------------------------------------------------

class Matrix{
private:
	int data[size][size];
	int row, column;
	string order;
	bool MultiplicationPossible;
	bool AdditionPossible;

public:
	Matrix()
	{
		//just a default constructor override
		MultiplicationPossible = true;
		AdditionPossible = true;
	}
	
	//initialize matrix with all data
	//elements 'zero'
	Matrix(int r, int col)
	{
		MultiplicationPossible = true;
		AdditionPossible = true;
		row = r;
		column = col;
		
		for (int i=0; i<row; ++i)
		{
			for (int j=0; j<column; ++j)
				data[i][j] = 0;
		}
	}
	
	//gets order of matrix in string form
	//the asign them to row and column attributes
	void GetOrder()
	{
		cout << "Enter the order of the matrix : ";
		cin>>order;
		
		//converting string to integer
		row = int(order[0]) - 48;
		column = int(order[2]) - 48;
	}
	
	void GetData()
	{
		//getting order
		GetOrder();
		
		cout << "\nEnter the data elements : \n";
		for (int i=0; i<row; ++i)
		{
			for (int j=0; j<column; ++j)
			{
				cout << "Matrix["<<i<<"]["<<j<<"] : ";
				cin >> data[i][j];
			}
		}
	}
	
	void ShowData()
	{
		if(!MultiplicationPossible)
			cout << "\nMatrix Multiplication Not Possible";
		
		else if(!AdditionPossible)
			cout << "\nMatrix Addition/Subtraction Not Possible";
		else
		{
			cout << "\n\nThe matrix is : \n\n";
			for (int i=0; i<row; ++i)
			{
				for (int j=0; j<column; ++j)
					cout << data[i][j] << " ";
				cout << endl;
			}
		}
	}
	
	//Adds two matrices
	Matrix operator +(Matrix m2)
	{
		//creating suitable matrix with required order
		//and initializing all values to zero
		Matrix m3(row, column);
		
		if(row!=m2.row or column!=m2.column)
		{
			m3.AdditionPossible = false;
		}
		else
		{
			for(int i=0; i<row; ++i)
			{
				for(int j=0; j<column; ++j)
					m3.data[i][j] += data[i][j] + m2.data[i][j];
			}
		}
		
		return m3;
		
	}
	
	//Subtracts two matrices
	Matrix operator -(Matrix m2)
	{
		//creating suitable matrix with required order
		//and initializing all values to zero
		Matrix m3(row, column);
		
		if(row!=m2.row or column!=m2.column)
		{
			m3.AdditionPossible = false;
		}
		else
		{
			for(int i=0; i<row; ++i)
			{
				for(int j=0; j<column; ++j)
					m3.data[i][j] += data[i][j] - m2.data[i][j];
			}
		}
		
		return m3;
		
	}
	
	//Multiplies two matrices
	Matrix operator *(Matrix m2)
	{
		//creating suitable matrix with required order
		//and initializing all values to zero
		Matrix m3(row, m2.column);
		
		if(column != m2.row)
		{
			m3.MultiplicationPossible = false;
		}
		else
		{	
			int i, j, k;
			for(i=0; i<row; ++i)
			{
				for(j=0; j<column; ++j)
				{
					//now actually multiplying with this formula
					for(k=0; k<m2.row; ++k)
						m3.data[i][j] += data[i][k]*m2.data[k][j];
				}
			}
		}
		
		return m3;
		
	}
		
	//scalar multiplication
	Matrix operator *(int scalar)
	{
		Matrix m2 = Matrix(row, column);
		
		for(int i=0; i<row; ++i)
		{
			for(int j=0; j<column; ++j)
				m2.data[i][j] = data[i][j]*scalar;
		}
		
		return m2;
	}
	
	//Transposes a matrix
	Matrix Transpose()
	{
		Matrix m2(column, row);
		
		for(int i=0; i<row; ++i)
		{
			for(int j=0; j<column; ++j)
				m2.data[j][i] = data[i][j];
		}
		
		m2.MultiplicationPossible = true;
		m2.AdditionPossible = true;
		
		return m2;
	}
};

//---------------------------------------------------------------------------------------------------------------------------------

#endif
