class BIT { // One-based indexing
    vector<int> bit;
    
    public:
    BIT(int size=0) {
        bit.assign(size + 1, 0);
    }
    int getSum(int idx) { // Get sum in range [1..idx]
        int sum = 0;
        while(idx)
        {
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }   
    
    void addValue(int idx, int val) {
        while(idx < bit.size())
        {
            bit[idx] += val;
            idx += idx & (-idx);
        }
    }
};

class NumArray {
    BIT bit;
    vector<int> nums;
        
    public:
    NumArray(vector<int>& nums) {
        this->bit = BIT(nums.size());
        this->nums = nums;
        for (int i = 0; i < nums.size(); i++)
            bit.addValue(i + 1, nums[i]);
    }
    void update(int index, int val) {
        int diff = val - nums[index]; // get diff amount of `val` compared to current value
        bit.addValue(index + 1, diff); // add this `diff` amount at index `index+1` of BIT, plus 1 because in BIT it's 1-based indexing
        nums[index] = val; // update latest value of `nums[index]`
    }
    int sumRange(int left, int right) {
        return bit.getSum(right + 1) - bit.getSum(left);
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */