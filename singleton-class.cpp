// singleton class implementation

#include <iostream>
#include <cstdio>
using namespace std;

class Singleton {
public:	
	static Singleton getInstance(int data) {
		static Singleton instance = Singleton(data);
		return instance;
	}
	void printInstance() {
		cout<<"value: "<<data<<endl;
		return;
	}
private:
	int data;
	Singleton(int data) {
		this->data = data;
	};
};

int main() {
	Singleton ptr = Singleton::getInstance(8);
	Singleton ptr2 = Singleton::getInstance(7);

	ptr.printInstance();
	ptr2.printInstance();
	cout<<endl;
	return 0;
}