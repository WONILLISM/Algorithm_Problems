#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#define PLL pair<long long,long long>
#define ll long long
#define endl '\n'


using namespace std;

/*
1. 한 번에 한 명씩 신청한 순서대로 방을 배정합니다.
2. 고객은 투숙하기 원하는 방 번호를 제출합니다.
3. 고객이 원하는 방이 비어 있다면 즉시 배정합니다.
4. 고객이 원하는 방이 이미 배정되어 있으면 원하는 방보다 번호가 크면서 비어있는 방 중 가장 번호가 작은 방을 배정합니다.
*/
unordered_map<ll, PLL> m;     //배정 받은 방번호, {배정 받은 사람, 다음 방 번호}
ll find_room(ll i, ll key){
    if(m.find(key)==m.end()){
        m.insert({key,{i,key+1}});
        return key+1;
    }
    else{ 
        ll nk = find_room(i, m[key].second);
        m[key].second = nk;
        return nk;
    }
}
vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    
    for(ll i=0; i<room_number.size(); i++){
        ll key = room_number[i];
        if(m.find(key)==m.end()){
            m.insert({key,{i,key+1}});
        }
        else{
            m[key].second = find_room(i,m[key].second);
        }
    }
    vector<PLL> tmp;
    for(auto res : m){
        tmp.push_back({res.second.first, res.first});
    }
    sort(tmp.begin(), tmp.end());
    for(auto ans : tmp)
        answer.push_back(ans.second);    
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