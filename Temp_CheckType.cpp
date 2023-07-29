/*
* (C) 2023 ZeHangZhu
* -*-coding:GBK-*-
*/
bool Temp::CheckType(string value) {

	//¼ì²éÊý×Ö
	istringstream sin(value);
	double test;
	return sin >> test && sin.eof();

}
