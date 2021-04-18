/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			 77%                                        Created:        16/12/2020
Correctness:		100%                                        Last Edited:    30/03/2021
Performance:		 60%
Time Complexity:	---

#######################################################################################################################

You are given N counters, initially set to 0, and you have two possible operations on them:

        >   increase(X) − counter X is increased by 1,
        >   max counter − all counters are set to the maximum value of any counter.

A non-empty array A of M integers is given. This array represents consecutive operations:

        >   if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
        >   if A[K] = N + 1 then operation K is max counter.

For example, given integer N = 5 and array A such that:

        A[0] = 3
        A[1] = 4
        A[2] = 4
        A[3] = 6
        A[4] = 1
        A[5] = 4
        A[6] = 4

    the values of the counters after each consecutive operation will be:

        (0, 0, 1, 0, 0)
        (0, 0, 1, 1, 0)
        (0, 0, 1, 2, 0)
        (2, 2, 2, 2, 2)
        (3, 2, 2, 2, 2)
        (3, 2, 2, 3, 2)
        (3, 2, 2, 4, 2)

The goal is to calculate the value of every counter after all operations. Write a function:

        vector<int> solution(int N, vector<int> &A);

that, given an integer N and a non-empty array A consisting of M integers, returns a sequence of integers 
representing the values of the counters.

Write an efficient algorithm for the following assumptions:

        >   N and M are integers within the range [1..100,000];
        >   each element of array A is an integer within the range [1..N + 1].

#####################################################################################################################*/

#include <iostream>
#include <vector>

std::vector<int> solution(int N, std::vector<int>& A);

int main() {

    std::vector<int> vecA = { 3, 4, 4, 6, 1, 4, 4 };
    std::vector<int> vecB = { 1, 1, 1, 2 };

    for (auto x : solution(5, vecA)) std::cout << x << " ";
    std::cout << std::endl;
    for (auto x : solution(1, vecB)) std::cout << x << " ";
    
    return 0;

}

//Paste into Codility to test
std::vector<int> solution(int N, std::vector<int>& A) {

    std::vector<int> counters(N, 0);
    int len = A.size();
    int highest = 0;
    
    //loop through the whole array
    for (int i = 0; i < len; i++) {
        //move 1: increase a single counter
        if (A[i] <= N) {
            counters[A[i] - 1]++;
            //if the value of this counter is more than the max value, set max value = to it
            if (counters[A[i] - 1] > highest) highest = counters[A[i] - 1];

        }
        //move 2: change all counters to maximum value
        else if (A[i] == N + 1) 
            std::fill(counters.begin(), counters.end(), highest);
    
    }

    return counters;

}