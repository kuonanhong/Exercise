/*
Given a positive integer n and you can do operations as follow:
If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?
Example 1:
Input:
8
Output:
3
Explanation:
8 -> 4 -> 2 -> 1
Example 2:
Input:
7
Output:
4
Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
*/
//从二进制编码角度考虑问题，两种方式(1)n->n/2,(2)n->n+1,(3)n->n-1,在XX不为空的前提下,XX10形式必定(1),XX11形式必定先(2)后(1),XX01形式必定先(3)后(1)。
class Solution {
public:
    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(n == 3) return 2;
        if(n == INT_MAX) return 32;
        if(n & 1){
            if((n & 3) == 3) return 1 + integerReplacement(n + 1);
            else return 1 + integerReplacement(n - 1);
        }
        else return 1 + integerReplacement(n >> 1);
    }
};
