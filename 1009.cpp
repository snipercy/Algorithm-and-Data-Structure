//
// Created by cy on 10/24/15.
//
#include<iostream>
#include<sstream>
#include<algorithm>

using namespace std;

string sub(string a, string b){
	int a1, b1;
	stringstream ss(a);

	ss >> a1;

	// haha
	ss.str("");
	ss.clear();

	ss << b;
	ss >> b1;

	a1 = a1 - b1;

	ss.str("");
	ss.clear();
	ss << a1;

	return ss.str();
}
int main()
{
	// read in num
	int num = 0;
	cin >> num;

	if(num <=0 || num >=10000)
		return 1;

	// num convert to str
	stringstream ss;
	ss << num;
	string num_str = ss.str();

	// num_str's length is less than 4, then add '0' to the end
	for(int l = num_str.length();4-l>0;l++){
		num_str+='0';
	}

	string a, b;
	while (num_str != "6174"){

		sort(num_str.begin(),num_str.end(), greater<int>());
		a = num_str;

		sort(num_str.begin(),num_str.end(), less<int>());
		b = num_str;

		num_str = sub(a, b);

		if(num_str == "0"){
			cout << a << " - " << b << " = " << "0000" << endl;
			break;
		}
		cout << a << " - " << b << " = " << num_str << endl;
	}
	return 0;
}
