#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

/*
 * @brief This function converts a Roman numeral string into its decimal (integer) equivalent.
 *
 * @details
 * The Roman numeral system uses specific letters to represent values, and the value of a numeral
 * is determined based on these rules:
 *
 * 1. When characters are grouped together in decreasing order of value, their values are summed.
 *    For example, "VI" is 5 + 1 = 6.
 *
 * 2. If a smaller value precedes a larger value (e.g., "IV"), the smaller value is subtracted
 *    from the larger one. This is known as an inversion.
 *
 * Approach:
 * - The function processes the Roman numeral string from right to left.
 * - It keeps track of consecutive identical characters, calculates their cumulative value, and
 *   determines whether to add or subtract this value based on the previous cumulative sum.
 * - Finally, the function returns the total decimal equivalent of the Roman numeral string.
 *
 * Example 1 : str = "CMXXXVIII"
 *              "C , M , XXX, V, III"
 *              "100, 1000, 5, 3"
 *              "(-100) , 1000, 5,  3"      this is inversion 100 !> 1000 - (100) is subtracted from its previous value
 *              "938"
 *
 * Example 2 : str = "CXXVII"
 *                   "100, (10+10), 5, (1+1)"
 *                   "100 , 20, 5, 2"
 *                   "127"
 */

int roman_to_decimal(string roman)
{
    map<char, int> romanMap = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
        {'*', 0}};

    char prevChar = '*';
    int cnt = 0;
    int n = roman.size();
    int prevSum = 0, totalSum = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        if (roman[i] == prevChar)
        {
            cnt++;
        }
        else
        {
            int curSum = romanMap[prevChar] * cnt;
            if (curSum > prevSum)
            {
                totalSum += curSum;
            }
            else
            {
                totalSum += (prevSum - curSum);
                totalSum -= prevSum;
            }

            prevSum = curSum;
            cnt = 1;
            prevChar = roman[i];
        }
    }

    /* To handle the i = 0th case */
    int curSum = romanMap[prevChar] * cnt;
    if (curSum > prevSum)
    {
        totalSum += curSum;
    }
    else
    {
        totalSum += (prevSum - curSum);
        totalSum -= prevSum;
    }

    return totalSum;
}

/*************************************************************************************************************************************************************/
/* Easier and simpler Code */

int romanToInt(string s)
{
    int n = s.length(), value = 0;
    unordered_map<char, int> rtoi{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    for (int i = 0; i < n - 1; i++)
    {
        if (rtoi[s[i]] >= rtoi[s[i + 1]])
            value += rtoi[s[i]];
        else
            value -= rtoi[s[i]];
    }
    value += rtoi[s[n - 1]];
    return value;
}

vector<string> sortRoman()
{
    vector<string> names = {
        "Steven XL", "Steven XVI", "David IX", "Mary XV", "Mary XIII", "Mary XX"};

    // Using Lambda function for custom comparator
    sort(names.begin(), names.end(), [](string &a, string &b)
         {
        // find the breakpoint i.e.(' ') for both strings
		auto breakpoint_a = a.find(' ');
        auto breakpoint_b = b.find(' ');

		string token1a = a.substr(0, breakpoint_a), token1b = b.substr(0, breakpoint_b);
		string token2a = a.substr(breakpoint_a + 1), token2b = b.substr(breakpoint_b + 1);
        
        // If token1 i.e. the name is same then sort by roman value else by name
		if(token1a == token1b)
			return romanToInt(token2b) >= romanToInt(token2a);
		return token1b > token1a; });

    return names;
}

int main()
{
    cout << roman_to_decimal("XL") << endl;
    cout << romanToInt("XL") << endl;
}