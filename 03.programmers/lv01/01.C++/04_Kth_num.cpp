#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int i = 0; i < commands.size(); i++){
        vector<int> cmd = commands[i];
        int s = cmd[0], e = commands[i][1], k = commands[i][2];
        vector<int> tmp;
        tmp.assign(cmd.begin() + s, cmd.begin() + e);
        for(auto a: tmp)
            cout<<a<<" ";
        cout<<endl;
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