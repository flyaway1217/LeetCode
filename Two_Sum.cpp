//coding:utf-8
/*
Program: 1.Two Sum
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-07-14 15:13:01
Last modified: 2015-07-14 18:35:02
GCC version: 4.7.3
*/

#include<iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
    vector<int> twoSum(vector<int>& nums,  int target)
    {
        int i, j, delta;
        vector<int> reval;
        unordered_map<int, int> table;

        for(i = 0; i < nums.size();++i)
        {
            table[nums[i]] = i;
        }
            
        for(i = 0; i < nums.size();++i)
        {
            delta = target-nums[i];
            if(table.find(delta) != table.end() && table[delta] != i)
            {
                reval.push_back(i+1);
                reval.push_back(table[delta] + 1);
                return reval;
            }
        }
    }
};



int main()
{
    vector<int> args;
    int i;
    int a[4] = {2, 7, 11, 15};

    for(i = 0; i < 4; ++i)
        args.push_back(a[i]);

    Solution s = Solution();

    vector<int> value = s.twoSum(args, 9);

    for(i = 0; i < value.size();++i)
        cout<<value[i]<<" ";

    return 0;
}
