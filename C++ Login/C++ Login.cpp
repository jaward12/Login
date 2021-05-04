// C++ Login.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isLoggedIn()
{

    string username, password, un, pw;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream read(username + ".txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;

    cout << "1: Register\n";
    cout << "2: Login\n";
    cout << "Your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        string username, password;

        cout << "Select a username: ";
        cin >> username;
        cout << "Select a password: ";
        cin >> password;

        ofstream file;
        file.open(username + ".txt", ios::out);
        if (file)
        {
            cout << "File created and data got written to file\n";
            file << username << endl << password << endl;
            file.close();
        }
        else
        {
            cout << "Error while creating the file\n";
        }

        main();
    }
    else
    {
        if (isLoggedIn())
        {
            cout << "Successfully logged in!\n";
            system("PAUSE");
            return 1;
        }
        else
        {
            cout << "username or password is wrong\n";
            system("PAUSE");
            return 0;
        }
    }
}
