#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

string generatePassword(int length, bool includeUppercase, bool includeLowercase, bool includeDigits, bool includeSpecialChars) {
    const string uppercaseChars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lowercaseChars = "abcdefghijklmnopqrstuvwxyz";
    const string digitChars = "0123456789";
    const string specialChars = "!@#$%^&*()";

    string password = "";

    string charSet = "";
    if (includeUppercase)
        charSet += uppercaseChars;
    if (includeLowercase)
        charSet += lowercaseChars;
    if (includeDigits)
        charSet += digitChars;
    if (includeSpecialChars)
        charSet += specialChars;

    int charSetLength = charSet.length();

    srand(time(0));

    for (int i = 0; i < length; i++) {
        int randomIndex = rand() % charSetLength;
        password += charSet[randomIndex];
    }

    return password;
}

enum PasswordStrength
{
    WEAK,
    MEDIUM,
    STRONG
};

// Check password length
bool checkLength(const std::string &password)
{
    return password.length() >= 8;
}

// Check if password contains uppercase letters
bool checkUppercase(const std::string &password)
{
    for (char c : password)
    {
        if (std::isupper(c))
        {
            return true;
        }
    }
    return false;
}

// Check if password contains lowercase letters
bool checkLowercase(const std::string &password)
{
    for (char c : password)
    {
        if (std::islower(c))
        {
            return true;
        }
    }
    return false;
}

// Check if password contains numbers
bool checkNumbers(const std::string &password)
{
    for (char c : password)
    {
        if (std::isdigit(c))
        {
            return true;
        }
    }
    return false;
}

// Check if password contains special characters
bool checkSpecialCharacters(const std::string &password)
{
    for (char c : password)
    {
        if (!std::isalnum(c))
        {
            return true;
        }
    }
    return false;
}

// Estimate password strength
PasswordStrength estimatePasswordStrength(const std::string &password)
{
    bool hasLength = checkLength(password);
    bool hasUppercase = checkUppercase(password);
    bool hasLowercase = checkLowercase(password);
    bool hasNumbers = checkNumbers(password);
    bool hasSpecialCharacters = checkSpecialCharacters(password);

    if (hasLength && hasUppercase && hasLowercase && hasNumbers && hasSpecialCharacters)
    {
        return STRONG;
    }
    else if (hasLength && ((hasUppercase && hasLowercase) || (hasUppercase && hasNumbers) || (hasLowercase && hasNumbers)))
    {
        return MEDIUM;
    }
    else
    {
        return WEAK;
    }
}

int main()
{

    cout<<"1 for check strength"<<endl;
    cout<<"2 for generate password"<<endl;
    int x; cin>>x;
    if(x==1){

    std::string password;
    std::cout << "Enter a password: ";
    std::cin >> password;

    PasswordStrength strength = estimatePasswordStrength(password);

    std::cout << "Password Strength: ";
    switch (strength)
    {
    case WEAK:
        std::cout << "Weak" << std::endl;
        break;
    case MEDIUM:
        std::cout << "Medium" << std::endl;
        break;
    case STRONG:
        std::cout << "Strong" << std::endl;
        break;
    }
    }
    else{
        int length;
    bool includeUppercase, includeLowercase, includeDigits, includeSpecialChars;

    cout << "Enter the length of the password: ";
    cin >> length;

    cout << "Include uppercase letters? (1 for Yes, 0 for No): ";
    cin >> includeUppercase;

    cout << "Include lowercase letters? (1 for Yes, 0 for No): ";
    cin >> includeLowercase;

    cout << "Include digits? (1 for Yes, 0 for No): ";
    cin >> includeDigits;

    cout << "Include special characters? (1 for Yes, 0 for No): ";
    cin >> includeSpecialChars;

    string password = generatePassword(length, includeUppercase, includeLowercase, includeDigits, includeSpecialChars);

    cout << "Generated password: " << password << endl;



    }

    return 0;
}