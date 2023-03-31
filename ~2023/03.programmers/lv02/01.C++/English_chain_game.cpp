#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_set<string> us;
    vector<int> cnt(n,0);
    for(int i=0; i<words.size(); i++){ 
        int idx = i%n;
        string key = words[i];
        if(i>0 && words[i-1].back() != words[i].front()){
            answer.push_back(idx+1);
            answer.push_back(cnt[idx]+1);
            return answer;
        }
        if(!us.count(key)){
            us.insert(key);
            cnt[idx]++;
        }
        else{
            answer.push_back(idx+1);
            answer.push_back(cnt[idx]+1);
            return answer;
        }
    }

    return answer = {0,0};
}
int main(){
    vector<string> w = {"tank", "kick", "know", "wheel", "land", "dream", "mother", "robot","tank"};
    for(auto ans : solution(3,w))
        cout<<ans<<" ";
    return 0;
}