#include<iostream>

using namespace std;

int main(){

    int arr[10] = {0};
    int first = 0;
    bool find_first = false;

    int i;
    for(i = 0

        // find the smallest number, skip '0'
        if(i != 0 && arr[i] != 0 && find_first == false)
        {
            first = i;
            find_first = true;
        }
    }

    cout << first;
    arr[first]--;

    for(i = 0; i < 10; i++){
        for(int j = 0; j < arr[i]; j++){
            cout << i;
        }
    }

    cout << endl;

    return 0;
}
    