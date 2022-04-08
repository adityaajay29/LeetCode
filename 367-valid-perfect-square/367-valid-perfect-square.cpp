class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1;
        int h=num;
        if(num==1)
            return true;
        while(l<=h)
        {
            long long mid=l+(h-l)/2;
            if(mid*mid == num)
                return true;
            if(mid*mid<num)
                l=mid+1;
            else 
                h=mid-1;
        }
        return false;
    }
};