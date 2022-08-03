#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> d(n, -1);
  
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
	  d[0]=0;
	
	 	for(int i=1; i<n; i++){
			for(int j=0; j<i; j++){
				if(d[j] !=-1 && i-j <=a[j]){
					if(d[i] == -1 || d[i] > d[j]+1){
							d[i]=d[j]+1;
					
					}
				}
			
			}
		}

	
	  cout << d[n-1];
	
		return 0;
	
}
