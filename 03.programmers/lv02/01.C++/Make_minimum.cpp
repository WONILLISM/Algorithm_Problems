#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B){
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int size = B.size();
    for(int i=0; i<A.size(); i++){
        answer += A[i]*B[size -1 -i];
    }
    return answer;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> a, b;
    a = {1,4,2};
    b = {3,4};
    // a = {1,2};
    // b = {3,4};
    cout<<solution(a,b)<<endl;
}