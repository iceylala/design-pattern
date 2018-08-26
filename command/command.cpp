#include <iostream>
#include <vector>
using namespace std;


class Cooker
{
	public:
		void chineseCooker(){
			cout<<"Chinese cook"<<endl;
		}
		void westernCook(){
			cout<<"Western cook"<<endl;
		}
};

class Command
{
	public:
		Cooker* _tmp;
	public:
		Command(Cooker* tmp):_tmp(tmp){}
		virtual void cook()=0;
};

class CcookCom:public Command
{
	public:
		CcookCom(Cooker* tmp):Command(tmp){}
		void cook(){
			_tmp->chineseCooker();
		}
};

class WcookCom:public Command
{
	public:
		WcookCom(Cooker* tmp):Command(tmp){}
		void cook(){
			_tmp->westernCook();
		}
};

class Waiter
{
	private:
		vector<Command* > _tmp;
	public:
		void add(Command* tmp){
			_tmp.push_back(tmp);
		}
		void notify(){
			for(vector<Command* >::iterator it=_tmp.begin();it!=_tmp.end();it++){
				(*it)->cook();
			}
		}
};

int main()
{
	Waiter* w_tmp = new Waiter;
	Cooker* c_tmp = new Cooker;
	
	Command* cc_tmp = new CcookCom(c_tmp);
	w_tmp->add(cc_tmp);

	Command* wc_tmp = new WcookCom(c_tmp);
	w_tmp->add(wc_tmp);

	w_tmp->notify();

	delete c_tmp;

	delete cc_tmp;
	delete wc_tmp;


	delete w_tmp;

	return 0;
}

