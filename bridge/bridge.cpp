#include <iostream>

using namespace std;


class Soft
{
	public:
		virtual void run()=0;
};

class Phone
{
	public:
		virtual void run()=0;
		virtual void setPhone(Soft* tmp)=0;
};

class Game:public Soft
{
	public:
		void run(){
			cout<<"Game run"<<endl;
		}
};

class List:public Soft
{
	public:
		void run(){
			cout<<"List run"<<endl;
		}
};

class Iphone:public Phone
{
	private:
		Soft* _tmp;
	public:
		void setPhone(Soft* tmp){
			_tmp = tmp;
		}
		void run(){
			_tmp->run();
		}	
};

class Ophone:public Phone
{
	private:
		Soft* _tmp;
	public:
		void setPhone(Soft* tmp){
			_tmp = tmp;
		}
		void run(){
			_tmp->run();
		}
};

int main()
{
	Game* g_tmp = new Game();
	List* l_tmp = new List();
	
	Iphone* ip_tmpf = new Iphone;
	ip_tmpf->setPhone(g_tmp);
	ip_tmpf->run();
	
	ip_tmpf->setPhone(l_tmp);
	ip_tmpf->run();

	Ophone* ip_tmps = new Ophone;
	ip_tmps->setPhone(g_tmp);
	ip_tmps->run();

	ip_tmps->setPhone(l_tmp);
	ip_tmps->run();

	delete g_tmp;
	delete l_tmp;
	
	delete ip_tmpf;
	delete ip_tmps;

	return 0;
}

