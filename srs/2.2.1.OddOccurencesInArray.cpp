/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:         100%                                        Created:        24/11/2020
Correctness:        100%                                        Last Edited:    28/03/2021
Performance:        100%
Time Complexity:	O(N) or O(N*log(N))

#######################################################################################################################

Given a non-empty array, of odd length and whose every every element of the array can be paired with another element
that has the same value, except for one unpaired element.

For example, in array A such that:

  A[0] = 9   A[1] = 3   A[2] = 9   A[3] = 3   A[4] = 9   A[5] = 7   A[6] = 9
            
        >   the elements at indexes 0 and 2 have value 9,
        >   the elements at indexes 1 and 3 have value 3,
        >   the elements at indexes 4 and 6 have value 9,
        >   the element at index 5 has value 7 and is unpaired.

Write a function:

        int solution(vector<int> &A);

that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired 
element.

For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]

Write an efficient algorithm for the following assumptions:

        >   N is an odd integer within the range [1..1,000,000];
        >   each element of array A is an integer within the range [1..1,000,000,000];
        >   all but one of the values in A occur an even number of times.

#####################################################################################################################*/

#include <iostream>
#include <vector>

int solution(std::vector<int> &A);

int main() {

    std::vector<int> vecA = { 9, 3, 9, 3, 9, 7, 9 };
    std::vector<int> vecB = { 1 };
    std::vector<int> vecC = { 7, 10, 20, 20, 7, 10, 11, 11, 1 };
    std::vector<int> vecD = { };

    std::cout << solution(vecA) << std::endl;
    std::cout << solution(vecB) << std::endl;
    std::cout << solution(vecC) << std::endl;
    std::cout << solution(vecD) << std::endl;
    
    return 0;
}

//Paste function into Codility to test
int solution(std::vector<int> &A) {

    //Case for vector of a single value
    if (A.size() == 1) 
        return A[0];

    int sum = 0;

    for (auto x : A)
        sum ^= x;       /*Bitwise exclusive OR asignment compares each bit of each operand
                        If one of the compared bits is a 1, then resulting bit is a 1. Otherwise
                        result in a 0. Effectively causes the pairs to cancel one another out*/
    
    return sum;

}