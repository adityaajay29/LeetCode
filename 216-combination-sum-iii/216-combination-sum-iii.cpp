class Solution {
public:
    
    vector<int> tmp;
    vector<vector<int>> res;
    
    void backTrack(int cur, int k, int n) {
        if (k == 1) {
            if (n > cur && n <= 9) {
                tmp.push_back(n);
                res.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        int upper_bound = (n - k * (k - 1) / 2) / k;
        for (int i = cur + 1; i <= min(upper_bound, 9); i++) {
            tmp.push_back(i);
            backTrack(i, k - 1, n - i);
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backTrack(0, k, n);
        return res;
    }
};