//coding:utf-8
/*
Program: Dungeon Game
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-01-27 19:47:29
Last modified: 2015-02-04 10:09:12
GCC version: 4.7.3
*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {

        int m = dungeon.size();
        int n = dungeon[0].size();
        int i,j;

        int right , down;
        
        vector<vector<int> > current_health(m, vector<int>(n, 0) );
        vector<vector<int> > min_health(m, vector<int>(n, 0) );

        //init

        for(i = 0; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                if(i == 0 && j == 0)
                {
                    current_health[i][j] = dungeon[i][j];
                    min_health[i][j] = dungeon[i][j];
                }
                else if(i == 0)
                {
                    current_health[i][j] = current_health[i][j-1] +  dungeon[i][j];
                    if(current_health[i][j] < min_health[i][j-1])
                        min_health[i][j] = current_health[i][j];
                    else
                        min_health[i][j] = min_health[i][j-1];
                    
                }
                else if(j == 0)
                {
                    current_health[i][j] = current_health[i-1][j] + dungeon[i][j];
                    if(current_health[i][j] < min_health[i-1][j])
                        min_health[i][j] = current_health[i][j];
                    else
                        min_health[i][j] = min_health[i-1][j];
                }
                else
                {
                    down = min(current_health[i][j-1] + dungeon[i][j], min_health[i][j-1]);
                    right = min(current_health[i-1][j] + dungeon[i][j], min_health[i-1][j]);
                    //
                    //down = current_health[i][j-1] + dungeon[i][j];
                    //right = current_health[i-1][j] + dungeon[i][j];
                    if (down > right)
                    {
                        min_health[i][j] = down;
                        current_health[i][j] = current_health[i][j-1] + dungeon[i][j];
                    }
                    else
                    {
                        min_health[i][j] = right;
                        current_health[i][j] = current_health[i-1][j] + dungeon[i][j];
                    }

                }
            }
        }

        for(i = 0; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                cout<<current_health[i][j]<<"\t";
            }
            cout<<endl;
        }

        cout<<"----------------------------"<<endl;

        for(i = 0; i < m; ++i)
        {
            for(j = 0; j < n; ++j)
            {
                cout<<min_health[i][j]<<"\t";
            }
            cout<<endl;
        }
        
        if(min_health[m-1][n-1] > 0)
            return 1;
        else
            return abs(min_health[m-1][n-1]) + 1;
    }

};


int main()
{

    #define N 3
    //int a[N][N] = {{0, 5}, {-2, -3}};
    int a[N][N] = {{-2,-3, 3}, {-5, -10,1},{10,30,-5}};
    //int a[N][N] = {{1,-3,3},{0,-2,0},{-3,-3,-3}};


    vector<vector<int> > args(N,vector<int>(N, 0));
    int i,j;

    for(i = 0;i < N; ++i)
    {
        for(j = 0; j < N; ++j)
        {
            args[i][j] = a[i][j];
        }
    }

    Solution s = Solution();
    cout<<s.calculateMinimumHP(args);

}
