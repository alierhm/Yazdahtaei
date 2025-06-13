//
// Created by Ali on 6/12/2025.
//
#include "getPasswordFromUser.h"
std::string getPasswordFromUser()
{
    string password = "";
    char inputCharacter = 0;

    while (true)
    {

        inputCharacter = _getch(); // get a character and don't show it to user; _getch() is conformant with new C++

        if (inputCharacter == 13)
        { // 13 is ASCII for newline
            cout << endl;
            return password;
        }
        else if (inputCharacter == 8 && password.length() != 0)
        { // 8 is ASCII for backspace
            password.pop_back();
            cout << "\b \b";
            continue;
        }
        else if (inputCharacter == 8 && password.length() == 0)
        {
            continue;
        }
        // if everything was OK, we append it.
        password.push_back(inputCharacter);
        cout << '*';
    }
}