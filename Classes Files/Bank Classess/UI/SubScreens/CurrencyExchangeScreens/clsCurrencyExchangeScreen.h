#pragma once
#include <iostream>
#include <iomanip>

#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"

using namespace std;

class clsCurrencyExchangeScreen :protected clsScreen
{
private:
    enum enCurrencyExchangeMenueOptions
    {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4
    };

    static short ReadCurrencyExchangeMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToCurrencyExchangeMenue()
    {
        cout << "\n\nPress any key to go back to Currency Exchange Menue...";
        system("pause>0");
        ShowCurrencyExchangeScreen();
    }

    static void _ShowListCurrenciesScreen()
    {
        clsCurrenciesListScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRateScreen()
    {
        clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
    }
    static void _ShowCurrencyCalculatorScreen()
    {
        clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
    }

    static void _PerformCurrencyExchangeMenueOption(enCurrencyExchangeMenueOptions CurrencyExchangeMenueOptions)
    {
        switch (CurrencyExchangeMenueOptions)
        {   
            case enCurrencyExchangeMenueOptions::eListCurrencies:
                system("cls");
                _ShowListCurrenciesScreen();
                _GoBackToCurrencyExchangeMenue();
                break;
            case enCurrencyExchangeMenueOptions::eFindCurrency:
                system("cls");
                _ShowFindCurrencyScreen();
                _GoBackToCurrencyExchangeMenue();
                break;
            case enCurrencyExchangeMenueOptions::eUpdateRate:
                system("cls");
                _ShowUpdateRateScreen();
                _GoBackToCurrencyExchangeMenue();
                break;
            case enCurrencyExchangeMenueOptions::eCurrencyCalculator:
                system("cls");
                _ShowCurrencyCalculatorScreen();
                _GoBackToCurrencyExchangeMenue();
                break;
            default:
                break;
        }
    }

public:
    static void ShowCurrencyExchangeScreen()
    {
        system("cls");
        _DrawScreenHeader("\t Currency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t  Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerformCurrencyExchangeMenueOption((enCurrencyExchangeMenueOptions)ReadCurrencyExchangeMenueOption());
    }
};