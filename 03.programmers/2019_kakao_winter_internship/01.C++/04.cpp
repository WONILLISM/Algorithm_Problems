#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define PLL pair<long long,long long>
#define ll long long
#define endl '\n'


using namespace std;
vector<long long> answer;
unordered_map<ll, PLL> m;     //배정 받은 방번호, {배정 받은 사람, 다음 방 번호}
ll find_room(ll i, ll key){
    if(m.find(key)==m.end()){
        m.insert({key,{i,key+1}});
        answer.push_back(key);
        return key+1;
    }
    else{ 
        ll nk = find_room(i, m[key].second);
        m[key].second = nk;
        return nk;
    }
}
vector<long long> solution(long long k, vector<long long> room_number) {
    for(ll i=0; i<room_number.size(); i++){
        ll key = room_number[i];
        if(m.find(key)==m.end()){
            m.insert({key,{i,key+1}});
            answer.push_back(key);
        }
        else{
            m[key].second = find_room(i,m[key].second);
        }
    }

    // vector<PLL> tmp;
    // for(auto res : m){
    //     tmp.push_back({res.second.first, res.first});
    // }
    // sort(tmp.begin(), tmp.end());
    // for(auto ans : tmp)
    //     answer.push_back(ans.second);    
    return answer;
}
int main(){
    ll k;
    vector<ll> rn;

    k=10;
    rn = {1,3,4,1,3,1};

    for(auto ans : solution(k,rn))
        cout<<ans<<endl;

    return 0;
}