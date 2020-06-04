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
    unordered_map<string,int> completetion_player;
    for(string s : completion) 
        completetion_player[s]++;
    for(string s : participant){
        auto itr = completetion_player.find(s);
        if(itr != completetion_player.end()) completetion_player[s]--;
        else if(!completetion_player[s])return s;
    }
}
int main(){
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};
    cout<<solution(participant, completion)<<endl;
    return 0;
}