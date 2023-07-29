/*
* (C) 2023 ZeHangZhu
* -*-coding:GBK-*-
*/
int Temp::AddNewObject(string type_obj,string obj_name,string value,bool output=false) {
	//���ֵ�������Ƿ����
	if(type_obj == "int") {
		if(CheckType(value) == false) {
			if(output == true)
				cout<<"LINE["<<__LINE__<<"]:����:"<<type_obj<<"��ֵ����Ϊ:"<<value<<endl;
			return -1;
		}
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
	//���
	if(output == true)
		cout<<data<<endl;
	return 0;
}
