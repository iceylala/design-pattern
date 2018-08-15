#include <iostream>

using namespace std;


class Person
{
	public:
		virtual void create_1()=0;
		virtual void create_2()=0;
		virtual void create_3()=0;
};

class Person_1:public Person
{
	public:
		void create_1(){
			cout<<"Create person_11"<<endl;
		}
		void create_2(){
			cout<<"Create person_12"<<endl;
		}
		void create_3(){
			cout<<"Create person_13"<<endl;
		}
};

class Person_2:public Person
{
	public:
		void create_1(){
			cout<<"Create person_21"<<endl;
		}
		void create_2(){
			cout<<"Create person_22"<<endl;
		}
		void create_3(){
			cout<<"Create person_23"<<endl;
		}
};

class Create
{
	private:
		Person *tmp;
	public:
		Create(Person* temp):tmp(temp){}
		void create(){
			tmp->create_1();
			tmp->create_2();
			tmp->create_3();
		}
};

int main()
{
	Person* tmp = new Person_1();
	Create* test = new Create(tmp);
	test->create();

	Person* tm = new Person_2();
	Create* tes = new Create(tm);
	tes->create();

	delete tmp;
	delete test;
	delete tm;
	delete tes;
	return 0;
}



