#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>

using namespace std;

struct Item {
	string name;
	int iid;
	double value;
	void print(ostream& out) {
		out << name << " " << iid << " " << value << endl;
	}
};

struct sortname {
	bool operator()(Item& a, Item& b) {
		return a.name < b.name;
	}
};

struct sortiid {
	bool operator()(Item& a, Item& b) {
		return a.iid < b.iid;
	}
};

struct sortvaluedec {
	bool operator()(Item& a, Item& b) {
		return a.value > b.value;
	}
};

template<typename T>
void printLi(T& p) {
	for (auto& n : p) {
		cout << n.name << " " << n.iid << " " << n.value << endl;
	}
	cout << endl;
}

int main() {
	
	vector<Item> vi;
	ifstream myFile { "myFile.txt" };
	for (int i = 0; i < 10; i++) {
		string a;
		int b;
		double c;
		myFile >> a >> b >> c;
		vi.push_back({a,b,c});
	}
	
	cout << "original:" << endl;
	printLi(vi); //myFile.txt
	
	sort(vi.begin(), vi.end(), sortname());
	cout << "sort name:" << endl;
	printLi(vi); //sort by name
	
	sort(vi.begin(), vi.end(), sortiid());
	cout << "sort iid: " << endl;
	printLi(vi); //sort by iid
	
	sort(vi.begin(), vi.end(), sortvaluedec());
	cout << "sort value dec:" << endl;
	printLi(vi); // sort by value dec
	
	vi.push_back(Item {"horse shoe", 99, 12.34});
	vi.push_back(Item {"Canon S400", 9988, 499.95});
	cout << "insert:" << endl;
	printLi(vi);
	
	for (int i = 0; i < vi.size(); i++) {
		if (vi[i].name == "horse shoe") {
			vi.erase(vi.begin() + i);
		}
		if (vi[i].name == "Canon S400") {
			vi.erase(vi.begin() + i);
		}
	}
	cout << "remove name:" << endl;
	printLi(vi);
	
	for (int i = 0; i < vi.size(); i++) {
		if (vi[i].iid == 135) {
			vi.erase(vi.begin() + i);
		}
		if (vi[i].iid == 43) {
			vi.erase(vi.begin() + i);
		}
	}
	cout << "remove iid:" << endl;
	printLi(vi);
	
	myFile.close();
	//List
	
	list<Item> li;
	ifstream myFile2("myFile.txt");
	for (int i = 0; i < 10; i++) {
		string a;
		int b;
		double c;
		myFile2 >> a >> b >> c;
		li.push_back({a,b,c});
	}
	cout << "original list:" << endl;
	printLi(li);
	
	li.sort(sortname());
	cout << "sort name list:" << endl;
	printLi(li);
	
	li.sort(sortiid());
	cout << "sort iid list:" << endl;
	printLi(li);
	
	li.sort(sortvaluedec());
	cout << "sort value dec list:" << endl;
	printLi(li);
	
	li.push_back(Item {"horse shoe", 99, 12.34});
	li.push_back(Item {"Canon S400", 9988, 499.95});
	cout << "insert item list:" << endl;
	printLi(li);
	
	for (list<Item>::iterator i = li.begin(); i!=li.end(); i++) {
		if ((*i).name == "horse shoe") {
			i = li.erase(i);
			i--;
		}
		if ((*i).name == "Canon S400") {
			i = li.erase(i);
			i--;
		}
	}
	cout << "remove item list:" << endl;
	printLi(li);
	
	for (list<Item>::iterator i = li.begin(); i!=li.end(); i++) {
		if ((*i).iid == 135) {
			i = li.erase(i);
			i--;
		}
		if ((*i).iid== 43) {
			i = li.erase(i);
			i--;
		}
	}
	cout << "remove iid list:" << endl;
	printLi(li);
	
	return 0;
}
