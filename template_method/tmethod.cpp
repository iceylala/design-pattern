#include <iostream>

using namespace std;


class Base
{
	public:
		void show(){
			cout<<"I am here"<<endl;
		}
		virtual void change()=0;
};

class Change1:public Base
{
	public:
		void change(){
			cout<<"It's change1"<<endl;
		}
};

class Change2:public Base
{
	public:
		void change(){
			cout<<"It's change2"<<endl;
		}
};

int main()
{
	Base *tmp = new Change1();
	Base *temp = new Change2();

	tmp->show();
	temp->show();

	tmp->change();
	temp->change();

	delete tmp;
	delete temp;
	return 0;
}

