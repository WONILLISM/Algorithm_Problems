#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#define endl '\n';
#define ll long long
using namespace std;

void solution_1002() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int x1, y1, d1, x2, y2, d2;
		scanf("%d%d%d", &x1, &y1, &d1);
		scanf("%d%d%d", &x2, &y2, &d2);
		int d = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
		int sum = (d1 + d2)*(d1 + d2);	//�� �Ÿ��� ��
		int dif = (d1 - d2)*(d1 - d2);  //�� �Ÿ��� ��
		
		//�� ���� �߽��� ��ġ�� ��
		if (d == 0) {
			if (dif == 0) printf("-1\n"); //�� ���� ��ġ�� ��
			else printf("0\n"); //�� ���� ��ġ���� ���� ��
		}
		else if (d == sum || d == dif)printf("1\n");  //������ ��, ������ ��
		else if (dif < d&&d < sum) printf("2\n");  //�� ������ ���� ��
		else printf("0\n");  //������ ���� ��
	}
}
int main() {
	solution_1002();
	return 0;
}