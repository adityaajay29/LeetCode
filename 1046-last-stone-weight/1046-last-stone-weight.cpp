class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());
        // for(auto x:stones)
        //     pq.push(x);
        while(!pq.empty() || pq.size()==1)
        {
            if(pq.size()==1)
                return pq.top();
            int first=pq.top();
            pq.pop();
            int second=pq.top();
            pq.pop();
            if(first==second)
                continue;
            else
                pq.push(first-second);
        }
        return 0;
    }
};