#include<iostream>
using namespace std;

//总结:前置递增返回引用，后置递增返回值

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);

public:
	MyInteger()
	{
		my_num = 0;
	}
	
	//重载前置的++运算符
	MyInteger& operator++()
	{
		//先做++运算
		++my_num;
		//再返回自身
		return *this;
	}
	
	//重载后置的++运算符
	//void operator++(int)	int代表占位参数，用于区分前置和后置
	MyInteger operator++(int)
	{
		
		//先 记录当时结果
		MyInteger temp = *this;
		//后 递增
		my_num++;
		//再返回自身
		return temp;

	}

private:
	int my_num;
};


//重载左移运算符
ostream& operator<<(ostream& cout, MyInteger myint)
{
	cout << myint.my_num;
	return cout;
}



void test01()
{
	MyInteger myint;
	cout << myint << endl;
	cout << ++myint << endl;

}
void test02()
{
	MyInteger myint;
	cout << myint++ << endl;
	cout << myint << endl;

}
int main()
{
	//test01();
	test02();
	return 0;
}