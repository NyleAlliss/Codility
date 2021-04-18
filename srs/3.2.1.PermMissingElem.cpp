/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			 80%                                        Created:        01/12/2020
Correctness:		100%                                        Last Edited:    30/03/2021
Performance:		 60%
Time complexity:	O(N) or O(N * log(N))

#######################################################################################################################

An array consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which 
means that exactly one element is missiong.

write a function:

			int solution(vector<int> &A);

	that, given an array A, returns the value of the missing element.

For example, given array A such that:

		A[0] = 2
		A[1] = 3
		A[2] = 1
		A[3] = 5
	the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

		>	N is an integer within the range [0..100,000];
		>	the elements of A are all distinct;
		>	each element of array A is an integer within the range [1..(N + 1)].

#####################################################################################################################*/
#include <iostream>
#include <vector>

int solution(std::vector<int>& A);

int main() {

	std::vector<int> vecA = { 2, 3, 1, 5 };
	
	std::cout << solution(vecA) << std::endl;

	return 0;
}

int solution(std::vector<int>& A) {

	int n = A.size() + 1;

	//the sum of all the numbers from 0 to n is given by:
	long int expected = n * (n + 1) / 2;
	long int total = 0;

	for (auto x : A) total += x;

	//comparing the value we obtained to expected can determine the missing number
	return expected - total;

}