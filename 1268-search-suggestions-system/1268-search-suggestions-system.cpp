class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> ans;
        int sz = searchWord.size();
        int n = products.size();
        for(int i=1;i<=sz;i++)
        {
            string prefix = searchWord.substr(0, i);
            vector<string> temp;
            for(int j=0;j<n;j++)
            {
                string curr = products[j];
                if(curr.substr(0, i) == prefix)
                {
                    temp.push_back(curr);
                }
            }
            if(temp.size() > 3)
                temp.resize(3);
            if(temp.size() == 0)
            {
                ans.push_back({});
            }
            else
                ans.push_back(temp);
        }
        return ans;
    }
};