#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct meeting{
	int start;
	int end;
};
//end-ascending order 
bool comp(const meeting &u, const meeting &v){
	if(u.end == v.end){
		return u.start < v.start;
	}
	else{
		return u.end < v.end; 
	}
}


int main() {

	int n,k;
	
	cin >> n;
	
	vector<meeting> v(n);
	
	for(int i=0; i<n; i++){
		cin >> v[i].start >> v[i].end;	
	}
	
	sort(v.begin(), v.end(),comp);
	
	int cnt=0;
	long long last = -9999;
	for(int i=0; i < n ;i++){

		if(v[i].start >= last){
			cnt++;
			last = v[i].end;
		}
		
	}

	cout << cnt << endl;
	
	return 0;
	
}
