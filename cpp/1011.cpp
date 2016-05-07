#include<iostream>
#include<string>

using namespace std;

int main()
{
	string num;
	cin >> num;

	int len = num.length();

	int hash[10] = {0};

	for (int i = 0; i < len; i++){
		hash[num[i] - '0']++;
	}

	for (int i = 0; i < 10; i++){
		if (hash[i]){
			printf("%d:%d\n", i, hash[i]);
		}
	}

	return 0;

}