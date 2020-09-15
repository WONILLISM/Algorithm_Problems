#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Pos
{
	int y, x, step, in;
} pos;
int cnt, n, ans = 32;
int dy[] = {0 ,-1, 0, 1};
int dx[] = {1, 0 ,-1, 0};
pos start;
vector<vector<int>> map;
vector<vector<int>> visit;

pos ctr_cursor(pos p, int d){
	pos cur = p;
	pos next;
	while (1){
		next.y = cur.y + dy[d], next.x = cur.x + dx[d];
		if (next.y >= 0 && next.y < n && next.x >= 0 && next.x < n){
			cur = next;
			if (map[next.y][next.x])
				return next;
		}
		else return cur;
	}
}
void process(pos cur, int count){
	if (cnt == count){
		ans = min(ans, cur.step);
		return ;
	}
	if (cur.step >= 32)
		return ;
	
	for (int d = 0; d < 4; d++){
		pos next;
		next.y = cur.y + dy[d], next.x = cur.x +dx[d];
		next.step = cur.step, next.in = cur.in;
		if (next.y >= 0 && next.y < n && next.x >= 0 && next.x < n && (visit[cur.y][cur.x] > visit[next.y][next.x])){
			pos next2 = ctr_cursor(cur, d);
			if (map[next.y][next.x]){
				if (cur.in == map[next.y][next.x]){
					visit[next.y][next.x] = visit[cur.y][cur.x];
					next.step = cur.step + 1;
					process(next, count + 2);
					next.step = cur.step;
					visit[next.y][next.x] = 0;

					visit[next2.y][next2.x] = visit[cur.y][cur.x];
					next2.step = cur.step + 1;
					process(next2, count + 2);
					next2.step = cur.step;
					visit[next2.y][next2.x] = 0;
				}
				else{
					if (cur.in){ 
						visit[next.y][next.x] = visit[cur.y][cur.x];
						next.step = cur.step + 1;
						process(next, count);
						next.step = cur.step;
						visit[next.y][next.x] = 0;

						visit[next2.y][next2.x] = visit[cur.y][cur.x];
						next2.step = cur.step + 1;
						process(next2, count);
						next2.step = cur.step;
						visit[next2.y][next2.x] = 0;
					}
					else{
						next.in = map[next.y][next.x];
						visit[next.y][next.x] = visit[cur.y][cur.x] + 1;
						next.step = cur.step + 1;
						process(next, count);
						next.step = cur.step;
						visit[next.y][next.x] = 0;

						next2.in = map[next2.y][next2.x];
						visit[next2.y][next2.x] = visit[cur.y][cur.x] + 1;
						next.step = cur.step + 1;
						process(next2, count);
						next2.step = cur.step;
						visit[next2.y][next2.x] = 0;
					}
				}
			}
			else{
				visit[next.y][next.x] = visit[cur.y][cur.x];
				next.step = cur.step + 1;
				process(next, count);
				next.step = cur.step;
				visit[next.y][next.x] = 0;

				if (next2.y != cur.y && next2.x != cur.x){
					visit[next2.y][next2.x] = visit[cur.y][cur.x];
					next2.step = cur.step + 1;
					process(next2, count);
					next2.step = cur.step;
					visit[next2.y][next2.x] = 0;
				}
			}
		}
	}
}
int solution(vector<vector<int>> board, int r, int c)
{
	map = board;
	n = board.size();
	for (auto row : board){
		for(auto col : row){
			if (col)cnt++;
		}
	}
	visit[r][c] = 1;
	pos start = {r,c,0,0};
	process(start, 0);
	return ans;
}
int main()
{
	vector<vector<int>> board = {
		{1, 0, 0, 3},
		{2, 0, 0, 0},
		{0, 0, 0, 2},
		{3, 0, 1, 0}};
	visit.assign(board.size(), vector<int>(board[0].size(), 0));
	int r = 1;
	int c = 0;
	cout << solution(board, r, c);
	return 0;
}