#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

bool negativan(double broj)
{
    if(broj<0)
        return true;
    return false;
}

bool tekuci(unsigned long long int broj)
{
    if(broj/100000000 == 32)
        return true;
    return false;
}

bool ispisi_podatke(string prezimeIme[],
                    unsigned long long int brRacuna[],
                    double saldo[],
                    int brKLijenata,
                    string pretraga)
{
    int br = 0;
    for(int i = 0; i < brKLijenata; i++)
    {
        if(prezimeIme[i] == pretraga)
        {
            cout << brRacuna[i] << ", " << saldo[i]<< "HRK" << endl;
            br++;
        }
    }
    if(br==0)
        return false;
    return true;
}

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
        cout<<"Broj 4 za brisanje racuna"<<endl;
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
        else if(odabir == 2)
        {
            for(int i = 0; i < brKlijenata; i++)
            {
                cout << brRacuna[i] << ", " << prezimeIme[i] << ", " << saldo[i] << endl;
            }
            cout << "Suma svih salda je " << accumulate(saldo, saldo+brKlijenata, 0.0) << " HRK" << endl;
            int max_indeks = max_element(saldo, saldo+brKlijenata) - saldo;
            cout << "Klijent koji ima najveci saldo je: " << prezimeIme[max_indeks] << endl;
            cout << "Broj racuna s negativnim saldom: " << count_if(saldo, saldo+brKlijenata, negativan) << endl;
            cout << "Broj tekucih racuna je: " << count_if(brRacuna, brRacuna+brKlijenata, tekuci) << endl;
            system("pause"); // koristeno kako bi se zadrzao ispis podataka jer nakon pritiska broja 2 program ne ispisuje stanje podataka do pritiska neke tipke vec automaski vraca na glavni izbornik
        }
        else if(odabir == 3)
        {
            cout << "Unesite ime i prezime koje pretrazujete: " << endl;
            string pretraga;
            cin.ignore();
            getline(cin, pretraga);
            if(ispisi_podatke(prezimeIme,brRacuna,saldo,brKlijenata,pretraga)==false)
            {
                cout << "Nema takvih klijenata." << endl;

            }
             system("pause");
        }
    }
    return 0;
}
