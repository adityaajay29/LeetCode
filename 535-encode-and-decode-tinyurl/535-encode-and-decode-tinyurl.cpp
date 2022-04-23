class Solution {
public:
    unordered_map<string,string>mp;
    int code=1;
    string codeWord="0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
//     function to generate random code words depending on value of code
    string append()
    {
        string key;
        int n=code;
        while(n>0)
        {
            key.push_back(codeWord[code%62]);
            n/=62;
        }
        return key;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        // cout<<append()<<endl;
        string ans="https://tinyurl.com/"+append();
//         updating the value of code
        code++;
//         making short long code key val pair
        mp[ans]=longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));