#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

long long solution(long long n) {
    long long answer = sqrt(n);
    if(answer*answer == n)return (answer+1)*(answer+1);
    else return -1;
}
int main(){
    cout<<solution(121)<<endl;
    return 0;
}