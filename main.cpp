#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class PasswordChecker
{
private:
    string password;

public:

    // Constructor
    PasswordChecker(string p)
    {
        password = p;
    }

    // Check if password has at least 8 characters
    bool checkLength()
    {
        return password.length() >= 8;
    }

    // Check for uppercase letter
    bool checkUppercase()
    {
        for (char c : password)
        {
            if (isupper(c))
                return true;
        }

        return false;
    }

    // Check for lowercase letter
    bool checkLowercase()
    {
        for (char c : password)
        {
            if (islower(c))
                return true;
        }

        return false;
    }

    // Check for a digit
    bool checkDigit()
    {
        for (char c : password)
        {
            if (isdigit(c))
                return true;
        }

        return false;
    }

    // Check for a special symbol
    bool checkSymbol()
    {
        for (char c : password)
        {
            if (!isalnum(c))
                return true;
        }

        return false;
    }

    // Calculate password score
    int getScore()
    {
        int score = 0;

        if (checkLength())
            score++;

        if (checkUppercase())
            score++;

        if (checkLowercase())
            score++;

        if (checkDigit())
            score++;

        if (checkSymbol())
            score++;

        return score;
    }

    // Display password result
    void showResult()
    {
        int score = getScore();

        cout << "\nScore: " << score << " / 5" << endl;

        if (score <= 2)
        {
            cout << "Strength: Weak" << endl;
        }
        else if (score <= 4)
        {
            cout << "Strength: Medium" << endl;
        }
        else
        {
            cout << "Strength: Strong" << endl;
        }

        cout << "\nTips:" << endl;

        if (!checkLength())
            cout << "- Use at least 8 characters." << endl;

        if (!checkUppercase())
            cout << "- Add an uppercase letter (A-Z)." << endl;

        if (!checkLowercase())
            cout << "- Add a lowercase letter (a-z)." << endl;

        if (!checkDigit())
            cout << "- Add a digit (0-9)." << endl;

        if (!checkSymbol())
            cout << "- Add a special symbol (! @ # $ % etc.)." << endl;

        if (score == 5)
            cout << "- Nothing to improve. Great password!" << endl;
    }
};

int main()
{
    cout << "PassCheck: Password Checker" << endl;
    cout << "Type 'quit' to exit." << endl;

    while (true)
    {
        string input;

        cout << "\nEnter a password: ";
        getline(cin, input);

        // Exit program
        if (input == "quit")
        {
            cout << "Goodbye!" << endl;
            break;
        }

        // Check for empty password
        if (input.empty())
        {
            cout << "Password cannot be empty." << endl;
            continue;
        }

        // Create PasswordChecker object
        PasswordChecker checker(input);

        // Display result
        checker.showResult();
    }

    return 0;
}