#include<set>
#include<map>
#include<cassert>
#include<vector>
#include<cstdio>
#include<cstring>
#include<memory>
#include<algorithm>
#include<string>
#include<queue>
#include<iostream>

using namespace std;

int n;
int minV = 1000000001;
int maxV = -1000000001;

void solve(vector<int>& arr, int idx, int cur, int pl, int mi, int mul, int di){

	if(idx == n){
		if(cur < minV)
			minV = cur;
		if(cur > maxV)
			maxV = cur;
	
		return;
	}

	if(pl > 0)
		 solve(arr, idx+1, cur+arr[idx], pl-1,mi,mul,di);
	if(mi > 0)
		solve(arr, idx+1, cur-arr[idx], pl,mi-1,mul,di);
	if(mul > 0)
		solve(arr, idx+1, cur*arr[idx], pl,mi,mul-1,di);
	if(di > 0)
		solve(arr, idx+1, cur/arr[idx], pl,mi,mul,di-1);

  
}

int main() {
	   
  int plus, minus,multi,div;
	
	cin >> n;
        
	vector<int> v(n);
			
	for(int i=0; i<n; i++){
            cin >> v[i];			
  }
	
  cin >> plus >> minus >> multi >> div;
	
	solve(v,1,v[0], plus, minus, multi, div);
	
	cout << maxV << endl;
	cout << minV << endl;
	
	
	return 0;
}
