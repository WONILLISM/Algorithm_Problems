#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    unordered_map<string, int> um;
    int idx = 26;
    
    for(int i=0; i<idx; i++){
        string str ="";
        char c = i+'A';
        str +=c;
        um[str] = i+1;
    }
    idx++;
    int l =0,r =1;
    while(r<=msg.size()){
        r = l+1;
        string next ="";
        while(1){           // 맵에 없는 문자를 찾을 때까지 r++
            next +=msg[r-1];
            if(um.find(next) ==um.end())break;
            else r++;
        }
        string cur = next.substr(0, r-l-1);
        answer.push_back(um[cur]);
        um[next] = idx++;
        l = r-1;        
    }
    return answer;
}
int main(){
    string msg = "KAKAO";
    
    for(auto ans : solution(msg))
        cout<<ans<<" ";
    return 0;
}