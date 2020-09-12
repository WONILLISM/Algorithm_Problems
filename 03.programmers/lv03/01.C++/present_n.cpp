#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1 <= N <= 9
// 1 <= number <= 32000
// 12 = 5 + 5 + (5 / 5) + (5 / 5)
// 12 = 55 / 5 + 5 / 5
// 12 = (55 + 5) / 5

int answer = 9;
int g_N;
int g_number;

void process(int sum, int cnt){
    if (cnt >=9) return ;
    if (sum == g_number){
        answer = min(answer, cnt);
        return ;
    }

    for (int i = 1; i <= 8; i++){
        int next = 0;
        for (int j = 0; j<i; j++)
            next = next * 10 + g_N;
        
        process(sum + next, cnt + i);
        process(sum - next, cnt + i);
        process(sum * next, cnt + i);
        process(sum / next, cnt + i);
    }
}
int solution(int N, int number) {
    g_N = N;
    g_number = number;

    process(0, 0);
    if (answer == 9)
        return -1;
    return answer;
}

int main(){
    int n = 5;
    int number = 12;
    cout<<solution(n, number)<<endl;
    return 0;
}