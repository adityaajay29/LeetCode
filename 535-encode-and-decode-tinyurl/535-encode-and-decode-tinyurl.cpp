class Solution {
public:
    
//     creating a map to store short url and its corresponding long url
    unordered_map<string,string>mp;
//     starting our coding with 
    int codeVal=0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string code="http://tinyurl.com/"+to_string(codeVal++);
        mp[code]=longUrl;
        // cout<<code<<" "<<mp[code];
        return code;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));