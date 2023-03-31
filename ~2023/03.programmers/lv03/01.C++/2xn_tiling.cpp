#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int mod = 1000000007;
int dp[60001];
int solution(int n) {
    if (n <= 2) return n;
    if (dp[n]) return dp[n];
    dp[n] = (solution(n - 1) + solution(n - 2))%mod;
    return dp[n];
}
int main(){
    cout << solution(4) << endl;
    return 0;
}