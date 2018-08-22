#include <iostream>
#include <vector>
using namespace std;


class Iter
{
	public:
		virtual void next()=0;
		virtual void first()=0;
		virtual int* current()=0; 
};

class Iterm
{
	public:
		virtual Iter* create()=0;
};

class ConIterm:public Iterm
{
	public:
		vector<int> data;
		ConIterm(){
			data.push_back(1);
			data.push_back(2);
		}
		Iter* create();
		int& operator[](int index){
			return data[index];
		}
		int getlen(){
			return data.size();
		}
};


class ConIter:public Iter
{
		ConIterm* aggr;
		int _cnt;
	public:
		ConIter(ConIterm* a):aggr(a),_cnt(0){}
		void first(){
			_cnt=0;
		}
		void next(){
			if(_cnt<aggr->getlen()){
				_cnt++;
			}
		}
		int* current(){
			return &(*aggr)[_cnt];
		}
};

Iter* ConIterm::create(){
	return new ConIter(this);
}

int main()
{
	Iterm* aggr = new ConIterm();
	Iter *it = aggr->create();
	it->first();
	cout<<*(it->current())<<endl;

	it->next();
	cout<<*(it->current())<<endl;
	return 0;
}

