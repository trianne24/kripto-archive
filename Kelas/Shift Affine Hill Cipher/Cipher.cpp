/*
	================PROGRAM SHIFT, AFFINE, DAN HILL CIPHER MASUKKAN KALIMAT================
	Angga (160001), Naufal (160033), Adryan (160049), Rifqy (160055), dan Patricia (160065)

********************************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

void shiftCipherEnc (){
	string msg;
	int key;
	cout<<"Input your message: ";
	cin>>msg;
	cout<<"Input the key: ";
	cin>>key;
	cout<<endl;
	
	//algorithm here
	string cipher = msg;
	for(int i=0;i<msg.length();i++){
		if(isupper(cipher[i]))
			cipher[i] = (((cipher[i] - 'A') + key + 26) % 26) + 'A';
		else if(islower(cipher[i]))
			cipher[i] = (((cipher[i] - 'a') + key + 26) % 26) + 'a';
		else if(isdigit(cipher[i]))
			cipher[i] = (((cipher[i] - '0') + key + 10) % 10) + '0';
	}
	cout<<"Encrypted message: "<<cipher;
}

void shiftCipherDec (){
	string cipher;
	int key;
	cout<<"Input your message: ";
	cin>>cipher;
	cout<<"Input the key: ";
	cin>>key;
	cout<<endl;
	
	//algorithm here
	string msg = cipher;

    for(int i=0;i<cipher.length();i++){
        if(isupper(cipher[i]))
            msg[i] = (((msg[i] - 'A' - key + (26 * (key/26))) % 26)) + 'A';
        else if(islower(cipher[i]))
            msg[i] = (((msg[i] - 'a' - key + (26 * (key/26))) % 26)) + 'a';
        else if(isdigit(cipher[i]))
            msg[i] = (((msg[i] - '0' - key + (10 * (key/10))) % 10)) + '0';
    }
    cout<<"Decrypted message: "<<msg;
}

void affineCipherEnc (){

}

void affineCipherDec (){

}

void hillCipherEnc (){

}

void hillCipherDec (){

}

void penutupan(){
    cout<<"By :\nAngga Kresnabayu\t\t140810160001\nMuhammad Naufal Monoarfa\t140810160033\nAdryan Luthfi Faiz\t\t140810160049\t\nMuhammad Rifqy Aulia Akbar\t140810160055\nPatricia Joanne\t\t\t140810160065";
}

int main (){
	int num1, num2; 
	int menuBack = 0;
	int keyLoop = 0;

	while (menuBack == 0){
		keyLoop = 0;
		cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
		cout<<"ENCRYPT/DECRYPT YOUR MESSAGE HERE!"<<endl;
		cout<<"-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+"<<endl<<endl;

		cout<<"Choose your cipher:"<<endl;
		cout<<"1. Shift Cipher"<<endl;
		cout<<"2. Affine Cipher"<<endl;
		cout<<"3. Hill Cipher"<<endl;
		cout<<"4. Exit"<<endl<<endl;

		cout<<"Enter the number: ";
		cin>>num1;
		cout<<endl;
		system("cls");
		switch (num1){
			case 1:
				cout<<"Shift Cipher Menu:"<<endl;
				cout<<"1. Encrypt"<<endl;
				cout<<"2. Decrypt"<<endl<<endl;
			break;
			case 2:
				cout<<"Affine Cipher Menu:"<<endl;
				cout<<"1. Encrypt"<<endl;
				cout<<"2. Decrypt"<<endl<<endl;
			break;
			case 3:
				cout<<"Hill Cipher Menu:"<<endl;
				cout<<"1. Encrypt"<<endl;
				cout<<"2. Decrypt"<<endl<<endl;
			break;
			case 4: return 0;
			break;
		}
		if(num1 != 4){
			cout<<"Enter the number: ";
			cin>>num2;
			system("cls");
		}
		
		//Shift Cipher Encrypt
		if(num1==1&&num2==1){
			shiftCipherEnc();
		}
		//Shift Cipher Decrypt
		else if(num1==1&&num2==2){
			shiftCipherDec();
		}
		//Affine Cipher Encrypt
		else if(num1==2&&num2==1){
			affineCipherEnc();
		}
		//Affine Cipher Decrypt
		else if(num1==2&&num2==2){
			affineCipherDec();
		}
		//Hill Cipher Encrypt
		else if(num1==3&&num2==1){
			hillCipherEnc();
		}
		//Hill Cipher Decrypt
		else if(num1==3&&num2==2){
			hillCipherDec();
		}

		cout<<"\n\nIngin mengulang program?\n1. Ya\n2. Tidak"<<endl;
		cin>>menuBack;
		while(keyLoop == 0)
		if(menuBack == 1){
			keyLoop = 1;
			system("cls");
			menuBack = 0;
		}
		else if(menuBack == 2){
			keyLoop = 1;
			system("cls");
			penutupan();
			break;
		}
		else{
			cout<<"Pilihan yang anda masukan salah, mohon masukan kembali : ";
			cin>>menuBack;
		}
	}
}
