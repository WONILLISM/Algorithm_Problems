#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    for(int len = 1; len <= s.size() / 2; len++){
        int tmp = 0;
        string cur = s.substr(0, len);
        int l = len, cnt = 1;
        while (1){
            if (cur == s.substr(l, len))cnt++;
            else{
                if (cnt == 1)tmp += len;
                else tmp += to_string(cnt).size() + len;
                cur = s.substr(l, len);
                cnt = 1;
            }
            if (l + len >= s.size()){
                if(cnt == 1) tmp += s.size() - l;
                else tmp += to_string(cnt).size() + s.size() - l;
                break;
            }
            l += len;
        }
        answer = min(answer, tmp);
    }
    return answer;
}
int main(){
    string s;
    s = "aabbaccc";
    cout << solution(s) << endl;
    return 0;
}