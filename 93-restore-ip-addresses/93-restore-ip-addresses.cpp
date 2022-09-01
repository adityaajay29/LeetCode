class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string temp;
//         group 1
        for(int i=1;i<=3;i++)
        {
//             group 2
            for(int j=1;j<=3;j++)
            {
//                 group 3
                for(int k=1;k<=3;k++)
                {
//                     group 4
                    for(int l=1;l<=3;l++)
                    {
//                         if all 4 groups combine to include all the digits, then only check if valid ip can be generated
                        if(i + j + k + l == s.size())
                        {
//                             g1
                            int a = stoi(s.substr(0, i));
//                             g2
                            int b = stoi(s.substr(i, j));
//                             g3
                            int c = stoi(s.substr(i + j, k));
//                             g4
                            int d = stoi(s.substr(i + j + k, l));
//                             if all the 4 groups have valid values
                            if(a <= 255 && b <= 255 && c <= 255 && d <= 255)
                            {
                                temp = to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
//                                 then check if after deletion of 3 dots, its length is same as given string
                                if(temp.size() == s.size() + 3)
                                {
                                    ans.push_back(temp);
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};