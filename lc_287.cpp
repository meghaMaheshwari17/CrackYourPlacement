// Description: Find the duplicate number in an array of n+1 integers.
#include<bits/stdc++.h>
class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int i=0;
        while(arr[i]!=-1){
            int temp=arr[i];
            arr[i]=-1;
            i=temp;
        }
        return i;
    }
};

