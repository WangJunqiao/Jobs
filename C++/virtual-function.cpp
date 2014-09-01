#include <iostream>
#include <cstdio>

using namespace std;

class A {
public:
	virtual void sss() {
		printf("a sss\n");
	}
	void ttt() {
		printf("a ttt\n");
	}
};

class B : public A {
public:
	virtual void sss() {
		printf("b sss\n");
	}
	void ttt() {
		printf("b ttt\n");
	}
};

int main() {
	A *b = new B();
	b->sss();
	b->ttt();
}

/*
output:
b sss
a ttt

 * */
