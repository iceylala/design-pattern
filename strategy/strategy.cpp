#include <iostream>

using namespace std;


class Strategy
{
	public:
		virtual void show()=0;
};

class CreateStrategy
{
	private:
		Strategy *op;
	public:
		CreateStrategy(Strategy *tmp):op(tmp){}
		~CreateStrategy(){
			delete op;
		}
	void show(){
		op->show();
	}
};


class StrategyFirst:public Strategy
{
	public:
		void show(){
			cout<<"This is first strategy"<<endl;
		}
};

class StrategySecond:public Strategy
{
	public:
		void show(){
			cout<<"This is second strategy"<<endl;
		}
};

class StrategyThird:public Strategy
{
	public:
		void show(){
			cout<<"This is third strategy"<<endl;
		}
};

int main()
{
	CreateStrategy tmp(new StrategyFirst);
	tmp.show();
	return 0;
}

