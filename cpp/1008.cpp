//
// Created by cy on 10/19/15.
//

/*
输入描述:
输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、
B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出描述:
输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。
如果解不唯一，则输出按字母序最小的解。
*/

#include <iostream>
#include <vector>

using namespace std;

int transform(char c)
{
	switch(c){
		case 'B': return 0;
		case 'C': return 1;
		case 'J': return 2;
	}
}

int main()
{
	// read in N
	int n;
	cin >> n;

	int k1, k2;
	int wins[3] = {0};
	int guests_jia[3] = {0};
	int guests_yi[3] = {0};

	for(int i = 0; i < n; i++){
		//read in gesture
		char a, b;
		cin >> a >> b;

		k1 = transform(a);
		k2 = transform(b);

		// jia win
		if((k1+1)%3 == k2) {
			// wins[0] is jia win times
			wins[0]++;
			guests_jia[k1]++;
		}
		else if(k1 == k2){
			wins[1]++;
		}
		else if((k2+1)%3 == k1){
			wins[2]++;
			guests_yi[k2]++;
		}
	}

	cout << wins[0] << ' '<< wins[1] << ' '<< wins[2] << endl;
	cout << wins[2] << ' '<< wins[1] << ' '<< wins[0] << endl;

	int j1 = 0, j2 = 0;
	for(int i = 0; i<3; i++){
		if(guests_jia[i] > guests_jia[j1]) j1 = i;
		if(guests_yi[i] > guests_yi[j2]) j2 = i;
	}
	//cout << j1 << ' ' << j2<< endl;

	const char arr[3] = {'B','C','J'};
	cout << arr[j1] << ' ' << arr[j2] << endl;
}
