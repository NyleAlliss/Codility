/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        27/12/2020
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(N*log(N))

#######################################################################################################################

An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 <= P < Q < R < N and:

        A[P] + A[Q] > A[R],
        A[Q] + A[R] > A[P],
        A[R] + A[P] > A[Q].

    For example, consider array A such that:

        A[0] = 10    A[1] = 2    A[2] = 5
        A[3] = 1     A[4] = 8    A[5] = 20

    Triplet (0, 2, 4) is triangular.

Write a function:

        int solution(vector<int> &A);

    that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array 
    and returns 0 otherwise. Assume that:

        >   N is an integer within the range [0..100,000]
        >   each element of array A is an integer within the range [−2,147,483,648..2,147,483,647]

#####################################################################################################################*/

#include <iostream>
#include <vector>
#include <algorithm>
 
using std::vector;

int solution(vector<int> &A);

int main() {

    vector<int> vecA = { 10, 2, 5, 1, 8, 20 };
    vector<int> vecB = { 10, 50, 2, 1 };
    vector<int> vecC = { -10, -7, 5, 10 };
    vector<int> vecD = { 2147483647, 2147483647, 2147483647 };

    std::cout << solution(vecA) << std::endl;
    std::cout << solution(vecB) << std::endl;
    std::cout << solution(vecC) << std::endl;
    std::cout << solution(vecD) << std::endl;

}

int solution(vector<int> &A) {

    //Variables
    int N = A.size();
    //sort array
    sort(A.begin(), A.end());
    //compare consecutive values in groups of 3 on the condition A[i] + A[i+1] > A[i+2]
    for (int i = 0; i < N - 2; i++) {
        if ((long long)A[i] + (long long)A[i + 1] > A[i + 2]) return 1;
    }
    return 0;
}