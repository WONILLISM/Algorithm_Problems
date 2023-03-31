#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dy[] = {0,1,0,-1};
int dx[] = {1,0,-1,0};
//회전하면서 지나치는 곳  우상, 우하, 좌하, 좌상
int ndy[] = { -1,1,1,-1 };
int ndx[] = { 1,1,-1,-1 };
struct POS {int x,y,d,t;};  //  좌표, 진행 방향, 시간

int visit[100][100][4];
int n;
bool isRange(int x1,int y1,int x2,int y2){
    return (x1>=0&&x1<n&&y1>=0&&y1<n) && (x2>=0&&x2<n&&y2>=0&&y2<n);
}

int solution(vector<vector<int>> board) {
    queue<POS> q;
    q.push({0,0,0,0});

    n = board.size();
    int cnt =0;

    while(!q.empty()){
        POS cur = q.front(); q.pop();

        // 나머지 한 칸
        int ay = cur.y +dy[cur.d], ax = cur.x + dx[cur.d];

        // 둘 중 한 칸이라도 도착하면 종료
        if((cur.y==n-1&&cur.x==n-1)||(ay==n-1&&ax==n-1)) return cur.t;

        int ny,nx,nay,nax;  //다음 좌표
        
        // 이동
        for(int d = 0; d < 4; d++){
            ny = cur.y +dy[d], nx = cur.x+dx[d];
            nay = ay +dy[d], nax = ax +dx[d];

            if(isRange(nx,ny,nax,nay) && !visit[ny][nx][cur.d]){ // 방문하지 않았고 범위 체크
                if(!board[ny][nx] && !board[nay][nax]){
                    visit[ny][nx][cur.d] = 1;
                    q.push({ny,nx,cur.d,cur.t +1});
                }
            }
        }
        
        // (x,y) 기준으로 90도 회전  
        for(int d =1; d < 4; d+=2){
            int nd = (cur.d + d)%4; //하
            nay = ay + dy[nd], nax = ax +dx[nd];
            int ry,rx;
            if(d==1){   // 시계방향
                ry = cur.y + ndy[nd];
                rx = cur.x + ndx[nd];
            }
            else{   // 반시계방향
                ry = cur.y + ndy[cur.d];
                rx = cur.x + ndx[cur.d];
            }
            if(isRange(rx,ry,nax,nay) && !visit[cur.y][cur.x][nd]){ // 방문하지 않았고 범위 체크
                if(!board[ry][rx] && !board[nay][nax]){
                    visit[cur.y][cur.x][nd] = 1;
                    q.push({cur.y,cur.x,nd,cur.t +1});
                }
            }
        }
        // 우 하 좌 상
        // (ax,ay) 기준으로 90도 회전 (우상, 우하, 좌하, 좌상)
        int dir = (cur.d + 2)%4;  // 축의 변경으로 인해 방향 바뀜 // 좌
        for(int d =1; d < 4; d+=2){
            int nd = (dir + d)%4;   //상, 하
            nay = ay +dy[nd], nax = ax +dx[nd];
            int ry,rx;
            if(d==1){   // 시계방향
                ry = ay + ndy[nd];
                rx = ax + ndx[nd];
            }
            else{   // 반시계방향
                ry = ay + ndy[dir];
                rx = ax + ndx[dir];
            }
            if(isRange(rx,ry,nax,nay) && !visit[ay][ax][(nd+2)%4]){ // 방문하지 않았고 범위 체크
                if(!board[ry][rx] && !board[nay][nax]){
                    visit[ay][ax][nd] = 1;
                    q.push({ay,ax,nd,cur.t +1});
                }
            }
        }
    }
}
int main(){
    vector<vector<int>> board = {
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}};
    cout<<solution(board)<<endl;
    return 0;
}