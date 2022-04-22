#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

template<typename T>
void print(vector<T> p) {
	for (auto& n : p) {
		cout << n << endl;
	}
}

int main() {
	
	vector<double> vd;
	ifstream ifile {"myDoubles.txt"};
	for(float f; ifile >> f;) {
		vd.push_back(f);
	}
	cout << "vd elements:" << endl;
	print(vd);
	cout << endl;
	
	//copy vd to vi
	vector<int> vi(16);
	copy(vd.begin(), vd.end(), vi.begin());
	
	double sum = 0;
	double visum = 0;
	
	for (int i = 0; i < 16; i++) {
		
		cout << vd[i] << " " << vi[i] << endl;
		sum += vd[i];
		visum += vi[i];
		
	}
	cout << "sum of vd: " << sum << endl;
	cout << "difference between vd and vi sum: " << sum-visum << endl;
	
	reverse(vd.begin(), vd.end());
	cout << "reversed vd:" << endl;
	print(vd);
	
	//vd mean value:
	double meany = sum/16;
	cout << "mean value of vd: " << meany << endl;
	
	vector<double> vd2;
	for (double i: vd) {
		if (i < meany) {
			vd2.push_back(i);
		}
	}
	cout << "vd2: " << endl;
	print(vd2);
	cout << endl;
	
	cout << "vd sorted again:" << endl;
	sort(vd.begin(), vd.end());
	print(vd);
	
	return 0;
}
