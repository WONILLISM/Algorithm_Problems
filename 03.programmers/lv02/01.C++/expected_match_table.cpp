#include <iostream>

using namespace std;

int solution(int n, int a, int b){
    int answer =0;
    a--,b--;
    while(a!=b){
        a = a>>1 == 0? 0: a>>1;
        b = b>>1 == 0? 0: b>>1;
        answer++;
    }
    return answer;
}
int main(){
    cout<<solution(8,4,7);
    return 0;
}