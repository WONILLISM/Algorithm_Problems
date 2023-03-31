#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        vector<int> tmp;
        tmp.assign(array.begin() + commands[i][0] -1, array.begin() + commands[i][1]);
        sort(tmp.begin(), tmp.end());
       answer.push_back(tmp[commands[i][2]-1]);
    }
    return answer;
}
int main(){
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

    for(auto ans : solution(array, commands))
        cout<<ans<<" ";
    return 0;
}

// vector<int> solution(vector<int> array, vector<vector<int>> commands) {
//     vector<int> answer;
//     for(int i = 0; i < commands.size(); i++){
//         vector<int> cmd = commands[i];
//         vector<int> tmp;
//         int s = cmd[0], e = cmd[1], k = cmd[2];
//         for(int j = s-1; j < e; j++)
//             tmp.push_back(array[j]);
//         sort(tmp.begin(), tmp.end());
//         answer.push_back(tmp[k-1]);
//     }
//     return answer;
// }