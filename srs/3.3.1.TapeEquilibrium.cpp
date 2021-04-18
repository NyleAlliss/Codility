/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			 69%                                        Created:        03/12/2020
Correctness:		100%                                        Last Edited:    30/03/2021
Performance:		 33%
Time Complexity:	O(N*N)

#######################################################################################################################

A non-empty array A consisting of N integers is given. Array A represents numbers on a tape. Any integer P, such that 
0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1]. 
We want to determine the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

		A[0] = 3
		A[1] = 1
		A[2] = 2
		A[3] = 4
		A[4] = 3
We can split this tape in four places:

		P = 1, difference = |3 − 10| = 7
		P = 2, difference = |4 − 9| = 5
		P = 3, difference = |6 − 7| = 1
		P = 4, difference = |10 − 3| = 7

Write a function:

		int solution(vector<int> &A);

	that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

Write an efficient algorithm for the following assumptions:

		>	N is an integer within the range [2..100,000];
		>	each element of array A is an integer within the range [−1,000..1,000].

#####################################################################################################################*/

#include <iostream>
#include <vector>

int solution(std::vector<int>& A);

int main() {

	std::vector<int> vecA = { 3, 1, 2, 4, 3 };
	std::vector<int> vecB = { 3, 1 };
	std::vector<int> vecC = { 3, 1, 2, 4, 500 };
	std::vector<int> vecD = { 100, 1, 2, 4, 3 };

	std::cout << solution(vecA) << std::endl;
	std::cout << solution(vecB) << std::endl;
	std::cout << solution(vecC) << std::endl;
	std::cout << solution(vecD) << std::endl;
	

	return 0;

}

//Paste into Codility to test
int solution(std::vector<int>& A) {

	int length = A.size();
	unsigned int lowest_value = 2147483647;
	
	//case of only 2 elements in array
	if (length == 2) return abs(A[0] - A[1]);

	//itterate through points in which the array can be split
	for (int j = 1; j < length; j++) {

		long long int sum_one = 0;
		long long int sum_two = 0;

		//for loop determines sum of first half of array
		for (int i = 0; i < j; i++) sum_one += A[i];

		//for loop to determine the sum of the second half
		for (int i = j; i < length; i++) sum_two += A[i];

		//Case if the sum of both halfs is equal (no difference)
		if (sum_one == sum_two)
			return 0;

		unsigned int difference = abs(sum_one - sum_two);

		//if absolute difference is the lowest so far the value is stored
		if (difference < lowest_value) {
			lowest_value = difference;

		}


	}


	return lowest_value;

}