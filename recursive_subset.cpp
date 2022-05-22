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
int sum;
int arr[20];
int total=0;

void solve(int idx, int s){
	
	 if(idx == n){
         if(s==sum){
		     total++;
         }
		 return;
	 }

    solve(idx+1, s + arr[idx]);
	solve(idx+1, s);

}



int main() {
	   
    
    	cin >> n;
	    cin >> sum;
    
		for(int i=0; i<n; i++){
        cin >> arr[i];			
     }
		
	  
	  solve(0,0);
    
	  if(sum == 0)
          total--;
    
      cout << total << endl;

	
	return 0;
}
