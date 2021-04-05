#include <stdio.h>  //Standard Input-Output Header File
#include <stdlib.h> //Standard Library (For C) Header File
#include <stdbool.h>//Standard Boolean Header File
#include <math.h>   //Math (Library For Calculation) Header File
 
//Functions
int verify_pin(int pin);
void login();   //A Void Function Means That No Value Is Computed And Returned By The Function
void main_menu(); //For A Void Function, One Cannot Modify Its Content
void check_balance(float balance);   //Meaning It Doesn't Accept Input From The Users But Can Only Display An Output From The System
float money_deposit(float balance);  //On The Other Hand, A Float Function Helps In Computing Data That Is In Decimal Form
float money_withdraw(float balance);
void menu_exit();
void error_message();
void charges();
void incorrect_pin();
void main_transaction(float balance);
void two_weeks_ago();
void one_month_age();
void two_months_ago();
void closing_transaction();
int transaction(float balance);

//Main Code
int main() {
    //Local Declarations
    int option;
    int pin;
    float balance = 15000.00;
    int choose;
    bool again = true;  // bool receipt = true;...By Default, The Variable 'again' Has Been Set To True Or Rather 1;

    int verify_pin(int pin); {
        system("clear");
        printf("\n\n\n\n\t\t\t\t\t Verify Your Pin To Continue: ");
        scanf("%d", &pin);
            if (pin != 1234) {
                system("clear");
                incorrect_pin();
                printf("\n\n\n\t\t\t\t\t Verify Your Pin Again To Continue: ");
                scanf("%d", &pin);
                if (pin != 1234) {
                    system("clear");
                    incorrect_pin();
                    printf("\n\n\n\t\t\t\t\t Verify Your Pin Again To Continue: ");
                    scanf("%d", &pin);
                    if (pin != 1234) {
                        printf("\033[0;31m");
                        printf("\n\n\n\n\t\t\t\t\tYou Have Made A Maximum Pin Attemption. \n\t\t\t\t\tKindly Contact Your Bank For Assistance \n\n\n");
                        return 0;
                    } else {
                        bool again = true;
                    }
                } else {
                    bool again = true;
                }
            } else {
                bool again = true;
            }
        }

    while (again) {    
    main_menu();
 
    printf("=~-~=~-~=~-~=~-~==~-~=~-~=~-~=~-~==~-~=~-~=~-~=~-~= \n\n");
    printf("Your Selection: \t");
    scanf("%d", &option);

        switch (option) {
            case 1:
             system("clear");
                check_balance(balance);
                break;
            case 2:
             system("clear");
                balance = money_deposit(balance);
                break;
            case 3:
             system("clear");
                balance = money_withdraw(balance);
                break;
            case 4:
            system("clear");
                charges();
                break;
            case 5:
             system("clear");
                transaction(balance);
                break;
            case 6:
             system("clear");
                menu_exit();
                return 0;
 
            default:
                error_message();
                break;
        }

        printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
        printf("Would You Like To Do Another Transaction: \n");
        printf("\t Option 1 => Yes \n");
        printf("\t Option 2 => No \n\n");
        printf("Your Option: ");
        scanf("%d", &choose);
        system("clear");

        switch (choose)
        {
            case 1:
                again = true;
                break;

            case 2:
                again = false;
                menu_exit();
                return 0;    
            
            default:
                again = false;
                error_message();
                    printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
                    printf("Would You Like To Do Another Transaction: \n");
                    printf("\t Option 1 => Yes \n");
                    printf("\t Option 2 => No \n\n");
                    printf("Your Option: ");
                    scanf("%d", &choose);
                    system("clear");

                    switch (choose)
                    {
                        case 1:
                            again = true;
                            break;

                        case 2:
                            again = false;
                            menu_exit();
                            return 0;    
                        
                        default:
                            again = false;
                            printf("\033[0;31m");
                            printf("Too Many Invalid Selection \n\n");
                            printf("\033[0m");
                            return 0;
                            break;
                    }
                break;
        }
}

    return 0;
}

//Main Menu
void main_menu() { 
    system("clear");
    printf("\033[0;32m");
    printf(" *************** Welcome To KCB Banking *************** \n");
    printf(" *************** Please Make A Selection ************** \n\n");
    printf("\033[0;36m");
    printf("Option 1 =>  Check Balance \n");
    printf("Option 2 =>  Deposit \n");
    printf("Option 3 =>  Withdraw \n");
    printf("Option 4 =>  View Charges \n");
    printf("Option 5 =>  Print Mini Statement \n");
    printf("Option 6 =>  Exit \n\n");
    printf("\033[0m");
}

