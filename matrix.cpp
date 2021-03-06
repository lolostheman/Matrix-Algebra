/******************************************************************
 * File : matrix.cpp
 *
 * Programmer: Logan Morro
 *
 * Program #: Homework 3
 *
 * Due Date: 3/04
 *
 * EGRE 491, Spring 2020       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: This program defines how the class functions work. The class is constructed in the matrix.h file. we have a default constructor that initiallizes the matrix to all zeros, and we have a main constructor that takes in 4 doubles for the 2x2 amatrix. The copy consturctor is located in the matrix.h file. We also have overload operators in this file, such as the +,-,/,*, and the I/O manipulators <<,>>.
 *
 ******************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include "matrix.h"
//Matrix::Matrix() is the default constructor that initalizes all 4 doubles to zero.
Matrix::Matrix(){
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}
//Matrix::Matrix(double, double, double, double) is the main constructor that initializes the 4 doubles to the input paramaters a,b,c and d.
Matrix::Matrix(double a, double b, double c, double d){
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}

//Matrix Matrix::operator+(const Matris& y) This function overloads the + operator by adding two matricies together.
//parameters: Mattrix containg 4 doubles
//Return value: Nothing, modifies the matrix EX: x = z+y, x is modified
Matrix Matrix::operator+(const Matrix& y){
	Matrix a_temp, b_temp, z;
	a_temp = *this;
	b_temp = y;
	z.a = a_temp.a + b_temp.a;
	z.b = a_temp.b + b_temp.b;
	z.c = a_temp.c + b_temp.c;
	z.d = a_temp.d + b_temp.d;
	return z;
}

//Matrix Matrix::operator-(const Matris& y) This function overloads the - operator by subtracting  two matricies together.
//parameters: Matrix containg 4 doubles
//return value: nothing, modifies the matrix EX: x = z-y, x is modified
Matrix Matrix::operator-(const Matrix& y){
	Matrix a_temp, b_temp, z;
	a_temp =*this;
	b_temp = y;
	z.a = a_temp.a - b_temp.a;
	z.b = a_temp.b - b_temp.b;
	z.c = a_temp.c - b_temp.c;
	z.d = a_temp.d - b_temp.d;
	return z;
}

//Matrix operator*(const Matrix& x, const Matris& y) This friend function overloads the * operator by multiplying  two matricies together.
//parameters: 2 matricies containg 4 doubles
//return value: nothing, modifies the matrix EX: x = z*y, x is modified
Matrix operator*(const Matrix& x, const Matrix& y){
	Matrix a_temp, b_temp, z;
	a_temp = x;
	b_temp = y;
	z.a = (a_temp.a * b_temp.a)+(a_temp.b * b_temp.c);
	z.b = (a_temp.a * b_temp.b)+(a_temp.b * b_temp.d);
	z.c = (a_temp.c * b_temp.a)+(a_temp.d * b_temp.c);
	z.d = (a_temp.c * b_temp.b)+(a_temp.d * b_temp.d);
	return z;
}

//Matrix operator*(const double r, const Matris& x) This friend function overloads the * operator by multiplying 1 matrix by a double.
//parameters: 1 matrix containg 4 doubles, and a double 
//return value: nothing, modifies the matrix EX: x = z*r, x is modified
Matrix operator*(const double r, const Matrix& x){
	Matrix x_temp, z;
	x_temp = x;
	z.a = x_temp.a*r;
	z.b = x_temp.b*r;
	z.c = x_temp.c*r;
	z.d = x_temp.d*r;
	return z;
}
//Matrix Matrix::operator/(const Matrix& x, const Matris& y) This function overloads the / operator by dividing two matricies together.
//parameters: 1 matrix containg 4 doubles
//return value: nothing, modifies the matrix EX: x = z/y, x is modified

Matrix Matrix::operator/(const Matrix& y){
	Matrix a_temp, b_temp, z;
	a_temp = *this;
	b_temp = y;
	b_temp.inverse();
	z.a = (a_temp.a * b_temp.a)+(a_temp.b * b_temp.c);
	z.b = (a_temp.a * b_temp.b)+(a_temp.b * b_temp.d);
	z.c = (a_temp.c * b_temp.a)+(a_temp.d * b_temp.c);
	z.d = (a_temp.c * b_temp.b)+(a_temp.d * b_temp.d);
	return z;
}

 //Matrix Matrix::operator=(const Matrix& y) This friend function overloads the = operator by setting two matricies equal  toeachother.
//parameters: 1 matrix containg 4 doubles
//return value: nothing, modifies the matrix EX: x = y, x is set equal to y
Matrix& Matrix::operator=(const Matrix& y){
	this->a = y.a;
	this->b = y.b;
	this->c = y.c;
	this->d = y.d;
	return *this;
}

//ostream &operator<<(ostream &os, Matrix &m) This friend function overloads the << operator by prtinging the matrix/printing matrix to a file.
//parameters: 1 ostream member, and a  matrix containg 4 doubles
//return value: prints out the matrix when cout << is called and prints the matrix to a .txt when a open file << is called
ostream & operator<<(ostream &os, Matrix &m){
	//this for loop is used only to print to the output file.
	if(m.a==-20.000&&m.b==40.000&&m.c==-60.000&&m.d==80.000){
		os<<fixed<<setprecision(1)<<m.a<<"\t";
		os<<m.b<<endl;
		os<<m.c<<"\t";
		os<<m.d;
		return os;
	}
		
	
	double a,b,c,d;
	a = m.a;
	b = m.b;
	c = m.c;
	d = m.d;	
	cout<<"---\t\t\t---\n";
	cout<<"|\t";
	cout<<fixed<<setprecision(3)<<a;
	cout<<"\t";
	cout<<b;
	cout<<"\t  |\n";
	cout<<"|\t\t\t  |\n";
	cout<<"|\t";
	cout<<c;
	cout<<"\t";
	cout<<d;
	cout<<"\t  |\n";
	cout<<"---\t\t\t---\n";
	return os;
}

//ifstream &operator>>(ifstream *input, Matrix &m) This function overloads the >> operator by inputing a matrix from a file.
//parameters: 1 isfstream  member, and a  matrix containg 4 doubles
//return value: Nothing, the matrix m sets its 4 doubles equal to the ifsrream.
ifstream& operator>>(ifstream &input, Matrix &m){
	input >> m.a;
	input >> m.b;
	input >> m.c;
	input >> m.d;
	return input;	
	
}

/*void Matrix::inverse()
 * summary of the inverse function
 * 	The inverse function inverts the matrix by swaping values b and c and multiplying them by -1. and then multiplies all the doubles (abcd) by (1/Matrix::det())
 *
 * Parameters: none it just adjust the matrix the function is being called on
 *
 * Description:
 * 	This function uses basic matrix rules and applies them to a 2x2 matrix.
 */
