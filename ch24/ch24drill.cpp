#include <iostream>
#include <cmath>
#include <complex>
#include <climits>
#include <vector>
#include "Matrix.h"
#include "MatrixIO.h"

using namespace std;
using namespace Numeric_lib;

int main() {
	
	cout << "size of char: " << sizeof(char) << endl;
	cout << "size of short: " << sizeof(short) << endl;
	cout << "size of int: " << sizeof(int) << endl;
	cout << "size of long: " << sizeof(long) << endl;
	cout << "size of float: " << sizeof(float) << endl;
	cout << "size of double: " << sizeof(double) << endl;
	cout << "size of int*: " << sizeof(int*) << endl;
	cout << "size of double*: " << sizeof(double*) << endl;
	cout << endl;
	
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int,2> d(10,10);
	Matrix<int,3> e(10,10,10);
	
	cout << "Matrix int 10: " << sizeof(a) << endl;
	cout << "Matrix int 100: " << sizeof(b) << endl;
	cout << "Matrix double 10: " << sizeof(c) << endl;
	cout << "Matrix int 10x10: " << sizeof(d) << endl;
	cout << "Matrix int 10x10x10: " << sizeof(e) << endl;
	cout << endl;
	
	cout << "num of elements int 10: " << a.size() << endl;
	cout << "num of elements int 100: " << b.size() << endl;
	cout << "num of elements double 10: " << c.size() << endl;
	cout << "num of elements int 10x10: " << d.size() << endl;
	cout << "num of elements int 10x10x10: " << e.size() << endl;
/*
	vector<int> vi;
	int n;
	cout << "integer input: ";
	
	while (cin >> n) {
		cout << "integer input: ";
		vi.push_back(n);
	}
	
	for (int i = 0; i < vi.size(); i++) {
		if (vi[i] < 0) {
			cout << "no square root" << endl;
		}
		else {
			cout << "square root of " << vi[i] << " is " << sqrt(vi[i]) << endl; 
		}
	}
*/	
	vector<double> vd;
	for (int i = 0; i < 10; i++) {
		
		double num;
		cout << "floating number: ";
		cin >> num;
		vd.push_back(num);
		
	}
	
	Matrix<double> m5(10);
	cout << "the matrix: ";
	for (int i = 0; i < 10; i++) {
		
		m5[i] = vd[i];
		cout << m5[i] << endl;
	}
	
	int n;
	int m;
	cout << "n: ";
	cin >> n;
	cout << "m: ";
	cin >> m;
	Matrix<int,2> m6(n,m);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			m6[i][j] = (i+1)*(j+1);
			cout << m6[i][j] << "  ";
		}
		cout << endl;
	}
	
	Matrix<complex<double>> com(10);
	complex<double> sum;
	for (int i = 0; i < 10; i++) {
		
		cout << "complex number: ";
		cin >> com[i];
		sum += com[i];
	}
	cout << "sum of complex<double>: " << sum << endl;
	
	Matrix<int,2> m8(2,3);
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "m8 matrix: ";
			cin >> m8[i][j];
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			cout << m8[i][j] << "  ";
		}
		cout << endl;
	}
	
	return 0;
}
