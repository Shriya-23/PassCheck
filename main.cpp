// PassCheck: Password Checker
// Built with standard C++ only

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string password;
    cout << "Enter a password: ";
    getline(cin, password);

    if (password.empty()) {
        cout << "Password cannot be empty." << endl;
        return 0;
    }

    // Look at each character and note which types are present
    bool hasUpper = false, hasLower = false, hasDigit = false, hasSymbol = false;

    for (char c : password) {
        unsigned char ch = static_cast<unsigned char>(c);
        if (isupper(ch))      hasUpper = true;
        else if (islower(ch)) hasLower = true;
        else if (isdigit(ch)) hasDigit = true;
        else                  hasSymbol = true;
    }

    // One point for each rule met (maximum 6)
    int score = 0;
    if (password.length() >= 8)  score++;
    if (password.length() >= 12) score++;
    if (hasUpper)  score++;
    if (hasLower)  score++;
    if (hasDigit)  score++;
    if (hasSymbol) score++;

    // Show the result
    cout << "\nScore: " << score << " / 6" << endl;
    if (score <= 2)      cout << "Strength: Weak" << endl;
    else if (score <= 4) cout << "Strength: Medium" << endl;
    else                 cout << "Strength: Strong" << endl;

    // Show tips for what is missing
    cout << "\nTips:" << endl;
    if (password.length() < 12) cout << "- Use at least 12 characters." << endl;
    if (!hasUpper)  cout << "- Add an uppercase letter (A-Z)." << endl;
    if (!hasLower)  cout << "- Add a lowercase letter (a-z)." << endl;
    if (!hasDigit)  cout << "- Add a digit (0-9)." << endl;
    if (!hasSymbol) cout << "- Add a symbol (! @ # $ % etc.)." << endl;
    if (score == 6) cout << "- Nothing to improve. Great password!" << endl;

    return 0;
}