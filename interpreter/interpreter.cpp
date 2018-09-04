#include <iostream>
#include <vector>
using namespace std;


class context
{};

class Base
{
	public:
		virtual void show(context* tmp)=0;
		virtual ~Base(){}
};

class Base_1:public Base
{
	public:
		void show(context* tmp){
			cout<<"Base 1"<<endl;
		}
};

class Base_2:public Base
{
	public:
		void show(context* tmp){
			cout<<"Base 2"<<endl;
		}
};

int main()
{
	vector<Base* > tmp;
	context* tmp_1 = new context;
	
	tmp.push_back(new Base_1);
	tmp.push_back(new Base_2);
	
	for(int i=0;i<tmp.size();i++){
		tmp[i]->show(tmp_1);
	}
	
	delete tmp_1;
	for(int i=0;i<tmp.size();i++){
		delete tmp[i];
	}	
	return 0;
}

