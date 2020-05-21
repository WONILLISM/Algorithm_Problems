#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// -10 -9 -8 -7 -6 -5 -4 -3 -2 -1 0 1 2 3 4 5 6
long long solution(int a, int b) {
    long long answer = 0;
    long long d = (a-b>=0? a-b : b-a) + 1;
    bool ov = d%2==0;
    if(ov)answer = (a+b)*d/2;
    else answer = (a+b)*(d-1)/2 + (a+b)/2;   
    return answer;
}
int main(){
    int a = 3, b = 5;
    cout<<solution(a,b)<<endl;
    return 0;
}