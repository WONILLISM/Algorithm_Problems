#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> um;
    vector<pair<string,string>> v;

    for (auto r : record){
        string tmp[3];
        int rec_idx = 0;
        for (int i = 0; i<r.size(); i++){
            if (r[i] != ' ')
                tmp[rec_idx].push_back(r[i]);
            else
                rec_idx++;
        }
        if (tmp[0]=="Enter"){
            um[tmp[1]] = tmp[2];
            v.push_back({tmp[0], tmp[1]});
        }
        else if (tmp[0] == "Leave"){
            v.push_back({tmp[0], tmp[1]});
        }
        else um[tmp[1]] = tmp[2];
    }


    for(auto ans : v){
        string res = "";
        if (ans.first == "Enter")
            res += um[ans.second] + "님이 들어왔습니다.";
        else res += um[ans.second] + "님이 나갔습니다.";
        answer.push_back(res);
    }
    return answer;
}
int main(){
    vector<string> record = {"Enter uid1234 Muzi", 
                            "Enter uid4567 Prodo",
                            "Leave uid1234",
                            "Enter uid1234 Prodo",
                            "Change uid4567 Ryan"};
    for(auto ans : solution(record))
        cout<<ans<<endl;
    return 0;
}