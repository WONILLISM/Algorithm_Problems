#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); ++i){
        int day = (99 - progresses[i]) / speeds[i] + 1;
        if (answer.empty() || max_day < day) {
            answer.push_back(1);
            max_day = day;
        }
        else answer.back()++;
    }
    return answer;
}
int main(){
    // vector<int> p = {40, 93, 30, 55, 60, 65};
    vector<int> p = {93,30,55};
    // vector<int> s = {60, 1, 30, 5 , 10, 7};
    vector<int> s = {1,30,5};
    for(auto ans : solution(p,s))
        cout<<ans<<" ";
    cout<<endl;
    return 0;
}