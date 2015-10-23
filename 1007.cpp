#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    // read in A and B
    string A;
    int B;
    cin >> A >> B;

    // C = A/B
    vector<int> C;

    int i = 0;
    int len = A.length();
    int d = 0;

    // divide
    for(i = 0; i < len; i++){
        d = d*10 + (A[i]-'0');
        C.push_back(d/B);
        d %= B;
    }

    // skip 0
    vector<int>::iterator iter = C.begin();
    for(;*iter == 0; ++iter);

    for(; iter != C.end(); iter++){
        cout << *iter;
    }

    cout << ' ' << d << endl;
    
    return 0;
}
