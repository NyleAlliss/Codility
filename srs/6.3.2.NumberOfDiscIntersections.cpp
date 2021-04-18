/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        20/03/2020
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(N*log(N)) or O(N)

#######################################################################################################################

N discs are drawn on a plane. The discs are numbered from 0 to N-1. An array A of N non-negative integers, specifying
the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say the J-th disc and K-th disc intersects if J != K and the J-th and K-th discs have at least one common point
(assuming that the discs contain their borders

See diagram: https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/

For the array:

        A[0] = 1
        A[1] = 5
        A[2] = 2
        A[3] = 1
        A[4] = 4
        A[5] = 0

    there are 11 (unorderer pairs of discs that intersect, namely:

        >   discs 1 and 4 intersect, and both intersect with all other discs;
        >   disc 2 also interacts with disc 0 and 3.

Write a function:

        int solution(vector<int> &A);

    that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of
    intersecting discs. The function should return ?1 if the number of intersecting pairs exceeds 10,000,000. Assume:

        >   N is an integer within the range [0..100,000]
        >   each element of array A is an integer within the range[0..2147483647]

#####################################################################################################################*/

#include <iostream>
#include <vector>
#include <algorithm>        

using std::vector;

int solution(vector<int>& A);

int main() {

    vector<long> A1(10);
    for (auto x : A1) std::cout << x << ' ';
    std::cout << std::endl;

    vector<int> vecA = { 1, 5, 2, 1, 4, 0 };
    std::cout << solution(vecA) << std::endl;

    vector<int> vecB = { 1, 2147483647, 0 };
    std::cout << solution(vecB) << std::endl;

    //vector<int> vecC = { 100, 100, -14, 5, 0, -10, 100 };
    //std::cout << solution(vecC) << std::endl;

    return 0;

}

int solution(vector<int>& A) {

    //Variables
    long int N = A.size();
    long long int counter = 0;
    int j = 0;
    int opened = 0;
    long long int open = 0;

    //Case empty arrary
    if (N == 0) return 0;

    //Create, fill, and sort vectors containing the upper and lower bound of each circle
    vector<long long int> upper(N, 0);
    vector<long long int> lower(N, 0);

    for (int i = 0; i < N; i++) {

        upper[i] = (long long)i + A[i];
        lower[i] = (long long)i - A[i];

    }

    std::sort(upper.begin(), upper.end());
    std::sort(lower.begin(), lower.end());

    //As we move along the axis each time we cross a lower value a circle opens (open++), each time we reach a upper 
    // bound a circle closes (open--). Each time a circle opens the number of circles it intersects with is given by
    //(open - 1).

    for (int i = 0; i < N; i++) {
        //while values of lower are below the next upper bound open++
        while (lower[j] <= upper[i]) {
            open++;
            counter += open - 1;
            j++;
            opened++;
            //return -1 if no of intersections exceeds limit
            if (counter > 10000000) return -1;
            //once every circle has been opened there can be no more intersections
            if (opened == N) return counter;
        }
        //Else we have a close ncounter a close
        open--;

    }

    return -1;

}