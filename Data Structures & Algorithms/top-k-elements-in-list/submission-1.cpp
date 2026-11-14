class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;

        for(int num : nums){
            cnt[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto &entry: cnt){
            pq.push({entry.second, entry.first});

            if(pq.size() > k) pq.pop();
        }

        vector<int> res;
        for(int i = 0; i<k; i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
