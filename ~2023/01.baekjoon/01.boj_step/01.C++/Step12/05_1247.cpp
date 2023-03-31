#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int n;
	string s;
	cin >> n;
	s = to_string(n);
	sort(s.begin(), s.end(), greater<char>());
	cout << stoi(s) << endl;
	return 0;
}