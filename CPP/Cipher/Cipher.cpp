/*
	================PROGRAM SHIFT, AFFINE, DAN HILL CIPHER MASUKKAN KALIMAT================
	Angga (160001), Naufal (160033), Adryan (160049), Rifqy (160055), dan Patricia (160065)

********************************************************************************************/

#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Matriks3x3 {
	float elemen[3][3];
	int determinan;
	float minor[3][3];
	float kofaktor[3][3];
	float transpose[3][3];
	int inversDeterminan;
	float inversElemen[3][3];
};

struct MatriksText1x3 {
	int elemen[1][3];
	int jumlahText;
	int chiperText[1][3];
	int plainText[1][3];
}text[99];

void inputMatriks3x3 (Matriks3x3 *matriks) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin>>matriks[0].elemen[i][j];
		}
	}
}

void cetakMatriks3x3 (Matriks3x3 *matriks) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout<<matriks[0].inversElemen[i][j]<<"\t";
		}
		cout<<endl;
	}
}

float determinanMatriks3x3 (Matriks3x3 *matriks) {
	return (matriks[0].elemen[0][0]*matriks[0].elemen[1][1]*matriks[0].elemen[2][2]) + (matriks[0].elemen[0][1]*matriks[0].elemen[1][2]*matriks[0].elemen[2][0]) + (matriks[0].elemen[0][2]*matriks[0].elemen[1][0]*matriks[0].elemen[2][1]) - (matriks[0].elemen[2][0]*matriks[0].elemen[1][1]*matriks[0].elemen[0][2]) - (matriks[0].elemen[2][1]*matriks[0].elemen[1][2]*matriks[0].elemen[0][0]) - (matriks[0].elemen[2][2]*matriks[0].elemen[1][0]*matriks[0].elemen[0][1]);
}

void minorMatriks3x3 (Matriks3x3 *matriks) {
	matriks[0].minor[0][0] = (matriks[0].elemen[1][1] * matriks[0].elemen[2][2]) - (matriks[0].elemen[1][2] * matriks[0].elemen[2][1]);
	matriks[0].minor[0][1] = (matriks[0].elemen[1][0] * matriks[0].elemen[2][2]) - (matriks[0].elemen[1][2] * matriks[0].elemen[2][0]);
	matriks[0].minor[0][2] = (matriks[0].elemen[1][0] * matriks[0].elemen[2][1]) - (matriks[0].elemen[1][1] * matriks[0].elemen[2][0]);
	
	matriks[0].minor[1][0] = (matriks[0].elemen[0][1] * matriks[0].elemen[2][2]) - (matriks[0].elemen[0][2] * matriks[0].elemen[2][1]);
	matriks[0].minor[1][1] = (matriks[0].elemen[0][0] * matriks[0].elemen[2][2]) - (matriks[0].elemen[0][2] * matriks[0].elemen[2][0]);
	matriks[0].minor[1][2] = (matriks[0].elemen[0][0] * matriks[0].elemen[2][1]) - (matriks[0].elemen[0][1] * matriks[0].elemen[2][0]);
	
	matriks[0].minor[2][0] = (matriks[0].elemen[0][1] * matriks[0].elemen[1][2]) - (matriks[0].elemen[0][2] * matriks[0].elemen[1][1]);
	matriks[0].minor[2][1] = (matriks[0].elemen[0][0] * matriks[0].elemen[1][2]) - (matriks[0].elemen[0][2] * matriks[0].elemen[1][0]);
	matriks[0].minor[2][2] = (matriks[0].elemen[0][0] * matriks[0].elemen[1][1]) - (matriks[0].elemen[0][1] * matriks[0].elemen[1][0]);
}

void kofaktorMatriks3x3 (Matriks3x3 *matriks) {
	int angka = 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (angka % 2 == 0) {
				matriks[0].kofaktor[i][j] = matriks[0].minor[i][j] * (-1);
			}else {
				matriks[0].kofaktor[i][j] = matriks[0].minor[i][j] * 1;
			}
			angka++;
		}
	}
}

void transposeMatriks3x3 (Matriks3x3 *matriks) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matriks[0].transpose[i][j] = matriks[0].kofaktor[j][i];
		}
	}
}

void inversDeterminan(Matriks3x3 *matriks) {
	int det = matriks[0].determinan % 26;
	switch(det){
		case 1	:
			matriks[0].inversDeterminan = 1;
			break;
		case 3	:
			matriks[0].inversDeterminan = 9;
			break;
		case 5	:
			matriks[0].inversDeterminan = 21;
			break;
		case 7	:
			matriks[0].inversDeterminan = 15;
			break;
		case 11	:
			matriks[0].inversDeterminan = 19;
			break;
		case 17	:
			matriks[0].inversDeterminan = 23;
			break;
		case 25	:
			matriks[0].inversDeterminan = 25;
			break;
		case 9	:
			matriks[0].inversDeterminan = 3;
			break;
		case 21	:
			matriks[0].inversDeterminan = 5;
			break;
		case 15	:
			matriks[0].inversDeterminan = 7;
			break;
		case 19	:
			matriks[0].inversDeterminan = 11;
			break;
		case 23	:
			matriks[0].inversDeterminan = 17;
			break;
		default	:
			matriks[0].inversDeterminan = 0;
			break;
	}
}

