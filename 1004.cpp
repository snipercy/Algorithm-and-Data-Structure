#include<iostream>
#include<string>

using namespace std;

const string week[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main(){

	// read in strings
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;

	int len1 = str1.length();
	int len2 = str2.length();

	int i = 0;
	int end = len1 > len2 ? len2 : len1;

	// get the 1st equal char from str1 and str2
	char c1;
	for (i = 0; i < end;++i){
		if (str1[i] == str2[i] && isupper(str1[i]) ) {
			c1 = str1[i];
			break;
		}
	}

	// get the second equal char
	++i;
	char c2;
	for (; i < end; i++){
		if (str1[i] == str2[i] && (isupper(str1[i]) || isdigit(str1[i])) ){
			c2 = str1[i];
			break;
		}
	}

	// for debug
	// cout << "c1" << c1 << " c2" << c2 << endl;

	int week_idx = c1 - 'A';
	printf("%s ",week[week_idx].c_str());

	
	// c2 transform to hour
	string hour;
	if (c2 >= '0' && c2 <= '9'){
		printf("0%d:", c2-'0');
	}
	else{
		printf("%d:", c2 - 'A'+10);
	}
	
	// get minute
	int minute;
	int len3 = str3.length();
	int len4 = str4.length();
	end = len3 > len4 ? len4 : len3;
	for (i = 0; i < end; i++){
		if (str3[i] == str4[i] && isalpha(str3[i]) ){
			break;
		}
	}

	if (i < 10){
		printf("0%d\n", i);
	}
	else
		printf("%d\n", i);
	
	system("pause");

	return 0;

}