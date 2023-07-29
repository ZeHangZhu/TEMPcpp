/*
* (C) 2023 ZeHangZhu
* -*-coding:GBK-*-
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype.h> 

using namespace std;

class Temp {
	private:
		/*���������б�*/
		string data;

		/*���ָ��������ַ���*/
		string GetChars(int start,int end,string data);

		/*��ʽ���ַ���*/
		string format(string data);

		/*����ʽ���ַ���*/
		string Unformat(string data);\
		
		/*�������*/
		bool CheckType(char* type,string value); 
	public:

		/*
		* �ڵ�Ԫ�������¶���
		* ֧�ֵ������� 'char','int','float','bool',����
		*/
		int AddNewObject(string type_obj,string obj_name,string value);

		/*������ȡ��Ԫ�е�����*/
		char GetObject(string type_name);

		/*���浽�ļ�*/
		int Save(string file);

};

int Temp::Save(string file){
	fstream fileobj;
	fileobj.open(file.c_str(),ios::app);
	fileobj<<data;
}

string Temp::GetChars(int start,int end,string data) {
	string temp;
	int i=start,j;

	for(j=0; i<end; i++) {
		temp[j] = data[i];
		j++;
	}

	return temp;
}

string Temp::format(string datas) {
	string temp;

	const char* data;
	data = datas.c_str();

	int i = 0;
	char ch;

	//��ʽ��
	while(i<datas.length()) {
		ch = data[i];
		if(ch == '\"') {
			temp += '^';
			temp += '0';
		} else if(ch == '^') {
			temp += '^';
			temp += '1';
		} else {
			temp += ch;
		}
		i++;
	}

	return temp;
}

string Temp::Unformat(string data) {
	string temp;

	return temp;
}

int Temp::AddNewObject(string type_obj,string obj_name,string value) {
	//���ֵ�������Ƿ����
	if(CheckType(tpye_obj.c_str(),value) == false){
		return -1;
	}

	/*���������ʾ*/
	if(type_obj == "char") {
		data = data + "c:";
	}

	else if(type_obj == "bool") {
		data = data + "b:";
	}

	else if(type_obj == "int") {
		data = data+"i:";
	}

	else if(type_obj == "float") {
		data = data+"f:";
	} else {
		cout<<"LINE["<<__LINE__<<"]:���Ͳ���Ϊ:"<<value <<endl;
		return -2;
	}
	//д������
	data += '[';
	data += obj_name;
	data += ']';
	/*д�뿪ͷ������*/
	data += '\"';
	/*д��ֵ*/
	data += format(value);
	/*д���β������*/
	data += "\"\n";
	cout<<data<<endl;
	return 0;
}
char Temp::GetObject(string type_name) {

	char temp[40960];

	/*��ȡĿ��λ��*/
	int i = data.find(type_name)-2;
	/*������ʼλ��*/
	int start = i;
	/*�������Ƿ����*/
	if(i<0) {
		cout<<"����["<<type_name<<"]������!"<<endl;
		return '\0';
	}

	/*ָ��ģʽ,1Ϊ����,2Ϊ������,3Ϊֵ,4�����ж�����*/
	unsigned int flag=1;
	while(1) {

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

//��������
int test() {
	Temp a;
	a.AddNewObject("char","test1","test\"^");
	a.AddNewObject("char","test2","test2");
	a.Save("1.txt");
	return 0;
}

int main(int argc,char *argv[]) {
	return test();
}