#include<iostream>
#include<algorithm>
#include<string>
#include <vector>
using namespace std;

class Solution {
private:
    static bool comp(const int& a, const int& b) { return a < b; }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i, j, k, line = 0;
        vector<vector<int>> ret;

        sort(nums.begin(), nums.end(), comp);

        for (i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                line = i;
            }
        }

        //
        for (i = 0; i < line; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            j = i + 1;
            k = nums.size() - 1;
            while (j < k) {

                if (nums[i] + nums[j] + nums[k] < 0) {
                    j++;

                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) {
                        j++;
                    }
                }
            }
        }
        return ret;
    }
};

int main(){
    Solution s1;
    vector<vector<int>> ret;
    vector<int> nums = {-1,0,1,2,-1,-4};
    int iter=0;

    ret = s1.threeSum(nums);
    while(iter<ret.size()){
        for(int i=0;i<3;i++)
        {
            cout<<ret[iter][i]<<",";
        }
        cout<<"\n";
        iter++;
    }
    return 0;
}