#include <iostream>
#include <vector>
#include "myprofile.h"

using namespace std;

int maxSubArray(vector<int>& nums){
    size_t snums = nums.size();
    int max_non_pos = INT_MIN;
    size_t i;
    for(i=0;i<snums;++i){
        if(nums[i] > max_non_pos)
            max_non_pos = nums[i];
        if(max_non_pos > 0)
            break;
    }
    if(i == snums)
        return max_non_pos;
    int result = nums[i]; // текущий результат - первый положительный элемент
    int curr_max = result;   // текущая макс. сумма - такой же
    for(++i;i<snums;++i){  // основной цикл
        curr_max += nums[i];
        if(nums[i]>curr_max){
            curr_max = nums[i];
            continue;
        }
        if(curr_max > result)
            result = curr_max;
    }
    if(curr_max > result)
        return curr_max;
    return result;
}

int main()
{
    vector<int> vec ={-3,1,-2,2};
    cout << maxSubArray(vec);
    return 0;
}
//----------------------------------------
