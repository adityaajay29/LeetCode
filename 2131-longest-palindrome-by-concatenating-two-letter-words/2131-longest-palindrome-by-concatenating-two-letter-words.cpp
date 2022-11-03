class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> arr(26, vector<int> (26));
        int ans = 0;
        for(string &s : words)
        {
            int a = s[0] - 'a';
            int b = s[1] - 'a';
            if(arr[a][b])
            {
                ans += 4;
                arr[a][b]--;
            }
            else
                arr[b][a]++;
        }
        for(int i=0;i<26;i++)
        {
            if(arr[i][i])
            {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};