class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<vector<int>> arr(26, vector<int> (26));
        int ans = 0;
        for(string &s : words)
        {
            int a = s[0] - 'a';
            int b = s[1] - 'a';
            if(arr[b][a])
            {
                ans += 4;
                arr[b][a]--;
            }
            else
                arr[a][b]++;
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