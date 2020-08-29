#include<iostream>
#include <string>
#include <vector>

using namespace std;

int pos;
bool process(string str) {
    bool chk = true;
    int l = 0, r = 0;
    vector<char> v;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') {
            l++;
            v.push_back(str[i]);
        }
        else {
            r++;
            if (v.empty())chk = false;
            else v.pop_back();
        }

        if (l == r) {
            pos = i + 1;//v위치
            return chk;
        }
    }
    return true;
}
string solution(string p) {
    /* 1 */
    if (p.empty())return p;
    string answer = "";

    /* 2 */
    bool correct = process(p);
    string u = p.substr(0, pos);
    string v = p.substr(pos, p.size() - pos);

    /* 3 */
    if (correct) {
        return u + solution(v);
    }

    /* 4 */
    answer = '(' + solution(v) + ')';
    for (int i = 1; i < u.size() - 1; i++) {
        if (u[i] == '(')answer += ")";
        else answer += "(";
    }
    return answer;
}