/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:     100%                                        Created:        19/11/2020
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

int Solution(int N);
std::vector<bool> toBinary(int N);


//If pasting this code into codility please remove the main function
int main()
{
    std::cout << Solution(1041) << std::endl << " " << std::endl;
    std::cout << Solution(6) << std::endl << " " << std::endl;
    std::cout << Solution(99) << std::endl << " " << std::endl;
    std::cout << Solution(512) << std::endl << " " << std::endl;

}

std::vector<bool> toBinary(int N) {

    //This function returns a bool string representing binary value of N. See later version for single function solution.

    /*Note this currently creates the binary in reverse order, this does not affect the solution but could be changed
    with reverse.() from <algorithm> */

    std::vector<bool> toBinary;               //create empty vector
    if (N == 0) {
        std::vector<bool> zero_vec = { 0 };
        return zero_vec;
    };
    while (N != 0) {                        //final while loop executed when N=1

        toBinary.push_back(N % 2 != 0);    //where N%2 == 0 adds 1 to vector, N%2 != 0 adds 0
        N /= 2;

    }

    return toBinary;
}

int Solution(int N) {

    //Call function that creates binary in a vector
    std::vector<bool> binary = toBinary(N);

    //Variables used to measure int gap
    int gap_counter = -1;       //Initial counter set to -1 to prevent counting before a 1
    int max_gap = 0;
    int i = 0;

    while (i != binary.size()) {

        if (binary[i] == 1) {
            if (gap_counter > max_gap) {
                max_gap = gap_counter;
            }

            gap_counter = 0;

        }

        if (gap_counter >= 0 && binary[i] == 0) {
            gap_counter++;
        }

        i++;

    }

    return max_gap;

}