/******************************************************************
 * File : matrix.cpp
 *
 * Programmer: Logan Morro
 *
 * Program #: Homework 2
 *
 * Due Date: 2/17
 *
 * EGRE 491, Spring 2020       Instructor: Robert Klenke
 *
 * Pledge: I have neither given nor received unauthorized aid on this program.
 *
 * Description: This program defines how the class functions work. The class is constructed in the matrix.h file. we have a default constructor that initiallizes the matrix to all zeros, and we have a main constructor that takes in 4 doubles for the 2x2 amatrix. The copy consturctor is located in the matrix.h file.
 *
 ******************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
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


/*void Matrix::inverse()
 * summary of the inverse function
 * 	The inverse function inverts the matrix by swaping values b and c and multiplying them by -1. and then multiplies all the doubles (abcd) by (1/Matrix::det())
 *
 * Parameters: none it just adjust the matrix the function is being called on
 *
 * Description:
 * 	This function uses basic matrix rules and applies them to a 2x2 matrix.
 */

Matrix Matrix::operator+(const Matrix& y){
	Matrix a_temp, b_temp, c;
	a_temp = *this;
	b_temp = y;
	z.a = a_temp.a + b_temp.a;
	z.b = a_temp.b + b_temp.b;
	z.c = a_temp.c + b_temp.c;
	z.d =  a_temp.d + b_temp.d;
	return c;
}

Matrix Matrix::operator-(const Matrix& y){
	Matrix a_temp, b_temp, c;
	a_temp = *this;
	b_temp = y;
	z.a = a_temp.a - b_temp.a;
	z.b = a_temp.b - b_temp.b;
	z.c = a_temp.c - b_temp.c;
	z.d = a_temp.d - b_temp.d;
	return c;
}


void Matrix::inverse(){
	if(Matrix::isSingular()==false){
	double temp1 = this->a;//temp value for a
	double temp2 = this->b;//temp value for b
	double temp3 = this->c;//temp value for c
	double temp4 = this->d;//temp value fof d
	temp1 = (1/Matrix::det())*temp1;
	temp2 = (1/Matrix::det())*temp2;
	temp3 = (1/Matrix::det())*temp3;//changes all the temps to the inverse
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

