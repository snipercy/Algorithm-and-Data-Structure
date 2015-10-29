#include<iostream>

using namespace std;

int main(){

    long A, B;
    cin >> A >> B;

    int D;
    cin >> D;

    long sum  = A + B;
    int res[1001];

    int idx = 0;
    while(sum){
        res[idx] = sum % D;
        sum /= D;
        idx++;
    }

    if(res[idx] == 0)
        idx--;
    for(int i = idx; i >= 0; i--){
        cout << res[i];
    }
    cout << endl;

    return 0;
}
