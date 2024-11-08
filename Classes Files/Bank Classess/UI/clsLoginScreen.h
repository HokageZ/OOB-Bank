#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"

class clsLoginScreen :protected clsScreen
{

private:
    static  bool _Login()
    {
        short FailedLoginCount = 0;
        bool LoginFaild = false;

        string Username, Password;
        do
        {
            if (LoginFaild)
            {
                FailedLoginCount++;
                cout << "\nInvlaid Username/Password! Ramaining tries: " << 3 - FailedLoginCount << "\n";
            }

			if (FailedLoginCount == 3)
			{
				cout << "You have reached the maximum number of tries!\n";
				return false;
			}

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild);

        CurrentUser.RegisterLogIn();
        clsMainScreen::ShowMainMenue();
        return true;
    }

public:
    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
        return _Login();
    }
};
