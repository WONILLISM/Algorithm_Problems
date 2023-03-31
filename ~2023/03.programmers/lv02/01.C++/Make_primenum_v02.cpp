#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

int answer;
bool chk_prime(int x){
	for(int i=2; i*i<=x; i++)
		if(x%i==0)return false;
	return true;
}
void process(vector<int> &nums,vector<bool> &chk, int i, int cnt, int sum){
	if(cnt>3)return;
	if(cnt == 3){
		if(chk_prime(sum))
			answer++;
		return;
	}
	for(int j =i; j<chk.size(); j++){
		if(!chk[j]){
			chk[j] =true;
			process(nums,chk, j, cnt+1 , sum + nums[j]);
			chk[j] = false;
		}
	}
}
int solution(vector<int> nums) {
	int n = nums.size();
	vector<bool> chk(n);
	process(nums,chk,0,0,0);

	return answer;
}
int main(){
    cout<<solution({1,2,7,6,4});
    return 0;
}