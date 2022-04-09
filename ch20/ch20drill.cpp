#include <iostream>
#include <algorithm>
#include <array>
#include <vector>
#include <list>

using namespace std;

template<typename T>
void increase(T& inc, int n){
	for(int& a : inc){
		a+=n;
	}
}

template<typename T>
void print(T& p){
	for(int& a : p){
		cout << a << " ";
	}
	cout << endl;
}

template<typename Iter1, typename Iter2>
Iter2 myCopy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p=f1; p!=e1; ++p){
		*f2=*p;
		f2++;
	}
	return f2;
}

int main(){
	
	constexpr int size = 10;
	array <int, 10> arr = {0,1,2,3,4,5,6,7,8,9};
	vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
	list <int> li = {0,1,2,3,4,5,6,7,8,9};

	cout << "Array elements: ";
	print(arr);

	cout << "Vector elements: ";
	print(vec);

	cout << "List elements: ";
	print(li);
	cout << endl;

	array<int, size> arr2 = arr;
	vector<int> vec2 = vec;
	list<int> li2 = li;
/*
	copy(begin(arr), end(arr), begin(arr2));
	copy(vec.begin(), vec.end(), back_inserter(vec2));
	copy(li.begin(), li.end(), back_inserter(li2));
*/
	cout << "Array2 elements: ";
	print(arr2);

	cout << "Vector2 elements: ";
	print(vec2);

	cout << "List2 elements: ";
	print(li2);
	cout << endl;

	increase(arr2, 2);
	increase(vec2, 3);
	increase(li2, 5);

	cout << "Array2(inc): ";
	print(arr2);
	cout << "Vector2(inc): ";
	print(vec2);
	cout << "List2(inc): ";
	print(li2);
	cout << endl;

	cout << "Array2 after copy: ";
	print(arr2);
	cout << "Vector2 after copy: ";
	print(vec2);
	cout << "List2 after copy: ";
	print(li2);
	cout << endl;
	
	myCopy(arr2.begin(), arr2.end(), vec2.begin());
	myCopy(li2.begin(), li2.end(), arr2.begin());

	vector<int>::iterator vit;
	vit = find(vec2.begin(), vec2.end(), 3);
	cout << "Is the vector contain the 3?\n";

	if(vit != vec2.end()){
		cout << "Found at: " << distance(vec2.begin(), vit) << endl << endl;
	}

	else{
		cout<< "Not found" << endl << endl;
	}	
	
	cout << "Is the List contain the 27?\n";
	list<int>::iterator lit;
	lit = find(li2.begin(), li2.end(), 27);
		
	if(lit != li2.end()){
		cout << "Found at: " << distance(li2.begin(), lit) << endl << endl;
	}
	else{
		cout << "Not found" << endl << endl;
	}
	
	return 0;
}