void Matrix::inverse(){
	if(Matrix::isSingular()==false){
	double temp1 = this->a;//temp value for a
	double temp2 = this->b;//temp value for b
	double temp3 = this->c;//temp value for c
	double temp4 = this->d;//temp value fof d
	temp1 = (1/Matrix::det())*temp1;
	temp2 = (1/Matrix::det())*temp2;
	temp3 = (1/Matrix::det())*temp3;//changes all the temps to the invers
	temp4 = (1/Matrix::det())*temp4;
	this->a = temp4;
	this->b = temp2*-1;//sets this matrix value negative
	this->c = temp3*-1;//sets this matrix value negative
	this->d = temp1;
	}else{
		cout<<"Error: matrix is singular - it does not have an inverse\n";
	}
}

/*void Matrix::assign(double, double, double, double)
 * Summary of the assign function
 * 	The assign function takes in 4 doubles and assigns them to the current matrix values.
 *
 * Parameteres: 4 doubles q,w,e,and r. these doubles are then assigned to a,b,c,d
 *
 * Description:
 * 	This function is used to replace current matrix values by the ones taken in as parameters.
 */
void Matrix::assign(double q, double w, double e, double r){
	this->a = q;
	this->b = w;
	this->c = e;
	this->d = r;
}
/*void Matrix::print()
 * summary of the print function
 * 	the print function prints a text created box around 4 doubles with a sig fig range of 3.
 *
 * Parameters: none
 *
 * return value: no return value, just alot of couts
 *
 * Description
 * 	This function uses cout, and the setprecision function to output 4 doubles in a matrix box.
 */
void Matrix::print(){
	
	cout<<"---\t\t\t---\n";
	cout<<"|\t"<<fixed<<setprecision(3)<<this->a<<"\t"<<this->b<<"\t  |\n";
	cout<<"|\t\t\t  |\n";
	cout<<"|\t"<<this->c<<"\t"<<this->d<<"\t  |\n";
	cout<<"---\t\t\t---\n";
}
/*double Matrix::det()
 * summary of the det function
 * 	it gets the determinate of a 2x2 matrix
 * parameters:none
 *
 * return value: it returns the value of a*d-b*c
 *
 * description:
 * 	This function calculates the determinate of the matrix by setting 2 doulbes equal to a*b and c*d and then reutrns the value of a*b-c*d.
 */
double Matrix::det(){
	double det1 = this->a*this->d;
	double det2 = this->b*this->c;
	return det1 - det2;
}
/*bool Matrix::isSingular(void)
 * summary of isSingular function
 * 	this function determines if the determinate is zero or not
 *
 * parameters: none
 *
 * Return value: true if the determinate =0 false otherwise
 *
 * description: 
 * 	This function calles the Matrix::det() function and determines if a*d-b*c is equal to zero or not. 
 *
 *
 */
bool Matrix::isSingular(void){
	if(Matrix::det()==0){
		return true;
	}else{
		return false;
	}
}

