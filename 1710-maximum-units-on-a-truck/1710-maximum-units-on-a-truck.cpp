class Solution {
public:
    static bool myComp(vector<int> &a,vector<int> &b)
    {
        return (a[1] > b[1]); 
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), myComp);
        
        int ans = 0;
        
        for(int i=0;i<n;i++)
        {
            int box = boxTypes[i][0];
            int units = boxTypes[i][1];
            
            if(box <= truckSize)
            {
                ans += box * units;
                truckSize -= box;
            }
            else
            {
                ans += truckSize * units;
                truckSize -= truckSize;
            }
        }
        return ans;
    }
};