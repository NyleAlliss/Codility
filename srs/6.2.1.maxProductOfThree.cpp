/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        14/03/2020
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(N * log(N))

#######################################################################################################################

A non-empty array A consisting of N integers is given. the product of triplet (P, Q, R) equates to A[P]*A[Q]*A[R] 
(0 <= P < Q < R < N). For example, array A such that:

        A[0] = -3
        A[1] =  1
        A[2] =  2
        A[3] = -2
        A[4] =  5
        A[5] =  6

    contains the following example triplets

        >   (0, 1, 2), product is −3 * 1 * 2 = −6
        >   (1, 2, 4), product is  1 * 2 * 5 = 10
        >   (2, 4, 5), product is  2 * 5 * 6 = 60

Write a function:

        int solution(vector<int> &A);

    that, given a non-empty array A, returns the value of the maximal product of any triplet. Assume:

        >   N is an integer within the range [3..100,000];
        >   each element of array A is an integer within the range [-1,000...1,000].

#####################################################################################################################*/

#include <iostream>
#include <vector>
#include <algorithm>        //needed when testing solution

using std::vector;

int solution(vector<int>& A);

int main() {

    vector<int> vecA = { -3, 1, 2, -2, 5, 6 };
    std::cout << solution(vecA) << std::endl;

    //vector<int> vecB = { 4, -3, 3, -2, 1, 5, 8 };
    //std::cout << solution(vecB) << std::endl;

    //vector<int> vecC = { 100, 100, -14, 5, 0, -10, 100 };
    //std::cout << solution(vecC) << std::endl;

    return 0;

}

//Paste into codility to test
int solution(vector<int>& A) {

    //Variable
    int N = A.size();

    //Case only 3 elements
    if (N == 3) return A[0] * A[1] * A[2];

    //Case only 4 elements
    if (N == 4) {
        if (A[0] * A[1] * A[2] > A[1] * A[2] * A[3]) return A[0] * A[1] * A[2];
        else return A[1] * A[2] * A[3];
    }
    
    //sort array
    std::sort(A.begin(), A.end());          //include <algorithm> if testing in Codility

    //Case all elements are <= 0
    if (A[N - 1] <= 0) return A[N - 1] * A[N - 2] * A[N - 3];

    //comparing product of two largest ves to 2nd and 3rd largest +ves
    if (A[0] * A[1] > A[N - 2] * A[N - 3]) { //-ves are larger
        return A[0] * A[1] * A[N - 1];
    }
    else return A[N - 1] * A[N - 2] * A[N - 3];

}
