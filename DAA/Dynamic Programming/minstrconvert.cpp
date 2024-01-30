// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Function to return the minimum
// cost to convert str1 to sr2
int minCost(string str1, string str2, int n)
{
    int cost = 0;

    // For every character of str1
    for (int i = 0; i < n; i++)
    {

        // If current character is not
        // equal in both the strings
        if (str1[i] != str2[i])
        {

            // If the next character is also different in both
            // the strings then these characters can be swapped
            if (i < n - 1 && str1[i + 1] != str2[i + 1])
            {
                swap(str1[i], str1[i + 1]);
                cost++;
            }

            // Change the current character
            else
            {
                cost++;
            }
        }
    }
    return cost;
}

// Driver code
int main()
{
    string str1 = "abb", str2 = "bba";
    int n = str1.length();

    cout << "Min number of operations is :" << minCost(str1, str2, n);

    return 0;
}
