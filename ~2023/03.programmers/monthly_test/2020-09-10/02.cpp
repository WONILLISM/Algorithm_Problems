/*
문제 설명
정수 n이 매개변수로 주어집니다. 다음 그림과 같이 밑변의 길이와 높이가 n인 삼각형에서 맨 위 꼭짓점부터 반시계 방향으로 달팽이 채우기를 진행한 후, 첫 행부터 마지막 행까지 모두 순서대로 합친 새로운 배열을 return 하도록 solution 함수를 완성해주세요.


제한사항
n은 1 이상 1,000 이하입니다.
입출력 예
n	result
4	[1,2,9,3,10,8,4,5,6,7]
5	[1,2,12,3,13,11,4,14,15,10,5,6,7,8,9]
6	[1,2,15,3,16,14,4,17,21,13,5,18,19,20,12,6,7,8,9,10,11]
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 4 3 2 1
// 0
// 1  2
// 3  4  5
// 6  7  8  9
// 10 11 12 13 14
// 15 16 17 18 19 20
// 1
// 2  9
// 3 10 8
// 4 5 6 7
vector<int> solution(int n)
{
	vector<int> answer;
	vector<vector<int>> tmp;
	int total_size = n * (n + 1) / 2;
	for (int i = 0; i < n; i++)
	{
		tmp.push_back(vector<int>());
		for (int j = 0; j < i + 1; j++)
		{
			tmp[i].push_back(0);
		}
	}
	int row = 0;
	int col = 0;
	int m = n;
	int num = 1;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmp[row][col] = num++;
			if (cnt % 3 == 0)
				row++;
			if (cnt % 3 == 1)
				col++;
			if (cnt % 3 == 2)
				row--, col--;
		}
		if (cnt % 3 == 0)
			row--,col++;
		if (cnt % 3 == 1)
			col-=2, row--;
		if (cnt % 3 == 2)
			row+=2, col++;
		cnt++;
		m--;
	}
	for(auto a : tmp)
		for(auto b : a)
			answer.push_back(b);
	return answer;
}
int main()
{
	for (auto ans : solution(5))
		cout << ans << endl;
	return 0;
}