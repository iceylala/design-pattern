#include <iostream>

using namespace std;


class Coll;

class Metor
{
	public:
		virtual void show(string str, Coll* tmp)=0;
};

class Coll
{
	public:
		Metor* tmp;
		Coll(Metor* tem):tmp(tem){}
		virtual void show()=0;
};


class Coll_1:public Coll
{
	public:
		Coll_1(Metor* tmp):Coll(tmp){}
		void send(string message){
			tmp->show(message,this);
		}
		void show(){
			cout<<"Coll1 show"<<endl;
		}
};

class Coll_2:public Coll
{
	public:
		Coll_2(Metor* tmp):Coll(tmp){}
		void send(string message){
			tmp->show(message,this);
		}
		void show(){
			cout<<"Coll2 show"<<endl;
		}
};

class Inc:public Metor
{
	public:
		Coll* tmp_1;
		Coll* tmp_2;
		void show(string message,Coll* tmp){
			if(tmp == tmp_1){
				tmp_2->show();
			}
			else{
				tmp_1->show();
			}
		}
};

int main()
{
	Inc* tmp = new Inc;
	tmp->tmp_1 = new Coll_1(tmp);
	tmp->tmp_2 = new Coll_2(tmp);

	tmp->show("123",tmp->tmp_1);
	tmp->show("123",tmp->tmp_2);

	delete tmp->tmp_1;
	delete tmp->tmp_2;
	delete tmp;
	return 0;
}


