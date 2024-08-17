#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> quadruplets;

        if (nums.size() < 4) 
        {
            return quadruplets;
        }

        std::sort(nums.begin(), nums.end());
        
        int n = nums.size();
        long add_result = 0;


        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
            if ((long) nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target) continue;
            
            for (int j = i + 1; j < n - 2; j++){
                if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
                if ((long) nums[i] + nums[j] + nums[n - 2] + nums[n - 1] < target) continue;

                int l = j + 1; int r = n - 1;
                while (l < r){
                    add_result = (long) nums[i] + nums[j] + nums[l] + nums[r];
                    if(add_result == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l<r && nums[l] == nums[l+1]){
                            l++;
                        }
                        l++;
                        while (l<r && nums[r] == nums[r-1]){
                            r--;
                        }
                        r--;
                    }
                    else if(add_result < target) {
                        l++;
                    }
                    else {
                        r--;
                    } 
                }
                
            }
        }
        return quadruplets;
    }
};


int main(){
    Solution s;
    std::vector<int> nums = {1,0,-1,0,-2,2};
    std::vector<std::vector<int>> result;
    int target = 0;
    result = s.fourSum(nums, target);
    for (const auto& vec : result) {
        std::cout << "[";
        for (size_t i = 0; i < vec.size(); ++i) {
            std::cout << vec[i];
            if (i < vec.size() - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}