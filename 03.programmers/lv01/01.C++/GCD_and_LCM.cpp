#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) { return a%b == 0 ? b: GCD(b,a%b); }
vector<int> solution(int n, int m){
    vector<int> answer;
    answer.push_back(GCD(n, m));
    answer.push_back(n * m/answer[0]);
    return answer;
}
int main(){
    for (auto ans : solution(3, 12))
        cout << ans << " ";
    return 0;
}