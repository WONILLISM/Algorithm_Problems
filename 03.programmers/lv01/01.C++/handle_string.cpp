#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    bool answer = true;
    int len = s.size();
    if(len==4||len ==6){
        for(int i=0; i<s.size(); i++){
            if(s[i]>=95) {
                answer=false;
                break;         
            }
        }
    }
    else{ 
        answer =false;
    }
    return answer;
}