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
		/*缓存数据列表*/
		string data;
		
		/*获得指定区域的字符串*/
		string GetChars(int start,int end,string data);
		
		/*格式化字符串*/
		string format(string data);
		
		/*反格式化字符串*/
		string Unformat(string data);

	public:
		/*
		* 在单元中增加新对象
		* 支持的类型有 'char','int','float','bool',类型
		*/
		int AddNewObject(string type_obj,string value);
		
		/*单独读取单元中的数据*/
		char GetObject(string type_name);
		
		/*储存到文件*/
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

	/*添加类型提示*/
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
			cout<<"LINE["<<__LINE__<<"]:类型不能为:"<<value <<endl;
			return -2;
		}

	/*写入值*/
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

	/*获取目标位置*/
	int i = data.find(type_name)-2;
	/*设置起始位置*/
	int start = i;
	/*检查变量是否存在*/
	if(i<0)
		{
			cout<<"变量["<<type_name<<"]不存在!"<<endl;
			return '\0';
		}

	/*指针模式,1为类型,2为变量名,3为值,4用于判定结束*/
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

	/*将数据段写入缓存*/

}

int test()
{
	Temp a;
	a.AddNewObject("wfsdwacf","dssa");	//异常测试
	a.AddNewObject("int","qardh");	//正常测试
	return 0;
}

int main()
{
	return test();
}
