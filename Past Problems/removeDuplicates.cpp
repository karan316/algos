#include<iostream>
#include<vector>
using namespace std;
 int removeDuplicates(vector<int>& nums) {
        if(nums.size() <=1 )
            return nums.size();
            vector<int>::iterator it;

        for(it=nums.begin()+1; it != nums.end(); ++it)
        {
            if((*it)==*(it-1))
               it = nums.erase(it-1);
        }
        return nums.size();
    }

int main()
{
    vector<int> a;
    int ele;
    cout<<"size: ";
    int n;
    cin>>n;
    cout<<"elements: \n";
    for(int i=0; i<n;i++)
    {
        cin>>ele;
        a.push_back(ele);
    }

    cout<<"length: "<<removeDuplicates(a);
}