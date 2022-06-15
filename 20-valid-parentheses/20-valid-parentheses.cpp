class Solution {
public:
    bool isMatch(char a, char b)
    {
        return (a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b == ']');
    }
    
    bool isValid(string s) {
        stack<char> stack;
        
        for(char x : s)
        {
            if(x == '(' || x == '{' || x == '[')
            {
                stack.push(x);
            }
            else
            {
                if(stack.empty())
                    return false;
                
                if(isMatch(stack.top(), x))
                {
                    stack.pop();
                }
                else
                    return false;
            }
        }
        return (stack.empty());
    }
};