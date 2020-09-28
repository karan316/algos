#include <bits/stdc++.h> 
using namespace std; 

int max(int a, int b) { return (a > b)? a : b; } 

int knapSack(int c, int w[], int p[], int n) 
{ 
	
if (n == 0 || c == 0) 
	return 0; 

// If weight of the nth item is more than Knapsack capacity W, then this item cannot be included in the optimal solution 
if (w[n-1] > c) 
	return knapSack(c, w, p, n-1); 

// Return the maximum of two cases: (1) nth item included (2) not included 
else return max( p[n-1] + knapSack(c-w[n-1], w, p, n-1), 
					knapSack(c, w, p, n-1) ); 
} 

int main() 
{ 
    int n;
    cout<<"Number of elements\n";
    cin>>n;
	int p[n]; 
	int w[n]; 
    cout<<"Profit for "<<n<<" items\n";
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<"Weight for "<<n<<" items\n";
    for(int i=0;i<n;i++)
    {
        cin>>w[i];
    }
    cout<<"Capacity: ";
	int c;
    cin>>c;
	cout<<knapSack(c, w, p, n); 
	return 0; 
} 

