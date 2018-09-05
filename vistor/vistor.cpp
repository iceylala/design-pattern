#include <iostream>
#include <vector>
using namespace std;


class Man;
class Woman;

class Action
{
	public:
		virtual void GetMan(Man* tmp)=0;
		virtual void GetWoman(Woman* tmp)=0;
		virtual ~Action(){}
};

class Success:public Action
{
	public:
		void GetMan(Man* tmp){
			cout<<"Success Man"<<endl;
		}
		void GetWoman(Woman* tmp){
			cout<<"Success Woman"<<endl;
		}
};

class Fail:public Action
{
	public:
		void GetMan(Man* tmp){
			cout<<"Fail Man"<<endl;
		}
		void GetWoman(Woman* tmp){
			cout<<"Fail Woman"<<endl;
		}
};

class Person
{
	public:
		virtual void show(Action* tmp)=0;
		virtual ~Person(){}
};

class Man:public Person
{
	public:
		void show(Action* tmp){
			tmp->GetMan(this);
		}
};

class Woman:public Person
{
	public:
		void show(Action* tmp){
			tmp->GetWoman(this);
		}
};


class Col
{
	private:
		vector<Person* > tmp;
	public:
		void add(Person* tm){
			tmp.push_back(tm);
		}
		void display(Action* tes){
			for(int i=0;i<tmp.size();i++){
				tmp[i]->show(tes);
			}
		}
		~Col(){
			for(int i=0;i<tmp.size();i++){
				delete tmp[i];
			}
		}
};

int main()
{
	Col* tmp = new Col;
	tmp->add(new Man);
	tmp->add(new Woman);
	tmp->add(new Man);
	Action* tmp_1 = new Success;
	Action* tmp_2 = new Fail;
	tmp->display(tmp_1);
	tmp->display(tmp_2);
	delete tmp_1;
	delete tmp_2;
	delete tmp;	
	return 0;
}

