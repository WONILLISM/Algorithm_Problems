#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    int i = 10;
    while(n){
        answer.push_back(n%i);
        n /=i;
    }
    return answer;
}