//
// Created by cy on 10/7/15.
//
/*
 *题目描述
	正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

	现给定A、DA、B、DB，请编写程序计算PA + PB。

	输入描述:
	输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

	 输入例子:
		3862767 6 13530293 3

	输出例子:
		399
 *
 */

#include<iostream>
#include<sstream>

using namespace std;

int main()
{
	// for store input
	string input;

	// get input
	string numA,  numB ;
	char a , b;
	cin >> numA >> a >> numB >> b;

	// for dubug
	// cout << numA <<' ' << a << ' ' << numB << ' ' << b;

	// get new num from numA
	string new_A;
	int len_A = numA.length();
	for(int i = 0; i < len_A; i++){
		if(numA[i] == a){
			new_A += a;
		}
	}
	new_A = new_A == ""	? "0" : new_A;

	// for debug
	// cout << "new_A:" << new_A << endl;

	//get new num from numB
	string new_B;
	int len_B = numB.length();
	for(int i = 0; i < len_B; i++){
		if(numB[i] == b){
			new_B += b;
		}
	}
	new_B = new_B == "" ? "0" : new_B;

	// for debug
	// cout << "new_B:" << new_B << endl;

	int res = atoi(new_A.c_str()) + atoi(new_B.c_str());

	cout << res << endl;

	return 0;
}
