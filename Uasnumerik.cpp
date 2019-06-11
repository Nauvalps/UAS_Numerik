#include <iostream>
#include <conio.h>
#include <string.h>
#include <math.h>
#include<iomanip>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 1000
// method konversi biner ke desimal
void binary(int desimal);
void binary(int desimal)
{ 
     int sisa;
     int hasil;
     
     if ( desimal <=1)
     {
        cout<<desimal;
        return;
     }
     sisa = desimal %2;
     hasil = desimal / 2;
     binary(hasil);
     cout<<sisa;
}
// akhir method

//method konversi bil desimal ke biner
void konversiDes(int bin) {
   int sisa1,hasil1,a;
   hasil1=0;
   int pangkat=0;
	   while(bin>=1) {
	      sisa1=bin%2;
	      hasil1+=sisa1*pow(2,pangkat);
	      bin=bin/10;
	      pangkat++;
	   }
   cout<<hasil1<<endl;
}
// akhir method konversi bil desimal ke biner

//method konversi octal - hexa
void konversiOctalHexa(){
	int a[20],b[20],c[20],rev[20];
    int h,i,j,k,l,x,fra,flag,rem,num1,num3;
    float rem1,num2,num4,dno;
    char s[20];
    x=fra=flag=rem=0;
    rem1=0.0;
    cout<<"Masukkan Bilangan Octal : ";
    cin>>s;
	    for(i=0,j=0,k=0;i<strlen(s);i++) {
	        if(s[i]=='.')
	        {
	            flag=1;
	        }
	        else if(flag==0)
	            a[j++]=s[i]-48;
	        else if(flag==1)
	            b[k++]=s[i]-48;
	    }
    x=j;
    fra=k;
	    for(j=0,i=x-1;j<x;j++,i--) {
	        rem = rem +(a[j] * pow(8,i));
	    }
	    for(k=0,i=1;k<fra;k++,i++) {
	        rem1 = rem1 +(b[k] / pow(8,i));
	    }
    rem1=rem+rem1;
    dno=rem1;
    num1=(int)dno;
    num2=dno-num1;
    i=0;
	    while(num1!=0) {
	        rem=num1 % 16;
	        rev[i] = rem;
	        num1=num1 /16;
	        i++;
	    }
    j=0;
	    while(num2!=0.0) {
	        num2=num2 * 16;
	        num3=(int)num2;
	        num4=num2-num3;
	        num2=num4;
	        a[j]=num3;
	        j++;
	        if(j==4) {
	            break;
	        }
	    }
    l=i;
    cout<<"nHasil Konversi Octal - Hexa  : ";
	    for(i=l-1;i>=0;i--) {
	        if(rev[i]==10)
	           cout<<"A";
	        else if(rev[i]==11)
	           cout<<"B";
	        else if(rev[i]==12)
	           cout<<"C";
	        else if(rev[i]==13)
	           cout<<"D";
	        else if(rev[i]==14)
	           cout<<"E";
	        else if(rev[i]==15)
	           cout<<"F";
	        else
	        cout<<rev[i];
	    }
    h=j;
    cout<<".";
	    for(k=0;k<h;k++) {
	        if(a[k]==10)
	           cout<<"A";
	        else if(a[k]==11)
	           cout<<"B";
	        else if(a[k]==12)
	           cout<<"C";
	        else if(a[k]==13)
	           cout<<"D";
	        else if(a[k]==14)
	           cout<<"E";
	        else if(a[k]==15)
	           cout<<"F";
	        else
	        cout<<a[k];
	    }
}
// akhir method konversi octal - hexa

// method konversi hexa-octal
int hex_to_oct(char hex[]);
int hex_to_oct(char hex[]) {
	int i,len, dec=0, oct=0;
	for(len=0; hex[len]!='\0'; len++);
	for(i=0; hex[i]!='\0'; i++,len--)
	{
		if(hex[i]>='0' && hex[i]<='9')
		{
			dec= dec + (hex[i]-'0')*pow(16,len-1);
		}
		if(hex[i]>='A' && hex[i]<='F')
		{
			dec = dec + (hex[i]-55)*pow(16,len-1);
		}
		if(hex[i]>='a' && hex[i]<='f')
		{
			dec = dec + (hex[i]-87)*pow(16,len-1);
		}
	} /* Now dec contains the decimal value of given hexadecimal number. */
	i=1;
	while(dec!=0)
	{
		oct = oct + (dec%8)*i;
		dec = dec/8;
		i = i*10;
	}
	return oct;
}
// akhir method konversi hexa-octal

//method konversi biner - octal 
int BinarytoOctal(int binaryNum) {
   int octalNum = 0, decimalNum = 0, count = 0;
   
   while(binaryNum != 0) {
      decimalNum += (binaryNum%10) * pow(2,count);
      ++count;
      binaryNum/=10;
   }
   count = 1;
   while (decimalNum != 0) {
      octalNum += (decimalNum % 8) * count;
      decimalNum /= 8;
      count *= 10;
   }
   return octalNum;
}
// akhir method konversi biner-octal

