#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    int answer = 0;
    string s = to_string(x);
    for(char c:s)
        answer +=c-'0';
    return x%answer==0;
}
int main(){
    cout<<solution(10)<<endl;
    return 0;
}