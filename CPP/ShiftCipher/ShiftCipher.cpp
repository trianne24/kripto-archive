/*
	=================================PROGRAM SHIFT CIPHER=================================
	Angga (160001), Naufal (160033), Adryan (160049), Rifqy (160055), dan Patricia (160065)

********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string encryptShift(string plain, int key){
    string cipher = plain;

    for(int i = 0; i < plain.length(); i++){
        if(isupper(cipher[i]))
            cipher[i] = (((cipher[i] - 'A') + key + 26) % 26) + 'A';
        else if(islower(cipher[i]))
            cipher[i] = (((cipher[i] - 'a') + key + 26) % 26) + 'a';
        else if(isdigit(cipher[i]))
            cipher[i] = (((cipher[i] - '0') + key + 10) % 10) + '0';
    }
    return cipher;
}
string decryptShift(string cipher, int key){
    string plain = cipher;

    for(int i = 0; i < cipher.length(); i++){
        if(isupper(cipher[i]))
            plain[i] = (((plain[i] - 'A' - key + (26 * (key/26))) % 26)) + 'A';
        else if(islower(cipher[i]))
            plain[i] = (((plain[i] - 'a' - key + (26 * (key/26))) % 26)) + 'a';
        else if(isdigit(cipher[i]))
            plain[i] = (((plain[i] - '0' - key + (10 * (key/10))) % 10)) + '0';
    }
    return plain;
}

int main(){
    string plain;
    int key;

    cout<<"Tuliskan pesan: ";
    getline(cin, plain);

    cout<<"Masukkan key: ";
    cin>>key;

    cout<<"Hasil enkripsi: "<<encryptShift(plain, key)<<endl;
    cout<<"Hasil dekripsi: "<<decryptShift(encryptShift(plain, key), key)<<endl;
}
