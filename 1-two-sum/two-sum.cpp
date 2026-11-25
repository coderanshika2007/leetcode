class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr;
        for(int i=0; i<nums.size(); i++){
            arr.push_back({nums[i],i});
        }
        int left = 0;
        int right = nums.size()-1;
        sort(arr.begin(), arr.end());
        while(left<right){
            int required = arr[left].first + arr[right].first;
            if(required < target){
                left = left+1;
            }else if(required == target){
                return {arr[left].second,arr[right].second};
            }else{
                right = right-1;
            }
        }
        return {};
    }
};