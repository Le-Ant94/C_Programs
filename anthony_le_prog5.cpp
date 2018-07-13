/*===============================================================

 Program: Auditorium Ticket Sales
 Author: Anthony Le
 Class: CS1428 Honors

 Instructor: Ziliang Zong
 Date: 11/02/2016
 Description: a program that handle ticket sales for an auditorium.
 Input: requested seat purchases by desired day, section, and seat number.
 Output: seat availability, a seating chart, or a day/floor summary.
 Compilation instructions: Usage:

 Modifications: 11/03/2016

 ===============================================================*/

#include <iostream>

using namespace std;

const char SOLD = '*';
const char AVAIL = '-';
const int rows = 3;
const int columns = 20;
char Thu[rows][columns];
char Fri[rows][columns];
char Sat[rows][columns];

char get_menu_choice(); //presents menu, gets user selection, returns only valid selection
char sell_seat(char Thu[rows][columns], char Fri[rows][columns], char Sat[rows][columns]); //checks if a seat selection is available, updates data as sold
void print_chart(char Thu[rows][columns], char Fri[rows][columns], char Sat[rows][columns]); //displays seating chart
void print_day_list(char Thu[rows][columns], char Fri[rows][columns], char Sat[rows][columns]); //displays sales summary, ordered by days
void print_section_list(char Thu[rows][columns], char Fri[rows][columns], char Sat[rows][columns]); //displays sales summary, ordered by sections

int main()
{
    char c;

    for (int r=0; r<rows; r++)
    {
        for (int c=0; c<columns; c++)
        {
            Thu[r][c] = AVAIL;
            Fri[r][c] = AVAIL;
            Sat[r][c] = AVAIL;
        }
    }

    do
    {
        c = get_menu_choice();

        switch (c)
        {
            case 's': sell_seat(Thu, Fri, Sat);
                break;

            case 'c': print_chart(Thu, Fri, Sat);
                break;

            case 'd': print_day_list(Thu, Fri, Sat);
                break;

            case 'f': print_section_list(Thu, Fri, Sat);
                break;

            case 'q': cout << "Bye" << endl;
                break;

            default: cout << " " << endl;
        }

    }

    while (c != 'Q' && c != 'q');

    return 0; //exit gracefully
}

char get_menu_choice() //presents menu, gets user selection, returns only valid selection
{
    char choice;

    //display main menu
    cout << "        *** Main Menu ***                  " << endl;
    cout << " S - Sell a Ticket                         " << endl;
    cout << " C - Display Seating Chart                 " << endl;
    cout << " D - Display Sales Summary - Day Listing   " << endl;
    cout << " F - Display Sales Summary - Floor Listing " << endl;
    cout << " Q - Quit                                  " << endl;
    cout << "                                           " << endl;

    //prompt user to enter choice
    cout << " Your choice:  " << endl;
    cin >> choice;

    //if statement in case user enters an invalid choice
    if ((choice != 'S' && choice != 's') && (choice != 'C' && choice !='c') && (choice != 'D' && choice != 'd') && (choice != 'F' && choice != 'f') && (choice != 'Q' && choice != 'q'))
    cout << "\"" << choice << "\" is not a valid choice. Try again." << endl;

    //user can enter either an uppercase or lowercase choice
    if (choice == 'S')
    {choice = 's';}
    if (choice == 'C')
    {choice = 'c';}
    if (choice == 'D')
    {choice = 'd';}
    if (choice == 'F')
    {choice = 'f';}
    if (choice == 'Q')
    {choice = 'q';}

    return choice;
}

