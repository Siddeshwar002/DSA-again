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