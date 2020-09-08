#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAX_INT = 2147483647;
vector<bool> visit;
vector<int> g_weak;
vector<int> g_dist;
int answer = MAX_INT;
int weak_size;
void process(vector<int> res){
	for (int i = 0; i < weak_size; i++){
		int end = g_weak[i];
		int idx = 0;
		bool chk = false;
		for (int j = i; j < i + weak_size; j++){
			if (g_weak[j] - end > res[idx]){
				end = g_weak[j];
				idx++;
				if (idx == res.size()){
					chk = true;
					break;
				}
			}
		}
		if (!chk)answer = min(answer, idx + 1);
	}
}

void dist_permute(int j, int cnt, vector<int> res){
	if (cnt == g_dist.size()){
		process(res);
		return ;
	}
	for (int i = 0; i < g_dist.size(); i++){
		if (!visit[i]){
			visit[i] = true;
			res.push_back(g_dist[i]);
			dist_permute(i, cnt + 1, res);
			res.pop_back();
			visit[i] = false;
		}
	}
}

int solution(int n, vector<int> weak, vector<int> dist) {
	g_weak = weak;
	g_dist = dist;
	weak_size = weak.size();
	vector<int> res;
	visit.assign(dist.size(), false);
	for (int i = 0; i < weak_size; i++)
		g_weak.push_back(weak[i] + n);

	dist_permute(0,0, res);
	if (answer == MAX_INT) return -1;
	return answer;
}
int main(){
	// vector<int> weak = {1,5,6,10};
	vector<int> weak = {1,3,4,9,10};
	// vector<int> dist = {1,2,3,4};
	vector<int> dist = {3,5,7};
	int n = 12;
	cout << solution(n, weak, dist) << endl;
	return 0;
}