#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

//Affine cipher

string encryptAffine(string plain, int a, int b)
{
    string cipher = "";

    //Processing
    for (int i = 0; i < plain.length(); i++)
    {
        if (isupper(plain[i]))
            cipher = cipher + (char) ((((a * (plain[i] - 'A' )) + b + 26) % 26) + 'A');
        else if (islower(plain[i]))
            cipher = cipher + (char) ((((a * (plain[i] - 'a' )) + b + 26) % 26) + 'a');
        else if (isdigit(plain[i]))
            cipher = cipher + (char) ((((a * (plain[i] - '0' )) + b + 10) % 10) + '0');
    }
    return cipher;
}

string decryptAffine(string cipher, int a, int b)
{
    string plain = "";
    int a_inv = 0;
    int a_inv_digit = 0;
    int flag = 0;

    //Processing
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if (flag == 1)
            a_inv = i;
    }
    flag = 0;
    for (int i = 0; i < 10; i++)
    {
        flag = (a * i) % 10;
        if (flag == 1)
            a_inv_digit = i;
    }

    for (int i = 0; i < cipher.length(); i++)
    {
        if (isupper(cipher[i]))
            plain = plain + (char) (((a_inv * (((cipher[i] - 'A') - b + 26)) % 26)) + 'A');
        else if (islower(cipher[i]))
            plain = plain + (char) (((a_inv * (((cipher[i] - 'a') - b + 26)) % 26)) + 'a');
        else if (isdigit(cipher[i]))
            plain = plain + (char) (((a_inv_digit * (((cipher[i] - '0') - b + 10)) % 10)) + '0');
    }

    return plain;
}
int main()
{
    string plain;
    int a, b;

    cout<<"Pesan : ";   getline(cin, plain);

    cout<<"Key a : ";   cin>>a;
    cout<<"Key b : ";   cin>>b;

    cout<<"Encrypted Message is : "<<encryptAffine(plain, a, b)<<endl;
     cout<<"Decrypted Message is : "<<decryptAffine((encryptAffine(plain, a, b)), a, b)<<endl;
}
