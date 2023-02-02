#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashtable.count(target - nums[i])) {
                return {hashtable[target - nums[i]], i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};