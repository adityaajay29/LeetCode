class Solution {
public:
    bool isValid(char a, char b)
    {
        return (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}');
    }
    
    bool isValid(string s) {
        stack<char> stack;
        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[')
                stack.push(c);
            
            else
            {
                if(stack.empty())
                    return false;
                
                if(isValid(stack.top(), c))
                {
                    stack.pop();
                }
                else
                    return false;
            }
        }
        return stack.empty();
    }
};