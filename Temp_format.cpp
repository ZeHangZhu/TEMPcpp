/*
* (C) 2023 ZeHangZhu
* -*-coding:GBK-*-
*/
string Temp::format(string datas) {
	string temp;

	const char* data;
	data = datas.c_str();

	int i = 0;
	char ch;

	//∏Ò ΩªØ
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
