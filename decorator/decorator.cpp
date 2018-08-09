#include <iostream>

using namespace std;


class Person
{
	private:
		string _name;
	public:
		Person(string name):_name(name){}
		Person(){}
		virtual void show(){
			cout<<_name<<endl;
		}
};


class Decorator:public Person
{
	protected:
		Person *humman;
	public:
		void createDecorator(Person *tmp){humman = tmp;}
		virtual void show(){
			humman->show();
			cout<<"No decorator"<<endl;
		}
};

class Tshirt:public Decorator
{
	public:
		void show(){
			humman->show();
			cout<<"Tshirt decorator"<<endl;
		}
};


class Britch:public Decorator
{
	public:
		void show(){
			humman->show();
			cout<<"Herebrith decorator"<<endl;
		}
};

int main()
{
	Person *any = new Person("any");
   	Tshirt *ts = new Tshirt();
	Britch *br = new Britch();
	ts->createDecorator(any);	
	br->createDecorator(ts);
	br->show();
	delete any;
	delete ts;
	delete br;
	return 0;
}

