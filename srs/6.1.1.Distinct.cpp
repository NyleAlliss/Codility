/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        09/03/2020
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(N*log(N)) or O(N)

#######################################################################################################################

Write a function

        int solution(vector<int> &A);

    that, given an array A consisting of N integers, returns the number of distinct values in array A.

For example, given array A consisting of six elements such that:

        A[0] = 2    A[1] = 1    A[2] = 1
        A[3] = 2    A[4] = 3    A[5] = 1

the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.


#####################################################################################################################*/

#include <iostream>
#include <vector>

using std::vector;

int solution(vector<int>& A);

int main() {

    vector<int> vecA = { 2, 1, 1, 2, 3, 1 };
    std::cout << solution(vecA) << std::endl;

    //vector<int> vecB = { 4, -3, 3, -2, 1, 5, 8 };
    //std::cout << solution(vecB) << std::endl;

    //vector<int> vecC = { 100, 100, -14, 5, 0, -10, 100 };
    //std::cout << solution(vecC) << std::endl;

    return 0;

}

int solution(vector<int>& A) {

    int upper_lim = 2000000;    //to create vector from [0..2,000,000]
    int shift = 1000000;        //shift required to set value of -1,000,000 to occur at index 0
    int N = A.size();
    int counter = 0;
    //array to hold whether a value has occured
    vector<bool> occurred(upper_lim, false);
    //loop through array
    for (int i = 0; i < N; i++) {
        //if the values corresponding index occured[A[i]+shift] has not occured yet
        if (!occurred[A[i] + shift]) {
            counter++;
            occurred[A[i] + shift] = true;
        }
    }

    return counter;

}
