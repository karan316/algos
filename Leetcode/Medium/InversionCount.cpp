
#include<bits/stdc++.h> 
using namespace std;

long long merge(vector<int> & a, vector<int> & temp, int left, int mid, int right) {
	int i = left;
	int j = mid;
	int k = left;
	long long count =0;
	while((i<=mid-1) && (j<=right)){
		if(a[i] <= a[j]) {
			temp[k++] = a[i++];
		} else {
			temp [k++] = a[j++];
			count += mid-i;
		}
	}
	while(i<=mid-1) 
		temp[k++] = a[i++];

	while(j<=right)
		temp[k++] = a[j++];
	for(int i=left; i<=right;i++)
		a[i] = temp[i];
	return count;
}

long long merge_sort(vector<int>& a, vector<int> & temp, int left, int right){
	long long count=0;
	if(right>left){
		int mid = (left+right)/2;

		count += merge_sort(a,temp, left, mid);
		count += merge_sort(a,temp, mid+1, right);

		count += merge(a, temp, left, mid+1, right);
	}
	return count;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n);
		vector<int> temp(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long long count = 0;

		count = merge_sort(a,temp, 0,a.size()-1 );

		cout<<count<<endl;
	}
}

