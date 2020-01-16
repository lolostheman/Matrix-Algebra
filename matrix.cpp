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
#include <string>
#include "matrix.h"

Matrix::Matrix(){
	this->a = 0;
	this->b = 0;
	this->c = 0;
	this->d = 0;
}
Matrix::Matrix(double a, double b, double c, double d){
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}



void Matrix::inverse(){
	if(Matrix::isSingular()==false){
	double temp1 = this->a;
	double temp2 = this->b;
	double temp3 = this->c;
	double temp4 = this->d;
	temp1 = (1/Matrix::det())*temp1;
	temp2 = (1/Matrix::det())*temp2;
	temp3 = (1/Matrix::det())*temp3;
	temp4 = (1/Matrix::det())*temp4;
	this->a = temp4;
	this->b = temp2*-1;
	this->c = temp3*-1;
	this->d = temp1;
	}else{
		cout<<"Error: matrix is singular - it does not have an inverse\n";
	}
}
void Matrix::assign(double q, double w, double e, double r){
	this->a = q;
	this->b = w;
	this->c = e;
	this->d = r;
}
void Matrix::print(){
	cout<<"---\t\t\t---\n";
	cout<<"|\t"<<this->a<<"\t"<<this->b<<"\t  |\n";
	cout<<"|\t\t\t  |\n";
	cout<<"|\t"<<this->c<<"\t"<<this->d<<"\t  |\n";
	cout<<"---\t\t\t---\n";
}
double Matrix::det(){
	double det1 = this->a*this->d;
	double det2 = this->b*this->c;
	return det1 - det2;
}
bool Matrix::isSingular(void){
	if(Matrix::det()==0){
		return true;
	}else{
		return false;
	}
}

