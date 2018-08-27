#include <iostream>

using namespace std;


class Request
{
	public:
		int _num;
};

class Base
{
	public:
		Base* _tmp;
	public:
		void set(Base* tmp){
			_tmp = tmp;
		}
		virtual void request(Request* req)=0;
};

class Upper:public Base
{
	public:
		void request(Request* req){
			if(req->_num < 10){
				cout<<"Upper said"<<endl;
			}
			else{
				_tmp->request(req);
			}			
		}
};

class Unner:public Base
{
	public:
		void request(Request* req){
			cout<<"Unner said"<<endl;
		}
};

int main()
{
	Request* req = new Request;
	Base* bre = new Upper;
	
	req->_num = 3;	
	bre->_tmp = new Unner;

	bre->request(req);

	req->_num = 10;
	bre->request(req);

	delete req;
	delete bre->_tmp;
	delete bre;
	return 0;
}


