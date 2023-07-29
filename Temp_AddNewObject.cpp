/*
* (C) 2023 ZeHangZhu
* -*-coding:GBK-*-
*/
int Temp::AddNewObject(string type_obj,string obj_name,string value,bool output=false) {
	//检查值与类型是否相符
	if(type_obj == "int") {
		if(CheckType(value) == false) {
			if(output == true)
				cout<<"LINE["<<__LINE__<<"]:类型:"<<type_obj<<"的值不能为:"<<value<<endl;
			return -1;
		}
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
	//输出
	if(output == true)
		cout<<data<<endl;
	return 0;
}
