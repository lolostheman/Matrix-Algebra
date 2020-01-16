/******************************************************************
 * Program #: Homework #2
 *
 * Programmer: Logan Morro
 *
 * Due Date: 2/17
 *
 * EGRE 491, Spring 2020       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: Program to demonstrate makefiles
 *
 * Input: NA
 *
 * Output: print statements showing the results.
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

//	~Matrix();	//destructor
	void inverse();
	bool isSingular(void);
	void assign(double, double, double, double);
	void print(void);
	double det(void);
private: 
	double a, b, c, d;

};

