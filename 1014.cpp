// 科学计数法转换
// eg: +1.23400E-03 -->  0.00123400

#include<iostream>
#include<string>
#include<cstring>
#include<iomanip>


using namespace std;

int main(){
	
	string inStr;
	cin >> inStr;

	if ('-' == inStr[0])
		printf("-");

	auto pos = inStr.find('E', 0);
	
	string subStr1 = inStr.substr(1, pos - 1);
	char flag = inStr[pos + 1];
	string subStr2 = inStr.substr(pos + 2, inStr.length() - pos - 2);

	int n = atoi(subStr2.c_str());

	subStr1.erase(subStr1.find('.', 0),1);

	if (flag == '-'){
		if (n == 0){
			subStr1.insert(1,1, '.');
			cout << subStr1 << endl;
		}
		else{
			cout << "0." << setfill('0') << setw(subStr1.length() + n - 1) << subStr1 << endl;
		}
	}
	else{
		if (n >= 0 && n < subStr1.length() - 1){
			subStr1.insert(n + 1, 1, '.');
			cout << subStr1 << endl;
		}
		else{
			subStr1.insert(subStr1.length(), n - subStr1.length() + 1, '0');
			cout << subStr1 << endl;
		}
	}

	return 0;
}
