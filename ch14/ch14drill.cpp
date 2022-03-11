#include <iostream>
#include <string>
using namespace std;

// abstarct class
class B1abs {
public:
	virtual void pvf() = 0;
};

class B1 : public B1abs {
public:
	virtual void vf() {
		cout << "B1::vf()" << endl;
	}
public:
	void f() {
		cout << "B1::f()" << endl;
	}
public:
	void pvf() {
		cout << "B1::pvf()" << endl;
	}
};
class D1 : public B1 {
public:
	virtual void vf() {
		cout << "D1::vf()" << endl;
	}
	void f() {
		cout << "D1::f()" << endl;
	}
};
class D2 : public D1{
public:
	void pvf() override {
		cout << "D2::pvf()" << endl;
	}
};
class B2abs {
	virtual void pvf() = 0;
};
class B2 : public B2abs {
public:
	void pvf() {
		cout << "B2::pvf()" << endl;
	}
};
class D21 : public B2 {
	string str = "data member";
public:
	void pvf() override {
		cout << str << endl;
	}
};
class D22 : public B2 {
	int answer = 42;
public:
	void pvf() override {
		cout << answer << endl;
	}
};
void f(B2& func) {
	func.pvf();
}

int main() {
	//1.
	B1 b1object;
	b1object.vf();
	b1object.f();
	cout << endl;

	//2.
	D1 d1object;
	d1object.vf();
	d1object.f();
	cout << endl;

	//3.
	B1& b1ref = d1object;
	b1ref.vf();
	b1ref.f();
	cout << endl;

	//6.
	D2 d2object;
	d2object.f();
	d2object.vf();
	d2object.pvf();
	cout << endl;

	//7.
	D21 d21object;
	d21object.pvf();

	D22 d22object;
	d22object.pvf();

	f(d21object);
	f(d22object);
}