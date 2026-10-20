// Input/output er jonno (cin, cout) header
#include <iostream>
// Output format korar jonno (setprecision) header
#include <iomanip>
// Dynamic array (vector) use korar jonno header
#include <vector>
// String type use korar jonno header
#include <string>
// Math function (round, isfinite) er jonno header
#include <cmath>
// size_t type er jonno header
#include <cstddef>
// numeric_limits use korar jonno header
#include <limits>
// Character function (toupper) er jonno header
#include <cctype>

// std:: likha chhara cout, cin, string etc. use korar jonno
using namespace std;

// Maximum koyta account toiri kora jabe
constexpr size_t MAX_ACCOUNTS = 100;
// Ekta account e maximum koto taka thakte parbe
constexpr double MAX_BALANCE = 1000000.0;
// Interest er jonno maximum din (100 bochhor)
constexpr int MAX_DAYS = 36500;

// 1 USD = koto EUR (fictional rate)
constexpr double USD_TO_EUR = 0.85;
// 1 USD = koto JPY (fictional rate)
constexpr double USD_TO_JPY = 110.0;

// Account er sob information ekshathe rakhar struct
struct Account
{
    int accountNumber;   // Account er unique number
    string ownerName;    // Account malikar naam
    double balance;      // Account e current taka
    char accountType;    // 'S' = Savings, 'C' = Checking
};

// Menu dekhanor function er declaration
void displayMenu();
// Notun account toiri korar function er declaration
Account createAccount(int accountNum);
// Taka jama dewar function er declaration
bool deposit(Account& account, double amount);
// Taka tola/withdraw korar function er declaration
bool withdraw(Account& account, double amount);
// Interest hishab korar function er declaration
double calculateInterest(const Account& account, int days);
// Currency convert korar function er declaration
double convertCurrency(double amount, char fromCurrency, char toCurrency);
// Account er summary dekhanor function er declaration
void displayAccountSummary(const Account& account);
// Boundary condition test korar function er declaration
void testBoundaryConditions();
// Taka ke cent (2 decimal) e round korar function er declaration
double roundMoney(double value);
// Character ke uppercase korar function er declaration
char toUpperChar(char c);
// Line er baki ongsho fele dewar function er declaration
void discardLine();
// Safe vabe int input newar function er declaration
bool readInt(int& out);
// Safe vabe double input newar function er declaration
bool readDouble(double& out);
// Safe vabe char input newar function er declaration
bool readChar(char& out);
// Account number diye account khujar function er declaration
Account* findAccount(int num);

// Sob account store korar global vector
vector<Account> accounts;

