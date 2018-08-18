#include <iostream>

using namespace std;


class Work;

class State
{
	public:
		virtual void change(Work* w)=0;
};
class TwoSite:public State
{
	public:
		void change(Work *w);
};
class Work
{
	private:
		State* sit;
		string element;
	public:
		Work();
		void set(const string &temp){
			element = temp;
		}
		string& get(){
			return element;
		}
		void setState(State* s){
			sit = s;
		}
		void change(){
			sit->change(this);
		}
};



class OneSite:public State
{
	public:
		void change(Work* w){
			if(w->get() == "one"){
				cout<<"it is me one"<<endl;
			}
			else if(w->get() == "two"){
				cout<<"change"<<endl;
				w->setState(new TwoSite());
				w->change();
				delete this;
			}
			else{
				cout<<"No match"<<endl;
			}
		}
};

void TwoSite::change(Work *w){
	if(w->get() == "two"){
		cout<<"it is me two"<<endl;
	}
	else if(w->get() == "one"){
		cout<<"change"<<endl;
		w->setState(new OneSite());
		w->change();
		delete this;
	}
	else{
		cout<<"No match"<<endl;
	}
}

Work::Work(){
	sit = new OneSite();
}

int main()
{
	Work* test = new Work();
	test->set("one");
	test->change();

	test->set("two");
	test->change();

	delete test;
	return 0;
}