/* 
    colors 
    black \033[0;30m
    red \033[0;31m
    green \033[0;32m
    yellow \033[0;33m
    blue \033[0;34m
    purple \033[0;35m
    cyan \033[0;36m
    white \033[0;37m
    reset \033[0m
*/

//Checking Balance
void check_balance(float balance) {
    printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    printf("\033[0;32m");
    printf("You Have Selected To Check Your Balance \n\n");
    printf("Your Current Account Balance Is Ksh. %.2f \n\n", balance);
    printf("\033[0m");
}

//Depositing Cash
float money_deposit(float balance) {
    float deposit;
    printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    printf("\033[0;32m");
    printf("You Have Selected To Deposit Some Money Into Your Account \n");
    printf("Your Current Account Balance Is Ksh. %.2f \n", balance);
    printf("\033[0m");
    printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    printf("Please Enter The Amount You Wish To Deposit \n\t");
    scanf("\t\t %f", &deposit);

    balance += deposit;
 
    printf("\033[0;34m");
    printf("\n Congratulations! Your New Account Balance Is Ksh. %.2f \n\n", balance);
    printf("\033[0m");
    return balance;
}

//Withdrawing Some Amount
float money_withdraw(float balance) {
    float withdraw;
    int select;
    bool back = true;

    printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    printf("\033[0;32m");
    printf("You Choose To Withdraw Some Money \n");
    printf("Your Balance Is: Ksh. %.2f \n\n", balance);
    printf("\033[0m");
    printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    printf("\033[0;36m");
    printf("Please Select An Amount To Withdraw: \n");
    printf("1. Ksh. 20,000 \n");
    printf("2. Ksh. 10,000 \n");
    printf("3. Ksh. 5,000 \n");
    printf("4. Ksh. 1,000 \n");
    printf("5. Others \n");
    printf("\033[0m");
    printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    printf("\n Your Selection: ");
    scanf("%d", &select);

    switch (select) {
            case 1:
                withdraw = 20000 + 1000;
                break;
            case 2:
                withdraw = 10000 + 1000;
                break;
            case 3:
                withdraw = 5000 + 100;
                break;
            case 4:
                withdraw = 1000 + 100;
                break;
            case 5:
                printf("\n Specify An Amount To Withdraw: ");
                scanf("%f", &withdraw);
                break;

            default:
                error_message();
                return balance;
    }
 
    if (withdraw <= balance) {
        back = false;
        balance -= withdraw;
        printf("\033[0;32m");
        printf("\n Congratulations For Making A withdrawal Worth Ksh. %.2f \n", withdraw);
        printf("\n Your New Balance Is Ksh. %.2f \n\n", balance);
        printf("\033[0m");
    } else {
        printf("\033[0;31m");
        printf("\n Sorry, You Don't Have Enough Money To Make This Transaction \n");
        printf("Kindly confirm Your Account Balance and continue \n");
        printf("\033[0m");
        printf("\033[0;34m");
        printf("\n\n Your Current Account Balance is Ksh. %.2f \n\n", balance);
        printf("\033[0m");
        }
    // }
    return balance;
}

