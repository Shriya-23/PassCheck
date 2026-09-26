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



