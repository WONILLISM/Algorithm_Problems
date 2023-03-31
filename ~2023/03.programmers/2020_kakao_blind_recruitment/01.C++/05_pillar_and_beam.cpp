#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Pos{
	bool pillar, beam;
}Pos;
Pos Map[101][101];

bool chk_pillar(int y, int x){
	bool ret = false;
	if (y == 0) ret = true;
	else {
		if (Map[y][x].beam) ret = true;		//보가 있으면
		if (Map[y][x - 1].beam) ret =true;  // 왼쪽에 보가 있으면
		if (Map[y - 1][x].pillar) ret = true; // 아래에 기둥이 있으면
	}
	return ret;
}

bool chk_beam(int y, int x, int n){
	bool ret = false;
	if (Map[y - 1][x].pillar) ret = true;					// 아래쪽에 기둥이 있으면
	if (x < n && Map[y - 1][x + 1].pillar) ret = true;		// 오른쪽에 기둥이 있으면
	if (x > 0 && x < n && Map[y][x - 1].beam && Map[y][x + 1].beam) ret = true;// 양 옆에 기둥이 있으면
	return ret;
}


void is_valid_struct(int y, int x, int n, int q){
	for (int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if (Map[i][j].pillar){
				if(!chk_pillar(i,j)){
					if (q) Map[y][x].beam = true;
					else Map[y][x].pillar = true;
					break;
				}
			}
			if (Map[i][j].beam){
				if (!chk_beam(i, j, n)){
					if (q) Map[y][x].beam = true;
					else Map[y][x].pillar = true;
					break;
				}
			}
		}
	}
}
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	for (auto cmd : build_frame){
		int x = cmd[0], y = cmd[1];
		int pillar_or_beam = cmd[2];
		int rm_and_add = cmd[3];

		if (rm_and_add){	// 설치
			if (pillar_or_beam){	// 보
				if (y > 0 && chk_beam(y, x, n)){
					Map[y][x].beam = true;
				}
			}
			else{	// 기둥
				if(chk_pillar(y, x)){
					Map[y][x].pillar = true;
				}
			}
		}
		else{	// 삭제
			if (pillar_or_beam){ //보
				Map[y][x].beam = false;
				is_valid_struct(y, x, n, pillar_or_beam);
			}
			else{
				Map[y][x].pillar = false;
				is_valid_struct(y, x, n, pillar_or_beam);
			}
		}
	}
	for (int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			if (Map[j][i].pillar)answer.push_back({i, j, 0});
			if (Map[j][i].beam)answer.push_back({i, j, 1});
		}
	}
	return answer;
}

int main(){
	int n = 5;
	vector<vector<int>> answer;
	// x, y, a, b
	// (좌표), 구조물 종류(0 기둥, 1 보), (0 삭제, 1 설치)
	vector<vector<int>> build_frame = {
		{0, 0, 0, 1}, 
		{2, 0, 0, 1}, 
		{4, 0, 0, 1}, 
		{0, 1, 1, 1}, 
		{1, 1, 1, 1}, 
		{2, 1, 1, 1}, 
		{3, 1, 1, 1}, 
		{2, 0, 0, 0}, 
		{1, 1, 1, 0}, 
		{2, 2, 0, 1}
	};
	answer = solution(n, build_frame);
	for(auto raw : answer){
		for (auto col : raw){
			cout << col << " ";
		}
		cout << endl;
	}

	return 0;
}