char sell_seat(char Thu[rows][columns], char Fri[rows][columns], char Sat[rows][columns]) //checks if a seat selection is available, updates data as sold
{
    char cDay= ' ';
    char cRow= ' ';
    int cColumn = -1;
    int a = 0;

    while (a != 1)
    {
        //choices that user can enter
        cout << "Enter seat request by Day (T)hursday, (F)riday, (S)aturday" << endl;
        cout << "followed by Section (F)loor, (B)alcony, (U)pper Balcony" << endl;
        cout << "followed by seat number (1 - 20)." << endl;

        cin >> cDay >> cRow >> cColumn;

        //if statement in case user enters an invalid date
        if ((cDay != 'T' && cDay != 't') && (cDay != 'F' && cDay !='f') && (cDay != 'S' && cDay != 's'))
            cout << "Your day input is invalid. Please try again." << endl;

        //if statement in case user enters an invalid section
        if ((cRow != 'F' && cRow != 'f') && (cRow != 'B' && cRow != 'b') && (cRow != 'U' && cRow != 'u'))
            cout << "Your section input is invalid. Please try again." << endl;

        //if statement in case user enters an invalid seat number
        if (cColumn < 1 || cColumn > 20)
            cout << "Your seat number is invalid. Please try again." << endl;

        //user enters Thursday
        if (cDay == 'T' || cDay == 't')
        {

            //user enters Floor
            if (cRow == 'F' || cRow == 'f')
            {
                if (Thu[0][cColumn - 1] != SOLD)
                {
                    Thu[0][cColumn - 1] = SOLD;
                    a=1;
                    cout << "Congratulations! You got the seat." << endl;
                }
                else (cout << "That seat was taken, please select another." << endl);
            }

            //user enters Balcony
            if (cRow == 'B' || cRow == 'b')
            {
                if (Thu[1][cColumn - 1] != SOLD)
                {
                    Thu[1][cColumn - 1] = SOLD;
                    a=1;
                    cout << "Congratulations! You got the seat." << endl;
                }
                else (cout << "That seat was taken, please select another." << endl);
            }

            //user enters Upper Balcony
            if (cRow == 'U' || cRow == 'u')
            {
                if (Thu[2][cColumn - 1] != SOLD)
                {
                    Thu[2][cColumn - 1] = SOLD;
                    a=1;
                    cout << "Congratulations! You got the seat." << endl;
                }
                else (cout << "That seat was taken, please select another." << endl);
            }
        }

        //user enters Friday
        if (cDay == 'F' || cDay == 'f')
        {

            //user enters Floor
            if (cRow == 'F' || cRow == 'f')
            {
                if (Fri[0][cColumn - 1] != SOLD)
                {
                    Fri[0][cColumn - 1] = SOLD;
                    a=1;
                    cout << "Congratulations! You got the seat." << endl;
                }
                else (cout << "That seat was taken, please select another." << endl);
            }

            //user enters Balcony
            if (cRow == 'B' || cRow == 'b')
            {
                if (Fri[1][cColumn - 1] != SOLD)
                {
                    Fri[1][cColumn - 1] = SOLD;
                    a=1;
                    cout << "Congratulations! You got the seat." << endl;
                }
                else (cout << "That seat was taken, please select another." << endl);
            }

            //user enters Upper Balcony
            if (cRow == 'U' || cRow == 'u')
            {
                if (Fri[2][cColumn - 1] != SOLD)
                {
                    Fri[2][cColumn - 1] = SOLD;
                    a=1;
                    cout << "Congratulations! You got the seat." << endl;
                }
                else (cout << "That seat was taken, please select another." << endl);
            }
        }

        //user enters Saturday
        if (cDay == 'S' || cDay == 's')
        {

            //user enters Floor
            if (cRow == 'F' || cRow == 'f')
            {
                if (Sat[0][cColumn - 1] != SOLD)
                {
                    Sat[0][cColumn - 1] = SOLD;
                    a=1;
                    cout << "Congratulations! You got the seat." << endl;
                }
                else (cout << "That seat was taken, please select another." << endl);
            }

            //user enters Balcony
            if (cRow == 'B' || cRow == 'b')
            {
                if (Sat[1][cColumn - 1] != SOLD)
                {
                    Sat[1][cColumn - 1] = SOLD;
                    a=1;
                    cout << "Congratulations! You got the seat." << endl;
                }
                else (cout << "That seat was taken, please select another." << endl);
            }

            //user enters Upper Balcony
            if (cRow == 'U' || cRow == 'u')
            {
                if (Sat[2][cColumn - 1] != SOLD)
                {
                    Sat[2][cColumn - 1] = SOLD;
                    a=1;
                    cout << "Congratulations! You got the seat." << endl;
                }
                else (cout << "That seat was taken, please select another." << endl);
            }
        }

    }

        if (cDay == 'T' || cDay == 't')
        {
            if (cRow == 'F' || cRow == 'f')
            {
                return Thu[0][cColumn - 1];
            }

            if (cRow == 'B' || cRow == 'b')
            {
                return Thu[1][cColumn - 1];
            }

            if (cRow == 'U' || cRow == 'u')
            {
                return Thu[2][cColumn - 1];
            }
        }

        if (cDay == 'F' || cDay == 'f')
        {
            if (cRow == 'F' || cRow == 'f')
            {
                return Fri[0][cColumn - 1];
            }

            if (cRow == 'B' || cRow == 'b')
            {
                return Fri[1][cColumn - 1];
            }

            if (cRow == 'U' || cRow == 'u')
            {
                return Fri[2][cColumn - 1];
            }
        }

        if (cDay == 'S' || cDay == 's')
        {
            if (cRow == 'F' || cRow == 'f')
            {
                return Sat[0][cColumn - 1];
            }

            if (cRow == 'B' || cRow == 'b')
            {
                return Sat[1][cColumn - 1];
            }

            if (cRow == 'U' || cRow == 'u')
            {
                return Sat[2][cColumn - 1];
            }
        }
    return 0;
}

