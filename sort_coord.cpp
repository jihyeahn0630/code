#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

struct coord{
	int x;
	int y;
};

bool comp(const coord &a, const coord &b){
	
	if(a.x == b.x){
		return a.y < b.y;
	}else if(a.x < b.x)
		return true;
	else
		return false;
		
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	
	int n;
	
	cin >> n;
  vector<coord> num(n);
	
	for(int i=0; i<n; i++){
		cin >> num[i].x >> num[i].y;	
	}
	
  sort(num.begin(),num.end(),comp);
	
	for(int i=0; i<n; i++){
		cout << num[i].x << " " << num[i].y <<'\n'; // 'endl' is time consuming.
	}
	
	return 0;
	
}
