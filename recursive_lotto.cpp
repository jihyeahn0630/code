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
vector<int> lotto;

void solve(vector<int>& arr, int idx, int cnt){
	if(cnt ==6){
		for(int num : lotto){
			printf("%d ",num);
		}
		cout << endl;
		return;
	}
	
	int n = arr.size();
	if(idx == n)
		return;
    
     lotto.push_back(arr[idx]);
     solve(arr, idx+1, cnt+1);
	
     lotto.pop_back();
	 solve(arr, idx+1, cnt);

}



int main() {
	   
    while(true){
		int n;
      
		cin >> n;
        if(n==0)
            break;
        
		vector<int> v(n);
			
		for(int i=0; i<n; i++){
            cin >> v[i];			
        }
		
		solve(v,0,0);
		cout << endl;
	}
	
	return 0;
}