void print_chart(char Thu[rows][columns], char Fri[rows][columns], char Sat[rows][columns]) //displays seating chart
{
    cout << "Thursday                   " << endl;
    cout << "       Floor        :";

    for (int c = 0; c < columns; c++)
    {
        cout << Thu[0][c];
    }
    cout << endl;

    cout << "       Balcony      :";

    for (int c = 0; c < columns; c++)
    {
        cout << Thu[1][c];
    }
    cout << endl;

    cout << "       Upper Balcony:";

    for (int c = 0; c < columns; c++)
    {
        cout << Thu[2][c];
    }
    cout << endl;

    cout << "Friday                   " << endl;
    cout << "       Floor        :";

    for (int c = 0; c < columns; c++)
    {
        cout << Fri[0][c];
    }
    cout << endl;

    cout << "       Balcony      :";

    for (int c = 0; c < columns; c++)
    {
        cout << Fri[1][c];
    }
    cout << endl;

    cout << "       Upper Balcony:";

    for (int c = 0; c < columns; c++)
    {
        cout << Fri[2][c];
    }
    cout << endl;

    cout << "Sat                   " << endl;
    cout << "       Floor        :";

    for (int c = 0; c < columns; c++)
    {
        cout << Sat[0][c];
    }
    cout << endl;

    cout << "       Balcony      :";

    for (int c = 0; c < columns; c++)
    {
        cout << Sat[1][c];
    }
    cout << endl;

    cout << "       Upper Balcony:";

    for (int c = 0; c < columns; c++)
    {
        cout << Sat[2][c];
    }
    cout << endl;
}

void print_day_list(char Thu[rows][columns], char Fri[rows][columns], char Sat[rows][columns]) //displays sales summary, ordered by days
{

    int count = 0;
    int totalcount = 0;
    int cost = 0;

    //displays Thursday ticket sale and price per section
    cout << " Thursday                  " << endl;
    cout << "       Floor        :   Tickets sold: ";

        for (int c=0; c<columns; c++)
        {
            if (Thu[0][c] == SOLD)
            {
                count++;
                totalcount++;
            }
        }

        cout << count << "  $" << count*30 << endl;
        cost+= count*30;

    count = 0;
    cout << "       Balcony      :   Tickets sold: ";

        for (int c=0; c<columns; c++)
        {
            if (Thu[1][c] == SOLD)
            {
                count++;
                totalcount++;
            }
        }

        cout << count << "  $" << count*20 << endl;
        cost += count*20;

    count = 0;
    cout << "       Upper Balcony:   Tickets sold: ";

        for (int c=0; c<columns; c++)
        {
            if (Thu[2][c] == SOLD)
            {
                count++;
                totalcount++;
            }
        }

        cout << count << "  $" << count*10 << endl;
        cost+= count*10;

    //displays Friday ticket sale and price per section
    count = 0;
    cout << " Fri                  " << endl;
    cout << "       Floor        :   Tickets sold: ";

    for (int c=0; c<columns; c++)
    {
        if (Fri[0][c] == SOLD)
        {
            count++;
            totalcount++;
        }
    }

    cout << count << "  $" << count*30 << endl;
    cost+= count*30;

    count = 0;
    cout << "       Balcony      :   Tickets sold: ";

    for (int c=0; c<columns; c++)
    {
        if (Fri[1][c] == SOLD)
        {
            count++;
            totalcount++;
        }
    }

    cout << count << "  $" << count*20 << endl;
    cost += count*20;

    count = 0;
    cout << "       Upper Balcony:   Tickets sold: ";

    for (int c=0; c<columns; c++)
    {
        if (Fri[2][c] == SOLD)
        {
            count++;
            totalcount++;
        }
    }

    cout << count << "  $" << count*10 << endl;
    cost += count*10;

    //displays Saturday ticket sale and price per section
    count = 0;
    cout << " Saturaday                  " << endl;
    cout << "       Floor        :   Tickets sold: ";

    for (int c=0; c<columns; c++)
    {
        if (Sat[0][c] == SOLD)
        {
            count++;
            totalcount++;
        }
    }

    cout << count << "  $" << count*30 << endl;
    cost += count*30;

    count = 0;
    cout << "       Balcony      :   Tickets sold: ";

    for (int c=0; c<columns; c++)
    {
        if (Sat[1][c] == SOLD)
        {
            count++;
            totalcount++;
        }
    }

    cout << count << "  $" << count*20 << endl;
    cost += count*20;

    count = 0;
    cout << "       Upper Balcony:   Tickets sold: ";

    for (int c=0; c<columns; c++)
    {
        if (Sat[2][c] == SOLD)
        {
            count++;
            totalcount++;
        }
    }

    cout << count << "  $" << count*10 << endl;
    cost+= count*10;

    //displays total ticket sales for all shows and price per section
    cout << "Total ticket sales for all show: " << totalcount << "  $" << cost << endl;
}

