#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    int len = s.size();
    if(len==4||len ==6)
        for(int i=0; i<s.size(); i++)
            if(s[i]>=95) return false;
    else return false;
    return true;
}