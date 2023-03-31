#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<pair<int, int>> vec;
    int n;
    cin>>n;
    while (n--){
        int x, y;
        cin >> x >> y;
        vec.push_back({x,y});
    }
    sort(vec.begin(), vec.end(), comp);
    for (auto v : vec)
        cout << v.first <<" " <<v.second<<endl;
    return 0;
}