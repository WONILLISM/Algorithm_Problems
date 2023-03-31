#include <iostream>
#include <vector>
#define ll long long
using namespace std;

const int MOD = 1234567;
typedef vector<vector<ll>> matrix;

matrix operator*(matrix &a, matrix &b){
    int n = a.size();
    matrix c(n, vector<ll>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= MOD;
        }
    }
    return c;
}
ll solution(int n){
    matrix res = {{1, 0}, {0, 1}};
    matrix fib = {{1, 1}, {1, 0}};
    while (n){
        if (n % 2 == 1)
            res = res * fib;
        fib = fib * fib;
        n >>= 1;
    }
    return res[0][1];
}
// #include<iostream>
// #include <string>
// #include <vector>

// using namespace std;
// const int MAX = 100001;
// const int MOD = 1234567;
// int dp[MAX];
// int solution(int n) {
//     if(n<=1)return dp[n] = n;
//     if(dp[n])return dp[n];
//     dp[n] = (solution(n-1) + solution(n-2))%MOD;
//     return dp[n];
// }
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n = 3;
    cout << solution(n) << endl;
}