//method konversi octal - biner
int OctalToBinary(int octalNum) {
   int decimalNum = 0, binaryNum = 0, count = 0;
   while(octalNum != 0) {
      decimalNum += (octalNum%10) * pow(8,count);
      ++count;
      octalNum/=10;
   }
   count = 1;
   while (decimalNum != 0) {
      binaryNum += (decimalNum % 2) * count;
      decimalNum /= 2;
      count *= 10;
   }
   return binaryNum;
}
// akhir method konversi octal - biner

// method konversi biner - hexa
void KonversiBinerHexa(){
	int hex[1000];
    int i = 1, j = 0, rem, dec = 0, binaryNumber;
	cout << "\n\n Convert a binary number to hexadecimal number:\n";
	cout << "----------------------------------------------------\n";
	cout << " Input a binary number: ";
	cin>> binaryNumber;
		while (binaryNumber > 0)  {
		   rem = binaryNumber % 2;
		   dec = dec + rem * i;
		   i = i * 2;
		   binaryNumber = binaryNumber / 10;
		}
    i = 0;
		while (dec != 0)  {
		   hex[i] = dec % 16;
		   dec = dec / 16;
		   i++;
		}
    cout<<" The hexadecimal value: ";
	for (j = i - 1; j >= 0; j--) {
		if (hex[j] > 9) {
			cout<<(char)(hex[j] + 55)<<"\n";
		} 
		else {
			cout<<hex[j]<<"\n";
		}
	}
}
// akhir method konversi biner - hexa

//method konversi hexa - biner
void KonversiHexaBiner(){
	char binaryNumber[MAX],hexaDecimal[MAX];
    long int i=0;
 
    cout<<"Masukkan Bilangan Hexadesimal: ";
    cin>>hexaDecimal;
 
    cout<<"nHasil Bilangan Biner: ";
    while(hexaDecimal[i])
    {
         switch(hexaDecimal[i])
         {
             case '0': cout<<"0000"; break;
             case '1': cout<<"0001"; break;
             case '2': cout<<"0010"; break;
             case '3': cout<<"0011"; break;
             case '4': cout<<"0100"; break;
             case '5': cout<<"0101"; break;
             case '6': cout<<"0110"; break;
             case '7': cout<<"0111"; break;
             case '8': cout<<"1000"; break;
             case '9': cout<<"1001"; break;
             case 'A': cout<<"1010"; break;
             case 'B': cout<<"1011"; break;
             case 'C': cout<<"1100"; break;
             case 'D': cout<<"1101"; break;
             case 'E': cout<<"1110"; break;
             case 'F': cout<<"1111"; break;
             case 'a': cout<<"1010"; break;
             case 'b': cout<<"1011"; break;
             case 'c': cout<<"1100"; break;
             case 'd': cout<<"1101"; break;
             case 'e': cout<<"1110"; break;
             case 'f': cout<<"1111"; break;
             default:  cout<<"nInvalid hexadecimal digit "<<hexaDecimal[i];
         }
         i++;
    }
}
//akhir method hexa -  biner

// method regula falsi
double fun(double x)
{
  return(x*x-4*x-10);
}

const double TOL=1e-5;

void regulafalsi()
{
    double x3,x1,x2,xs,f1,f2,f3;
    int iter=0;
    cout << "Enter brackting numbers x1, x2" << endl;
    cin>>x1>>x2;

    f1=fun(x1);
    f2=fun(x2);

    if((f1*f2)>0)
        {
            cout<<"\nDoesn't bracket...\n";
         }
    else
    {
        do
        {
            xs=x3;
            x3=x1-(f1*(x2-x1))/(f2-f1);
            f3=fun(x3);
            iter++;

            cout<<setprecision(10)<<setw(3)<<iter<<setw(15)<<x1<<setw(15)<<x2<<setw(15)<<fun(x3)<<endl;

            if((f1*f3)<0)

                x2=x3;
            else
                x1=x3;
                f1=fun(x1);
                f2=fun(x2);
        }while(fabs(fun(x3))>=TOL);//Terminating case
    }
    cout<<"\nThe root of the equation is :"<<x3;
    cout<<"\n\nf(x)="<<fun(x3);
}
// akhir method regula falsi

double func(double x)
{
    return x*x*x - 2*x*x + 3;
}
 
double e=0.01;
double c;
 
