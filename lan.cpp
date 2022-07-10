#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;


long long getMax(long long a, long long b){
	if(a>b)
		return a;
	else
		return b;
}


int main() {
//  ios_base::sync_with_stdio(false);
//  cin.tie(nullptr);
	
	int n,k;
	
	cin >> n >> k;
    vector<long long> lan(n);
	
	for(int i=0; i<n; i++){
		cin >> lan[i];
	}
	
	sort(lan.begin(),lan.end());
	
	long long maxV = lan[n-1];
	long long minV = 0;
	
	while(minV < maxV){
		long long mid = (minV + 1 + maxV)/2;
		long long sum = 0;
		
		for(int i=0; i<n; i++){
			sum += getMax(lan[i]/mid,0);
		}
		
		if(sum < k)
			maxV = mid -1;
		else
			minV = mid;
		
	}
	
	
	
	cout << minV << endl;
	
	
	return 0;
	
}
