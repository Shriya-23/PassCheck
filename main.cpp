#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

class Rule {
public:
    virtual bool isSatisfied(const string& password) const = 0;
    virtual string tip() const = 0;
    virtual ~Rule() {}
};

class LengthRule : public Rule {
private:
    int minLength;
public:
    explicit LengthRule(int len) : minLength(len) {}

    bool isSatisfied(const string& password) const override {
        return static_cast<int>(password.length()) >= minLength;
    }

    string tip() const override {
        return "Use at least " + to_string(minLength) + " characters.";
    }
};

class UpperCaseRule : public Rule {
public:
    bool isSatisfied(const string& password) const override {
        for (char c : password)
            if (isupper(static_cast<unsigned char>(c))) return true;
        return false;
    }

    string tip() const override {
        return "Add an uppercase letter (A-Z).";
    }
};

class LowerCaseRule : public Rule {
public:
    bool isSatisfied(const string& password) const override {
        for (char c : password)
            if (islower(static_cast<unsigned char>(c))) return true;
        return false;
    }

    string tip() const override {
        return "Add a lowercase letter (a-z).";
    }
};

class DigitRule : public Rule {
public:
    bool isSatisfied(const string& password) const override {
        for (char c : password)
            if (isdigit(static_cast<unsigned char>(c))) return true;
        return false;
    }

    string tip() const override {
        return "Add a digit (0-9).";
    }
};

class SymbolRule : public Rule {
public:
    bool isSatisfied(const string& password) const override {
        for (char c : password) {
            unsigned char ch = static_cast<unsigned char>(c);
            if (!isupper(ch) && !islower(ch) && !isdigit(ch)) return true;
        }
        return false;
    }

    string tip() const override {
        return "Add a symbol (! @ # $ % etc.).";
    }
};

class PasswordChecker {
private:
    string password;
    vector<Rule*> rules;

public:
    explicit PasswordChecker(const string& pw) : password(pw) {
        rules.push_back(new LengthRule(8));
        rules.push_back(new LengthRule(12));
        rules.push_back(new UpperCaseRule());
        rules.push_back(new LowerCaseRule());
        rules.push_back(new DigitRule());
        rules.push_back(new SymbolRule());
    }

    ~PasswordChecker() {
        for (Rule* r : rules) {
            delete r;
        }
    }

    int getScore() const {
        int score = 0;
        for (const Rule* r : rules) {
            if (r->isSatisfied(password)) score++;
        }
        return score;
    }

    string getStrength() const {
        int score = getScore();
        if (score <= 2) return "Weak";
        if (score <= 4) return "Medium";
        return "Strong";
    }

    void showTips() const {
        bool anyTip = false;
        for (const Rule* r : rules) {
            if (!r->isSatisfied(password)) {
                cout << "- " << r->tip() << endl;
                anyTip = true;
            }
        }
        if (!anyTip) {
            cout << "- Nothing to improve. Great password!" << endl;
        }
    }

    void showReport() const {
        cout << "\nScore: " << getScore() << " / " << rules.size() << endl;
        cout << "Strength: " << getStrength() << endl;
        cout << "\nTips:" << endl;
        showTips();
    }
};

int main() {
    cout << "PassCheck: Password Checker (type 'quit' to exit)" << endl;

    while (true) {
        string input;
        cout << "\nEnter a password: ";
        getline(cin, input);

        if (input == "quit") {
            cout << "Goodbye!" << endl;
            break;
        }
        if (input.empty()) {
            cout << "Password cannot be empty." << endl;
            continue;
        }

        PasswordChecker checker(input);
        checker.showReport();
    }

    return 0;
}