void print_section_list(char Thu[rows][columns], char Fri[rows][columns], char Sat[rows][columns]) //displays sales summary, ordered by sections
{
    int Tcount = 0;
    int Fcount = 0;
    int Scount = 0;
    int totalcount = 0;
    int cost = 0;

    //displays Floor ticket sales and price per day
    cout << "Floor" << endl;

    for (int c=0; c<columns; c++)
    {
        if (Thu[0][c] == SOLD)
        {
            Tcount++;
            totalcount++;
        }

        if (Fri[0][c] == SOLD)
        {
            Fcount++;
            totalcount++;
        }

        if (Sat[0][c] == SOLD)
        {
            Scount++;
            totalcount++;
        }
    }

    cout << "       Thursday    Tickets sold: " << Tcount << "  $" << Tcount*30 << endl;
    cout << "       Friday      Tickets sold: " << Fcount << "  $" << Fcount*30 << endl;
    cout << "       Saturday    Tickets sold: " << Scount << "  $" << Scount*30 << endl;

    cost += Tcount*30 + Fcount*30 + Scount*30;

    Tcount = 0;
    Fcount = 0;
    Scount = 0;

    //displays Balcony ticket sales and price per day
    cout << "Balcony" << endl;

    for (int c=0; c<columns; c++)
    {
        if (Thu[1][c] == SOLD)
        {
            Tcount++;
            totalcount++;
        }

        if (Fri[1][c] == SOLD)
        {
            Fcount++;
            totalcount++;
        }

        if (Sat[1][c] == SOLD)
        {
            Scount++;
            totalcount++;
        }
    }

    cout << "       Thursday    Tickets sold: " << Tcount << "  $" << Tcount*20 << endl;
    cout << "       Friday      Tickets sold: " << Fcount << "  $" << Fcount*20 << endl;
    cout << "       Saturday    Tickets sold: " << Scount << "  $" << Scount*20 << endl;

    cost += Tcount*20 + Fcount*20 + Scount*20;

    Tcount = 0;
    Fcount = 0;
    Scount = 0;

    //displays Upper Balcony ticket sales and price per day
    cout << "Upper Balcony" << endl;

    for (int c=0; c<columns; c++)
    {
        if (Thu[2][c] == SOLD)
        {
            Tcount++;
            totalcount++;
        }

        if (Fri[2][c] == SOLD)
        {
            Fcount++;
            totalcount++;
        }

        if (Sat[2][c] == SOLD)
        {
            Scount++;
            totalcount++;
        }
    }

    cout << "       Thursday    Tickets sold: " << Tcount << "  $" << Tcount*10 << endl;
    cout << "       Friday      Tickets sold: " << Fcount << "  $" << Fcount*10 << endl;
    cout << "       Saturday    Tickets sold: " << Scount << "  $" << Scount*10 << endl;

    cost += Tcount*10 + Fcount*10 + Scount*10;

    //displays total ticket sales for all shows and price per day
    cout << "Total ticket sales for all shows: " << totalcount << "  $" << cost << endl;
}
