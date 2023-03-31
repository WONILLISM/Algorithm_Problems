#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#define endl '\n'
using namespace std;

class Member{
public:
	int idx;
	int age;
	string name;

	Member() : idx(0), age(0), name(""){}
	~Member(){}
	bool operator <(Member &m){
		if (this->age == m.age)
			return this->idx < m.idx;
		return this->age < m.age;
	}
	
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<Member> member_vec;
	int n,i = 0;
	cin>>n;
	while(n--){
		Member a;
		cin >> a.age >> a.name;
		a.idx = i;
		member_vec.push_back(a);
		i++;
	}
	sort(member_vec.begin(), member_vec.end());
	for (auto mem : member_vec)
		cout<<mem.age<<" "<<mem.name<<endl;
	return 0;
}