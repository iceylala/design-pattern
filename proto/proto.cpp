#include <iostream>

using namespace std;


class proto
{
	public:
		~proto(){}
		virtual void show()=0;
		virtual proto* clone()=0;
};

class proto1:public proto
{
	public:
		void show(){
			cout<<"proto1 clone"<<endl;
		}
		proto* clone(){
			proto *p = new proto1();
			*p = *this;
			return p;
		}
};

class proto2:public proto
{
	public:
		void show(){
			cout<<"proto2 clone"<<endl;
		}
		proto* clone(){
			proto *p = new proto2();
			*p = *this;
			return p;
		}
};

int main()
{
	proto* tmp1 = new proto1();
	proto* tmp_1 = tmp1->clone();
	tmp1->show();
	tmp_1->show();
	
	proto* tmp2 = new proto2();
	proto* tmp_2 = tmp2->clone();
	tmp2->show();
	tmp_2->show();

	delete tmp_1;
	delete tmp1;
	
	delete tmp_2;
	delete tmp2;	
	return 1;
}

