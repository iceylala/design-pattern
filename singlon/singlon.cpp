#include <iostream>

using namespace std;


class Single
{
	private:
		static Single* tmp;
		Single(){}
	public:
		static Single* get(){
			if(NULL == tmp){
					Single::tmp = new Single();
			}
			return Single::tmp;
		}
};

Single* Single::tmp = NULL;

int main()
{
	Single* s1 = Single::get();
	Single* s2 = Single::get();

	if(s1 == s1){
		cout<<"same"<<endl;
	}
	else{
		cout<<"doesnot"<<endl;
	}
	return 0;
}



