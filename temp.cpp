/*
* Copyright (C) 2023 ZeHangZhu
* -*- coding:GBK -*-
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Temp
{
	private:
		/*���������б�*/
		string data;
		
		/*���ָ��������ַ���*/
		string GetChars(int start,int end,string data);
		
		/*��ʽ���ַ���*/
		string format(string data);
		
		/*����ʽ���ַ���*/
		string Unformat(string data);

	public:
		/*
		* �ڵ�Ԫ�������¶���
		* ֧�ֵ������� 'char','int','float','bool',����
		*/
		int AddNewObject(string type_obj,string value);
		
		/*������ȡ��Ԫ�е�����*/
		char GetObject(string type_name);
		
		/*���浽�ļ�*/
		int Save(string file);
		
};

string Temp::GetChars(int start,int end,string data)
{
	string temp;
	int i=start,j;
	for(j=0; i<end; i++)
		{
			temp[j] = data[i];
			j++;
		}
	return temp;
}

int Temp::AddNewObject(string type_obj,string value)
{

	/*���������ʾ*/
	if(type_obj == "char")
		{
			data = data + "c:";
		}

	else if(type_obj == "bool")
		{
			data = data + "b:";
		}

	else if(type_obj == "int")
		{
			data = data+"i:";
		}

	else if(type_obj == "float")
		{
			data = data+"f:";
		}
	else
		{
			cout<<"LINE["<<__LINE__<<"]:���Ͳ���Ϊ:"<<value <<endl;
			return -2;
		}

	/*д��ֵ*/
	data += '\"';

	int i=0;
	while(1)
		{
			if(value[i] == '\0')
				break;
			if(value[i] == '\\')
				break;
		}

}

char Temp::GetObject(string type_name)
{

	char temp[40960];

	/*��ȡĿ��λ��*/
	int i = data.find(type_name)-2;
	/*������ʼλ��*/
	int start = i;
	/*�������Ƿ����*/
	if(i<0)
		{
			cout<<"����["<<type_name<<"]������!"<<endl;
			return '\0';
		}

	/*ָ��ģʽ,1Ϊ����,2Ϊ������,3Ϊֵ,4�����ж�����*/
	unsigned int flag=1;
	while(1)
		{

			if(data[i] == '\0')
				break;

			if(data[i] == ':')
				flag = 2;

			if(data[i] == '\"' && flag == 2)
				flag = 3;

			if(data[i] == '\"' && flag == 3)
				flag = 4;

			if(data[i] == ';' && flag == 4)
				break;

			i++;
		}

	/*�����ݶ�д�뻺��*/

}

int test()
{
	Temp a;
	a.AddNewObject("wfsdwacf","dssa");	//�쳣����
	a.AddNewObject("int","qardh");	//��������
	return 0;
}

int main()
{
	return test();
}
