#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> player = {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    vector<int> cnt = {0,0,0};
    for(int i=0; i<answers.size(); i++)
        for(int j=0; j<3; j++)
            if(player[j][i%player[j].size()] == answers[i])cnt[j]++;
    int max_val = *max_element(cnt.begin(),cnt.end());
    for(int i=0; i<cnt.size(); i++)
        if(max_val==cnt[i])
            answer.push_back(i+1);
    sort(answer.begin(),answer.end());
    return answer;
}