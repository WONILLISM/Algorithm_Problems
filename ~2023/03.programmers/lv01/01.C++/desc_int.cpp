#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string s = to_string(n);
    sort(s.begin(), s.end());
    reverse(s.begin(), s.end());
    answer = stoll(s);
    return answer;
}
int main(){
    cout<<solution(118372)<<endl;
    return 0;
}