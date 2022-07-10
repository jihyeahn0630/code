#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string>
using namespace std;

int n,k;
/*
1~9 → (9-1+1) × 1
10~99 → (99-10+1) × 2
100~120 → (120-100+1) × 3
*/

long long find_len(int n){
	long long num=0;
	
	for(int start=1, len=1; start<=n; start*=10, len++){
		int end = start*10-1;
		if(end > n){
			end = n;
		}
		
		num += (end-start +1)*len;
	}
	
	return num;
}


int main() {
  
	int sol;
	 
	cin >> n >> k;
  
	long long ck = find_len(n);
	if(ck < k){
		cout<< -1 <<endl;
	     return 0;   
    }
	int start = 1;
	int end = n;
	
	while(start <= end){
		int mid = (start+end)/2;
		
		long long tmp = find_len(mid);
		
		if(tmp < k){
			start = mid+1;
		}else{
			sol = mid;
			end = mid-1; 
		}
		
	}
  //sol : 16
   string sol_str = to_string(sol);
	long long leng = find_len(sol);
	
	cout << sol_str[sol_str.length() - (leng-k) - 1] << endl;
	
	return 0;
	
}
