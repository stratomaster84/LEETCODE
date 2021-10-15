#include <iostream>
#include <vector>
#include <algorithm>
#include "myprofile.h"

using namespace std;

size_t getpivot(const vector<int>& nums, size_t b, size_t e){
    // must be e-b >= 2
    if(nums[b]<nums[e])
        return b;
    size_t median = (e+b)/2;
    if(nums[b] > nums[median]){
        if(median-b == 1)
            return median;
        return getpivot(nums,b,median);
    }
    if(e-median == 1)
        return e;
    return getpivot(nums,median+1,e);
}
int find_binary(const vector<int>& nums, size_t b, size_t e,int target){
    if(e-b <= 1){
        if(nums[b]==target)
            return b;
        else if(nums[e]==target)
            return e;
        else
            return -1;
    }
//--------------
    size_t median = (b+e)/2;
    if(target < nums[median])
        return find_binary(nums,b,median-1,target);

    return find_binary(nums,median,e,target);
}
int search(vector<int>& nums, int target) {
    size_t vSize = nums.size();
    if(vSize == 1)
        return nums[0]==target?0:-1;
    else if(vSize == 2){
        if(nums[0]==target)
            return 0;
        else if(nums[1]==target)
            return 1;
        else
            return -1;
    }
//-----------------------------
    if(nums[0]<nums[vSize-1])
        return find_binary(nums,0,vSize-1,target);
    size_t pivot = getpivot(nums,0,vSize-1);
    if(nums[0]>target)
        return find_binary(nums,pivot,vSize-1,target);
    return find_binary(nums,0,pivot-1,target);
}

int main()
{
    vector<int> vec = {6,7,8,0,1,2,4,5};
    cout << search(vec,4);
    return 0;
}
//----------------------------------------