// Program ekhan theke shuru hoy
int main()
{
    // Program er title print kora hocche
    cout << "===== BANK ACCOUNT SYSTEM =====" << endl;
    // Program ta ki kore ta bola hocche
    cout << "This program demonstrates a simple banking system." << endl;
    // Ekta faka line print kora hocche
    cout << endl;

    // User er menu choice rakhar variable
    int choice = 0;
    // Notun account er number 100 theke shuru hobe
    int accountCounter = 100;

    // Menu bar bar dekhanor loop shuru
    do
    {
        // Menu print kora hocche
        displayMenu();
        // User ke choice dite bola hocche
        cout << "Enter your choice: ";
        // Input invalid hole choice 0 kore deya hocche
        if (!readInt(choice))
        {
            choice = 0;
        }

        // Choice onujayi kaj bhaag kora hocche
        switch (choice)
        {
        // Case 1: Notun account toiri
        case 1:
        {
            // Account limit er niche thakle
            if (accounts.size() < MAX_ACCOUNTS)
            {
                // Notun account toiri kore counter 1 baranor hocche
                Account newAccount = createAccount(accountCounter++);
                // Account ta list e jog kora hocche
                accounts.push_back(newAccount);
                // Success message
                cout << "Account created successfully!" << endl;
                // Notun account er summary dekhano
                displayAccountSummary(newAccount);
            }
            else
            {
                // Limit shesh hole message
                cout << "Maximum number of accounts reached." << endl;
            }
            // Switch theke berhiye jawa
            break;
        }

        // Case 2: Taka jama dewa
        case 2:
        {
            // Account number rakhar variable
            int accNum;
            // Jamar poriman rakhar variable
            double amount;
            // Account number chaowa hocche
            cout << "Enter account number: ";
            // Input thik na hole error dekhiye break
            if (!readInt(accNum))
            {
                cout << "Invalid input." << endl;
                break;
            }

            // Account khuje pointer ana hocche
            Account* acc = findAccount(accNum);
            // Account na pele message dekhiye break
            if (!acc)
            {
                cout << "Account not found." << endl;
                break;
            }

            // Koto taka jama dibe ta chaowa hocche
            cout << "Enter amount to deposit: ";
            // Input thik na hole error dekhiye break
            if (!readDouble(amount))
            {
                cout << "Invalid input." << endl;
                break;
            }

            // Deposit successful hole
            if (deposit(*acc, amount))
            {
                // Success message
                cout << "Deposit successful!" << endl;
                // Update howa summary dekhano
                displayAccountSummary(*acc);
            }
            else
            {
                // Fail hole error message
                cout << "Invalid amount or maximum balance exceeded." << endl;
            }
            // Switch theke berhiye jawa
            break;
        }

        // Case 3: Taka tola
        case 3:
        {
            // Account number rakhar variable
            int accNum;
            // Tolar poriman rakhar variable
            double amount;
            // Account number chaowa hocche
            cout << "Enter account number: ";
            // Input thik na hole error dekhiye break
            if (!readInt(accNum))
            {
                cout << "Invalid input." << endl;
                break;
            }

            // Account khuje pointer ana hocche
            Account* acc = findAccount(accNum);
            // Account na pele message dekhiye break
            if (!acc)
            {
                cout << "Account not found." << endl;
                break;
            }

            // Koto taka tulbe ta chaowa hocche
            cout << "Enter amount to withdraw: ";
            // Input thik na hole error dekhiye break
            if (!readDouble(amount))
            {
                cout << "Invalid input." << endl;
                break;
            }

            // Withdraw successful hole
            if (withdraw(*acc, amount))
            {
                // Success message
                cout << "Withdrawal successful!" << endl;
                // Update howa summary dekhano
                displayAccountSummary(*acc);
            }
            else
            {
                // Fail hole error message
                cout << "Insufficient funds or invalid amount." << endl;
            }
            // Switch theke berhiye jawa
            break;
        }

        // Case 4: Interest hishab
        case 4:
        {
            // Account number ar din rakhar variable
            int accNum, days;
            // Account number chaowa hocche
            cout << "Enter account number: ";
            // Input thik na hole error dekhiye break
            if (!readInt(accNum))
            {
                cout << "Invalid input." << endl;
                break;
            }

            // Account khuje pointer ana hocche
            Account* acc = findAccount(accNum);
            // Account na pele message dekhiye break
            if (!acc)
            {
                cout << "Account not found." << endl;
                break;
            }

            // Koto din er interest ta chaowa hocche
            cout << "Enter number of days (0-" << MAX_DAYS << "): ";
            // Din invalid ba range er baire hole error
            if (!readInt(days) || days < 0 || days > MAX_DAYS)
            {
                cout << "Invalid number of days." << endl;
                break;
            }

            // Interest hishab kora hocche
            double interest = calculateInterest(*acc, days);
            // Output 2 decimal fixed format e set kora
            cout << fixed << setprecision(2);
            // Interest er poriman dekhano
            cout << "Interest earned after " << days << " days: $" << interest << endl;
            // Interest soho balance koto hobe dekhano
            cout << "Balance with interest would be: $" << acc->balance + interest << endl;

            // Interest 0 ba kom hole apply korar dorkar nai
            if (interest <= 0.0)
            {
                cout << "No interest to apply." << endl;
                break;
            }

            // User ke interest apply korbe kina jiggesh kora
            cout << "Apply interest to the balance? (Y/N): ";
            // User er uttor rakhar variable
            char ans;
            // Uttor 'Y' hole interest jog hobe
            if (readChar(ans) && toUpperChar(ans) == 'Y')
            {
                // Interest ke deposit hishabe jog kora
                if (deposit(*acc, interest))
                {
                    // Success message
                    cout << "Interest applied!" << endl;
                    // Update howa summary dekhano
                    displayAccountSummary(*acc);
                }
                else
                {
                    // Max balance cross korle error
                    cout << "Cannot apply: maximum balance exceeded." << endl;
                }
            }
            else
            {
                // User na bolle ba invalid hole
                cout << "Interest not applied." << endl;
            }
            // Switch theke berhiye jawa
            break;
        }

        // Case 5: Currency convert
        case 5:
        {
            // Account number rakhar variable
            int accNum;
            // Kon currency theke kon currency, tar variable
            char fromCurr, toCurr;
            // Account number chaowa hocche
            cout << "Enter account number: ";
            // Input thik na hole error dekhiye break
            if (!readInt(accNum))
            {
                cout << "Invalid input." << endl;
                break;
            }

            // Account khuje pointer ana hocche
            Account* acc = findAccount(accNum);
            // Account na pele message dekhiye break
            if (!acc)
            {
                cout << "Account not found." << endl;
                break;
            }

            // Currency er option dekhano
            cout << "Available currencies: U (USD), E (EUR), J (JPY)" << endl;
            // Source currency chaowa hocche
            cout << "From currency (U/E/J): ";
            // Input thik na hole error dekhiye break
            if (!readChar(fromCurr))
            {
                cout << "Invalid input." << endl;
                break;
            }
            // Target currency chaowa hocche
            cout << "To currency (U/E/J): ";
            // Input thik na hole error dekhiye break
            if (!readChar(toCurr))
            {
                cout << "Invalid input." << endl;
                break;
            }

            // Source currency uppercase kora
            char from = toUpperChar(fromCurr);
            // Target currency uppercase kora
            char to = toUpperChar(toCurr);

            // Source currency valid kina check
            bool validFrom = (from == 'U' || from == 'E' || from == 'J');
            // Target currency valid kina check
            bool validTo = (to == 'U' || to == 'E' || to == 'J');

            // Kono ekta invalid hole error
            if (!validFrom || !validTo)
            {
                cout << "Invalid currency selection." << endl;
                break;
            }

            // Balance ke convert kora hocche
            double convertedAmount = convertCurrency(acc->balance, from, to);

            // Result er label print shuru
            cout << "Converted amount: ";
            // Target currency er naam print kora
            switch (to)
            {
            case 'U':
                cout << "USD ";
                break;
            case 'E':
                cout << "EUR ";
                break;
            case 'J':
                cout << "JPY ";
                break;
            }
            // Converted poriman 2 decimal e print
            cout << fixed << setprecision(2) << convertedAmount << endl;
            // Switch theke berhiye jawa
            break;
        }

        // Case 6: Sob account dekhano
        case 6:
        {
            // Kono account na thakle message
            if (accounts.empty())
            {
                cout << "No accounts to display." << endl;
            }
            else
            {
                // Heading print
                cout << "\n===== ACCOUNT SUMMARIES =====" << endl;
                // Prottek account er upor loop
                for (const Account& acc : accounts)
                {
                    // Account er summary dekhano
                    displayAccountSummary(acc);
                    // Alada korar line
                    cout << "----------------------------" << endl;
                }
            }
            // Switch theke berhiye jawa
            break;
        }

        // Case 7: Boundary test chalano
        case 7:
            // Test function call
            testBoundaryConditions();
            // Switch theke berhiye jawa
            break;

        // Case 8: Program shesh
        case 8:
            // Biday message
            cout << "Exiting program. Thank you!" << endl;
            // Switch theke berhiye jawa
            break;

        // Onno kono choice hole
        default:
            // Invalid choice message
            cout << "Invalid choice. Please try again." << endl;
        }

        // Menu r moddhe faka line
        cout << endl;

        // Input stream bondho hoye gele loop theke berhiye jao
        if (cin.eof()) break;
        // Choice 8 na howa porjonto loop cholbe
    }
    while (choice != 8);

    // Program successfully shesh
    return 0;
}

