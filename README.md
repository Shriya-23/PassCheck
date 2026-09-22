# PassCheck: Password Checker

A simple command-line password strength checker built with C++.

PassCheck reads a password, checks it against a small set of rules, gives a score out of 6, labels it Weak, Medium or Strong, and tells the user what to improve.

---

## Why I Chose This Project

While learning C++, I wanted a project that was small enough for me to understand but still useful in the real world.

A password checker fits this well:

- **It covers the fundamentals:** in one small program you use strings, loops, conditions, booleans, and standard library functions.
- **It teaches secure habits:** it doesn't store or send the password, and it validates input.
- **It's a real-world problem:** everyone uses passwords, so it's easy to explain to both technical and non-technical people.
- **It has a clear, testable result:** you type a password and get an instant score, which helps make my fundamentals strong.

---

## Need for This Project

- Many people still use short, simple passwords such as `123456` or `password`.
- Most users do not know why their password is weak or how to fix it.
- PassCheck addresses this by giving immediate feedback: a score, a strength label, and specific tips on what is missing.
- It works offline and needs no extra libraries.
- It does not store or send the password anywhere.

---

## Features

- Checks password length (8+ and 12+ characters)
- Detects uppercase letters, lowercase letters, digits and symbols
- Calculates a score from 0 to 6
- Classifies the password as **Weak**, **Medium** or **Strong**
- Prints tips for each missing requirement
- Rejects empty input
### Scoring Rules

| Rule | Points |
|------|--------|
| Length of 8 or more characters | 1 |
| Length of 12 or more characters | 1 |
| Contains an uppercase letter (A-Z) | 1 |
| Contains a lowercase letter (a-z) | 1 |
| Contains a digit (0-9) | 1 |
| Contains a symbol (! @ # $ % etc.) | 1 |
| **Maximum score** | **6** |

### Strength Levels

| Score | Result |
|-------|--------|
| 0 to 2 | Weak |
| 3 to 4 | Medium |
| 5 to 6 | Strong |

## C++ Concepts and Technologies Used

### Technologies

| Category | Details |
|----------|---------|
| Language | C++ (C++11 or later) |
| Standard library headers | `<iostream>`, `<string>`, `<cctype>` |
| Compiler | g++ (TDM-GCC 10.3.0) |
| Editor | Visual Studio Code |
| Version control | Git and GitHub |
| Platform | Windows (command line) |
| External libraries | None |

## Learning Outcomes

By building this project I learned how to:

- Set up a C++ development environment (g++ and VS Code) and compile and run a program from the command line
- Take user input safely with `getline`, including passwords that contain spaces
- Use `std::string` and loop through it one character at a time
- Classify characters with `isupper()`, `islower()` and `isdigit()` from `<cctype>`
- Use `bool` flags to record what was found in a loop
- Apply `if`, `else if` and `else` logic to turn a score into a result
- Validate input (rejecting an empty password)
- Write readable, commented code and explain it line by line
- Use Git and GitHub to version and publish my work
- Think critically about my own code by identifying its limitations and planning improvements



