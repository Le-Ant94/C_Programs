/*===============================================================
 
 Program: Happy Prime Numbers
 Author: Anthony Le
 Class: CS1428 Honors
 
 Instructor: Ziliang Zong
 Date: 12/02/2016
 Description: a program that determines the number of happy prime numbers from 1 to 1 million.
 Input: (none)
 Output: the number of happy prime numbers from 1 to 1 million.
 Compilation instructions: Usage:
 
 Modifications: 12/06/2016
 
 ===============================================================*/

#include <iostream>
#include <cmath>

using namespace std;

//Shortcut to eliminate numbers that are not prime
int isPrime(int n)
{
    int i;
    
    if (n <= 1) //Only numbers greater than 1 can be both happy and prime
        return false;
    
    if (n == 2) //Since 2 is the first prime number
        return true;
    
    if (n % 2 == 0) //Any number with a multiple of 2 (other than 2) is not prime
        return 0;
    
    for (i = 3; i <= sqrt (n); i += 2)
        if (n % i == 0)
            return 0;
    
    return true;
}

bool is_happy_prime(int x) //Determine if a number is both happy and prime
{
    if(isPrime(x) == 0 || x < 7) //Recalling the shortcut process
        return false;
    
    //Eliminate numbers that are not happy
    int result;
    
    for ( ; x != 1; )
    {
        result = 0;
        
        for ( ; x != 0; x /= 10)
        {
            result += (x % 10) * (x % 10); //Square digit and add it to total
        }
        
        x = result;
        
        if (x == 4) //If x is 4, it is a sad number
            return false;
    }
    
    return true;
}

int main()
{
    int happy_prime_number = 0;
    
    for (int x = 1; x < 1000000; ++x)
    {
        if (is_happy_prime(x))
            ++happy_prime_number;
    }
    
    cout << "There are " << happy_prime_number << " happy prime numbers between 1 and 1 million." << endl;
}