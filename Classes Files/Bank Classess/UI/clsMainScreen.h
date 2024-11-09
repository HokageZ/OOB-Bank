#pragma once
#include <iostream>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsManageUsersScreen.h"
#include "clsCurrencyExchangeScreen.h"
#include "clsLoginScreen.h"
#include "Global.h"

using namespace std;

class clsMainScreen :protected clsScreen
{
private:
    enum enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eLogout = 10
    };

    static short _ReadMainMenueOption(short NumOfOptions)
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to " << NumOfOptions << " ]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, NumOfOptions, "Enter Number between 1 to " + to_string(NumOfOptions)+ " ? ");
        return Choice;
    }

    static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientListScreen::ShowClientsList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsersScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
         clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen()
    {
		clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case enMainMenueOptions::eListClients:
            system("cls");
            if (CheckAccessRights(clsUser::enPermissions::pListClients))
                _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eAddNewClient:
            system("cls");
            if (CheckAccessRights(clsUser::enPermissions::pAddNewClient))
                _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eDeleteClient:
            system("cls");
            if (CheckAccessRights(clsUser::enPermissions::pDeleteClient))
                _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eUpdateClient:
            system("cls");
            if (CheckAccessRights(clsUser::enPermissions::pUpdateClients))
                _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eFindClient:
            system("cls");
            if (CheckAccessRights(clsUser::enPermissions::pFindClient))
                _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eShowTransactionsMenue:
            system("cls");
            if (CheckAccessRights(clsUser::enPermissions::pTranactions))
                _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eManageUsers:
            system("cls");
            if (CheckAccessRights(clsUser::enPermissions::pManageUsers))
                _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        case enMainMenueOptions::eLoginRegister:
            system("cls");
            if (CheckAccessRights(clsUser::enPermissions::pShowLogInRegister))
                _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
		case enMainMenueOptions::eCurrencyExchange:
			system("cls");
			if (CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
				_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;            
        case enMainMenueOptions::eLogout:
            system("cls");
            _Logout();
            break;
        }
    }

public:
    static void ShowMainMenue()
    {
        system("cls");
        _DrawScreenHeader("\t\tMain Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((enMainMenueOptions)_ReadMainMenueOption(10));
    }

};
