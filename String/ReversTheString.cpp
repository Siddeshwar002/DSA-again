#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    string ans = "";
    if (s.length() == 0)
        return s;

    stack<string> st;
    bool word = false;
    int start;
    s += ' ';
    for (int i = 0; i < s.length(); i++)
    {

        if (s[i] == ' ' and !word)
            continue;
        else if (s[i] != ' ' and !word)
        {
            start = i;
            word = true;
        }
        else if (s[i] == ' ' and word)
        {
            string sub = s.substr(start, i - start + 1);
            cout << sub << endl;
            st.push(sub);
            word = false;
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        // ans += " ";
        cout << st.top() << endl;
        st.pop();
    }
    ans.pop_back();
    return ans;
}

// ! Speacial Funtion - '>>'
// * operator  -->  >>
string reverseWords_2(string s)
{
    vector<string> words;
    stringstream ss(s);
    string tmp;
    while (ss >> tmp)
        words.push_back(tmp);

    string ans;
    for (int i = words.size() - 1; i >= 0; --i)
    {
        if (i != words.size() - 1)
            ans += " ";
        ans += words[i];
    }
    return ans;
}

int main()
{
    // string s = "the sky is blue";
    // string s = "  hello world  ";
    string s = "      a good   example      ";
    string ans = reverseWords_2(s);
    cout << ":" << ans << ":";
}