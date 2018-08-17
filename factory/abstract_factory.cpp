#include <iostream>

using namespace std;


class Iuser
{
	public:
		virtual void usershow()=0;
};

class Department
{
	public:
		virtual void departshow()=0;
};

class AccessUser:public Iuser
{
	public:
		void usershow(){
			cout<<"Access show"<<endl;
		}
};

class AccessDepart:public Department
{
	public:
		void departshow(){
			cout<<"Access depart"<<endl;
		}
};

class SqlUser:public Iuser
{
	public:
		void usershow(){
			cout<<"Sql show"<<endl;
		}
};

class SqlDepart:public Department
{
	public:
		void departshow(){
			cout<<"Sql depart"<<endl;
		}
};

class Factory
{
	public:
		virtual Iuser* createUser()=0;
		virtual Department* createDepart()=0;
};


class AccessFactory:public Factory
{
	public:
		Iuser* createUser(){
			return new AccessUser();
		}
		Department* createDepart(){
			return new AccessDepart();
		}
};

class SqlFactory:public Factory
{
	public:
		Iuser* createUser(){
			return new SqlUser();
		}
		Department* createDepart(){
			return new SqlDepart();
		}
};

int main()
{
	Factory *access = new AccessFactory();
	Iuser* access_user = access->createUser();
	Department* access_depart = access->createDepart();

	access_user->usershow();
	access_depart->departshow();

	

	Factory *sql = new SqlFactory();
	Iuser* sql_user = sql->createUser();
	Department* sql_depart = sql->createDepart();

	sql_user->usershow();
	sql_depart->departshow();

	delete access_user;
	delete access_depart;
	delete access;

	delete sql_user;
	delete sql_depart;
	delete sql;

	return 0;
}