void perkalianMatriks3x3xInversDeterminan (Matriks3x3 *matriks) {
	int untukMod;
	
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			untukMod = int(matriks[0].transpose[i][j] * matriks[0].inversDeterminan) % 26;
			if (untukMod < 0) {
				matriks[0].inversElemen[i][j] = 26 + untukMod;
			}else {
				matriks[0].inversElemen[i][j] = untukMod;
			}
		}
	}
}

void inversMatriks3x3 (Matriks3x3 *matriks) {
	minorMatriks3x3(matriks);
	kofaktorMatriks3x3(matriks);
	transposeMatriks3x3(matriks);
	perkalianMatriks3x3xInversDeterminan(matriks);
}

void getText () {
	string kata;
	cout<<"Masukkan kata kelipatan 3\t:\t"; cin>>kata;
	
	char arrayKata[kata.length()];
	
	strncpy(arrayKata, kata.c_str(), sizeof(arrayKata));
	
	if ((sizeof(arrayKata)%3) != 0) {
		cout<<"kata harus kelipatan 3"<<endl;
	}else {
		int looping = sizeof(arrayKata) / 3;
		text[0].jumlahText = looping;
		int indexArray = 0;
		for (int i = 0; i < looping; i++) {
			text[i].elemen[0][0] = arrayKata[indexArray];
			indexArray++;
			text[i].elemen[0][1] = arrayKata[indexArray];
			indexArray++;
			text[i].elemen[0][2] = arrayKata[indexArray];
			indexArray++;
		}
	}	
}

int mod26 (int angka) {
	if (angka < 0) {
		return (26 + (angka%26));
	}else {
		return (angka%26);
	}
}

void cetakChiperText () {
	for (int i = 0; i < text[0].jumlahText; i++) {
		cout<<char(text[i].chiperText[0][0]);
		cout<<char(text[i].chiperText[0][1]);
		cout<<char(text[i].chiperText[0][2]);
	}
}

void cetakPlainText () {
	for (int i = 0; i < text[0].jumlahText; i++) {
		cout<<char(text[i].plainText[0][0]);
		cout<<char(text[i].plainText[0][1]);
		cout<<char(text[i].plainText[0][2]);
	}
}

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
	string msg;
	int a,b;
	cout<<"Input your message: ";
	cin>>msg;
	cout<<"Input a: ";
	cin>>a;
	cout<<"Input b: ";
	cin>>b;
	cout<<endl;
	
	//algorithm here
	string cipher = "";
    for (int i=0;i<msg.length();i++){
        if (isupper(msg[i]))
            cipher = cipher + (char) ((((a * (msg[i] - 'A' )) + b + 26) % 26) + 'A');
        else if (islower(msg[i]))
            cipher = cipher + (char) ((((a * (msg[i] - 'a' )) + b + 26) % 26) + 'a');
        else if (isdigit(msg[i]))
            cipher = cipher + (char) ((((a * (msg[i] - '0' )) + b + 10) % 10) + '0');
    }
    cout<<"Encrypted message: "<<cipher;
}

void affineCipherDec (){
	string cipher;
	int a,b;
	cout<<"Input your message: ";
	cin>>cipher;
	cout<<"Input a: ";
	cin>>a;
	cout<<"Input b: ";
	cin>>b;
	cout<<endl;
	
	//algorithm here
	string msg = "";
    int a_inv = 0;
    int a_inv_digit = 0;
    int flag = 0;

    for (int i=0;i<26;i++){
        flag = (a*i) % 26;
        if (flag==1) a_inv = i;
    }
    flag = 0;
    for (int i=0;i<10;i++){
        flag = (a*i) % 10;
        if (flag==1) a_inv_digit = i;
    }
    for (int i=0;i<cipher.length();i++){
        if (isupper(cipher[i]))
            msg = msg + (char) (((a_inv * (((cipher[i] - 'A') - b + 26)) % 26)) + 'A');
        else if (islower(cipher[i]))
            msg = msg + (char) (((a_inv * (((cipher[i] - 'a') - b + 26)) % 26)) + 'a');
        else if (isdigit(cipher[i]))
            msg = msg + (char) (((a_inv_digit * (((cipher[i] - '0') - b + 10)) % 10)) + '0');
    }
	cout<<"Decrypted message: "<<msg;
}

void hillCipherEnc (Matriks3x3 *matriks){
	//algorithm here
	for (int i = 0; i < text[0].jumlahText; i++) {
		for (int j = 0; j < 3; j++) {
			if (text[i].elemen[0][j] >= 65 && text[i].elemen[0][j] <= 90) {
				text[i].chiperText[0][j] = 	mod26(((text[i].elemen[0][0] - 65)*matriks[0].elemen[0][j]) + ((text[i].elemen[0][1] - 65)*matriks[0].elemen[1][j]) + ((text[i].elemen[0][2] - 65)*matriks[0].elemen[2][j])) + 65;
			}else if (text[i].elemen[0][j] >= 97 && text[i].elemen[0][j] <= 122) {
				text[i].chiperText[0][j] = 	mod26(((text[i].elemen[0][0] - 97)*matriks[0].elemen[0][j]) + ((text[i].elemen[0][1] - 97)*matriks[0].elemen[1][j]) + ((text[i].elemen[0][2] - 97)*matriks[0].elemen[2][j])) + 97;
			}else {
				text[i].chiperText[0][j] = 	text[i].elemen[0][j];
			}
		}
	}
}

