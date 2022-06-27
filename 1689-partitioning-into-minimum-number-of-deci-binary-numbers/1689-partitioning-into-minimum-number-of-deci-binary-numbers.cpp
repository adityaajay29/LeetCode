class Solution {
public:
    int minPartitions(string n) {
        int sz = n.size();
        string temp = "";
        for(int i=0;i<sz;i++)
        {
            temp += '0';
        }
        int part = 0;
        while(n != temp)
        {
            part++;
            for(int i=0;i<sz;i++)
            {
                if(n[i] > '0')
                {
                    n[i] -= 1;
                }
            }
        }
        return part;
    }
};