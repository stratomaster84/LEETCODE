#include <iostream>
#include <vector>
#include "myprofile.h"

using namespace std;

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    size_t snums = nums.size()+1;
    size_t all_capacity = 1;
    while(--snums)
        all_capacity *= snums;

    snums = nums.size();
    size_t i;

    vector<int> next_perm(nums);
    while(all_capacity--){
        result.push_back(next_perm);
// next permutation
        i=snums-1;
        while(i){
            if(next_perm[i-1]<next_perm[i])
                break;
            i--;
        }
        size_t j = i; // is what to swap
        if(i != 0){
            j--;
            for(;i<snums;i++){
                if(next_perm[j]>=next_perm[i])
                    break;
            }
            swap(next_perm[j],next_perm[i-1]);
            j++;
        }
    // inverse "j" to end
        size_t median = (snums-j)/2;
        for(i=0;i<median;i++)
            swap(next_perm[i+j],next_perm[snums-i-1]);
        if(next_perm == nums)
            break;
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
    vector<int> vec = {1,1,1,2,7};
    cout << 17 << "\n\n" << permuteUnique(vec) << "\n\n" << 18;

    return 0;
}
//----------------------------------------
