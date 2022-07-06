class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int res = 0;
        int n = s.size();
        
        int i = 0;
//         handling leading whitespaces
        while(i < n && s[i] == ' ')
        {
            i++;
        }
//         handling sign 
        if(i < n && s[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if(i < n && s[i] == '+')
        {
            i++;
        }
        while(i < n && isdigit(s[i]))
        {
            int curr = s[i] - '0';
//             handling overflows
            if(res > INT_MAX / 10 || (res == INT_MAX / 10 && curr > INT_MAX % 10))
                return (sign == -1 ? INT_MIN : INT_MAX);
            
            res = (res * 10) + curr;
            i++;
        }
        return sign * res;
    }
};