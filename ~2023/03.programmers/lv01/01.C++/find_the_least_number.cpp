#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int m = *min_element(arr.begin(),arr.end());
    for(int i=0; i<arr.size(); i++)
        if(arr[i]!=m)answer.push_back(arr[i]);
    return answer.empty()? vector<int>(1,-1):answer;
}

// vector<int> solution(vector<int> arr) {
//     vector<int> answer = arr;
//     int m = *min_element(arr.begin(),arr.end());
//     auto itr = find(answer.begin(),answer.end(),m);
//     answer.erase(itr);
//     return answer.empty()? vector<int>(1,-1):answer;
// }