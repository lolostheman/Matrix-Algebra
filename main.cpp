#include <iostream>
#include <fstream>
#include "matrix.h"


int main(int argc, char *argv[])
{
	ifstream infile;
	ofstream outfile;
	string prog_name;
	string infile_name;
	string outfile_name;

	Matrix w;
	Matrix x;
	Matrix y(1.0, 2.0, 3.0, 4.0);
	Matrix z(x);

  prog_name = argv[0];

 if(argc < 3) {
    cout << "\nERROR, missing input and output file names!\n";
  cout << "Usage: " <<prog_name << "  <input file name> <output file name>\n";
    return(-1);
  }

  if(argc > 3) {
    cout << "\nERROR, too many arguments!\n";
  cout << "Usage: " <<prog_name << "  <input file name> <output file name>\n";
    return(-1);
  }
 
  infile_name = argv[1];
  outfile_name = argv[2];
 
  if(infile_name == "--help" || outfile_name == "--help") {
  cout << "\nProgram to read a list of integer numbers from a file\n";
  cout << "Usage: " <<prog_name << "  <input file name> <output file name>\n";
  return(-1);

  }
  
  infile.open(infile_name, fstream::in);
  if(!infile.is_open()) {
    cout << "\nERROR Could not open input file " << infile_name << "!\n";
  cout << "Usage: " <<prog_name << "  <input file name> <output file name>\n";
    return(-1);
  }

  outfile.open(outfile_name, fstream::out);
  if(!outfile.is_open()) {
    cout << "\nERROR Could not open output file " << outfile_name << "!\n";
  cout << "Usage: " <<prog_name << "  <input file name> <output file name>\n";
    return(-1);
  }


	cout << "\nx matrix is: \n";
	cout << x;
	cout << "\ny matrix is: \n";
	cout << y;

	x = y;

	cout << "\nx = y\n";
	cout << "x matrix now is: \n";
	cout << x;

	x.assign(1.0, 2.0, 8.0, 7.0);
	y.assign(5.0, 4.0, 4.0, 5.0);

	z = x + y;

	cout << "\nx matrix is: \n";
	cout << x;
	cout << "\ny matrix is: \n";
	cout << y;
	cout << "\nz = x + y matrix is: \n";
	cout << z;

	x = z - y;

	cout << "\nz matrix is: \n";
	cout << z;
	cout << "\ny matrix is: \n";
	cout << y;
	cout << "\nx = z - y matrix is: \n";
	cout << x;

	x.assign(30.0, 50.0, 25.0, 40.0);
	y.assign(2.0, 3.0, 1.0, 1.0);

	z = x * y;

	cout << "\nx matrix is: \n";
	cout << x;
	cout << "\ny matrix is: \n";
	cout << y;
	cout << "\nz = x * y matrix is: \n";
	cout << z;

	x.assign(0.0, 0.0, 0.0, 0.0);
	x = z / y;

	cout << "\nz matrix is: \n";
	cout << z;
	cout << "\ny matrix is: \n";
	cout << y;
	cout << "\nx = z / y matrix is: \n";
	cout << x;

	double r = 2.0;

	x = r * y;

	cout << "\ny matrix is: \n";
	cout << y;
	cout << "\nx = 2.0 * y matrix is: \n";
	cout << x;
	
	infile >> w;
	cout << "\nRead w matrix from << argv[1] " << "\n";
	cout << "w matrix is: \n";
	cout << w;

	w = r * w;
	
	outfile << w;
	
	infile.close();
}		/* end main */