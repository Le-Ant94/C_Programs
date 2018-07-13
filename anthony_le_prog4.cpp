/*===============================================================

 Program: Magic Piggybank
 Author: Anthony Le
 Class: CS1428 Honors

 Instructor: Ziliang Zong
 Date: 10/17/2016
 Description: a program that implements a magical piggybank.
 Input: the user will be able to insert/remove an amount of money and view the available balance in the piggybank.
 Output: the program will display the correct balance available in the piggybank after each transaction.
 Compilation instructions: Usage:

 Modifications: 10/18/2016

 ===============================================================*/

#include <iostream>
#include <iomanip>

using namespace std;

int main ()

{
    int o;
    float m, d, w, r;
    int Q, D, N, P;


    //initial value
    m=0.00;


    do
    {
    //display starting menu
    cout << "***********************************" << endl;
    cout << "*        Piggy Bank Menu          *" << endl;
    cout << "*                                 *" << endl;
    cout << "* Current Balance $ "  <<setw(6)<< m <<"        *" << endl;
    cout << "*                                 *" << endl;
    cout << "* 1)  Make Deposit                *" << endl;
    cout << "* 2)  Make Withdrawal             *" << endl;
    cout << "* 3)  View Coins                  *" << endl;
    cout << "* 4)  Exit Program                *" << endl;
    cout << "*                                 *" << endl;
    cout << "***********************************" << endl;

     //enter option (o)
    cout << "Enter choice: " << endl;
    cin >> o;


    switch (o)
    {
        case 1:

            //enter the amount of money to be deposited (d)
            cout << "Enter the amount to be deposited: $ " << endl;
            cin >> d;

            //display new balance
            if (d>=0.00)
            {
                m+=d;
                cout << m << endl;
            }

            //display "negative input" error message
            else if (d<0.00)
            {
                cout << "Invalid amount -- Negative values are not allowed" << endl;
            }

            //display "exceed limit" error message
            else if (d>=891.44)
            {
                cout << "The piggybank wil not hold that much. You may deposit up to $ 891.44" << endl;
            }
            break;

        case 2:

            //enter the amount of money to be withdrawal (w)
            cout << "Enter the amount to be withdrawn: $ " << endl;
            cin >> w;

            //display new balance
            if (w>=0.00)
            {
                m-=w;
                cout << m << endl;
            }

            //display "negative input" error message
            else if (w<0.00)
            {
                cout << "Invalid amount -- Negative values are not allowed" << endl;
            }

            //display "exceed limit" error message
            else if (w>m)
            {
                cout << "The piggybank does not contain that much. You may withdrawal up to $ " << m << endl;
            }
            break;

        case 3:

            //calculations
            Q=m/0.25;
            r=m-Q*0.25;

            D=r/0.10;
            r=r-D*0.10;

            N=r/0.05;
            r=r-N*0.05;

            P=r/0.01;

            //display statistics
            cout << "****************************************" << endl;
            cout << "*              Statistics              *" << endl;
            cout << "****************************************" << endl;
            cout << "*                                      *" << endl;
            cout << "*  Quarters " <<setw(6)<<Q<< " $ " <<setw(6)<<Q*0.25<<setw(13)<<"*" << endl;
            cout << "*  Dimes    " <<setw(6)<<D<< " $ " <<setw(6)<<D*0.10<<setw(13)<<"*" << endl;
            cout << "*  Nickels  " <<setw(6)<<N<< " $ " <<setw(6)<<N*0.05<<setw(13)<<"*" << endl;
            cout << "*  Pennies  " <<setw(6)<<P<< " $ " <<setw(6)<<P*0.01<<setw(13)<<"*" << endl;
            cout << "*                                      *" << endl;
            cout << "****************************************" << endl;
            break;

        case 4:

            //exit program
            cout << "GOODBYE!"  << endl;
            break;

        default:

            cout << " Invalid Option -- Try again" << endl;
    }

    }

    while (o>=1&&o<4);

    //exit gracefully
    return 0;
}
