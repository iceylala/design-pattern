#include <iostream>
#include <vector>
using namespace std;


class Base
{
	public:
		virtual void say()=0;
};

class Stocker:public Base
{
	public:
		void say(){
			cout<<"Stocker say"<<endl;
		}
};

class Swimmer:public Base
{
	public:
		void say(){
			cout<<"Swimmer Say"<<endl;
		}
};

class Notify
{
	private:
		vector<Base* > tmp;
	public:
		void add(Base* temp){
			tmp.push_back(temp);
		}
		void say(){
			for(vector<Base* >::iterator it=tmp.begin();it!=tmp.end();it++){
				(*it)->say();
			}
		}
};

int main()
{
	Base* tmpfirst = new Stocker();
	Base* tmpsecond = new Swimmer();
	Notify* tmp = new Notify();

	tmp->add(tmpfirst);
	tmp->add(tmpsecond);

	tmp->say();

	delete tmpfirst;
	delete tmpsecond;
	delete tmp;
	return 0;
}

