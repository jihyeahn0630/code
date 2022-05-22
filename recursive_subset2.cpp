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
int sum=0;
int total=0;
int visit[2000010];


void solve(vector<int>& arr, int idx, int s){

	 if(idx == n+1){
		 return;
	 }
	
	visit[s] = 1;

  solve(arr, idx+1, s + arr[idx]);
	solve(arr, idx+1, s);

}



int main() {
	  int flag=0; 
	  cin >> n;
	  vector<int> arr(n);
    
	for(int i=0; i<n; i++){
				cin >> arr[i];
				sum += arr[i];
     }
		
	   sort(arr.begin(), arr.end());
	
		 solve(arr, 0,0);
	
	 	for(int i=1; i<=sum; i++){
			if(visit[i]==0){
				cout << i <<endl;
                flag = 1;
				break;
			}
		}
  
    	if(flag==0)
		cout << sum+1 <<endl;
    
	return 0;
}
