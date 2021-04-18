/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        23/02/2020
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(N)

#######################################################################################################################

A non-empty array A consisting of N integers is given. A pair of integers (P, Q), such that 0 <= P < Q < N, is called
a slice of array A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of
A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise, the average equals
(A[P] + A[P + 1] + ... + A[Q]) / (Q - P + 1).

    For example, array A such that:

        A[0] = 4
        A[1] = 2
        A[2] = 2
        A[3] = 5
        A[4] = 1
        A[5] = 5
        A[6] = 8

    contains the following example slices:

        >   slice (1, 2), whose average is (2 + 2) / 2 = 2;
        >   slice (3, 4), whose average is (5 + 1) / 2 = 3;
        >   slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.

    The goal is to find the starting position of a slice whose average is minimal.

Write a function:

        int solution(vector<int> &A);

     that, given a non-empty array A consisting of N integers, returns the starting position of the slice with the
     minimal average. If there is more than one slice with a minimal average, you should return the smallest starting
     position of such a slice.

#####################################################################################################################*/

#include <iostream>
#include <vector>

using std::vector;

int solution(vector<int>& A);

int main() {

    vector<int> vecA = { 4, 2, 2, 5, 1, 5, 8 };
    std::cout << solution(vecA) << std::endl;

    vector<int> vecB = { 4, -3, 3, -2, 1, 5, 8 };
    std::cout << solution(vecB) << std::endl;

    vector<int> vecC = { -3, -5, -8, -4, -10 };
    std::cout << solution(vecC) << std::endl;

    return 0;

}

int solution(vector<int>& A) {

    int N = A.size();
    double minimum = 10001;
    int minimum_index = -1;
    double sum = 0;
    double average = 0;
    //int min_len = 0;                  /Variable used to track the length of substring

    //The minimum value of consecutive values in a list will always be at most 3 consecutive values
    //so we calculate all averages from 2 or 3 values
    for (int i = 0; i < (N - 1); i++) {
        sum = (double)A[i] + (double)A[i + 1];
        average = sum / 2;
        if (average < minimum) {
            minimum = average;
            minimum_index = i;
            //min_len = 2;
        }
        if (i + 2 < N ) {
            sum += (double)A[i + 2];
            average = sum / 3;
            if (average < minimum) {
                minimum = average;
                minimum_index = i;
                //min_len = 3;
            }

        }

    }

    //std::cout << "Len: " << min_len << std::endl;
    return minimum_index;

}
