#include<iostream>
using namespace std;

//�ܽ�:ǰ�õ����������ã����õ�������ֵ

class MyInteger
{
	friend ostream& operator<<(ostream& cout, MyInteger myint);

public:
	MyInteger()
	{
		my_num = 0;
	}
	
	//����ǰ�õ�++�����
	MyInteger& operator++()
	{
		//����++����
		++my_num;
		//�ٷ�������
		return *this;
	}
	
	//���غ��õ�++�����
	//void operator++(int)	int����ռλ��������������ǰ�úͺ���
	MyInteger operator++(int)
	{
		
		//�� ��¼��ʱ���
		MyInteger temp = *this;
		//�� ����
		my_num++;
		//�ٷ�������
		return temp;

	}

private:
	int my_num;
};


//�������������
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