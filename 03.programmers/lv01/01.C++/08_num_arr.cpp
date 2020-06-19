#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    sort(arr.begin(), arr.end());
    for(int res : arr)
        if(res%divisor == 0)answer.push_back(res);
    if(answer.empty())answer.push_back(-1);
    return answer;
}
int main(){
    vector<int> arr = {5,9,7,10};
    int div = 5;
    for(int ans : solution(arr,div))
        cout<<ans<<" ";
    return 0;
}