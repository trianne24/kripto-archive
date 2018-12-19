//CPP program to illustate Affine Cipher

#include<bits/stdc++.h>
#include<conio.h>
#include<string>
#include<iostream>
using namespace std;

//Key values of a and b
const int a = 17;
const int b = 20;

string shiftCipher(string text, int s)
{
    string result = "";

    // traverse text
    for (int i=0;i<text.length();i++)
    {
        // apply transformation to each character
        // Encrypt Uppercase letters
        if (isupper(text[i]))
            result += char(int(text[i]+s-65)%26 +65);

    // Encrypt Lowercase letters
    else
        result += char(int(text[i]+s-97)%26 +97);
    }

    // Return the resulting string
    return result;
}

string affineCipher(string msg)
{
    //Cipher Text initially empty
    string cipher = "";
    for (int i = 0; i < msg.length(); i++)
    {
        // Avoid space to be encrypted
        if(msg[i]!=' ')
            /* applying encryption formula ( a x + b ) mod m
            {here x is msg[i] and m is 26} and added 'A' to
            bring it in range of ascii alphabet[ 65-90 | A-Z ] */
            cipher = cipher + (char) ((((a * (msg[i]-'A') ) + b) % 26) + 'A');
        else
            //else simply append space character
            cipher += msg[i];
    }
    return cipher;
}


void pembuka(){
    cout<<"Program Enkripsi menggunakan Shift Cipher dan Affine Cipher"<<endl;
    cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - -  - - - "<<endl;
    cout<<"1. Shift Cipher"<<endl;
    cout<<"2. Affine Cipher"<<endl;
    cout<<"3. Shift + Affine Cipher"<<endl;
    cout<<"4. Affine + Shift Cipher"<<endl;
    cout<<"5. Done"<<endl<<endl;
    cout<<"Masukan angka untuk mengakses fitur program :";
}

void penutupan(){
    cout<<"By :\nAngga Kresnabayu\t\t140810160001\nMuhammad Naufal Monoarfa\t140810160033\nAdryan Luthfi Faiz\t\t140810160049\t\nMuhammad Rifqy Aulia Akbar\t140810160055\nPatricia Joanne\t\t\t140810160065";
}

void menu(){
    string pilih;
    string plaintext;
    int kunci;

    pembuka();

    cin>>pilih;

    system("cls");

    if(pilih == "1"){
        cout<<"Masukan pesan yang ingin di enkripsi!\nPlaintext\t: ";
        cin.ignore();
        getline(cin, plaintext);
        cout<<"\nMasukan ANGKA untuk dijadikan kunci!"<<endl;
        cin>>kunci;
        cout<<endl<<"Ciphertext\t: "<<shiftCipher(plaintext, kunci);
        cout<<"\n(PRESS ANY KEY)";
        getch();
        system("cls");
        menu();
    }
    else if (pilih == "2"){
        cout<<"Masukan pesan yang ingin di enkripsi!\nPlaintext\t: ";
        cin.ignore();
        getline(cin, plaintext);
        cout<<endl<<"Ciphertext\t: "<<affineCipher(plaintext);
        cout<<"\n(PRESS ANY KEY)";
        getch();
        system("cls");
        menu();
    }
    else if (pilih == "3"){
        cout<<"Masukan pesan yang ingin di enkripsi!\nPlaintext\t: ";
        cin.ignore();
        getline(cin, plaintext);
        cout<<"\nMasukan ANGKA untuk dijadikan kunci!"<<endl;
        cin>>kunci;
        cout<<endl<<"Ciphertext\t: "<<affineCipher(shiftCipher(plaintext, kunci));
        cout<<"\n(PRESS ANY KEY)";
        getch();
        system("cls");
        menu();
    }
    else if (pilih == "4"){
        cout<<"Masukan pesan yang ingin di enkripsi!\nPlaintext\t: ";
        cin.ignore();
        getline(cin, plaintext);
        cout<<"\nMasukan ANGKA untuk dijadikan kunci!"<<endl;
        cin>>kunci;
        cout<<endl<<"Ciphertext\t: "<<shiftCipher(affineCipher(plaintext), kunci);
        cout<<"\n(PRESS ANY KEY)";
        getch();
        system("cls");
        menu();
    }
    else if (pilih == "5"){
        return;
    }
    else {
        cout<<"Anda salah memasukan angka, silahkan masukan kembali\n(PRESS ANY KEY)";
        getch();
        system("cls");
        menu();
    }

}

//Driver Program
int main(void)
{
    menu();
    penutupan();
    return 0;
}
