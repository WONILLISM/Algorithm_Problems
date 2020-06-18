#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    return s.size()%2 == 0? s.substr(s.size()/2,2) : s.substr(s.size()/2 -1,2);
}
int main(){
    string s = "abcde";
    cout<<solution(s)<<endl;
    return 0;
}