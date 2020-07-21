#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string arrangement) {
    int answer = 0;
    vector<char> v;  //  stack
    for(int i=0; i<arrangement.size(); i++){
        char c = arrangement[i];
        if(c == '(') v.push_back(c);
        else {
            v.pop_back();
            if(arrangement[i-1]=='(')answer+=v.size();
            else answer++;
        }
    }
    return answer;
}
int main(){
    string s = "()(((()())(())()))(())";
    cout<<solution(s)<<endl;
    return 0;
}