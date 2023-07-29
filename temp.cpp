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
		/*缓存数据列表*/
		string data;

		/*获得指定区域的字符串*/
		string GetChars(int start,int end,string data);

		/*格式化字符串*/
		string format(string data);

		/*反格式化字符串*/
		string Unformat(string data);\
		
		/*检查类型*/
		bool CheckType(char* type,string value); 
	public:

		/*
		* 在单元中增加新对象
		* 支持的类型有 'char','int','float','bool',类型
		*/
		int AddNewObject(string type_obj,string obj_name,string value);

		/*单独读取单元中的数据*/
		char GetObject(string type_name);

		/*储存到文件*/
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

	//格式化
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
	//检查值与类型是否相符
	if(CheckType(tpye_obj.c_str(),value) == false){
		return -1;
	}

	/*添加类型提示*/
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
		cout<<"LINE["<<__LINE__<<"]:类型不能为:"<<value <<endl;
		return -2;
	}
	//写入名称
	data += '[';
	data += obj_name;
	data += ']';
	/*写入开头的引号*/
	data += '\"';
	/*写入值*/
	data += format(value);
	/*写入结尾的引号*/
	data += "\"\n";
	cout<<data<<endl;
	return 0;
}
char Temp::GetObject(string type_name) {

	char temp[40960];

	/*获取目标位置*/
	int i = data.find(type_name)-2;
	/*设置起始位置*/
	int start = i;
	/*检查变量是否存在*/
	if(i<0) {
		cout<<"变量["<<type_name<<"]不存在!"<<endl;
		return '\0';
	}

	/*指针模式,1为类型,2为变量名,3为值,4用于判定结束*/
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

	/*将数据段写入缓存*/

}

//正常测试
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