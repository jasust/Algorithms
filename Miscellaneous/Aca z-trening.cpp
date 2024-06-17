/*
    Aleksandar 'Al3kSaNdaR' Ivanovic

    z-koren
*/
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

class BigInteger
{
    private :

        enum { MAX_LEN = 2012 };

        int Number[MAX_LEN];

        int Len;

    public :

        BigInteger ( int Num )
        {
            memset ( Number, 0, sizeof ( Number ) );

            Len = 0;

            if ( ! Num ) Len++;

            while ( Num )
            {
                Number[Len++] = Num % 10;

                Num /= 10;
            }
        }

        BigInteger ( void )
        {
            memset ( Number, 0, sizeof ( Number ) );

            Len = 1;
        }

        void Print ( void )
        {
            for ( int i = Len - 1; i >= 0; i-- ) printf ( "%d", Number[i] );

            printf ( "\n" );
        }

        void PrintZKoren ( void )
        {
            printf ( "%d\n", Len );

            for ( int i = Len - 1; i >= 0; i-- ) printf ( "%d\n", Number[i] );
        }

        void PrintLastDigit ( void )
        {
            printf ( "%d\n", Number[0] );
        }

        BigInteger operator + ( const BigInteger & BigInt )
        {
            int Carry = 0;

            BigInteger Answer ( * this );

            if ( BigInt.Len > Answer.Len ) Answer.Len = BigInt.Len;

            for ( int i = 0; i < Answer.Len; i++ )
            {
                Answer.Number[i] += ( BigInt.Number[i] + Carry );

                Carry = Answer.Number[i] / 10;

                Answer.Number[i] %= 10;
            }

            if ( Carry != 0 )
            {
                Answer.Number[Answer.Len] = Carry;

                Answer.Len++;
            }

            return Answer;
        }

        BigInteger operator - ( const BigInteger & BigInt )
        {
            BigInteger Answer ( * this );

            int Carry = 0;

            for ( int i = 0; i < Answer.Len; i++ )
            {
                Answer.Number[i] = Answer.Number[i] - BigInt.Number[i] - Carry;

                if ( Answer.Number[i] < 0 )
                {
                    Answer.Number[i] = Answer.Number[i] + 10;

                    Carry = 1;
                }
                else Carry = 0;
            }

            while ( ( ! Answer.Number[Answer.Len - 1] ) && ( Answer.Len > 1 ) ) Answer.Len--;

            return Answer;
        }

        BigInteger operator * ( const BigInteger & BigInt )
        {
            BigInteger Answer ( 0 );

            for ( int i = 0; i < Len; i++ )
            {
                int Carry = 0;

                for ( int j = 0; j < BigInt.Len; j++ )
                {
                    int Temp = Answer.Number[i + j] + Number[i] * BigInt.Number[j] + Carry;

                    Answer.Number[i + j] = Temp % 10;

                    Carry = Temp / 10;
                }

                Answer.Number[i + BigInt.Len] = Carry;
            }

            Answer.Len = Len + BigInt.Len;

            while ( ( ! Answer.Number[Answer.Len - 1] ) && ( Answer.Len > 1 ) ) Answer.Len--;

            return Answer;
        }

        BigInteger operator / ( int Num )
        {
            BigInteger Answer ( 0 );

            int Remain = 0;

            for ( int i = Len - 1; i >= 0; i-- )
            {
                Remain = Remain * 10 + Number[i];

                Answer.Number[i] = Remain / Num;

                Remain = Remain % Num;
            }

            Answer.Len = Len;

            while ( ( ! Answer.Number[Answer.Len - 1] ) && ( Answer.Len > 1 ) ) Answer.Len--;

            return Answer;
        }

        /*

        BigInteger Sqrt ( void )
        {
            BigInteger Low ( 0 ), High ( * this ), Mid;

            if ( ( Len == 1 ) && ( Number[0] == 1 ) ) return BigInteger ( 1 );

            while ( Low < High )
            {
                Mid = ( Low + High ) / 2;

                if ( Mid == Low ) break;

                if ( Mid * Mid == ( * this ) )
                {
                    Low = Mid;

                    break;
                }

                if ( Mid * Mid < ( * this ) ) Low = Mid;
                else High = Mid;
            }

            return Low;
        }

        */

        BigInteger Sqrt ( void )
        {
            BigInteger Answer ( 0 ), Remain ( 0 ), Odd ( 0 ), Count;

            int Length = Len - 1 + Len % 2;

            while ( Length >= 0 )
            {
                BigInteger LastTwo ( Number[Length] * 10 + Number[Length - 1] );

                Odd = Answer * 20 + 1;

                Remain = Remain * 100 + LastTwo;

                Count = 0;

                while ( ( Remain > Odd ) || ( Remain == Odd ) )
                {
                    Count = Count + 1;

                    Remain = Remain - Odd;

                    Odd = Odd + 2;
                }

                Answer = Answer * 10 + Count;

                Length -= 2;
            }

            return Answer;
        }

        int operator < ( const BigInteger & BigInt )
        {
            if ( Len < BigInt.Len ) return 1;

            if ( Len > BigInt.Len ) return 0;

            int i;

            for ( i = Len - 1; i >= 0; i-- ) if ( Number[i] != BigInt.Number[i] ) break;

            if ( i == -1 ) return 0;

            if ( Number[i] < BigInt.Number[i] ) return 1;

            return 0;
        }

        int operator == ( const BigInteger & BigInt )
        {
            if ( Len != BigInt.Len ) return 0;

            for ( int i = Len - 1; i >= 0; i-- ) if ( Number[i] != BigInt.Number[i] ) return 0;

            return 1;
        }

        int operator > ( const BigInteger & BigInt )
        {
            if ( ( * this ) < BigInt ) return 0;

            if ( ( * this ) == BigInt ) return 0;

            return 1;
        }
};

int main ( void )
{
    int N;

    BigInteger Number ( 0 );

    scanf ( "%d", &N );

    for ( int i = 0; i < N; i++ )
    {
        int Digit;

        scanf ( "%d", &Digit );

        Number = Number * 10 + Digit;
    }

    BigInteger Sol = Number.Sqrt ( );

    Sol.PrintZKoren ( );

    return 0;
}
