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


int solve(vector<int>& v){
	int energy;
	int nsize = v.size();
	int maxS=-1;
	
	if(nsize == 2)
		return 0;
	
	for(int i=1 ; i < nsize-1; i++){
		energy = v[i-1]*v[i+1];
		
		vector<int> b(v);
		b.erase(b.begin()+i);
		
		energy += solve(b);
		if(energy > maxS)
			maxS = energy;
	}

	return maxS;
}



int main() {
  int n;
	cin >> n ;
	vector<int> v(n);
	
	for(int i=0; i<n; i++){
		cin >> v[i];
  }

	cout << solve(v) <<endl;
	
	
	return 0;
}
