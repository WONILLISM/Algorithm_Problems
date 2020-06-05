#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    for(int i=0; i<arr1.size(); i++){
        answer.push_back(vector<int>());
        for(int j=0; j<arr1[i].size(); j++){
            answer[i].push_back(arr1[i][j] + arr2[i][j]);
        }
    }
    return answer;
}
int main(){
    vector<vector<int>> arr1 = {{1,2},{2,3}};
    vector<vector<int>> arr2 = {{3,4},{5,6}};
    return 0;
}