// Taka ke nearest cent e round kore
double roundMoney(double value)
{
    // 100 diye gun, round, abar 100 diye bhag
    return std::round(value * 100.0) / 100.0;
}

// Ekta character ke uppercase e convert kore
char toUpperChar(char c)
{
    // unsigned char e cast kore toupper call, abar char e fera
    return static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
}

// Current line er baki shob input fele dey
void discardLine()
{
    // Newline ('\n') pawa porjonto shob ignore kore
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Ekta int input pore, success hole true dey
bool readInt(int& out)
{
    // Input porte fail hole
    if (!(cin >> out))
    {
        // Stream shesh hoye gele false
        if (cin.eof()) return false;
        // Error flag clear kora
        cin.clear();
        // Kharap line fele deya
        discardLine();
        // Fail bole jana
        return false;
    }
    // Input er baki ongsho fele deya
    discardLine();
    // Success
    return true;
}

// Ekta double input pore, valid (finite) hole true dey
bool readDouble(double& out)
{
    // Input porte fail hole
    if (!(cin >> out))
    {
        // Stream shesh hoye gele false
        if (cin.eof()) return false;
        // Error flag clear kora
        cin.clear();
        // Kharap line fele deya
        discardLine();
        // Fail bole jana
        return false;
    }
    // Input er baki ongsho fele deya
    discardLine();
    // nan ba inf hole false, noile true
    return std::isfinite(out);
}

// Ekta character input pore, success hole true dey
bool readChar(char& out)
{
    // Input porte fail hole
    if (!(cin >> out))
    {
        // Stream shesh hoye gele false
        if (cin.eof()) return false;
        // Error flag clear kora
        cin.clear();
        // Kharap line fele deya
        discardLine();
        // Fail bole jana
        return false;
    }
    // Input er baki ongsho fele deya
    discardLine();
    // Success
    return true;
}

// Account number diye account khuje pointer dey
Account* findAccount(int num)
{
    // Sob account er upor loop (reference diye)
    for (auto& a : accounts)
    {
        // Number mile gele oi account er address return
        if (a.accountNumber == num) return &a;
    }
    // Kothao na pele nullptr
    return nullptr;
}

// Menu print kore
void displayMenu()
{
    // Menu heading
    cout << "\n===== MENU =====" << endl;
    // Option 1
    cout << "1. Create a new account" << endl;
    // Option 2
    cout << "2. Deposit money" << endl;
    // Option 3
    cout << "3. Withdraw money" << endl;
    // Option 4
    cout << "4. Calculate interest" << endl;
    // Option 5
    cout << "5. Convert currency" << endl;
    // Option 6
    cout << "6. Display all accounts" << endl;
    // Option 7
    cout << "7. Test boundary conditions" << endl;
    // Option 8
    cout << "8. Exit" << endl;
}

// User er input diye notun account toiri kore return kore
Account createAccount(int accountNum)
{
    // Notun account object
    Account newAccount;
    // Account number set kora
    newAccount.accountNumber = accountNum;

    // Naam chaowa hocche
    cout << "Enter account owner name: ";
    // Puro line (space soho) naam hishabe pora
    getline(cin, newAccount.ownerName);
    // Naam faka hole default naam deya
    if (newAccount.ownerName.empty())
    {
        newAccount.ownerName = "Unknown";
    }

    // Initial balance rakhar variable
    double initialBalance = 0.0;
    // Initial balance chaowa hocche
    cout << "Enter initial balance: $";
    // Invalid ba range er baire hole 0 set
    if (!readDouble(initialBalance) || initialBalance < 0.0 || initialBalance > MAX_BALANCE)
    {
        cout << "Invalid initial balance. Setting balance to 0." << endl;
        initialBalance = 0.0;
    }
    // Balance ke cent e round kore set kora
    newAccount.balance = roundMoney(initialBalance);

    // Account type chaowa hocche
    cout << "Enter account type (S for Savings, C for Checking): ";
    // Default type Checking
    char type = 'C';
    // Input fail hole Checking e thaka
    if (!readChar(type))
    {
        type = 'C';
    }
    // Type uppercase kora
    type = toUpperChar(type);
    // S ba C na hole default Checking
    if (type != 'S' && type != 'C')
    {
        cout << "Invalid type. Defaulting to Checking." << endl;
        type = 'C';
    }
    // Type account e set kora
    newAccount.accountType = type;

    // Toiri account return
    return newAccount;
}

// Account e taka jama kore, success hole true dey
bool deposit(Account& account, double amount)
{
    // Amount nan/inf hole reject
    if (!std::isfinite(amount)) return false;

    // Amount cent e round kora
    amount = roundMoney(amount);
    // Amount 0 ba negative hole reject
    if (amount <= 0.0) return false;

    // Notun balance hishab kora
    double newBalance = roundMoney(account.balance + amount);
    // Max balance cross korle reject
    if (newBalance > MAX_BALANCE) return false;

    // Balance update kora
    account.balance = newBalance;
    // Success
    return true;
}

// Account theke taka tole, success hole true dey
bool withdraw(Account& account, double amount)
{
    // Amount nan/inf hole reject
    if (!std::isfinite(amount)) return false;

    // Amount cent e round kora
    amount = roundMoney(amount);
    // Amount 0/negative ba balance er beshi hole reject
    if (amount <= 0.0 || amount > account.balance) return false;

    // Balance theke taka kome balance update
    account.balance = roundMoney(account.balance - amount);
    // Success
    return true;
}

// Dewa din er jonno interest hishab kore
double calculateInterest(const Account& account, int days)
{
    // Din negative hole interest 0
    if (days < 0)
    {
        return 0.0;
    }

    // Savings e 3%, Checking e 1% bochhorik rate
    double rate = (account.accountType == 'S') ? 0.03 : 0.01;

    // Bochhorik rate ke 365 diye bhag kore dainik rate
    double dailyRate = rate / 365.0;
    // Balance * dainik rate * din = interest
    double interest = account.balance * dailyRate * static_cast<double>(days);

    // Interest ke cent e round kore return
    return roundMoney(interest);
}

// USD er madhyome ek currency theke arekta e convert kore
double convertCurrency(double amount, char fromCurrency, char toCurrency)
{
    // Same currency hole kono convert dorkar nai
    if (fromCurrency == toCurrency)
    {
        return amount;
    }

    // Convert hocche emon poriman
    double result = amount;

    // Source EUR hole USD te ana (rate diye bhag)
    if (fromCurrency == 'E')
    {
        result /= USD_TO_EUR;
        // Source JPY hole USD te ana (rate diye bhag)
    }
    else if (fromCurrency == 'J')
    {
        result /= USD_TO_JPY;
    }

    // Target EUR hole USD theke EUR (rate diye gun)
    if (toCurrency == 'E')
    {
        result *= USD_TO_EUR;
        // Target JPY hole USD theke JPY (rate diye gun)
    }
    else if (toCurrency == 'J')
    {
        result *= USD_TO_JPY;
    }

    // Convert kora poriman return
    return result;
}

// Ekta account er details print kore
void displayAccountSummary(const Account& account)
{
    // Account number print
    cout << "\nAccount Number: " << account.accountNumber << endl;
    // Malik er naam print
    cout << "Owner: " << account.ownerName << endl;
    // S hole Savings, noile Checking print
    cout << "Type: " << (account.accountType == 'S' ? "Savings" : "Checking") << endl;
    // Balance 2 decimal e print
    cout << "Balance: $" << fixed << setprecision(2) << account.balance << endl;
}

// Kichu edge case (shimanar kache) test kore
void testBoundaryConditions()
{
    // Test section er heading
    cout << "\n===== TESTING BOUNDARY CONDITIONS =====" << endl;

    // Test er jonno ekta dummy account
    Account testAccount;
    // Test account er number
    testAccount.accountNumber = 999;
    // Test account er naam
    testAccount.ownerName = "Test Account";
    // Test account er shuru balance
    testAccount.balance = 1000.0;
    // Test account Savings type
    testAccount.accountType = 'S';

    // Shuru obosthar label
    cout << "Initial test account:" << endl;
    // Shuru obosthar summary
    displayAccountSummary(testAccount);

    // Test 1: Onek boro amount jama dewar chesta
    double largeAmount = 2000000000.0;
    // Test 1 er heading
    cout << "\nTest 1: Large deposit of $" << fixed << setprecision(2) << largeAmount << endl;

    // Deposit try kora, result ok te rakha
    bool ok = deposit(testAccount, largeAmount);
    // Accept hoyeche na reject hoyeche dekhano
    cout << "Deposit " << (ok ? "accepted" : "rejected (exceeds MAX_BALANCE)") << endl;
    // Deposit er por label
    cout << "After large deposit attempt:" << endl;
    // Deposit er por summary
    displayAccountSummary(testAccount);

    // Test 2: Khub chhoto amount (round hole 0 hoy)
    cout << "\nTest 2: Tiny deposit of $0.001" << endl;
    // Chhoto deposit try kora
    ok = deposit(testAccount, 0.001);
    // Accept/reject dekhano
    cout << "Deposit " << (ok ? "accepted" : "rejected (rounds to 0.00)") << endl;

    // Test 3: Decimal precision, balance abar 100 kora
    testAccount.balance = 100.0;
    // Test er jonno bochhorik rate
    double rate = 0.03333333;
    // Dainik rate hishab
    double dailyRate = rate / 365.0;
    // 30 diner interest hishab
    double interest = testAccount.balance * dailyRate * 30.0;

    // Test 3 er heading
    cout << "\nTest 3: Decimal precision" << endl;
    // Rate percentage e (6 decimal) dekhano
    cout << "Interest rate: " << fixed << setprecision(6) << rate * 100.0 << "%" << endl;
    // Dainik rate (10 decimal) dekhano
    cout << "Daily rate: " << fixed << setprecision(10) << dailyRate << endl;
    // 30 diner interest (6 decimal) dekhano
    cout << "Interest for 30 days: $" << fixed << setprecision(6) << interest << endl;

    // Test 4: Boro amount er currency conversion
    double largeBalance = 1000000.0;
    // USD theke EUR
    double eurAmount = convertCurrency(largeBalance, 'U', 'E');
    // USD theke JPY
    double jpyAmount = convertCurrency(largeBalance, 'U', 'J');
    // EUR theke abar USD (round trip check)
    double roundTrip = convertCurrency(eurAmount, 'E', 'U');

    // Test 4 er heading
    cout << "\nTest 4: Currency conversion precision" << endl;
    // Output 2 decimal e set
    cout << fixed << setprecision(2);
    // Original amount dekhano
    cout << "Original amount: $" << largeBalance << endl;
    // EUR amount dekhano
    cout << "Converted to EUR: EUR " << eurAmount << endl;
    // JPY amount dekhano
    cout << "Converted to JPY: JPY " << jpyAmount << endl;
    // Round trip er por USD dekhano
    cout << "USD -> EUR -> USD: $" << roundTrip << endl;

    // Test 5: Integer overflow
    int maxInt = numeric_limits<int>::max();
    // Ekta chhoto int
    int smallInt = 100;
    // long long e jog korle overflow hoy na
    long long safeResult = static_cast<long long>(maxInt) + smallInt;

    // Test 5 er heading
    cout << "\nTest 5: Integer overflow" << endl;
    // Int er maximum value dekhano
    cout << "Maximum integer value: " << maxInt << endl;
    // Jog korar chhoto int dekhano
    cout << "Small integer to add: " << smallInt << endl;
    // Safe jog er fol dekhano
    cout << "Result of addition (long long): " << safeResult << endl;
}
