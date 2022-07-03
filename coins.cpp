#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


int main() {

	int n,k;
	
	cin >> n >> k;
	
	vector<int> v(n);
	vector<int> cnt(n);
	
	for(int i=0; i<n; i++){
		cin >> v[i];	
	}
	
	int m;
  for(int i=n-1; i>=0;i--){
		if(k / v[i] != 0){
			cnt[i]=k/v[i];
			k=k-cnt[i]*v[i];
		}
		else{
			cnt[i]=0;
		}
	}
	int sum=0;
	for(int i =0; i<n; i++)
		sum += cnt[i];
	
	cout << sum << endl;
	
	return 0;
	
}
