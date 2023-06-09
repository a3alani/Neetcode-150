/*
 Note: 2/2

 @params int array, int
 @return vector with 2 indicies
 * 
 * Edge cases:
 * always solution
 * same index can not be used twice
 * 
 * solution: time O(n) space O(n)
 1. iterate through array
 2. find the complement of target and element at i
 3. if complement in map, return index of element at i and value of key from map
 4. else add element at i to map and move to next one
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> pairs;

        unordered_map<int, int> numsMap;

        int complement;
        for(int i = 0; i < nums.size(); i++){
            complement = target - nums[i];
            if(numsMap.find(complement) != numsMap.end()){
                pairs.push_back(i);
                pairs.push_back(numsMap[complement]);
                break;
            }
            numsMap.insert(pair<int, int>(nums[i], i));
        }
    return pairs;
    }
};
