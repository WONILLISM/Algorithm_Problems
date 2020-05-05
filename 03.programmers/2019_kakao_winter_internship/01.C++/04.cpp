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
unordered_map<ll, ll> m;     //배정 받은 방번호, {배정 받은 사람, 다음 방 번호}
ll find_room(ll key){
    if(m.find(key)==m.end()){
        m.insert({key, key+1});
        answer.push_back(key);
        return key+1;
    }
    else{ 
        ll nk = find_room(m[key]);
        m[key] = nk;
        return nk;
    }
}
vector<long long> solution(long long k, vector<long long> room_number) {
    for(ll i=0; i<room_number.size(); i++){
        ll key = room_number[i];
        if(m.find(key)==m.end()){
            m.insert({key,key+1});
            answer.push_back(key);
        }
        else{
            m[key] = find_room(m[key]);
        }
    }
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