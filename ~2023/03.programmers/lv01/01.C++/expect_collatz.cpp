#include <string>
#include <vector>
#define ll long long

using namespace std;

int solution(int num) {
    int answer = 0;
    ll n = num;
    while(n>1){
        n = n%2 == 0? n/2:n*3 +1;
        answer++;
        if(answer>=500) return -1;
    }
    return answer;
}