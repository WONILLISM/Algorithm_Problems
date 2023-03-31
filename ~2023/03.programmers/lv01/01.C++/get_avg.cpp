#include <iostream>
#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for(auto a: arr) answer+=a;
    return answer/arr.size();
}
int main(){
    cout<<solution({1,2,3,4})<<endl;
    return 0;
}