#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n,m;

int count(int mask, vector<int> &words){
    int cnt=0;
    
    for(int word : words){
       if((word & ((1<<26)-1 - mask)) == 0)
         cnt++;
    }
    
    
    return cnt;
}

int solve(int idx, int k, int mask, vector<int> &words){
    int ans=-1;
    if(k<0)
        return 0;
    
    if(idx == 26){
		
        return count(mask, words);
    }
    
  // 	cout << mask << endl;
    int tmp = solve(idx+1, k-1, mask | (1<<idx),words);
    if(tmp>ans)
        ans=tmp;
    
    
    if(idx != 'a'-'a'&& idx!='n'-'a'&& idx!='t'-'a' && idx !='i'-'a' && idx !='c'-'a'){
        tmp = solve(idx+1, k, mask, words);
        if(tmp>ans)
        ans=tmp;
    }
        
    return ans;
}
