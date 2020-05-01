#include <iostream>

using namespace std;


int main()
{
    system("Color 0A");
    int brKlijenata = 0;
    unsigned long long int *brRacuna = new unsigned long long int[1000];
    string *prezimeIme = new string[1000];
    double *saldo = new double[1000];
    int odabir;
    while(1)
    {
        system("cls");
        cout<<"Dobrodosli u banku!"<<endl;
        cout<<"============================================="<< endl;
        cout<<"GLAVNI IZBORNIK"<< endl;
        cout<<"============================================="<< endl;
        cout<<"Odaberite..."<<endl;
        cout<<"Broj 1 za unos novog racuna"<<endl;
        cout<<"Broj 2 za ispis svih podataka"<<endl;
        cout<<"Broj 3 za pretragu po prezimenu i imenu"<<endl;
        cout<<"Broj 4 za brisanje računa"<<endl;
        cout<<"Broj 5 za izmjenu podataka prema broju računa"<<endl;
        cout<<"Broj 6 za ispis sortirano po prezimenu i imenu (trenutno onemoguceno)"<<endl;
        cout<<"Broj 7 za izlaz iz programa"<<endl;
        cout<<"============================================="<< endl;
        cin>>odabir;
        cout<<endl;
        if(odabir == 1)
        {
            unsigned long long unos;
            while(1)
            {
                try
                {
                    cout << "Unesite broj racuna (broj mora biti jedninstven-znamenke se ne smiju ponavljati): ";
                    cin >> unos;
                    if(unos < 1000000000 || unos > 9999999999)
                        throw "Broj racuna mora imati 10 znamenki";
                    break;
                }
                catch(const char* msg)
                {
                    cout << msg << endl;
                }
            }
            brRacuna[brKlijenata] = unos;
            cout << "Unesite prezime i ime klijenta banke: " << endl;
            cin.ignore();
            getline(cin, prezimeIme[brKlijenata]);
            cout << "Unesite saldo klijenta banke: ";
            cin >> saldo[brKlijenata];
            brKlijenata++;
        }
    }
}