//Exiting Menu
void menu_exit() {
    printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    printf("\033[0;32m");
    printf("\t ------------Your Receipt Is Ready---------- \n");
    printf("\t Thank You For Using The ATM Banking Machine. \n");
    printf("\t Brought To You By KBC Banking \n\n");
    printf("\033[0m");
    printf("\n =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
}

// Fee Charges
void charges() {
    bool back = true;
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    printf("\033[0;32m");
    printf("The Following Are The Charges Done Per Transaction; \n\n");
    printf("\033[0;36m");
    printf("Ksh. 100     - Ksh. 999       ==> Ksh. 10 \n");
    printf("Ksh. 1,000   - Ksh. 9999      ==> Ksh. 100 \n");
    printf("Ksh. 10,000  - Ksh. 49,999    ==> Ksh. 1,000 \n");
    printf("Ksh. 50,000  - Ksh. 99,999    ==> Ksh. 5,000 \n");
    printf("Transactions Above Ksh. 100,000 ==> Ksh. 10,000 \n");
    printf("\033[0m");
}

//Error Message
void error_message() {
    printf("\033[31m");
    printf("\n You Made An Invalid Selection. \n\n Please Make A Valid Selection. \n\n");
    printf("\033[0m");
}

void incorrect_pin() {
    printf("\033[0;31m");
    printf("\n\n\n\n\t\t\t\t\t Incorrect Pin. Please Try Again \n\n\n\n");
    printf("\033[0m");
}

void main_transaction(float balance) {
    printf("\033[0;35m");
    printf("\t\t\t\t\t\t\t BANK STATEMENT \n\n\n");
    printf("\033[0m");
    printf("Account Holder Details \n\n");
    printf("\033[0;34m");
    printf("\t Name: Cyber Ghost \n");
    printf("\t Phone Number: 0769 692 554 \n");
    printf("\t Address: 451-00100, Nairobi \n\n\n");
    printf("\033[0m");
    printf("Account Details \n\n");
    printf("\033[0;34m");
    printf("\t Account Type: Student Account \n");
    printf("\t Account Number: 365001010 \n");
    printf("\t Ksh. %.2f \n\n\n", balance);
    printf("\033[0m");
    printf("Account Statement \n\n");
    printf("\033[0;36m");
    printf(" =======================================================================================================================\n");
    printf("|| Txn Date \t || Value Time \t || Description \t || Ref No. \t || Debit \t || Credit \t || Balance    ||\n");
    printf("||===============||==============||======================||==============||==============||==============||============||\n");
}

void two_weeks_ago() {
    printf("|| 02nd Mar 2021 || 09:42 AM \t || Withdrawal \t\t || KCB04CA780 \t || Ksh. 30,000  || Ksh. 15,000  || Ksh. 15,000||\n");
    printf("|| 28th Feb 2021 || 07:30 PM \t || Deposit \t\t || KCB04DP190 \t || Ksh. 1,000   || Ksh. 29,000  || Ksh. 30,000||\n");
    printf("|| 24TH Feb 2021 || 03:21 PM \t || Withdrawal \t\t || KCB03AZ473 \t || Ksh. 14,000  || Ksh. 13,000  || Ksh. 1,000 ||\n");
}

void one_month_age() {
    printf("|| 10th Feb 2021 || 11:00 AM \t || Withdrawal \t\t || KCB01PQ111 \t || Ksh. 35,000  || Ksh. 21,000  || Ksh. 14,000||\n");
    printf("|| 04th Feb 2021 || 04:39 PM \t || Withdrawal \t\t || KCB97RS240 \t || Ksh. 40,000  || Ksh. 5,000   || Ksh. 35,000||\n");
}

void two_months_ago() {
    printf("|| 01st Feb 2021 || 09:22 AM \t || Withdrawal \t\t || KCB96ZA591 \t || Ksh. 80,000  || Ksh. 40,000  || Ksh. 40,000||\n");
    printf("|| 30th Jan 2021 || 12:59 PM \t || Withdrawal \t\t || KCB74FG345 \t || Ksh. 90,000  || Ksh. 10,000  || Ksh. 80,000||\n");
    printf("|| 26th Jan 2021 || 02:57 PM \t || Deposit \t\t || KCB70BC640 \t || Ksh. 20,000  || Ksh. 70,000  || Ksh. 90,000||\n");
}

void closing_transaction() {
    printf(" =======================================================================================================================\n");
    printf("\033[0m");
}

int transaction(float balance) {
    int option;

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    printf("\033[0;32m");
    printf("Select A Period You Want To Check Your Mini Statement \n");
    printf("\033[0;33m");
    printf("\t Option 1: Two Weeks Ago \n");
    printf("\t Option 2: One Month Ago \n");
    printf("\t Option 3: Two Months Ago \n\n");
    printf("\033[0m");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n\n");
    printf("Your Selection: \t");
    scanf("%d", &option);

        switch (option) {
            case 1:
             system("clear");
                main_transaction(balance);
                two_weeks_ago();
                closing_transaction();
                break;
            case 2:
             system("clear");
                main_transaction(balance);
                two_weeks_ago();
                one_month_age();
                closing_transaction();
                break;
            case 3:
             system("clear");
                main_transaction(balance);
                two_weeks_ago();
                one_month_age();
                two_months_ago();
                closing_transaction();
            return 0;

            default:
                error_message();
                break;
        }
}