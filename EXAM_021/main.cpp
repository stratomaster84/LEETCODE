#include <iostream>
#include <vector>
#include "myprofile.h"

using namespace std;

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    size_t snums = nums.size()+1;
    size_t all_capacity = 1;
    while(--snums)
        all_capacity *= snums;

    snums = nums.size();
    size_t i;

    result.reserve(all_capacity);
    while(all_capacity--){
        result.push_back(nums);
// next permutation
        i=snums-1;
        while(i){
            if(nums[i-1]<nums[i])
                break;
            i--;
        }
        size_t j = i;
        if(i != 0){
            j--;
            for(;i<snums;i++){
                if(nums[j]>nums[i])
                    break;
            }
            swap(nums[j],nums[i-1]);
            j++;
        }
    // inverse "j" to end
        size_t median = (snums-j)/2;
        for(i=0;i<median;i++)
            swap(nums[i+j],nums[snums-i-1]);
    }
    return result;
}

ostream& operator<<(ostream& MyStream, const vector<vector<int>> &vv){
    for(auto &v : vv){
        for(int x : v)
            MyStream << x << ' ';
        MyStream << '\n';
    }
    return MyStream;
}


int main()
{
    vector<int> vec = {1,2,4};
    cout << 17 << "\n\n" << permute(vec) << "\n\n" << 18;

    return 0;
}
//----------------------------------------