void hillCipherDec (Matriks3x3 *matriks){
	//algorithm here
	for (int i = 0; i < text[0].jumlahText; i++) {
		for (int j = 0; j < 3; j++) {
			if (text[i].chiperText[0][j] >= 65 && text[i].chiperText[0][j] <= 90) {
				text[i].plainText[0][j] = 	mod26(((text[i].chiperText[0][0] - 65)*matriks[0].inversElemen[0][j]) + ((text[i].chiperText[0][1] - 65)*matriks[0].inversElemen[1][j]) + ((text[i].chiperText[0][2] - 65)*matriks[0].inversElemen[2][j])) + 65;
			}else if (text[i].chiperText[0][j] >= 97 && text[i].chiperText[0][j] <= 122) {
				text[i].plainText[0][j] = 	mod26(((text[i].chiperText[0][0] - 97)*matriks[0].inversElemen[0][j]) + ((text[i].chiperText[0][1] - 97)*matriks[0].inversElemen[1][j]) + ((text[i].chiperText[0][2] - 97)*matriks[0].inversElemen[2][j])) + 97;
			}else {
				text[i].plainText[0][j] = 	text[i].chiperText[0][j];
			}
		}
	}
}

void closing(){
	cout<<"-+-+-+-+-+-+-+-+-+-+-+-+"<<endl;
    cout<<"C++ Cryptography Program"<<endl;
	cout<<"-+-+-+-+-+-+-+-+-+-+-+-+"<<endl<<endl;
	cout<<"Angga Kresnabayu\t\t140810160001\nMuhammad Naufal Monoarfa\t140810160033\nAdryan Luthfi Faiz\t\t140810160049\t\nMuhammad Rifqy Aulia Akbar\t140810160055\nPatricia Joanne\t\t\t140810160065";
}


int main (){
	int num1, num2; 
	int menuBack = 0;
	int keyLoop = 0;
	Matriks3x3 matriks[1];

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
			case 4:
				system("cls");
				closing();
				return 0;
			break;
			// not yet error handling //
		}
		
		if(num1 != 4){
			cout<<"Enter the number: ";
			cin>>num2;
			// not yet error handling //
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
			cout<<"Input 3x3 matrix: "<<endl;
			inputMatriks3x3(matriks);
			cout<<endl;
			matriks[0].determinan = determinanMatriks3x3(matriks);
			
			if (matriks[0].determinan == 0) {
				cout<<"Determinant = 0"<<endl;
				cout<<"Encrypt failed. Please try new matrix.";
			}
			else {
				inversDeterminan(matriks);
				if (matriks[0].inversDeterminan != 0) {
					inversMatriks3x3(matriks);
					getText();
					hillCipherEnc(matriks);
					hillCipherDec(matriks);
					cout<<"\nCipher Text:\t";
					cetakChiperText();
					cout<<endl;
					cout<<"\nPlainText:\t";
					cetakPlainText();
				}else {
					cout<<"Inverse of determinant = 0"<<endl;
					cout<<"Encrypt failed. Please try new matrix.";
				}
			}
		}
		//Hill Cipher Decrypt
		else if(num1==3&&num2==2){
			cout<<"Input 3x3 matrix: "<<endl;
			inputMatriks3x3(matriks);
			cout<<endl;
			matriks[0].determinan = determinanMatriks3x3(matriks);
			
			if (matriks[0].determinan == 0) {
				cout<<"Determinant = 0"<<endl;
				cout<<"Decrypt failed. Please try new matrix.";
			}
			else {
				inversDeterminan(matriks);
				if (matriks[0].inversDeterminan != 0) {
					inversMatriks3x3(matriks);
					getText();
					hillCipherEnc(matriks);
					hillCipherDec(matriks);
					cout<<"\nCipher Text:\t";
					cetakChiperText();
					cout<<endl;
					cout<<"\nPlainText:\t";
					cetakPlainText();
				}else {
					cout<<"Inverse of determinant = 0"<<endl;
					cout<<"Decrypt failed. Please try new matrix.";
				}
			}
		}
		
		cout<<endl<<endl<<"Replay Program?"<<endl<<"1. Yes\n2. No"<<endl;
		cout<<"Enter the number: ";
		cin>>menuBack;
		while(keyLoop == 0){
			if(menuBack == 1){
				keyLoop = 1;
				system("cls");
				menuBack = 0;
			}
			else if(menuBack == 2){
				keyLoop = 1;
				system("cls");
				closing();
				break;
			}
			else {
				cout<<"Error! Please input only the number given: ";
				cin>>menuBack;
			}
		}
	}
}
