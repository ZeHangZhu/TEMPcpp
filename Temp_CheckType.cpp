/*
* (C) 2023 ZeHangZhu
* -*-coding:GBK-*-
*/
bool Temp::CheckType(string value) {

	//�������
	istringstream sin(value);
	double test;
	return sin >> test && sin.eof();

}
