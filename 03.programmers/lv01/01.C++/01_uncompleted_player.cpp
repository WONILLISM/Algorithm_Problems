#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// string solution(vector<string> participant, vector<string> completion) {
//     string answer = "";
//     for(string player : participant){
//         auto iter = find(completion.begin(), completion.end(), player);
//         if(iter == completion.end()) answer = player;
//         else completion.erase(iter);
//     }
//     return answer;
// }
// string solution(vector<string> participant, vector<string> completion) {
//     sort(participant.begin(), participant.end());
//     sort(completion.begin(), completion.end());
//     for(int i = 0; i < completion.size(); i++){
//         if(completion[i]!=participant[i]) return participant[i];
//     }
//     return participant.back();
// }
// string solution(vector<string> participant, vector<string> completion) {
//     unordered_multiset<string> completetion_player;
//     for(string s : completion) 
//         completetion_player.insert(s);
//     for(string s : participant){
//         auto itr = completetion_player.find(s);
//         if(itr != completetion_player.end()) completetion_player.erase(itr);
//         else return s;
//     }
// }
string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string,int> completion_player;
    for(string s : completion) 
        completion_player[s]++;
    for(auto a : completion_player)
        cout<<a.second<<endl;
    for(string s : participant){
        auto itr = completion_player.find(s);
        if(itr != completion_player.end()) {
            completion_player[s]--;
            if(completion_player[s]==-1) return s;
        }
        else return s;
    }
}
int main(){
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};
    cout<<solution(participant, completion)<<endl;
    return 0;
}