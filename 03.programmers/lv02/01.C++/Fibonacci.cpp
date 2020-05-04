#include<iostream>
#include <string>
#include <vector>

using namespace std;
const int MAX = 100001;
const int MOD = 1234567;
int dp[MAX];
int solution(int n) {
    if(n==0)return dp[n] = 0;
    if(n==1)return dp[n] = 1;
    if(dp[n])return dp[n];
    else{
        dp[n] = (solution(n-1) + solution(n-2))%MOD;
        return dp[n];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 3;
    cout<<solution(n)<<endl;
}