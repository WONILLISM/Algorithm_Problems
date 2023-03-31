#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int visit[30][30];

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	bool chk = false;
	while (!chk) {
        fill(&visit[0][0],&visit[n-1][m],0);
		chk = true;
		for (int i = 0; i < m - 1;i++) {
			for (int j = 0; j < n - 1; j++) {
				if (board[i][j]){
                    if ((board[i][j] == board[i][j + 1])&& (board[i][j]== board[i + 1][j])&&(board[i][j]== board[i + 1][j + 1])) {
                        visit[i][j] = 1;
                        visit[i][j+1] = 1;
                        visit[i+1][j] = 1;
                        visit[i + 1][j + 1] = 1;
                        chk = false;
                    }
                }
			}
		}

		for (int i = 0; i < m; i++) {	//제거
			for (int j = 0; j < n; j++) {
				if (visit[i][j]) {
					answer++;
					for (int k = i-1; k >=0; k--) {
						board[k + 1][j] = board[k][j];
						board[k][j] = 0;
					}
				}
			}
        }
	}

	return answer;
}
int main()
{
    int m = 4, n = 5;
    vector<string> board = {
        "CCBDE",
        "AAADE",
        "AAABF",
        "CCBBF"};
    cout << solution(m, n, board) << endl;
    return 0;
}