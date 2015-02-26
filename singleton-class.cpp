// singleton class implementation in C++

#include <iostream>
#include <cstdio>
using namespace std;

class Singleton {
private:
	int data;
	static Singleton* ptr;
	// private constructor
	Singleton(int data) {
		this->data = data;
	}     				
public:	
	static Singleton* getInstance(int data);
	void printInstance();	
};

Singleton* Singleton::ptr = NULL;
Singleton* Singleton::getInstance(int data) {
	if (!ptr)
		ptr = new Singleton(data);
	return ptr;
}
void Singleton::printInstance() {
	cout<<"value: "<<data<<endl;
	return;
}

int main() {
	Singleton* s1 = Singleton::getInstance(1);
	// to check wether new instance with value 2 gets instantiated
	Singleton* s2 = Singleton::getInstance(2);

	s1->printInstance();
	s2->printInstance();
	cout<<endl;
	return 0;
}