/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        08/12/2020
Correctness:		100%                                        Last Edited:    30/03/2021
Performance:		100%
Time Complexity:	O(N)

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

	int N = A.size();
	unsigned int lowest_value = 2147483647;
	long long int total = 0;
	long long int counter = 0;
	long long int difference = 0;

	//itterate through array to determine the total sum of the array
	for (auto x : A) total += x;

	//loop to determine the sum of first array
	for (int i = 0; i < N - 1; i++) {

		counter += A[i];
		//defference determined using total sum requiring less loops
		difference = abs(2 * counter - total);
		//if absolute difference is the lowest so far the value is stored
		if (difference < lowest_value) lowest_value = difference;

	}

	return lowest_value;

}