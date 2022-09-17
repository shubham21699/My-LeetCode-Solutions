class Solution {
public:
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.length()-1;
        
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        int n = words.size();
        vector<vector<int>> result;
        
        std::vector<std::string> storage;  // Storage for unordered_map that using string_view: can be avoided with C++20 heterogeneous lookup
        
        storage.reserve(std::size(words));
        
        for (auto & word : words)
            storage.emplace_back(std::rbegin(word), std::rend(word));
        
        // Put reversed words with their indices to the dictionary
        std::unordered_map<std::string_view, int> m;
        
        for (int i = 0; i < std::size(storage); ++i)
            m[storage[i]] = i;


        for (int i = 0; i < std::size(words); ++i)
            if (!std::empty(words[i]))            
                for (int j = 0; j <= std::size(words[i]); ++j)
                {
                    const std::string_view left { words[i].c_str(), (size_t)j };
                    const std::string_view right { words[i].c_str() + j };

                    auto it = m.find(left);
                    if (it != std::end(m) && it->second != i && std::equal(std::begin(right), std::begin(right) + (std::size(right) >> 1), std::rbegin(right)))
                        result.emplace_back(std::vector<int> { i, it->second });

                    it = m.find(right);
                    if (it != std::end(m) && it->second != i && j && std::equal(std::begin(left), std::begin(left) + (std::size(left) >> 1), std::rbegin(left)))
                        result.emplace_back(std::vector<int> { it->second, i });
                }
        
        return result;

        
//         // OR: Correct but not passed 1 testcase and can ony be passed using Trie
//         unordered_map<string, int> dict;
        
//         for(int i=0 ; i<n ; i++) {
//             string x = words[i];
//             reverse(x.begin(), x.end());
            
//             dict[x] = i; 
//         }
        
//         if(dict.find("") != dict.end()) {
//             for(int i=0 ; i<n ; i++) {
//                 if(dict[""] == i) continue;
//                 if(isPalindrome(words[i])) result.push_back({ dict[""], i });
//             }
//         }
        
//         for(int i=0 ; i<n ; i++) {
//             if(words[i] == "") continue;
            
//             for(int j=0 ; j<words[i].length() ; j++) {
                
//                 string left = words[i].substr(0, j);
//                 string right = words[i].substr(j);
                
//                 // when j = 0, left = "", right = self, so here covers concatenate(self, "")
                
//                 // for "llsss", "sll" :
//                 // when j=2 left = "lls"; right="ss"; m["lls"] is exists,
//                 // so if right is palindrome, the pair is palindrome
//                 auto it = dict.find(left);
//                 if(it != dict.end() && isPalindrome(right) && it->second != i) {
//                     result.push_back({ i, it->second }); 
//                 }
                
//                 // for "lls", "sssll" :
//                 // when j=2 left = "ss";right="sll"; m["lls"] is exists,
//                 // so if left is palindrome, the pair is palindrome
//                 it = dict.find(right);
//                 if(it != dict.end() && isPalindrome(left) && it->second != i) {
//                     result.push_back({ it->second, i });
//                 }
                
//             }
//         }
        
//         return result;
        
        
//         // OR: Brute Force Solution
//         for(int i=0 ; i<n ; i++) {
//             for(int j=0 ; j<n ; j++) {
//                 if(i == j) continue;
                
//                 string x = words[i] + words[j];
//                 if(isPalindrome(x)) result.push_back({ i, j });
//             }
//         }
        
//         return result;
    }
};