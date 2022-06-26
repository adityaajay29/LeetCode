class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int slide = 0;
        int n = cardPoints.size();
        int sum = 0;
        int window = n - k;
        
        for(int x : cardPoints)
            sum += x;
        
        for(int i=0;i<window;i++)
        {
            slide += cardPoints[i];
        }
        if(k == n)
            return sum;
        
        int ans = slide;
        
        for(int i=window;i<n;i++)
        {
            slide -= cardPoints[i - window];
            slide += cardPoints[i];
            ans = min(ans, slide);
        }
        return sum - ans;
    }
};