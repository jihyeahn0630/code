#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

vector<long long> num(500010);
vector<long long> check(500010);


int lower_bound(long long key, int idx){
	int start = 0;
	int end = idx-1;
	int mid;
	int ans=0;
	
	while(start <= end){
		mid = (start+end)/2;
		if(key == num[mid]){
			ans = mid;
			end = mid -1;
		}
		else if(key < num[mid]){
			end = mid -1;
		}
		else {
			start = mid + 1;
		}	

	}
	
	return ans;
}

int upper_bound(long long key, int idx){
	int start = 0;
	int end = idx-1;
	int mid;
  int ans=0;
	
	while(start <= end){
		mid = (start+end)/2;
		if(key == num[mid]){
			ans = mid +1;
			start = mid +1;
		}else if(key > num[mid]){
			start = mid +1;
		}
		else {
			end = mid - 1;
		}	

	}
	
	return ans;
}
