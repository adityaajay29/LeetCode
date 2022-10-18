class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        
        string temp = countAndSay(n - 1);
        string ans = "";
        char curr = temp[0];
        int count = 1;
        for(int i=1;i<=temp.size();i++)
        {
            if(temp[i] == curr)
                count++;
            else
            {
                ans += to_string(count);
                ans.push_back(curr);
                curr = temp[i];
                count = 1;
            }
        }
        return ans;
    }
};