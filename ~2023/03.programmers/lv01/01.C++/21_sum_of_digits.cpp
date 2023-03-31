#include <iostream>

using namespace std;

int process(int sum, int n){
	if(n==0) return sum;
	return process(sum + n%10, n/10);
}
int solution(int n){
    return process(0,n);
}
// int solution(int n){
// 	   if(n==0)return 0;
//     return n%10 + solution(n/10);
// }
// int solution(int n){
//     int answer = 0;
// 	string s = to_string(n);
// 	for (int i = 0; i < s.length(); i++)
// 		answer += s[i] - '0';
//     return answer;
// }