//Automat de Cafea Software//
//Andrada Stefania Mihailov//
//Info 1, Grupa 3//

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

const int NUMEbautura=30;
const int NUMARbauturi=10;

struct Bautura
{
    char Nume[NUMEbautura];
    double pret;
    int numar;
};
int Alegere(Bautura a[])
{
    int aleg;
    cout<<endl;
    for(int i=0; i<NUMARbauturi; i++)
    {
        cout<<(i+1)<<".  "<<a[i].Nume<<" : "<<a[i].pret<<" lei"<<endl;
    }
    cout<< (NUMARbauturi+1)<< ".  ADMINISTRATOR."<<endl;
    cout<<endl<<endl<<endl;
    cout<<"Alege una dintre variante: ";
    cin>>aleg;
    system("CLS");
    cout<<endl<<endl<<endl;
    while(aleg<1 || aleg>11)
    {
        cout<<"Alegerea ta este invalida. Alege din nou: "<<endl<<endl;
        for(int i=0; i<NUMARbauturi; i++)
    {
        cout<<(i+1)<<".  "<<a[i].Nume<<" : "<<a[i].pret<<" lei"<<endl;
    }
    cout<< (NUMARbauturi+1)<< ".  ADMINISTRATOR."<<endl;
    cout<<endl<<endl<<endl;
        cin>>aleg;
        system("CLS");
        cout<<endl<<endl<<endl;
    }
    return aleg-1;
}

void Tranzactie(Bautura a[], int aleg, double &castiguritotale)
{
    double bani;
    if(a[aleg].numar==0)
    {
        cout<<"Din pacate, aceasta bautura nu mai este disponibila."<<endl;
        cout<<endl<<endl<<endl;
        return;
    }
    cout<< "Introdu banii ";
    cin>>bani;
    cout<<endl<<endl<<endl;
    while(bani< a[aleg].pret)
    {
        cout<<"Te rog sa introduci cel putin "<< a[aleg].pret<<" lei pentru a-ti lua bautura dorita."<<endl;
        cout<<"Banii adaugati pana acum ti-au fost inapoiati"<<endl;
        cout<<"Introdu banii: ";
        cin>>bani;
        system("CLS");
        cout<<endl<<endl<<endl;
    }
    if (bani>=a[aleg].pret)
    {
        cout<<endl;
        cout<<"...Te rog asteapta! Bautura ta este in curs de preparare."<<endl<<endl;
        cout<<"Poti ridica paharul! Enjoy :D"<<endl<<endl;

        cout<<"Restul tau a fost calculat: "<<(bani-a[aleg].pret)<<" lei."<<endl<<endl;
        cout<<" Poti ridica restul."<<endl;

        castiguritotale+=a[aleg].pret;
        a[aleg].numar--;
        cout<<" Au mai ramas "<<a[aleg].numar<<" portii din aceasta bautura."<<endl;
    }
}
void ADMIN(Bautura a[],int aleg, double castiguritotale)
{  int y,c,p, z;
      cout<<"Ai intrat in meniul de administrator. Ce iti doresti sa faci in continuare?"<<endl;
            cout<<"1. Adauga resurse."<<endl;
            cout<<"2. Modifica pretul unei bauturi."<<endl;
            cout<<"3. Verifica suma incasata pana acum."<<endl;
            cout<<"*Apasa orice alta cifra pentru a reveni la meniul principal."<<endl;
            cout<<"Tasteaza-ti alegerea: "<<endl;
            cin>>y;
            if(y==1){
                system("CLS");
                cout<<"Care este bautura a carei cantitati o modifici?"<<endl;
                for(int i=0; i<NUMARbauturi; i++)
                    {
                        cout<<(i+1)<<".  "<<a[i].Nume<<endl;
                    }
                cin>>aleg;
                aleg=aleg-1;
                system("CLS");
                cout<<"Ai ales "<<a[aleg].Nume<<endl<<endl;
                cout<<"Introdu noua cantitate "<<endl;
                cin>>c;
                system("CLS");
                a[aleg].numar=c;
                cout<<"Cantitatea de "<<a[aleg].Nume<<" este acum "<<a[aleg].numar<<endl;
                cout<<"Apasa orice cifra urmata de tasta ENTER pentru a continua:"<<endl;
                cin>>z;
                system("CLS");
                ADMIN(a,aleg,castiguritotale);
            }
            else
              if(y==2){
                 system("CLS");
                cout<<"Care este bautura al carei pret il modifici?"<<endl;
                for(int i=0; i<NUMARbauturi; i++)
                    {
                        cout<<(i+1)<<".  "<<a[i].Nume<<endl;
                    }
                cin>>aleg;
                aleg=aleg-1;
                system("CLS");
                cout<<"Ai ales "<<a[aleg].Nume<<endl<<endl;
                cout<<"Introdu noul pret "<<endl;
                cin>>p;
                system("CLS");
                a[aleg].pret=p;
                cout<<"Pretul pentru produsul "<<a[aleg].Nume<<" este acum "<<a[aleg].pret<<" lei."<<endl;
                cout<<"Apasa orice cifra urmata de tasta ENTER pentru a continua:"<<endl;
                cin>>z;
                system("CLS");
                 ADMIN(a,aleg,castiguritotale);

            }
            else
            if(y==3){
                system("CLS");
                cout<<"Automatul a incasat pana acum "<< castiguritotale<<" lei."<<endl;
                cout<<"Apasa orice cifra urmata de tasta ENTER pentru a continua:"<<endl;
                cin>>z;
                system("CLS");
                ADMIN(a,aleg,castiguritotale);
            }



}

int main()
{   long int x;
    int y,c,p;
    int aleg;
    double castiguritotale=0;
    Bautura aparat[NUMARbauturi]={{"Latte         ", 3.00, 5},
                             {"Cappuccino    ", 2.00, 5},
                             {"Ceai de fructe", 2.00, 5},
                             {"Ceai verde    ", 2.00, 5},
                             {"Ceai de lamaie", 2.00, 5},
                             {"Nesquik       ", 3.00, 5},
                             {"Ciocolata calda alba", 3.00, 5},
                             {"Irish Mocha   ", 3.00, 5},
                             {"Cappuccino cu ciocolata", 3.00, 5},
                             {"Cappuccino vienez", 3.00, 5}
};
    aleg=Alegere(aparat);
    while(aleg!=10)
    {
        Tranzactie(aparat,aleg,castiguritotale);
        aleg=Alegere(aparat);
    }
    cout<<"Introdu parola( codul ADMIN format din 8 cifre): "<<endl;
    cin>>x;
    cout<<endl;
    system("CLS");
    cout<<endl;
    if (x==14091999)
        { system("CLS");
            ADMIN(aparat,aleg,castiguritotale);
        }
    else
        cout<<"Parola este gresita. Nu se pot afisa date."<<endl;
    aleg=Alegere(aparat);
    while(aleg!=10)
    {
        Tranzactie(aparat,aleg,castiguritotale);
        aleg=Alegere(aparat);
    }
    return 0;

}
