#include <iostream>
#include <string>
using namespace std;





class CreateBase
{
	public:
		virtual void show() {cout<<"I am Base"<<endl;}
};

class CreateFactory
{
	public:
		CreateFactory() {}
		CreateBase *real_create(string type);
};



class factory1:public CreateBase
{
	public:
		void show() {cout<<"I am factory1"<<endl;}
};

class factory2:public CreateBase
{
	public:
		void show() {cout<<"I am factory2"<<endl;}
};

class factory3:public CreateBase
{
	public:
		void show() {cout<<"I am factory3"<<endl;}
};

CreateBase * CreateFactory::real_create(string type)
{
	if(type == "factory1"){
		return new factory1();
	}
	else if(type == "factory2"){
		return new factory2();
	}else{
		return new factory3();
	}
}

int main()
{
	CreateFactory test;
	CreateBase *tmp = test.real_create("factory1");
	tmp->show();
	delete tmp;
	return 0;
}

