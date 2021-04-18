/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        06/02/2020
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(1)

#######################################################################################################################

Write a function:

		int solution(int A, int B, int K);

	that determined the amount of numbers divisible by K in the range [A..B] assuming:

		>	A and B are integers within the range [0..2,000,000,000]
		>	K is an integer within the range [1..2,000,000,000]
		>	A <= B

For example, for A=6, B=11 and K=2, your function should return 3, because there are three numbers divisible by 2 in
the range, namely 6, 8, and 10.



#####################################################################################################################*/

#include <iostream>

int solution(int A, int B, int K);

int main() {

	std::cout << solution(6, 11, 2) << std::endl;
	std::cout << solution(6, 11, 15) << std::endl;
	std::cout << solution(6, 11, 2) << std::endl;


	return 0;

}

int solution(int A, int B, int K) {
    return B / K - A / K + !(A % K);
}