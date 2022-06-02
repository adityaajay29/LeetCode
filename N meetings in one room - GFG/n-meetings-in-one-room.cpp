// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    struct myType
    {
        int s;
        int e;
    };
    
    static bool myComp(myType x, myType y)
    {
        if(x.e == y.e)
        return x.s < y.s && x.e == y.e;
        
        return x.e < y.e;
    }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<myType> meets(n);
        for(int i=0;i<n;i++)
        {
            meets[i].s = start[i];
            meets[i].e = end[i];
        }
        sort(meets.begin(), meets.end(), myComp);
        int prevEnd = meets[0].e;
        int ans = 1;
        for(int i=1;i<n;i++)
        {
            if(meets[i].s > prevEnd)
            {
                ans++;
                prevEnd = meets[i].e;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends