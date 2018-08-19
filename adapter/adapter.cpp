#include <iostream>

using namespace std;


class Base
{
	public:
		virtual void show(){
			cout<<"Base show"<<endl;
		}
};

class Other
{
	public:
		void show(){
			cout<<"Other show"<<endl;
		}
};

class Here:public Base
{
	private:
		Other* tmp;
	public:
		Here(){
			tmp = new Other();
		}
		void show(){
			Base::show();
			tmp->show();
		}
		~Here(){
			delete tmp;
		}
};

int main()
{
	Here* temp = new Here();
	temp->show();
	delete temp;
	return 0;
}



