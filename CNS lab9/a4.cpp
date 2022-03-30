
// El Gamal
#include <bits/stdc++.h>
#include <gmp.h>
#include <gmpxx.h>
using namespace std;

int main()
{

    int n = 160; // number of bits;
    mpz_t g;
    mpz_init(g);

    mpz_t p;
    mpz_init(p);

    mpz_t x;
    mpz_init(x);

    mpz_t y;
    mpz_init(y);

    mpz_t k;
    mpz_init(k);

    mpz_t c1;
    mpz_init(c1);

    gmp_randstate_t state;
    gmp_randinit_default(state);

    // Key Generation

    mpz_urandomb(p, state, n); // Random number n bit
    mpz_nextprime(p, p);       // Make it prime number

    mpz_urandomb(g, state, n); // Random number n bit

    while (mpz_cmp(p, g) < 0) // Ensure that p is greater than g
    {
        mpz_urandomb(g, state, n);
    }

    gmp_printf("\nThe value of p is %Zd \n", p);
    gmp_printf("The value of g is %Zd \n", g);

    mpz_urandomb(x, state, n);

    while (mpz_cmp(g, x) < 0)
    {
        mpz_urandomb(x, state, n);
    }

    gmp_printf("The value of x is %Zd \n", x);

    mpz_powm(y, g, x, p);

    gmp_printf("The value of y is %Zd \n", y);
    char message[50];
    int count = 0;

    printf("\nGive message : ");

    fgets(message, sizeof(message), stdin);

    while (message[count] != '\n') // Counting the length of the message
    {

        count++;
    }

    mpz_urandomb(k, state, n);

    while (mpz_cmp(p, k) < 0) // Ensure that p is greater than k
    {
        mpz_urandomb(k, state, n);
    }

    gmp_printf("\nThe value of k is %Zd \n", k);

    mpz_powm(c1, g, k, p); // Calculate C1

    gmp_printf("\n\nThe value of C1 is %Zd \n", c1);

    int i;
    mpz_t c2[count];

    for (i = 0; i < count; i++)
    {
        mpz_init2(c2[i], n);
    }

    mpz_t temp2;
    mpz_init(temp2);

    mpz_t temp3;
    mpz_init(temp3);

    mpz_powm(temp2, y, k, p); // temp2 = (y^k)mod p

    gmp_printf("\n\ntemp2 = (y^k)mod p :%Zd \n", temp2);

    for (i = 0; i < count; i++)
    {

        mpz_mul_si(c2[i], temp2, message[i]);

        gmp_printf("C2[%d] = %Zd\n", i, c2[i]);
    }

    mpz_clear(temp2);
    mpz_clear(temp3);
    mpz_clear(k);
}
