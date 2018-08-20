#include <iostream>

using namespace std;


class re
{
	private:
		string _state;
	public:
		re(string state):_state(state){}
		string get(){
			return _state;
		}
};

class Base
{
	private:
		string _state;
	public:
		void set(re &tmp){
			_state = tmp.get();
		}
		string back(){
			return _state;
		}
		void set(string &tem){
			_state = tem;
		}
		re* get(){
			return new re(_state);
		}
};

class keep
{
	public:
		re* tmp;
};

int main()
{
	Base s;
	string z("1");
	s.set(z);
	cout<<"s is "<<s.back()<<endl;

	keep a;
	a.tmp = s.get();

	z = "2";
	s.set(z);
	cout<<"s is "<<s.back()<<endl;

	s.set(*a.tmp);
	cout<<"s is "<<s.back()<<endl;
	return 0;
}


