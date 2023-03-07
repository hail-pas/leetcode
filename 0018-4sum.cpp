#include<iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<long>> ans;
    vector<long> myNums, subans;
    long tar, numSize;
    void DFS(int low, int sum) {
        if (sum == tar && subans.size() == 4) {
            ans.emplace_back(subans);
            return;
        }
        for (int i = low; i < numSize; ++i) {
            if (numSize - i < long(4 - subans.size())) {  // 后续元素不够凑齐4个
                return;
            }
            if (i > low && myNums[i] == myNums[i - 1]) { // 去重
                continue;
            }
            // 3、2、1、0、-1
            if (i < numSize - 1 && sum + myNums[i] + long(3 - subans.size()) * myNums[i + 1] > tar) { //剪枝
                return;
            }
            if (i < numSize - 1 && sum + myNums[i] + long(3 - subans.size()) * myNums[numSize - 1] < tar) { //剪枝
                //
                continue;
            }
            subans.emplace_back(myNums[i]);
            DFS(i + 1, myNums[i] + sum);
            subans.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        myNums = vector<long>(nums.begin(), nums.end());
        tar = target;
        numSize = nums.size();
        if (numSize < 4) {
            return vector<vector<int>>();
        }
        DFS(0, 0);
        vector<vector<int>> my_ans(0);
        for (auto i: ans) {
            vector<int> temp(i.begin(), i.end());
            my_ans.push_back(temp);
        }
        return my_ans;
    }
};


int main(int argc, char const *argv[]) {
    std::vector<int> nums = {1,0,-1,0,-2,2};
    int target  = 0;
    for (auto i: Solution().fourSum(nums, target)) {
        for (auto j: i) {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}