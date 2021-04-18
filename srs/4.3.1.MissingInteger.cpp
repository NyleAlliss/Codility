/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        17/01/2021
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(N)

#######################################################################################################################

Write a function:
		
		int solution(vector<int> &A);

that, given an array A of Nintegers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function would return 5.

	Given A = [1, 2, 3], the function should return 4.

	Given A = [-1, -3 ], the function should return 1.

Write an efficient algorithm for the following assumptions:

		>	N is an integer within the range [1..100,000]
		>	each element of array A is an integer within the range [-1,000,000..1,000,000]

#####################################################################################################################*/

#include <iostream>
#include <vector>

int solution(std::vector<int> &A);

int main() {

	std::vector<int> vecA = { 1, 3, 6, 4, 1, 2 };
	std::vector<int> vecB = { 0 };
	std::vector<int> vecC = { 1, 3, 6, 4, 1, 2 };

	std::cout << solution(vecA) << std::endl;
	std::cout << solution(vecB) << std::endl;
	std::cout << solution(vecC) << std::endl;

	return 0;

}

int solution(std::vector<int> &A) {

	int max_val = 1000000;

	//Create array to track when values have occured
	std::vector<bool> not_occured(max_val, true);
	//track value has occured in array where index number - 1 represent whether that value has occured
	for (auto x : A) {
		if (x > 0) {
			not_occured[x - 1] = false;
		}

	}
	//loop through not_occured vector to find first value that hasnt occured
	for (int i = 0; i < max_val; i++) {
		if (not_occured[i]) {
			return i + 1;
		}

	}
}