//coding:utf-8
/*
Program: 2. Add Two Numbers
Description: 
Author: Flyaway - flyaway1217@gmail.com
Date: 2015-07-14 18:35:29
Last modified: 2015-07-14 19:04:07
GCC version: 4.7.3
*/

#include<iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x),  next(NULL) {}
};

class Solution {
    public:
    ListNode* addTwoNumbers(ListNode* l1,  ListNode* l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *root = new ListNode(-1);
        ListNode *r = root;

        int step = 0;
        int sum = 0;
        while(p != NULL || q != NULL)
        {
            if(p != NULL)
                sum = p->val;
            else
                sum = 0;

            if(q != NULL)
                sum += q->val;

            sum += step;

            r->next = new ListNode(sum % 10);
            r = r->next;
            
            step = sum / 10;

            if(p != NULL)
                p = p->next;
            if(q != NULL)
                q = q->next;
        }
        if(step != 0)
        {
            r->next = new ListNode(1);
            r = r->next;
        }
        return root->next;
    }
};


ListNode* makeList(int arg[], int size)
{
    int i;
    ListNode *root = new ListNode(arg[0]);
    ListNode *p = NULL;
    p = root;
    for(i = 1; i < size; ++i)
    {
        p->next = new ListNode(arg[i]);
        p = p->next;
    }
    return root;
}

void PrintList(ListNode *root)
{
    ListNode *p = root;
    while(p != NULL)
    {
        cout << p->val<<" ";
        p = p->next;
    }
}

int main()
{
    //int a[3] = {2, 4, 3};
    //int b[3] = {5, 6, 4};

    int a[2] = {1, 8};
    int b[1] = {0};

    ListNode *p = makeList(a, 2);
    ListNode *q = makeList(b, 1);
    Solution s = Solution();

    ListNode *ans = s.addTwoNumbers(p, q);
    PrintList(ans);

    return 0;
}


