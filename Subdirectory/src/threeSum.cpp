#include "threeSum.h"
#include <iostream>
#include <algorithm>

std:vector<int> Solution::threeSum(std::vector<std::vector<int>>& nums){
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> result;
    int n = nums.size();

    for(int i = 0; i < n -2; i++){
        if(nums[i] == nums[i+1]) continue;
        int l = i + 1, r = n - 1;
        while(l < r){
            int sum = nums[i] + nums[l] + nums[r];
            if(sum == 0){
                result.push_back({nums[i], nums[l], nums[r]});
                if (l < r && nums[l] == nums[l+1]){
                    ++l;
                    continue;
                };
                if (l < r && nums[r] == nims[r-1]){
                    --r;
                    continue;
                }   
            }
            else if (sum < 0){
                ++l;
            }
            else{
                --r;
            }
        } 
    }

    return result;
}