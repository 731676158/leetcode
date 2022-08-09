#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution_of {
public:
    stack<string> ops;
    vector<string> res;
    
    vector<string> RPN(vector<string>& tokens) {
        vector<string>::iterator it = tokens.begin();
        unordered_map<string,int> oprts;
        oprts["("] = 1;
        oprts[")"] = 1;
        oprts["+"] = 2;
        oprts["-"] = 2;
        oprts["*"] = 3;
        oprts["/"] = 3;
        while (it != tokens.end())
        {
            if (oprts.find(*it) == oprts.end())
            {
                res.push_back(*it);
            }
            else if ((*it) == "(")
            {
                ops.push(*it);
            }
            else if ((*it) == ")")
            {
                while (ops.top() != "(")
                {
                    res.push_back(ops.top());
                    ops.pop();
                }
                ops.pop();
            }
            else
            {
                while (!ops.empty() && oprts[ops.top()] >= oprts[*it])
                {
                    res.push_back(ops.top());
                    ops.pop();
                }
                ops.push(*it);
            }
            ++it;
        }
        while (!ops.empty())
        {
            res.push_back(ops.top());
            ops.pop();
        }
        return res;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        vector<string>::iterator it = tokens.begin();
        unordered_set<string> oprts{ "+","-","*","/" };
        int opn1 = 0; int opn2 = 0;
        while (it != tokens.end())
        {
            if (oprts.find(*it) == oprts.end())
            {
                nums.push(atoi((*it).c_str()));
            }
            else
            {
                opn2 = nums.top();
                nums.pop();
                opn1 = nums.top();
                nums.pop();
                nums.push(
                    ((*it) == "+") ? (opn1 + opn2) : ((*it) == "-") ? (opn1 - opn2) : ((*it) == "*") ? (opn1 * opn2) : (opn1 / opn2)
                );
            }
            ++it;
        }
        return nums.top();
    }

};