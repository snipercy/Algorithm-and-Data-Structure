#include<deque>

using namespace std;

int main(){
	int p[200001]={0};
	int num;

	scanf("%d",&num);
	printf("%d\n",num);
	for(int i = 0; i < num; i++){
		scanf("%d", &p[i]);
	}

	for(int i = 1; i <= num; i++){
		if(i == 1){
			printf("%d ", p[0]);
		}
		else{
			int max = 0;
			deque<int> stk_max;
			for(int j = 0; j < num; j++){
				while(stk_max.size() > 0 && p[j] < stk_max.front()){
					stk_max.pop_front();
				}
				stk_max.push_front(p[j]);
				if(stk_max.size() > i)
					stk_max.pop_front();
			}
			printf("%d ", stk_max.front());
		}
	}

	return 0;


}