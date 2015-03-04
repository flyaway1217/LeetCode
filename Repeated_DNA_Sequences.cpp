//coding:utf-8
/*
Program: Repeated DNA Sequences
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-03-03 19:54:46
Last modified: 2015-03-04 11:25:29
GCC version: 4.7.3
*/
#include<iostream>
#include<unordered_set>
#include<vector>
#include<string>
#include<bitset>
using namespace std;

class Solution {
    public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        vector<string> reval;
        unordered_set<int> tmp;

        if(s.size() <= 10)
            return reval;

        unordered_set<int> container;
        int i,j;
        int num = init(s);
        container.insert(num);

        //bitset<32> mysets(num);
        //cout<<mysets<<endl;
        for(i = 1, j = 10; j < s.size(); ++i,++j)
        {
            num = num << 2;
            num = num | map(s[j]);
            num = num & 1048575;

            //bitset<32> myset(num);
            //cout<<myset<<endl;
            // if already existing
            if(container.find(num) != container.end() && tmp.find(num) == tmp.end())
            {
                reval.push_back(s.substr(i,10));
                tmp.insert(num);
            }
            container.insert(num);
        }

        return reval;
        
    }

    int init(string s)
    {
        int reval = 0;
        for(int i = 0;i < 10; ++i)
        {
            reval = reval << 2;
            reval = reval | map(s[i]);
        }
        return reval;
    }

    int map(char DNA)
    {
        if (DNA == 'A')
            return 0;
        else if(DNA == 'C')
            return 1;
        else if(DNA == 'G')
            return 2;
        else if(DNA == 'T')
            return 3;
        else
            return 0;
    }
};


int main()
{

    //string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    string str = "AAAAAAAAAAAA";
    Solution s = Solution();

    vector<string> reval = s.findRepeatedDnaSequences(str);

    cout<< str << endl;
    for(int i = 0; i < reval.size(); ++i)
    {
        cout << reval[i] << endl;
    }

}
