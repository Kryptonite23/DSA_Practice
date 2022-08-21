class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;
        if(nums.size()==0 || nums.size() ==1)
            return nums;

        for(auto it:nums){
            if(it == (it-1))
                mp[nums[it]]++;
        }
        for(auto it:mp){
            if(it.second > 1)
            ans.push_back(it.first);
        }
        return ans;
    }
};

// Approach 2
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto num : nums) freq[num]++;
        
        priority_queue<pair<int, int>> pq;
        for (auto [a, b] : freq) pq.push({b, a});
        
        vector<int> res;
        while (k) {
            res.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        
        return res;
    }
};