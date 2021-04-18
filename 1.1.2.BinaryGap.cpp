/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:     100%                                        Created:        21/11/2020
Correctness:    100%                                        Last Edited:    28/03/2021
Performance:    N/A

#######################################################################################################################

Create function that returns the length of the longest binary gap within a positive integer N. This is any maximal
sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example:

    >   9 has binary representation 1001 and contains a binary gap of length 2
    >   529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3
    >   20 has binary representation 10100 and contains one binary gap of length 1
    >   15 has binary representation 1111 and has no binary gaps
    >   The number 32 has binary representation 100000 and has no binary gaps.

Write an efficient algorithm for the following assumptions:

        N is an integer within the range [1..2,147,483,647]

N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary
gap is of length 5

#####################################################################################################################*/

#include <iostream>
#include <vector>

int solution(int N);

int main()
{
    std::cout << "Max binary gap: " << solution(0) << std::endl << std::endl;
    std::cout << "Max binary gap: " << solution(1041) << std::endl << std::endl;
    std::cout << "Max binary gap: " << solution(6) << std::endl << std::endl;
    std::cout << "Max binary gap: " << solution(99) << std::endl << std::endl;
    std::cout << "Max binary gap: " << solution(512) << std::endl << std::endl;
    std::cout << "Max binary gap: " << solution(2147483647) << std::endl << std::endl;

}

//Copy this function to test in Codility
int solution(int N) {

    int gap_counter = -1;       //Initial counter set to -1 to prevent counting before a 1
    int max_gap = 0;

    //if (N == 0) { return max_gap; }

    while (N != 0) {                        //final while loop executed when N=1

        //std::cout << N % 2;                 //Prints binary for user ease - if testing in codility comment line
        if (N % 2) {

            if (gap_counter > max_gap) { max_gap = gap_counter; }

            gap_counter = 0;

        }

        if (gap_counter >= 0 && !(N % 2)) { gap_counter++; }

        N /= 2;

    }

    //std::cout << std::endl;                     //If testing in codility please comment line
    return max_gap;

}
