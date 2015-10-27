#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

struct moon_cake
{
	double number, totle, price;
	bool operator < (const moon_cake& a) const{
		return price > a.price;
	}
};

int main(){

	int moon_cake_kinds = 0;
	int need_sold = 0;
	moon_cake cake[1000];

	memset(cake, 0, sizeof(cake));


	cin >> moon_cake_kinds >> need_sold;

	for (int i = 0; i < moon_cake_kinds; i++){
		cin >> cake[i].number;
	}

	for (int i = 0; i < moon_cake_kinds; i++){
		cin >> cake[i].totle;
	}

	for (int i = 0; i < moon_cake_kinds; i++){
		cake[i].price = (cake[i].totle / cake[i].number);
	}

	sort(cake, cake + moon_cake_kinds);

	double res = 0;
	int i = 0;
	while (i < moon_cake_kinds && need_sold >0){
		if (cake[i].number > need_sold){
			res += cake[i].price * need_sold;
			break;
		}
		else{
			res += cake[i].totle;
			need_sold -= cake[i].number;
			i++;
		}
	}

	printf("%.2f", res);
	return 0;
}