#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;



int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
	
	int n;
	
	cin >> n;
  vector<int> num(n);
	
	for(int i=0; i<n; i++){
		cin >> num[i];	
	}
	
	
	sort(num.begin(),num.end());
	
	for(int i=0; i < n ;i++){
		cout << num[i] << endl;
	}
	
	return 0;
	
}