void bisection(double a,double b)
{
    if(func(a) * func(b) >= 0)
    {
        cout<<"Incorrect a and b";
        return;
    }
 
    c = a;
 
    while ((b-a) >= e)
    {
        c = (a+b)/2;
        if (func(c) == 0.0){
            cout << "Root = " << c<<endl;
            break;
        }
        else if (func(c)*func(a) < 0){
                cout << "Root = " << c<<endl;
                b = c;
        }
        else{
                cout << "Root = " << c<<endl;
                a = c;
        }
    }
}

class Switch {
	public:
	int pilih;
	void print(){
	cout << "\nProyek Komputasi Numerik\n";
    cout << "=============== ==\n\n";
    cout << "\n Menu Utama :\n";
    cout << "1. Menghitung Penjumlahan Bilangan Pecahan\n";
    cout << "2. Konversi Biner - Desimal\n";
    cout << "3. Menghitung Galat\n";
    cout << "4. Persamaan Non Linier\n";
    cout << "5. Interpolasi dan Polinomial\n";
    cout << "6. Diferensial\n";
    cout << "7. Integral\n";
    cout << "8. Persamaan Linier\n";
    cout << "9. (Optimasi Numerik)\n";
    cout << "10.(Regresi Linier)\n";
    cout << "\n Masukkan pilihan anda : ";
    cin>>pilih;
    cout<<"\n" << endl;
    
    switch (pilih){
		case 1:{		
			int hasil;
			float bil=1;
			cout<<"Masukkan Jumlah Penjumlahan = ";cin>>hasil;
          for(int i=1; i<=hasil; i++){
          	cout<<bil;
          	bil= bil + 0.1;
          	cout<<"+0.1 = "<< bil<<'\n';
		  }
	}
			break;
		case 2:
			cout<<"\nKonversi Biner - Desimal - Octal - Hexa:\n";
			cout<<" 1. Desimal - Biner\n";
			cout<<" 2. Biner - Desimal\n";
			cout<<" 3. Octal - Hexa\n";
			cout<<" 4. Hexa - Octal\n";
			cout<<" 5. Biner - Octal\n";
			cout<<" 6. Biner - Hexa\n";	
			cout<<" 7. Hexa - Biner\n";	
			cout << "\n Masukkan pilihan anda : ";
			cin>>pilih;
			cout<<"\n" << endl;
			switch (pilih){
				case 1:
				int x;    
                    cout << "Masukkan Bilangan Desimal : ";
	                cin>>x;
	                cout << x << " dalam biner adalah " ; 
	                binary(x);
	                cout<<endl;
				break;
				case 2:
				    int bin,des;
                    int pil;
              		cout<<"\nBiner Ke  Desimal ";
					cout<<"\nMasukkan Bilangan Biner = ";
					cin>>bin;
              		cout<<"Hasil Konversi    = ";
              		konversiDes(bin);
					  break;
				case 3:
					konversiOctalHexa();
					break;
				case 4:
					char hex[20],c;
					int n;
					cout<<"Masukkan Bilangan Hexadesimal = ";
					cin>>hex;
					cout<<"Hasil Bilangan Octal =  "<<hex_to_oct(hex);
					getch();
					break;
				case 5:
					int binerNum, octalNum;
					cout <<"\nBinary - Octal Octal - Binary"<<endl;
					cout<<"Masukkan Bilangan Biner = ";
					cin>>binerNum;
					cout<<"Hasil Bilangan  Octal = "<<BinarytoOctal(binerNum)<<endl;
					cout <<"\nOctal to Binary"<<endl;
					cout<<"Masukkan Bilangan Octal =  ";
					cin>>octalNum;
					cout<<"Hasil Bilangan Biner =  "<<OctalToBinary(octalNum)<<endl;
					break;
				case 6:
					KonversiBinerHexa();
					break;
				case 7:
					KonversiHexaBiner();
					break;			
		       }	
			break;
		case 3 :
			break;
		case 4 :
			cout<<"\nPersamaan Non Linier :\n";
			cout<<" 1. Iterasi Titik Tetap\n";
			cout<<" 2. Metode Biseksi\n";
			cout<<" 3. Metode Regula Falsi\n";
			cout<<" 4. Metode Newton Raphson\n";
			cout<<" 5. Metode Secant\n";	
			cout << "\n Masukkan pilihan anda : ";
			cin>>pilih;
			switch (pilih) {
				case 1 :
					break;
				case 2 :
					double a,b;
				    a=-10;
				    b=20;
				    cout<<"The function used is x^3-2x^2+3\n";
				    cout<<"a = "<<a<<endl;
				    cout<<"b = "<<b<<endl;
				    bisection(a,b);
				    cout<<"\n";
				    cout<<"Accurate Root calculated is = "<<c<<endl;
					break;
				case 3 :
					regulafalsi();
					break;
				case 4 :
					break;
				case 5 :
					break;
			}
			break;
	    }
    }	
};


int main(int argc, char** argv) {
	Switch obj1;
	obj1.pilih;
	obj1.print();
	return 0;
}
