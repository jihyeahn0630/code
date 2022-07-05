#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<long long> num(500010);
vector<long long> check(500010);


int binary_search(long long key, int idx){
	int start = 0;
	int end = idx-1;
	int mid;
	
	while(start <= end){
		mid = (start+end)/2;
		if(key == num[mid]){
			return 1;	
		}
		else if(key > num[mid]){
			start = mid + 1;
		}	
		else{
			end = mid -1;
		}	
			
	}
	
	return -1;
}

int main() {

	int n,m;
	
	cin >> n;

	
	for(int i=0; i<n; i++){
		cin >> num[i];	
	}
	
	cin >> m;

	
	for(int i=0; i < m ;i++){
			cin >> check[i];	
	}
	
	sort(num.begin(),num.begin()+n);
	
	for(int i=0; i < m ;i++){
		if(binary_search(check[i],n) == 1)
			cout << "1 ";
		else 
			cout << "0 ";
		
	}
	
	return 0;
	
}
