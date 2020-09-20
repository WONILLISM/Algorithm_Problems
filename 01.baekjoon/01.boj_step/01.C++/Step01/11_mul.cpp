#include <iostream>
#include <string>

#define endl '\n'
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	cin >> a >> b;
	cout << (a * (b%10)) << endl << (a * ((b/10)%10)) << endl << (a * (b/100)) << endl << a*b<<endl;
	return 0;
}