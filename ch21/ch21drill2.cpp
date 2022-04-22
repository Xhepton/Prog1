#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

template<typename T, typename C>
void printMap(map<T, C>& p) {
	for(auto& n : p) {
		cout << n.first << " " << n.second << endl;
	}
}

template<typename T, typename C>
void readMap(map<T, C>& p, int n) {
	T key;
	C value;
	for (int i = 0; i < n; i++)
	{
		cout << "pair: ";
		cin >> key >> value;
		p.insert(pair<T, C>(key, value));
	}
}


int main() {
	map<string, int> msi;
	
	msi["cabin"] = 11;
	msi["tree"] = 23;
	msi["island"] = 31;
	msi["glass"] = 42;
	msi["ground"] = 58;
	msi["place"] = 69;
	msi["none"] = 75;
	msi["bones"] = 88;
	msi["hills"] = 93;
	msi["tester"] = 100;
	
	printMap(msi);
	
	msi.clear();
	printMap(msi);
	
	readMap(msi, 1);
	cout << "element in msi after cin:" << endl;
	printMap(msi);
	
	readMap(msi, 10);
	cout << "elements in msi after cin:" << endl;
	printMap(msi);
	
	int sum = 0;
	for(auto& n : msi) {
		sum += n.second;
	}
	
	map<int, string> mis;
	for(auto& n : msi) {
		mis.insert(pair<int, string>(n.second, n.first));
	}
	cout << "mis map:" << endl;
	printMap(mis);
	
	return 0;
}
