#include<bits/stdc++.h>
#include"Myshared_ptr.hpp"
using namespace std;
int main()
{
	Myshared_ptr<int> p1;
	Myshared_ptr<int> p2(p1);
	Myshared_ptr<int> p3(new int(2));
	cout << p1.get() << ' ' << p1.use_count() << endl;
	p2 = p3;
	cout << *(p2.get()) << endl;
	Myshared_ptr<int> p11(p1);
	cout << p11.use_count() << endl;
	cout << *p3 << endl;
	Myshared_ptr<pair<int, int>> p4(new pair<int,int>(1,2));
	cout << p4->first << endl;
	if (p4 || !p4)
	{	
		auto p5 = p3;
		cout << p5.use_count() << endl;
	}
	cout << p3.use_count() << endl;
	p1 = p3;
	cout << p1 - p2 << endl;
	Myshared_ptr<int> p6(new int(6));
	p1 = p6;
	cout << *p1 << ' ' << *p2 << endl;
	p1.swap(p2);
	cout << *p1 << ' ' << *p2 << endl;
	getchar();
}