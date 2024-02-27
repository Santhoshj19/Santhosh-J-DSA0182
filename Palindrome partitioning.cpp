#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome(string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void partitionPalindrome(string s, vector<vector<string>>& partitions, vector<string>& current, int start) {
    if (start == s.length()) {
        partitions.push_back(current);
        return;
    }
    for (int i = start; i < s.length(); i++) {
        string substr = s.substr(start, i - start + 1);
        if (isPalindrome(substr)) {
            current.push_back(substr);
            partitionPalindrome(s, partitions, current, i + 1);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> partitions;
    vector<string> current;
    partitionPalindrome(s, partitions, current, 0);
    return partitions;
}

int main() {
    string s = "aab";
    vector<vector<string>> partitions = partition(s);
    for (vector<string> partition : partitions) {
        for (string palindromicSubstr : partition) {
            cout << palindromicSubstr << " ";
        }
        cout << endl;
    }
    return 0;
}