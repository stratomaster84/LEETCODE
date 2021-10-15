#include <iostream>
#include <vector>
#include "myprofile.h"

using namespace std;

int jump_tmp(const vector<int> &nums, int pos){
    int vsize = nums.size();
    int min = vsize;
    for(int i = 1;i <= nums[pos];++i){
        if(pos+i == vsize-1)
            return 1;
        int res = jump_tmp(nums,pos+i);
        if(res<min)
            min = res;
    }
    if(min != vsize)
        min++;
    return min;
}
int jump(const vector<int> &nums){
    if(nums.size() == 1)
        return 0;
    return jump_tmp(nums,0);
}
int main()
{
    vector<int> nums  = {4,1,3,1,1};
    vector<int> nums2 = {2,3,0,1,4};

    cout << jump(nums) << '\n' << jump(nums2) << endl;

    return 0;
}
