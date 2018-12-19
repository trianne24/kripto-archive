#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string.h>

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

void enkripsiMatriks3x3 (Matriks3x3 *matriks) {
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

void dekripsiMatriks3x3 (Matriks3x3 *matriks) {
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

int main () {
	Matriks3x3 matriks[1];
	
	cout<<"Masukkan Elemen-elemen matriks 3x3!"<<endl;
	inputMatriks3x3(matriks);
	cout<<endl;
	matriks[0].determinan = determinanMatriks3x3(matriks);
	
	if (matriks[0].determinan == 0) {
		cout<<"Determinan Matriks = 0"<<endl;
		cout<<"Enkripsi dan dekripsi tidak dapat dilakukan";
	}else {
		inversDeterminan(matriks);
		if (matriks[0].inversDeterminan != 0) {
			inversMatriks3x3(matriks);
			getText();
			enkripsiMatriks3x3(matriks);
			dekripsiMatriks3x3(matriks);
			cout<<"\nChiper Text\t:\t";
			cetakChiperText();
			cout<<endl;
			cout<<"\nPlainText\t:\t";
			cetakPlainText();
		}else {
			cout<<"Invers determinan = 0"<<endl;
			cout<<"Enkripsi dan Dekripsi tidak dapat dilakukan";
		}
	}
}
