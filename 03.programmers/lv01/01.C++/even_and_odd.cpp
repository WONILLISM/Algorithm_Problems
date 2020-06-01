#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int num) {
    return num%2 == 0?"Even":"Odd";
}
int main(){
    cout<<solution(3)<<endl;
    return 0;
}