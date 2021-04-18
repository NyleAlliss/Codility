/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        13/12/2020
Correctness:		100%                                        Last Edited:    30/03/2021
Performance:		100%
Time Complexity:	O(N)

#######################################################################################################################

A small frog at (position 0) wants to get to the other side of a river (position X + 1) and must travel across leaves
that fall to the surface of the river each second. The array A consisting of N integers represents the falling leaves.
A[K] represents the position where one leaf falls at time K seconds.

The frog can only cross when leaves appear at every position across the river. the positions of the leaves does not
change after they fall to the surface.

For example, you are given integer X = 5 and array A such that:

		A[0] = 1
		A[1] = 3
		A[2] = 1
		A[3] = 4
		A[4] = 2
		A[5] = 3
		A[6] = 5
		A[7] = 4

In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across 
the river.

Write a function:

		int solution(int X, vector<int> &A);

that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog 
can jump to the other side of the river. If the frog is not able to jump to the other side the function should return
-1.

Write an efficient algorithm for the following assumptions:

		>	N and X are integers within the range [1..100,000];
		>	each element of array A is an integer within the range [1..X].

#####################################################################################################################*/
#include <iostream>
#include <vector>

int solution(int X, std::vector<int>& A);

int main() {

	std::vector<int> vecA = { 1, 3, 100000, 4, 2, 3, 5, 4, };
	std::vector<int> vecB = { 1, 3, 1, 4, 2, 3, 4 };
	std::vector<int> vecC = { 1 };

	std::cout << solution(5, vecA) << std::endl;
	std::cout << solution(5, vecB) << std::endl;
	std::cout << solution(1, vecC) << std::endl;

	return 0;

}

int solution(int X, std::vector<int>& A) {

	int N = A.size();		//Max value that a value can take
	int counter = 0;
	//Create an array of false values the same length as A. leaf_tracker[X] represents whether the value X+1 has occured
	//yet in array A
	std::vector<bool> leaf_tracker(N, false);

	//loop through array
	for (int i = 0; i < N; i++) {
		//Check A[i] is <=X and hasnt already appeared in A
		if ( (A[i] <= X) && (!leaf_tracker[A[i] - 1]) ) {	

			leaf_tracker[A[i] - 1] = true;
			counter++;
			//if counter = x then all the leaves between 1 and X have landed on the surface
			if (counter == X)
				return i;

		}

	}

	return -1;


}
