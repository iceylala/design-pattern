#include <iostream>

using namespace std;


class One
{
	public:
		void show(){
			cout<<"I am one"<<endl;
		}
};

class Two
{
	public:
		void show(){
			cout<<"I am two"<<endl;
		}
};

class Three
{
	public:
		void show(){
			cout<<"I am thress"<<endl;
		}
};

class Fade
{
	private:
		One* one;
		Two* two;
		Three* three;
	public:
		Fade(){
			one = new One();
			two = new Two();
			three = new Three();
		}
		~Fade(){
			delete one;
			delete two;
			delete three;
		}
		show(){
			one->show();
			two->show();
			three->show();
		}
};

int main()
{
	Fade* fade = new Fade();
	fade->show();
	delete fade;
	return 0;
}

