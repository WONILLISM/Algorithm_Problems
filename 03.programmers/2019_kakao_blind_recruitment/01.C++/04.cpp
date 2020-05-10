#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define ll long long

using namespace std;

vector<pair<ll, int>> food_map;

bool cmp(const pair<ll, int>& a, const pair<ll, int>& b){
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    ll n = food_times.size();
    for(int i = 0; i < n; i++)
        food_map.push_back(make_pair((ll)food_times[i], i+1));

    sort(food_map.begin(), food_map.end()); 
        
    ll i = 0;
    for(; i<n; i++){
        ll diff = i == 0 ? food_map[i].first : food_map[i].first - food_map[i-1].first;
        if(k - diff * (n-i) < 0 ) break;    
        k -= diff * (n-i); 
    }

    if(i == food_map.size()) return -1;

    sort(food_map.begin()+i, food_map.end(), cmp);
    answer = food_map[i+k%(n-i)].second;
    return answer;
}

int main(){
    vector<int> ft = {3,3,3,5,1,2};
    ll k =9;
    cout<<solution(ft,k)<<endl;
    return 0;
}