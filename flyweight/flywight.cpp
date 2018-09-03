#include <iostream>
#include <vector>
using namespace std;

class Res
{
	private:
		string name;
	public:
		Res(string name):name(name){}
		string getName(){return name;}
		virtual void show()=0;
		virtual ~Res(){}
};

class OpenRes:public Res
{
	public:
		OpenRes(string name):Res(name){}
		void show(){
			cout<<getName()<<endl;
			cout<<"Open Res"<<endl;
		}
};

class ClosRes:public Res
{
	public:
		ClosRes(string name):Res(name){}
		void show(){
			cout<<getName()<<endl;
			cout<<"Clo Res"<<endl;
		}	
};

class Collector
{
	private:
		vector<Res* > tmp;
	public:
		Res* get(int i){
			if(i >= tmp.size()){
				return NULL;
			}
			else{
				return tmp[i];
			}
		}
		void add(string pre){
			tmp.push_back(new OpenRes(pre));
		}
		~Collector(){
			for(int i=0;i<tmp.size();i++){
				delete tmp[i];
			}
		}
};

int main()
{
	Res* tmp_1 = new ClosRes("Colse");
	tmp_1->show();

	Collector* tmp = new Collector;
	tmp->add("Open_1");
	tmp->add("Open_2");
	tmp->get(0)->show();
	tmp->get(1)->show();

	delete tmp_1;
	delete tmp;
	return 0;
}

