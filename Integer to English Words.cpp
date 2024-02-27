#include <iostream>
#include <vector>
#include <string>

using namespace std;

string below_20[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                    "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string thousands[] = {"", "Thousand", "Million", "Billion"};

string numberToWords(int num) {
    if (num == 0) return "Zero";
    string res = "";
    int i = 0;
    while (num > 0) {
        if (num % 1000 != 0) {
            res = helper(num % 1000) + thousands[i] + " " + res;
        }
        num /= 1000;
        i++;
    }
    // remove trailing space
    while (res.back() == ' ') res.pop_back();
    return res;
}

string helper(int num) {
    if (num == 0) return "";
    else if (num < 20) return below_20[num] + " ";
    else if (num < 100) return tens[num / 10] + " " + helper(num % 10);
    else return below_20[num / 100] + " Hundred " + helper(num % 100);
}

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << numberToWords(num) << endl;
    return 0;
}