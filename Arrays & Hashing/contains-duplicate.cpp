/*
 Note: 2/2 but changed approach

 @param int array
 @return bool
 
 Edge Cases:
 * empty array
 * atleast twice
 * 
 Solution
 *  Brute Fore time O(n^2) space O(1): iterate twice and compare elements with each other
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size-1; i++){
            for(int j = i+1; j < size; j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }
        return false;
    }

 * Effecient: time O(n) space O(n)
 * one pass: iterate once
 * if element at i in map return false
 * else add it
 * after return true
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> numsSet;

        for(int i = 0; i < nums.size(); i++){
            if(numsSet.find(nums[i]) != numsSet.end()){  //if not equal then found 
                return true;
            }
            numsSet.insert(nums[i]);
        }
        return false;
    }
};









