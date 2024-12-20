class Solution {
public:
    vector<int> twoSum(vector<int>& a, int target) {
        unordered_map<int,int>u1;
        for(int i=0;i<a.size();i++){
            if(u1.find(target-a[i])!=u1.end()){
                return {u1[target-a[i]],i};
            }
            u1[a[i]]=i;
        }
        return {};
    }
};