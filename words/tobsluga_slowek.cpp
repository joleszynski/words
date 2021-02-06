#include "tobsluga_slowek.h"
#include "tzapis_odczyt.h"
#include "trim.h"
#include "tmenu.h"


using namespace std;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                        //Konstruktory
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Tobsluga_slowek::Tobsluga_slowek(string sciezka, int x)
{
    if(x == 0 || x == 1)
    {
        podzial(sciezka, x); //funkcja dzieląca linie na części
        wyswietlenie();  //funkcja wyświetlająca słówka i sprawdzająca
        ocena();   //słówka wyświetlająca punktacje i oceny
    }
    else if(x == 2)
    {
        dopisuje_slowka(sciezka);
    }
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Tobsluga_slowek::Tobsluga_slowek(string sciezka)
{
    wyswietla_wszystkie(sciezka);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                       //Funkcje
//***************************************************************************************************************************************
void Tobsluga_slowek::podzial(string sciezka, int x)
{
    Tzapis_odczyt odczyt(sciezka);  //obiekt z funkcja zapis odczyt odczytujący słówka z pliku
    //-------------------
    vector<string> slowka = {odczyt.vec_slowka};  //wector na słówka z innego obiektu
    //-------------------
    size_t pozycja;  //pozycja znaku pomiedzy slowkami
    string pol, ang; //slowko pol i ang
    //-------------------
    int rozmiar = slowka.size();  //rozmiar wektoru
    //-------------------
    for(int i=0; i<rozmiar; i++) //petla delegujaca slowka do wektorow
    {
        pozycja = slowka[i].find_first_of("|", 0); //znajduje pozycje znaku w linii
        //-------------------
        ang = slowka[i].substr(0, (pozycja));  //dodaje slowko angielskie
        pol = slowka[i].substr(pozycja+1);     // dodaje slowko polskie
        //-------------------
        if(x == 0) //jesli 0 to do wpisania jest slowko polskie
        {
            znaczenie.push_back(trim(ang));
            tlumaczenie.push_back(trim(pol));
        }
        else if(x == 1) //jesli 1 to do wpisania jest slowko angielskie
        {
            znaczenie.push_back(trim(pol));
            tlumaczenie.push_back(trim(ang));
        }
    }
}
//***************************************************************************************************************************************
//Funkcja wyswietlająca słówka
void Tobsluga_slowek::wyswietlenie()
{
    int roz_slow = znaczenie.size(); //rozmiar wektoru ze slowkami
    string odp; //string na odpowiedz
    //------------------------------
    for(int i=0; i<roz_slow; i++)
    {
        system("cls");
        cout<<"\n\n\n\n\t"<<(i+1)<<". "<<znaczenie[i]<<"  :  ";  //wypisuje slowko
            getline(cin, trim(odp));  //czeka na odpowiedź
        //------------------------------
        if(odp == tlumaczenie[i]) //sprawdzenie poprawnosci
        {
         cout<<"\n\t\t"<<"Dobrze !"<<endl;
         punkty += 1;
         getchar();
        }
        else
        {
            cout<<"\n\t\t"<<"Zle !\t";
            cout<<"Poprawne slowko to ->   "<<tlumaczenie[i]<<endl<<endl;
            getchar();
        }
    }
}
//***************************************************************************************************************************************
//Funkcja wyświetlająca i sprawdzjąca ilość punktów
void Tobsluga_slowek::ocena()
{
    int wekt = znaczenie.size();
    //------------------------------
    cout<<"\n\n\n\n\t"<<"Twoje punkty: "<<punkty<<" / "<<wekt<<endl;
    //------------------------------
    int procenty = 0;
    procenty = (punkty * 100) / wekt;
    //------------------------------
    cout<<"\t\t\t\t"<<"Ocena: ";
    //------------------------------
    if(procenty>=0 && procenty<41 ) {cout<<" 1 "<<endl;}
    else if(procenty>=42 && procenty<=50 ) {cout<<" 2 "<<endl;}
    else if(procenty>=51 && procenty<=75 ) {cout<<" 3 "<<endl;}
    else if(procenty>=76 && procenty<=90 ) {cout<<" 4 "<<endl;}
    else if(procenty>=91 && procenty<=99 ) {cout<<" 5 "<<endl;}
    else if(procenty== 100)                {cout<<" 6 "<<endl;}
    //------------------------------
    getchar();
    //------------------------------
    Tmenu obj("m");
}
//***************************************************************************************************************************************
//Funkcja wyświetla wszystkie słówka
void Tobsluga_slowek::wyswietla_wszystkie(string sciezka)
{
    podzial(sciezka, 0);

    int dl_wekt = znaczenie.size();
    system("cls");


    for(int i = 0; i<dl_wekt; i++)
    {
        system("cls");
        cout<<"\n\n\n\n\t"<<znaczenie[i]<<" ---> "<<tlumaczenie[i]<<endl;
        getchar();
    }
    Tmenu obj("m");
}
//***************************************************************************************************************************************
//Funkcja dopisująca słówka
void Tobsluga_slowek::dopisuje_slowka(string sciezka)
{
    fstream plik;
    int ile_slowek;
    string ile;
    vector<string> slowka;
    string ang, pol, line;

    plik.open(sciezka, ios::app);
    if(plik.good() == false) cout<<"ERROR otwarcie pliku do zapisu";

    cout<<"\n\n\t\tPodaj ile slowek chcesz wpisac: ";
    getline(cin, ile);
    ile_slowek = atoi(ile.c_str());

    cin.clear();
    system("cls");
    for(int i = 0; i<ile_slowek; i++)
    {
        cout<<(i+1)<<"/"<<ile_slowek<<endl;
        int q = 0;
        while (q != 1)
        {
            cout<<"\n\n\tWpisz slowko Angielskie:  ";
            getline(cin, ang);
            if(ang == ""){ q = 0; system("cls"); }
            else {q = 1;}
        }
        q = 0;
        while (q != 1)
        {
            cout<<"\n\n\tWpisz slowko Polskie:  ";
            getline(cin, pol);
            if(pol == ""){ q = 0; system("cls");}
            else {q = 1;}
        }

        line = ang + " | " + pol + '\n';

        plik<<line;
    }

    plik.close();

    cout<<"Zapisano poprawnie !";
    getchar();
    Tmenu menu("m");




}
//***************************************************************************************************************************************









