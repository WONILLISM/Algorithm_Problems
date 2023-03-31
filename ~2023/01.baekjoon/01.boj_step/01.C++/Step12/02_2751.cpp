#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> arr;
    int n;
    cin>>n;
    while (n--){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    for (auto ans : arr)
        cout<<ans<<endl;
    return 0;
}