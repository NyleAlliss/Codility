/*#####################################################################################################################

Created by: Nyle Alliss

Task Score:			100%                                        Created:        09/12/2020
Correctness:		100%                                        Last Edited:    01/04/2021
Performance:		100%
Time Complexity:	O(N)

#######################################################################################################################

A string S consisting of N characters is considered to be properly nested if any of the following conditions are true:

        >   S is empty
        >   S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string
        >   S has the form "VW" where V and W are properly nested strings

    For example, the string "{[()()]}" is properly nested but "([)()]" is not. Write a function:

        int solution(string &S);

    that given a string S consisting of N characters returns 1 if S is properly nester and 0 otherwise. Assume:

        >   N is an integer within the range [0..200,000]
        >   string S consists only of the following characters: "(", "{", "[", "]", "}", and/or ")".

#####################################################################################################################*/

#include <iostream>
#include <string>

using std::string;

int solution(string& A);

int main() {

    string A = "{[()()]}";
    string B = "([)()]";

    std::cout << solution(A) << std::endl;
    std::cout << solution(B) << std::endl;

    return 0;

}

int solution(string& A) {

    //Variables
    int open = 0;
    string open_brackets = "";
    for (auto x : A) {
        switch (x) {
        case '(':
        case '{':
        case '[': {
            open_brackets.resize(++open, x);
            //open++;
            break;
        }
        case ')': {
            if (open > 0 && open_brackets[open - 1] == '(') {
                open_brackets.resize(--open);
            }
            else return 0;
            break;
        }
        case '}': {
            if (open > 0 && open_brackets[open - 1] == '{') {
                open_brackets.resize(--open);
            }
            else return 0;
            break;
        }
        case ']': {
            if (open > 0 && open_brackets[open - 1] == '[') {
                open_brackets.resize(--open);
            }
            else return 0;
            break;
        }

        }

    }
    if (open == 0) return 1;
    return 0;
}