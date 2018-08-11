#include <iostream>

using namespace std;


class Set
{
	public:
		virtual void show()=0;
		~Set(){}
};

class Shoes:public Set
{
	public:
		void show(){
			cout<<"Shoes show"<<endl;
		}
};

class Clothes:public Set
{
	public:
		void show(){
			cout<<"Clothes show"<<endl;
		}
};

class BaseCreate
{
	public:
		virtual Set* setCreate()=0;
};


class ShoesCreate:public BaseCreate
{
	public:
		Set *setCreate(){
			return new Shoes();
		}
};

class ClothesCreate:public BaseCreate
{
	public:
		Set *setCreate(){
			return new Clothes();
		}
};

int main()
{
	BaseCreate *tmp = new ShoesCreate();
	Set *testShoes = tmp->setCreate();
	testShoes->show();

	BaseCreate *any = new ClothesCreate();
	Set *testClothes = any->setCreate();
	testClothes->show();

	delete testShoes;
	delete tmp;

	delete testClothes;
	delete any;
	return 0;
}

