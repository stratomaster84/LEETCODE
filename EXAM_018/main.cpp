#include <iostream>
#include <vector>
#include "myprofile.h"

using namespace std;

void reverse(vector<int>& nums, size_t b,size_t e){
    size_t median = (e-b)>>1;
    for(size_t i=0;i<=median;++i){
        swap(nums[b+i],nums[e-i]);
    }
}

void nextPermutation(vector<int>& nums) {
    size_t sSize = nums.size();
    if(sSize == 1)
        return;
    if(sSize == 2){
        swap(nums[0],nums[1]);
        return;
    }

    size_t cur_el = sSize-1; // last element; already means >=2

    while(cur_el){
        if(nums[cur_el-1] < nums[cur_el])
            break;
        --cur_el;
    }
    if(cur_el == 0){
        reverse(nums,0,sSize-1);
        return;
    }
// else: nums[cur_el-1] less than nums[cur_el]
    size_t i = cur_el;
    for(;i<sSize;++i){
        if(nums[cur_el-1]>=nums[i]){
            break;
        }
    }
    swap(nums[cur_el-1],nums[i-1]);
    reverse(nums,cur_el,sSize-1);
}

int main()
{
    auto printVec = [](const vector<int>& v){
        for(auto& i:v){
            cout << i << ' ';
        }
        cout << '\n';
    };

    vector<int> vec = {7,9,12,1,0};

    printVec(vec);
    nextPermutation(vec);
    printVec(vec);
    nextPermutation(vec);
    printVec(vec);
    nextPermutation(vec);
    printVec(vec);
    nextPermutation(vec);
    printVec(vec);
    nextPermutation(vec);
    printVec(vec);
    nextPermutation(vec);
    printVec(vec);
    nextPermutation(vec);
    printVec(vec);

    return 0;
}
//----------------------------------------
