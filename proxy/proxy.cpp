#include <iostream>

using namespace std;


class Request
{
	public:
		virtual void show()=0;
		~Request(){}
};

class RealRequest:public Request
{
	public:
		void show(){
			cout<<"Real request"<<endl;
		}
};


class Proxy:public Request
{
	private:
		Request *tmp;
	public:
		Proxy(Request *req):tmp(req){}
		void show(){
			cout<<"Proxy show"<<endl;
			tmp->show();
		} 
};

int main()
{
	RealRequest *tmp = new RealRequest();
	Proxy *tx = new Proxy(tmp);
	tx->show();
	delete tmp;
	delete tx;
	return 0;
}

