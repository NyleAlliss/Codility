/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:         100%                                        Created:        01/12/2020
Correctness:        100%                                        Last Edited:    28/03/2021
Performance:        100%
Time Complexity:	O(1)

#######################################################################################################################

A frog located at position X want to to the otherside of the road and needs to get to a position greater than Y. The
frog always jumps a set distance D.

Write a function:

        int solution(int X, int Y, int D);

that, given three integers X, Y and D, returns the minimal number of jumps from position X to a position equal to or 
greater than Y.

Write an efficient algorithm for the following assumptions:

        >   X, Y and D are integers within the range [1..1,000,000,000];
        >   X ? Y.

#####################################################################################################################*/
#include <iostream>

int solution(int X, int Y, int D);

int main() {

    std::cout << solution(10, 85, 30) << std::endl;
    std::cout << solution(10, 10, 30) << std::endl;
    std::cout << solution(10, 110, 200) << std::endl;
    
    return 0;

}

//Copy this function into Codility to test
int solution(int X, int Y, int D) {
    
    int distance = Y - X;           //determine distance to travel
    int jumps = distance / D;       //no of whole jumps required to travel distance

    if (distance % D)               //if modulus has remainder an extra jump is required
        jumps++;

    return jumps;

}
