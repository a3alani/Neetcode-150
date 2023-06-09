/* 
 Note: 1/2

 @params string s, string t
 @return bool

 Edge Cases:
 * empty?
 * string of ints?
 
 * Brute Force Solution: sort then compare
 * time O(n log n + m log m) space O(1)
 bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if(s == t){
            return true;
        }
        return false;
    }
 *
 * Efficient:
 * time O(n) space O(n) 
 1. one pass to put s in a map with value of freq
 2. second pass to put t in a map with value of freq
 3. compare and return false if not equal
 4. else true
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        if(s.length() != t.length()){
            return false;
        }

        for(char c: s){
            if(sMap.find(c) != sMap.end()){
                sMap[c]++;
            } else{
                sMap.insert(pair<char, int>(c, 1));
            }        
        }

        for(char d: t){
            if(tMap.find(d) != tMap.end()){
                tMap[d]++;
            } else{
                tMap.insert(pair<char, int>(d, 1));
            }        
        }

        for(const auto& pair : sMap){
            if(tMap[pair.first] != pair.second){
                return false;
            }
        }
        return true;
    }
};
