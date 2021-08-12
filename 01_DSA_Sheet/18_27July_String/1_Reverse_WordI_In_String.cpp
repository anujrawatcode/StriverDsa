// Reverse words in a given string

// Input: s = “geeks quiz practice code”
// Output: s = “code practice quiz geeks”

// Input: s = “getting good at coding needs a lot of practice”
// Output: s = “practice of lot a needs coding at good getting”

#include <bits/stdc++.h>
using namespace std;

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

string reverseWords(string s)
{
    vector<string> ans;
    istringstream ss(s);
    string word = s;
    while (ss >> word)
        ans.push_back(word);

    reverse(ans.begin(), ans.end());

    string temp = "";
    for (int i = 0; i < ans.size(); i++)
    {
        temp += ans[i] + " ";
    }

    temp.pop_back();
    return temp;
}
int main()
{
    string s;
    // getline(cin, s);
    s = "geeks quiz practice";
    solve(s);
    // cout << s;
}