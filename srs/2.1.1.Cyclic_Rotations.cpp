/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:     100%                                        Created:        21/11/2020
Correctness:    100%                                        Last Edited:    28/03/2021
Performance:    N/A

#######################################################################################################################

Create a function that rotates a vector by a given amount K. Rotation of the vector causes the elements to move to the
by K places, with the value in the final element of the vector being shifted back to the start.

Write a function:

            vector<int> solution(vector<int> &A, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]

Assume that:

        >   N and K are integers within the range [0..100];
        >   each element of array A is an integer within the range [−1,000..1,000].

#####################################################################################################################*/

#include <vector>
#include <iostream>

std::vector<int> solution(std::vector<int> &A, int K);
void vector_print(std::vector<int> A);

int main() {

    std::vector<int> vecA = { 3, 8, 9, 7, 6 };
    std::vector<int> vecB = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::vector<int> vecC = { -5, 4, 8, 0, -6, 4 };
    std::vector<int> vecD = { };

    vector_print(solution(vecA, 3));
    std::cout << std::endl;
    vector_print(solution(vecB, 6));
    std::cout << std::endl;
    vector_print(solution(vecC, 4));
    std::cout << std::endl;
    vector_print(solution(vecA, 7));
    std::cout << std::endl;
    vector_print(solution(vecA, 0));
    std::cout << std::endl;
    vector_print(solution(vecD, 0));
    
    return 0;

}

//Copy this function into Codility to test
std::vector<int> solution(std::vector<int> &A, int K) {

    int length = A.size();

    //Case of empty vector
    if (length == 0)  return A; 

    int shift = K % length;                 //Determine effective shift (shifting a N=6 array by 9, is 
                                            //the same as shifting by 3) each value

    //Case that effective shift 
    if (shift == 0) { return A; }          

    //find the index value that will be [0] in the new vector and push_back from there
    int i = length - shift;                 
    std::vector<int> temp = {};

    //Push_back from new [0] point to the end
    while (i < length) {

        temp.push_back(A[i]);
        i++;

    }
    
    i = 0;

    //Push_back from 0 to the new [0] point
    while (i < length - shift) {

        temp.push_back(A[i]);
        i++;

    }

    return temp;

}


//function to print vector
void vector_print(std::vector<int> B) {

    int length = B.size();

    if (length == 0) {

        std::cout << "[ ]";
        return;
    }

    std::cout << "[";
    for (int i = 0; i < (length - 1); i++) {
        std::cout << B[i] << ", ";
    }
    std::cout << B[(length - 1)] << "]";

}