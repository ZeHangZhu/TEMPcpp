/*
* (C) 2023 ZeHangZhu
* -*-coding:GBK-*-
*/
string Temp::GetChars(int start,int end,string data) {
	//ÅÐ¶ÏÊÇ·ñ³¬³ö·¶Î§
	if(data.length() <end)
		return "-1";

	string temp;
	int i,j=0;

	for(i=start; i<=end; i++) {
		temp+= data[i];
		j++;
	}

	return temp;
}
