class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>set1(nums1.begin(),nums1.end());
        unordered_set<int>set2(nums2.begin(),nums2.end());
        vector<int>list1,list2;
        for(auto ele : set1){
            if(set2.find(ele) == set2.end())list1.push_back(ele);
        }
        for(auto ele : set2){
            if(set1.find(ele) == set1.end())list2.push_back(ele);
        }
        return {list1, list2};
    }
};