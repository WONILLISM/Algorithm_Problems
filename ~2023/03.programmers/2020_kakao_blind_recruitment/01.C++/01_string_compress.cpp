#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = s.size();
    int len = 1;    // 자를 길이
    while(len <= s.size() / 2){
        int tmp = 0;    // 현재 탐색중인 문자열의 길이
        string cur = s.substr(0,len);// 현재 기준 문자열
        int l = len, cnt = 1;
        while(1){
            if(cur == s.substr(l,len))cnt++;
            else{
                if(cnt==1)tmp+=len;
                else tmp += to_string(cnt).size() + len;
                cur = s.substr(l,len);
                cnt = 1;
            }
            if(l+len>=s.size()){
                if(cnt==1)tmp+=s.size() - l;
                else tmp += to_string(cnt).size() + s.size() - l;
                break;
            }
            l+=len;
        }
        answer = min(answer, tmp);
        len++;
    }
    return answer;
}
int main(){
    /*
    2a2ba4c 7
    aabbacccc 9 
    aabbacccc 9 
    aabbacccc 9

    */
    string s = "aabbacccc";
    cout<<solution(s)<<endl;
    return 0;
}








// #include<iostream>
// #include <string>
// #include <vector>
// #include <queue>
// #include<algorithm>

// using namespace std;

// int solution(string s) {
// 	int answer = s.size();
// 	cout << s << endl << endl;
// 	for (int len = 1; len < s.size(); len++) {	//스플릿 길이
// 		int res = 0;
// 		string test;
// 		queue<pair<string, int>> q;
// 		q.push({ s.substr(0, len),0 });
// 		while (!q.empty()) {
// 			string cur = q.front().first;
// 			int idx = q.front().second;
// 			q.pop();
// 			int cnt = 0;
// 			for (int i = idx; i < s.size(); i += cur.size()) {
// 				string tmp = s.substr(i, cur.size());
// 				if (cur != tmp) {
// 					q.push({ tmp,i });
// 					break;
// 				}
// 				else {
// 					cnt++;
// 				}
// 			}
// 			if (cnt > 1) res += to_string(cnt).size();
// 			test += cur;
			
// 			res += cur.size();
// 		}
// 		answer = min(res, answer);
// 	}
// 	return answer;
// }