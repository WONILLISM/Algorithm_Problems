#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer;
    answer.push_back(x);
    n--;
    while(n--){
        answer.push_back(x+answer.back());
    }
    return answer;
}
int main(){
    int x = 2;
    int n = 5;

    for(auto ans : solution(x,n)){
        cout<<ans<<" ";
    }
    return 0;
}