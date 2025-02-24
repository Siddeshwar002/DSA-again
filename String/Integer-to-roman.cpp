// My Code 
// If else way of handling

class Solution {
public:
    string intToRoman(int num) {
        string num_str = to_string(num);
        string ans = "";
        int n = num_str.length();

        map<int, string> numToRoman = {{1, "I"},   {5, "V"},   {10, "X"},
                                       {50, "L"},  {100, "C"}, {500, "D"},
                                       {1000, "M"}};

        for (int i = 0; i < num_str.length(); i++) {
            int num1 = num_str[i] - '0';
            if(num1 == 0)continue;

            if (num1 == 4) {
                int num2 = 5;
                int num3 = pow(10, (n - 1 - i));

                ans += numToRoman[num3];
                ans += numToRoman[num2 * num3];
            } else if (num1 == 9) {
                int num2 = 10;
                int num3 = pow(10, (n - 1 - i));

                ans += numToRoman[num3];
                ans += numToRoman[num2 * num3];
            } else if (num1 > 5) {
                int num4 = pow(10, (n - 1 - i));
                int num2 = 5 * num4;
                int num3 = num1 % 5;

                ans += numToRoman[num2];

                for (int i = 1; i <= num3; i++)
                    ans += numToRoman[num4];
            } else if (num1 < 5) {
                int num3 = num1;
                int num4 = pow(10, (n - 1 - i));

                for (int i = 1; i <= num3; i++)
                    ans += numToRoman[num4];
            } else if (num1 == 5) {
                int num4 = pow(10, (n-1-i));
                ans += numToRoman[5*num4];
            }
        }
        return ans;
    }
};

// ------------------------------------------------------------------------------------------
// TC : O(13 * N)

class Solution {
public:
    std::string intToRoman(int num) {
        // Define Roman numeral symbols and their corresponding values
        std::vector<std::pair<int, std::string>> valueSymbols = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        
        std::string result;

        for (const auto& [value, symbol] : valueSymbols) {
            // for each avale check if you can accomodate that value
            // If yes then consider that and build your string

            while (num >= value) {
                result += symbol;
                num -= value;
            }

            // Early exit if num becomes 0
            if (num == 0) {
                break;
            }
        }
        return result;
    }
};

// ------------------------------------------------------------------------------------------
// TC : O(mapSize * N)


class Solution {
public:
    std::string intToRoman(int num) {
        // Define Roman numeral symbols and their corresponding values
        std::vector<std::pair<int, std::string>> valueSymbols = {
            {100000, "(C)"},  // 100,000 : 10^5
            {90000, "(XC)"},  // 90,000
            {50000, "(L)"},   // 50,000
            {40000, "(XL)"},  // 40,000
            {10000, "(X)"},   // 10,000
            {9000, "(IX)"},   // 9,000
            {5000, "(V)"},    // 5,000
            {4000, "(IV)"},   // 4,000
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };
        
        std::string result;

        for (const auto& [value, symbol] : valueSymbols) {
            // Append the symbol while the value can be subtracted from num
            // If yes then consider that and build your string

            while (num >= value) {
                result += symbol;
                num -= value;
            }

            // Early exit if num becomes 0
            if (num == 0) {
                break;
            }
        }
        return result;
    }
};