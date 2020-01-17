/******************************************************************
  File: matrix.h
 
 * Program #: Homework #3
 *
 * Programmer: Logan Morro
 *
 * Due Date: 3/04
 *
 * EGRE 491, Spring 2020       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: this is the .h file for the matrix program. This file initializes mulitpe constructors and a desructor. The matrix functions are defined here. The private values are 4 doubles a,b,c,and d, these doubles are the 4 entries for the 2x2 matrix.
 *
 ******************************************************************/
#include <iostream>
using namespace std;
class Matrix
{
public:

	Matrix();	//default constructor
	Matrix(double a, double b, double c, double d);	//main constructor
	Matrix(const Matrix &copy){
		a = copy.a;
		b = copy.b;
		c = copy.c;
		d = copy.d;
	}

	Matrix& operator=(const Matrix& m);
	Matrix operator+(const Matrix& y);
	Matrix operator-(const Matrix& y);
	friend Matrix operator*(const double r, const Matrix& x);
	friend Matrix operator*(const Matrix& x, const Matrix& y);
	Matrix operator/(const Matrix& y);

	friend ostream& operator<<(ostream &os, Matrix& m);
	friend ifstream& operator>>(ifstream &input, Matrix& m);
//	friend ostream& operator>>(istream &os, const Matrix& m);



//	~Matrix();	//destructor
	void inverse();
//	void inverseconst()const;
	bool isSingular(void);
	void assign(double, double, double, double);
	void print(void);
	double det(void);
private: 
	double a, b, c, d;

};

