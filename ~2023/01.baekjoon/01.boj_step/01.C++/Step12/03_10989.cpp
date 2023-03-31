#include <iostream>
#include <vector>
#define endl '\n'

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr(10001, 0);
    int n, Max;
    cin >> n;
    Max = 0;
    while (n--){
        int a;
        cin>>a;
        arr[a]++;
        Max = Max < a ? a : Max;
    }
    for (int i = 1; i <= Max; i++){
        if (arr[i]){
            for (int j = 0; j < arr[i]; j++){
                cout << i << endl;
            }
        }
    }
    
    return 0;
}