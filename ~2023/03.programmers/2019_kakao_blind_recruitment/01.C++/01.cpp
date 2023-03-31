#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> um;   // key = id value = 닉네임
    queue<pair<string,string>> q;
    for(int i=0; i<record.size(); i++){
        vector<string> tmp(3,"");
        int idx=0;
        for(int j=0; j<record[i].size(); j++){
            char c = record[i][j];
            if(c==' ') idx++;
            else tmp[idx]+=c;
        }
        string cmd = tmp[0];
        string id , nick;
        cout<<cmd<<endl;
        if(cmd == "Enter"){
            id = tmp[1], nick = tmp[2];
            if(um.find(id)==um.end())
                um.insert({id,nick});
            else um[id] = nick;
            q.push({id,"님이 들어왔습니다."});
        }
        else if(cmd == "Leave"){
            id = tmp[1];
            q.push({id,"님이 나갔습니다."});
        }
        else{
            id = tmp[1], nick = tmp[2];
            um[id] = nick;
        }
    }
    
    while(!q.empty()){
        pair<string, string> cur = q.front();
        q.pop();
        answer.push_back(um[cur.first]+cur.second);
    }
    return answer;
}
int main(){
    vector<string> r = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    for(auto ans : solution(r))
        cout<<ans<<endl;
    return 0;
}