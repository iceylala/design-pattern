#include <iostream>
#include <vector>
using namespace std;


class Base
{
	public:
		virtual void add(Base* tmp)=0;
		virtual void notify()=0;
};

class BaseOne:public Base
{
	public:
		void add(Base* tmp){
			cout<<"Noneed add"<<endl;
		}
		void notify(){
			cout<<"Hello BaseOne"<<endl;
		}
};

class Component:public Base
{
	private:
		vector<Base* > tmp;
	public:
		void add(Base* tem){
			tmp.push_back(tem);
		}
		void notify(){
			for(int i=0;i<tmp.size();++i){
				tmp[i]->notify();
			}
		}
		~Component(){
			for(int i=0;i<tmp.size();++i){
				delete tmp[i];
			}
		}
};

int main()
{
	Base* temp_1 = new BaseOne();
	Component temp;

	temp.add(temp_1);
	temp.notify();

	Base* temp_2 = new BaseOne();
	temp.add(temp_2);
	temp.notify();
	return 0;
}

