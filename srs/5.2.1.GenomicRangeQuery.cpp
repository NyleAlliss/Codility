/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        09/02/2020
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(N + M)

#######################################################################################################################

DNA sequence represnted as a string of letters A, C, G and T, representing nucleotides, each of which has an impact 
factor of 1, 2, 3, and 4 respectively. You are going to answer several queriesof the form: what is the minimal impact 
factor of nucleotides contained in a particular part of a given DNA sequence.

The DNA sequence is given as a non-empty string consisting of N characters. There are M queries, which are given in 
non-empty arraysP and Q, each consisting of M integers. The K-th query (0 <= K < M) requires you to find the minimal 
impact factor of nucleotides contained in the sequence between positions P[k] and Q[K] (inclusive).

For example the string S = CAGCCTA and arrays P, Q such that:

	P[0] = 2	Q[0] = 4
	P[1] = 5	Q[1] = 5
	P[2] = 0	Q[2] = 6

	The Answer to these M = 3 queries are as follows:

		>	Between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 
			respectively, so the answer is 2.
		>	Between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
		>	Between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose 
			impact factor is 1, so the answer is 1.

Write a function:

		vector<int> solution(string &S, vector<int> &P, vector<int> &Q);

	that given the above returns an array consisting of M integers specifying the consecutive answer to all queries.
	For the above example the output should be [2, 4, 1]. Assume that:

		>	N is an integer within the range [1..100,000]
		>	M is an integer within the range [1..50,000];
		>	each element of arrays P, Q is an integer within the range [0..N − 1];
		>   P[K] ≤ Q[K], where 0 ≤ K < M;
		>   string S consists only of upper-case English letters A, C, G, T.

#####################################################################################################################*/

#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

vector<int> solution(string& S, vector<int>& P, vector<int>& Q);

int main() {

	string S1 = "CAGCCTA";
	vector<int> P1 = { 2, 5, 0 }, Q1 = { 4, 5, 6 };

	for (auto x : solution(S1, P1, Q1)) std::cout << x << ' ';


	return 0;
}

vector<int> solution(string& S, vector<int>& P, vector<int>& Q) {

	//variables
	int N = S.size();
	int M = P.size();

	//Vectors for each nucleotide whos values will represent their index in string, A[0] = 3 represents the first A in the
	//string having index value of 3
	vector<int> A = { };
	vector<int> C = { };
	vector<int> G = { };
	vector<int> T = { };
	//iterating though A and using a switch statement to populate the nucleotide vectors
	for (int i = 0; i < N; i++ ) {
		switch (S[i]) {
		case 'A':
			A.push_back(i);
			break;
		case 'C':
			C.push_back(i);
			break;
		case 'G':
			G.push_back(i);
			break;
		default:
			T.push_back(i);
			break;

		}

	}

	//create results vector
	vector<int> result(M, 0);

	//Cycle through each set of instructions in P and Q

		//Search through each nucleotides string in order of ascending impact factor if any values of in the nucleotide vector are in 
		//range defined by [ P[i]..Q[i] ]. If the value is in the range nucleotides impact parameter is placed in results[i] 
		//and we move to instructions an array[ P[i+1]..Q[i+1] ] repeating M times.

	//loop through each set of instructions P[i] and Q[i]
	for (int i = 0; i < M; i++ ) {
		//if there is an A within this range set results[i] = 1;
		for (auto x : A) {
			if (x >= P[i]) {
				if (x > Q[i]) break;
				result[i] = 1;
				break;
			}
		}
		//if there is an C within this range set results[i] = 2;
		if (result[i]) continue;
		for (auto x : C) {
			if (x >= P[i]) {
				if (x > Q[i]) break; 
				result[i] = 2;
				break;
			}
		}
		//if there is an G within this range set results[i] = 3;
		if (result[i]) continue;
		for (auto x : G) {
			if (x >= P[i]) {
				if (x > Q[i]) break;
				result[i] = 3;
				break;
			}
		}
		//if there is a result[i] go to nxt iteration
		if (result[i]) continue;
		//else must contain only T, so set result[i] = 4
		result[i] = 4;

	}

	return result;



}
