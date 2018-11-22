/* Program Hill Cipher 2x2 oleh:
Angga Kresnabayu (140810160001)
Muhammad Islam Taufikurahman (140810160062)
Patricia Joanne (140810160065)
********************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

struct matriks {
	int isi[2][2];
	int det;
};
struct blok {
	int pos[2];
	int caps[2];
};
void inputData(string& input){
	system("cls");
	cout<<"Masukkan kalimat\t: ";
	cin.ignore();
	getline(cin, input);
}
matriks inputKunci(){
	matriks kunci;
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			cout<<"Masukkan kunci "<<"["<<i<<","<<j<<"]: ";cin>>kunci.isi[i][j];
		}
	}
	kunci.det=(kunci.isi[0][0]*kunci.isi[1][1])-(kunci.isi[0][1]*kunci.isi[1][0]);
	return kunci;
}
void inversMatriks(matriks& input){
	int hold;
	hold=input.isi[0][0];
	input.isi[0][0]=input.isi[1][1];
	input.isi[1][1]=hold;
	input.isi[1][0]*=-1;
	input.isi[0][1]*=-1;
}
int cek_GCD(int a,int b){
	int residu;
	if(b == 0){
		return 0;
	}
	else if(b == 1){
		return 1;
	}
	else if(b != 0){
		residu = a % b ;
		return cek_GCD(b,residu);
	}
	else{
		return 0;
	}
}
int cekKunci(matriks kunci){
	if(kunci.det != 0){
		return 1;
	}
	else{
		return 0;
	}
}
int cek_huruf(char huruf){
	if(huruf >= 65 && huruf <= 90)return 65;
	else if (huruf >=97 && huruf <=122)return 97;
	else return 3;
}
blok cari_huruf(string input,int& p){
	blok hold;
	int i,n,j;
	n = input.size();
	hold.caps[1]=0;
	for (i=0;i<2;i++){
		hold.caps[i]=cek_huruf(input[p]);
		j=0;
		while(hold.caps[i] == 3){
			hold.caps[i] = cek_huruf(input[p+ ++j ]);
			if(p+j == n){
				hold.caps[i]=4;
			}
		}
		p+=j;
		hold.pos[i] = p;
		p++;
	}
	return hold;
}
void kaliMatriks(int hasil[],matriks kunci,string input,blok hold){
	int i,j;
	for(i = 0; i<2;i++){
		for(j = 0; j < 2; j++){
			hasil[i]+=(kunci.isi[i][j]*input[hold.pos[j]]);
		}
	}
}
void toAscii(char& input,int hasil,int caps){
	input=(hasil%26)+caps;
}

string enkripsi(string input,int& sinyal) {	
	int n,i;
	int hasil[2];
	matriks kunci;
	blok hold;
	kunci=inputKunci();
	
	system("cls");
	n = input.size();
	if(cek_GCD(kunci.det,26) == 1){
		sinyal = 2;
		for (i = 0; i < n; i++) {
			hold=cari_huruf(input,i);
			cout<<hold.caps[1]<<endl;
			if(hold.caps[1] == 4){
				cout<<"in"<<endl;
				string ghost;
				hold.pos[1]=hold.pos[0] + 1;
				ghost=input;
				ghost[hold.pos[1]]=65;
				hold.caps[1]=65;
				hasil[0]=0;
				hasil[1]=0;
				ghost[hold.pos[0]]-=hold.caps[0];
				ghost[hold.pos[1]]-=hold.caps[1];
				kaliMatriks(hasil,kunci,ghost,hold);
				toAscii(input[hold.pos[0]],hasil[0],hold.caps[0]);
				return input;
			}
			hasil[0]=0;
			hasil[1]=0;
			input[hold.pos[0]]-=hold.caps[0];
			input[hold.pos[1]]-=hold.caps[1];
			kaliMatriks(hasil,kunci,input,hold);
			toAscii(input[hold.pos[0]],hasil[0],hold.caps[0]);
			toAscii(input[hold.pos[1]],hasil[1],hold.caps[1]);
		}
	}
	else {
		if(kunci.det == 0)sinyal=1;
		else sinyal=0;
	}
	return input;
}

string dekripsi(string input,int& sinyal){
	int n,i;
	int hasil[2],invDet=0;
	matriks kunci;
	blok hold;
	kunci=inputKunci();
	inversMatriks(kunci);
	system("cls");
	n = input.size();
	if(cek_GCD(kunci.det,26) == 1){
		sinyal = 2;
		while((invDet*kunci.det) % 26 !=1){
			invDet++;
		}
		cout<<invDet<<endl;
		for (i = 0; i < n; i++) {
			hold=cari_huruf(input,i);
			if(hold.caps[1] == 4){
				int asal=-1,cipher,a,b;
				
				a=kunci.isi[1][1];
				b=(kunci.isi[0][1]*-1);
				cipher=input[hold.pos[0]]-hold.caps[0];
				while(hasil[0] != cipher){
					asal++;
					hasil[0]=0;
					hasil[0]= (a*asal)+(b*0);
					hasil[0] %= 26;
				}
				input[hold.pos[0]]=asal+hold.caps[0];
				return input;
			}
			hasil[0]=0;
			hasil[1]=0;
			input[hold.pos[0]]-=hold.caps[0];
			input[hold.pos[1]]-=hold.caps[1];
			kaliMatriks(hasil,kunci,input,hold);
			hasil[0] *= invDet;
			hasil[1] *= invDet;
			toAscii(input[hold.pos[0]],hasil[0],hold.caps[0]);
			toAscii(input[hold.pos[1]],hasil[1],hold.caps[1]);
		}
	}
	else {
		if(kunci.det==0) sinyal=1;
		else sinyal=0;
	}
	return input;
}


int main(){
	int pilihan=9, sinyal;
	string input, hasil;

	do {
		system("cls");
		cout << "===============================" << endl;
		cout << "|        HILL CIPHER 2X2      |" << endl;
		cout << "===============================" << endl;
		cout << "| 1. Enkripsi                 |" << endl;
		cout << "| 2. Dekripsi                 |" << endl;
		cout << "| 0. Keluar                   |" << endl;
		cout << "===============================" << endl;
		cout << " Masukkan pilihan: ";
		cin >> pilihan;
		
		switch (pilihan){
			case 1:
				inputData(input);
				hasil=enkripsi(input,sinyal);
				if(sinyal == 2){
					cout << "Hasil Enkripsi: "<<hasil<<endl;
				}
				else if (sinyal == 1){
					cout<<"Kunci tidak memiliki invers!"<<endl;
				}
				else {
					cout<<"GCD determinan kunci dan 26 bukan 1!"<<endl;
				}
				system("pause");
				break;
			case 2:
				inputData(input);
				hasil=dekripsi(input,sinyal);
				if(sinyal == 2){
					cout << "Hasil Dekripsi: "<<hasil<<endl;
				}
				else if (sinyal == 1){
					cout<<"Kunci tidak memiliki invers!"<<endl;
				}
				else {
					cout<<"GCD determinan kunci dan 26 bukan 1!"<<endl;
				}
				system("pause");
				break;
			default:
				cout << "Input salah!" << endl;
				system("cls");
				break;
		}
	}
	while (pilihan != 0);
	cout << "Dibuat oleh:" << endl;
	cout << "Angga Kresnabayu (140810160001)" << endl;
	cout << "Muhammad Islam Taufikurahman (140810160062)" << endl;
	cout << "Patricia Joanne (140810160065)" << endl;
	system("pause");
}

