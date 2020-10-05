#include<bits/std++.h>

using namespace std;

class Solution {
public:
    int bitwiseComplement(int N) {
	    if(N==0) return 1;
	    int k;
	    for(int i=0;i<N;i++) {
		    if(N>pow(2,i)-1) {
			    k = pow(2,i)-1;
			    break;
		    }
	    }
	return k-N;		    
	    
    }
}if(N<2) return !N;
	    int k;
        int i = 0;
//         increment k until it becomes just greater than N
        while((k = pow(2,i++)-1 ) < N);
	return k-N;		    ;
