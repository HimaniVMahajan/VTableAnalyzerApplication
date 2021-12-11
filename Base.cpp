//VTABLE Analyzer Application.

using namespace std;
#include<iostream>

class Base
{
	public:
	
	int i;
	int j;
	
	virtual void fun()
	{
		cout<<"\nBase fun\n";
	}
	
	virtual void gun()
	{
		cout<<"\nBase gun\n";
	}
	
	void sun()
	{
		cout<<"\nBase sun\n";
	}
};

class Derived : public Base
{
	public:
	
	int x;
	int y;
	
	void fun()
	{
		cout<<"\nDerived fun\n";
	}
	
	void sun()
	{
		cout<<"\nDerived sun\n";
	}
	
	virtual void run()
	{
		cout<<"\nDerived run\n";
	}
};

int main()
{
	Base bobj;
	Derived dobj;
	
	cout<<endl<<"size of Base object: "<<sizeof(bobj)<<endl;
	cout<<endl<<"size of Derived object: "<<sizeof(dobj)<<endl;
	
	int *op = (int *)(&dobj);
	cout<<"\nAddress of dobj: "<<op<<endl;
	
	int *vptr = (int*)(*op);
	cout<<"\nAddress of vptr: "<<vptr<<endl;
	
	void(*fp)();
	
	fp = (void(*)())(*vptr);
	fp();
	
	fp = (void(*)())(*(vptr + 1));
	fp();
	
	fp = (void(*)())(*(vptr + 2));
	fp();
	
	return 0;
}
