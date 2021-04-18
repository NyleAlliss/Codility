/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:		100%                                        Created:        02/02/2020
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(N)

#######################################################################################################################

A permutation is a sequence containing each element from 1 to N once, and only once. For example the array A such that:

		A[0] = 4
		A[1] = 1
		A[2] = 3
		A[3] = 2

	is a permutation, but array A such that:

		A[0] = 4
		A[1] = 1
		A[2] = 3

	is not.

Given that:

		>	N is an integer within range [1..100,000]
		>	each element of array A is integer within the range [1..1,000,000,000]

	write a function:

		int solution(vector<int> &A);

	that, given an array returns 1 if the array is a permutation and 0 if not.

#####################################################################################################################*/

#include <iostream>
#include <vector>

int solution(std::vector<int>& A);

int main() {

	std::vector<int> vecA = { 4, 1, 3, 2 };
	std::vector<int> vecB = { 4 };
	std::vector<int> vecC = { 1 };

	std::cout << solution(vecA) << std::endl;
	std::cout << solution(vecB) << std::endl;
	std::cout << solution(vecC) << std::endl;
	
	
	return 0;

}

int solution(std::vector<int>& A) {

	//Array to track occurence
	int len = A.size();
	//create array with number of elements equal to the max possible value in A
	std::vector<bool> occurence(1000000000, false);
	//set occurence to true for each value, occurence[i] indicates if value i+1 has occured in A
	for (auto x : A) {
		if (occurence[x - 1]) 
			return 0;
		occurence[x - 1] = true;

	}
	//if any values are missing before reaching N-1 return 0
	for (int i = 0; i < len; i++) {
		if (!occurence[i])
			return 0;
	}

	return 1;


}
