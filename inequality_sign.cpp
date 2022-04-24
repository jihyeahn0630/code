#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


bool check(vector<int> &num, vector<char> &a){
    for(long unsigned int i=0; i<a.size() ;i++){
        if(a[i]=='<'&& num[i] > num[i+1]){
            return false;
        }
        if(a[i]=='>'&& num[i] < num[i+1]){
            return false;
        }
    }
    
    return true;
}

int main(){
    int k;
    cin >> k;
    vector<char> a(k);
    for(int i=0; i<k; i++){
        cin >> a[i];
    }
    
    vector<int> big(k+1);
    vector<int> small(k+1);
    
    for(int i=0; i<k+1; i++){
        big[i]=9-i;
        small[i]=i;
    }
    
    //find the smallest one
    do{
        if(check(small,a)){
            break;
        }
        
    }while(next_permutation(small.begin(), small.end()));
    
     //find the biggest one
    do{
        if(check(big,a)){
            break;
        }
        
    }while(prev_permutation(big.begin(), big.end()));
    
          
     for(long unsigned int i=0;i<big.size();i++)
          cout << big[i];
          
     cout << '\n';
     for(long unsigned int i=0;i<small.size();i++)
          cout << small[i];  
           
           
     return 0;
}
