/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        05/03/2020
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(N)

#######################################################################################################################

A non-empty array A consisting of N integers is given. The consecutive elements of array A represent consecutive cars
on the road. Arrary A contains only 0s and/or 1s:

        >   0 represents a car travelling east
        >   1 represents a car travelling west

The goal is to count the passing cars. We say a pair of cars (P, Q), where 0 <= P < Q < N, is passing when P is
travelling east and q is travelling west.

Consider the example:

        A[0] = 0
        A[1] = 1
        A[2] = 0
        A[3] = 1
        A[4] = 1

    we have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4)

Write a function:

        int solution(vector<int> &A);

    that returns the number of pairs of passing cars. The function should return -1 if the number of passing cars 
    exceeds 1,000,000,000. Assume:

            >   N is an integer within the range [1..100,000];
            >   each element of array A is an integer that can have one of the following values: 0, 1.


#####################################################################################################################*/

#include <iostream>
#include <vector>

using std::vector;

int solution(vector<int>& A);

int main() {

    vector<int> vecA = { 0, 1, 0, 1, 1 };
    std::cout << solution(vecA) << std::endl;

    //vector<int> vecB = { 4, -3, 3, -2, 1, 5, 8 };
    //std::cout << solution(vecB) << std::endl;

    vector<int> vecC = { 100, 100, -14, 5, 0, -10, 100 };
    //std::cout << solution(vecC) << std::endl;

    return 0;

}

int solution(vector<int>& A) {

    int N = A.size();
    int counter = 0;
    int total = 0;
    
    //from east (A[-1]) to west (A[N + 1]) record the number of passes for each car travelling west noting car must pass
    //at least the same cars as the one before it.

    for (int i = 0; i < N; i++) {
        //count east bound cars
        if (!A[i]) counter++;
        //Once we meet a west bound car the count represents the number of cars it passes to we add this to total
        else {
            total += counter;
        
        }
        if (total > 1000000000) return-1;

    }

    return total;

}
