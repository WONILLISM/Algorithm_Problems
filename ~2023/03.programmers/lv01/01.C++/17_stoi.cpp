#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int ret = 0, sign=1;
    for(int i=0; s[i]; i++){
        if(s[i] == '-') sign = -1;
        else if(s[i] == '+') sign = 1;
        else ret = ret * 10 + s[i] - '0';
    }
    return ret * sign;
}
int main(){
    string s = "1234";
    cout<<solution(s)<<endl;
    return 0;
}


// int solution(string s) {
//     return stoi(s);
// }