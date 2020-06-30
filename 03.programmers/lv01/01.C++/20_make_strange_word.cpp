#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    string tmp = "";
    int idx =0;
    for(int i=0; i<=s.size(); i++){
        if(s[i] == ' ' || s[i] == '\0'){
            if(s[i] == ' ')tmp+=' ';
            answer +=tmp;
            tmp = "";
            idx = 0;
        }
        else{
            tmp += idx%2 == 0?toupper(s[i]):tolower(s[i]);
            idx++;
        }
    }
    return answer;
}