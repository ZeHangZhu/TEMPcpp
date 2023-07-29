/*
* (C) 2023 ZeHangZhu
* -*-coding:GBK-*-
*/
int Temp::Save(string file,char cover = 'y') {
	fstream fileobj;
	if(cover == 'y')
	fileobj.open(file.c_str(),ios::trunc);
	if(cover == 'n')
	fileobj.open(file.c_str(),ios::app);
	fileobj<<data;
}
