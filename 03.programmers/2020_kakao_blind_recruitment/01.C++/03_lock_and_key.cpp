#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rot_key;
void rotate_key(){
    int m = rot_key.size();
    vector<vector<int>> tmp(m, vector<int>(m, 0));
    for (int i = 0; i < m; i++){
        for (int j = 0; j <m; j++){
            tmp[j][m - i - 1] = rot_key[i][j];
        }
    }
    rot_key = tmp;    
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int key_size = key.size();
    int lock_size = lock.size();
    int cnt_l = 0;

    rot_key = key;
    for (int i = 0; i < lock_size; i++)
        for (int j = 0; j < lock_size; j++)
            if (lock[i][j] == 0)
                cnt_l++;
    for (int r = 0; r < 4; r++){
        for (int i = -key_size + 1; i < lock_size; i++ ){
            for (int j = -key_size + 1; j < lock_size; j++ ){
                int cnt_k = 0, is_unlock = 0;
                for (int y = 0; y < key_size; y++){
                    for(int x = 0; x < key_size; x++){
                        int ly = i + y, lx = j + x;
                        if (ly >= 0 && ly < lock_size && lx >= 0 && lx < lock_size){
                            if (lock[ly][lx] == 1 && rot_key[y][x] == 1) is_unlock = 1;
                            else if (lock[ly][lx] == 0 && rot_key[y][x] == 1) cnt_k++;
                        }
                    }
                }
                if (cnt_k == cnt_l && is_unlock == 0) return true;
            }
        }
        rotate_key();
    }
    return false;
}
int main(){
    vector<vector<int>> key = 	{
        {0, 0, 0}, 
        {1, 0, 0}, 
        {0, 1, 1}
    };
    vector<vector<int>> lock = {
        {1, 1, 1}, 
        {1, 1, 0}, 
        {1, 0, 1}
    };

    cout<<solution(key, lock)<<endl;
    return 0;
}