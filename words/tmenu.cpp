#include "tmenu.h"
#include "tekran.h"
#include "getch.h"

using namespace std;



extern Tekran ekran(' ');

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//***************************************************************************************************************************
//definicje konstruktorów
Tmenu::Tmenu(int xx, int yy, string nnn) :  pokazuje(nnn), x(xx), y(yy) //konstruktor obiektu z danym wartościami
{
    narysuj();
}
//***************************************************************************************************************************
Tmenu::Tmenu(int xx, int yy, string nnn, string n) :  pokazuje(nnn), x(xx), y(yy) //konstruktor obiektu z danym wartościami
{
    ekran.napisz(x, y, pokazuje);
}
//***************************************************************************************************************************
Tmenu::Tmenu(std::string wybor) //konstruktor obiektu z wywolanie funkcji menu zaleznie od wartosci wybor
{
    if(wybor == "m")
    {
        mmenu();
    }

}
//***************************************************************************************************************************
Tmenu::Tmenu(){}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


                                       //Funkcje pomocnicze
//***************************************************************************************************************************
//Funkcja rysująca ramki
void Tmenu::narysuj()
{
    ekran.napisz(x, y,   " ____________________________ ");  //30 znakow w lini
    ekran.napisz(x, y+1, "|                            |");
    ekran.napisz(x, y+2, "|____________________________|");
    //-------------------------------
    ekran.napisz(x+7,y+1, pokazuje);
    //ekran.wyswietl();
}
//***************************************************************************************************************************
//Funkcja rysująca ramki z gwiazdkami
void Tmenu::narysuj_gw()
{
    ekran.napisz(x, y,   " **************************** ");  //30 znakow w lini
    ekran.napisz(x, y+1, "*                            *");
    ekran.napisz(x, y+2, " ****************************  ");
    //-------------------------------
    ekran.napisz(x+7,y+1, pokazuje);
    //ekran.wyswietl();
}
//***************************************************************************************************************************
//Funkcja rysująca strzałki
void Tmenu::narys_st()
{
    string pok = "--->" + pokazuje + "<---";

    ekran.napisz(x-4, y, pok);
}
//*******************************************************************************************************************************
//Funkcja pobierjąca numer wciśnietego klawisza
int Tmenu::key()
{
    //dopisać instrukcję działająca na bezpośrednie wciśnięcie ESC
    int znak; //zmienna z numerem wciśnietęgo klawisza
    int arrow;
    //------------------------------------
    while(true)
    {
        znak = getch();
        //------------------------------------
        if(znak == 224) return arrow = getch();
        else return znak;
    }
}
//*******************************************************************************************************************************
//Funkcja zwracająca wartość pozycji
int Tmenu::poz(int &pozycja, int dlugosc, int klawisz, int x)
{
    if(x == 0) return pozycja = 0;
    switch(klawisz)
    {
    case 72: pozycja--; break; //strzałka w górę
    case 77: pozycja--; break; //strzałka w prawo
    case 80: pozycja++; break; //strzałka w dół
    case 75: pozycja++; break; //strzałka w lewo
    }
    //------------------------------------
    if(pozycja < 0)
    {
        return pozycja = dlugosc;
    }
    else if (pozycja > dlugosc)
    {
        return pozycja = 0;
    }
    //------------------------------------
    return 0;
}
//*******************************************************************************************************************************
//Funkcja tworząca dynamicznie obiekty z okienkami
void Tmenu::tab_obiektow(int dlugosc, int x, int y, std::vector<std::string> nazwa)
{
    Tmenu * wsk_menu = new Tmenu[dlugosc];  //Utworzenie dynamicznie tablicy na obiekty
    //------------------------------------
    for(int i=0; i<dlugosc; i++) //petla tworzaca obiekty
    {
        wsk_menu[i] = Tmenu(x, y, nazwa[i]);  //argumenty i obiekt
        y += 3;
    }
    //------------------------------------
    for(int i=0; i<dlugosc; i++)  //dodanie stworzonych obiektów do ogolnego vectora Tmenu_obiekty
    {
        Tmenu_obiekty.push_back(wsk_menu[i]);
    }
    delete []wsk_menu;
}
//*******************************************************************************************************************************
//Funkcja tworząca tablice z nazwami plików
void Tmenu::tab_plikow(int dlugosc, int x, int y, std::vector<std::string> nazwa)
{
    Tmenu * wsk_plik = new Tmenu[dlugosc];
    string n;
    for(int i=0; i<dlugosc; i++)
    {
        wsk_plik[i] = Tmenu(x, y, nazwa[i], n);
        y ++;
    }

    for(int i=0; i<dlugosc; i++)
    {
        pliki.push_back(wsk_plik[i]);
    }
    delete []wsk_plik;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






                            //Funkcje tworzące Menu wyboru pliku ze słowkami i jego wyswietlaniem

//***************************************************************************************************************************
//Funkcja wyświatlająca menu główne
int Tmenu::mmenu()
{
    int klawisz;
    int pozycja = 0;
    int x = 0;
    //------------------------------------
    while(true)
    {
        ekran.wyczysc();
        //------------------------------------
        Tmenu * wsk_tekst = new Tmenu[4]  //Tworzy dynamicznie tablicę obiektów
        {
          {Tmenu(42, 1, "Sprawdz sie")},
          {Tmenu(42, 4, "Wyswietl slowka")},
          {Tmenu(42, 7, "Zapisz slowka")},
          {Tmenu(42, 10, "Zakoncz ")}
        };
        //------------------------------------
        if(x == 0) ekran.wyswietl();
        //------------------------------------
        klawisz = key(); //pobiera klaiwsz
        poz(pozycja, 3, klawisz, x);  //funkcja zwracająca pozycja
        //------------------------------------
        system("cls");
        //------------------------------------
        wsk_tekst[pozycja].narysuj_gw();   //rysuje ramke z gwiazdkami wokol wartosci wybranej klawiszem
        //------------------------------------
        ekran.wyswietl();
        //------------------------------------
        if(klawisz == 13)  //sprwawdz czy enter jesli tak to akcja
        {
            if (pozycja == 0)
                wsk_tekst[pozycja].sprmenu(0);
            else if(pozycja == 1)
                wsk_tekst[pozycja].sprmenu(1);
            else if(pozycja == 2)
                wsk_tekst[pozycja].zapisz_s();
            else if(pozycja == 3)
                exit(0);
        }
        //------------------------------------
        delete [] wsk_tekst;  //usuwa wskaznik obiektow
        x++;
    }
}

//*******************************************************************************************************************************
//Funkcja tworząca menu sprawdz sie
void Tmenu::sprmenu(int wywolanie)
{
    int pozycja = 0;
    int x = 0;
    int klawisz;
    //------------------------------------
    Tzapis_odczyt fol_pli; //obiekt klasy oodczyt_zapis
    //------------------------------------
    vector<string> lista_folderow = {fol_pli.foldery}; //przypisanie do prywatnego vectoru funkcji
    //------------------------------------
    int dl_folder = lista_folderow.size();
    //------------------------------------
    while(true)
    {
        ekran.wyczysc();
        //------------------------------------
        tab_obiektow(dl_folder, 42, 1, lista_folderow);
        Tmenu_obiekty.push_back(Tmenu(42, 25, "Powrot"));
        //------------------------------------
        if(x == 0) ekran.wyswietl();
        //------------------------------------
        klawisz = key(); //pobiera klawisz
        poz(pozycja, dl_folder, klawisz, x);  //zwraca pozycja
        //------------------------------------
        system("cls");
        //------------------------------------
        Tmenu_obiekty[pozycja].narysuj_gw();
        //------------------------------------
        ekran.wyswietl();
        //------------------------------------
        if(klawisz == 13) //sprawdza wartosc klawisza
        {

            if(pozycja == dl_folder) mmenu();
            else if(wywolanie == 1 || wywolanie == 0)
            {
                fol_pli.odczyt_plik(lista_folderow[pozycja]);
                plimenu(fol_pli.pliki, lista_folderow[pozycja], wywolanie);
            }
            else if(wywolanie == 2)
            {
                string nazwa;
                system("cls");
                int q = 0;
                while(q != 1)
                {
                    cout<<"Podaj nazwe pliku:  ";
                    getline(cin, nazwa);
                    if(nazwa == "") {q = 0; system("cls");}
                    else {q = 1;}
                }


                string sciezka = "Moduly\\" + lista_folderow[pozycja] + "\\" + nazwa;

                Tobsluga_slowek dopis(sciezka, 2);
            }
            Tmenu_obiekty.clear();
        }
        x++;
    }
}
//*******************************************************************************************************************************
//Funkcja tworząca menu wyboru plików
void Tmenu::plimenu(vector<string> nazwa, std::string nazwa_folderu, int wywolanie)
{
    int pozycja = 0;
    int klawisz;
    int x = 0;
    int rozmiar = nazwa.size();
    //------------------------------------
    vector<string> loc_nazwa = { nazwa};
    //------------------------------------
    while(true)
    {
        ekran.wyczysc();
        //------------------------------------
        tab_plikow(rozmiar, 42, 1, nazwa); //funkcja tworząca obiekty
        pliki.push_back(Tmenu(42, 25, "Powrot", "n"));
        //------------------------------------
        if(x == 0) ekran.wyswietl(); //warunek sprawdzajacy jesli x = 0 to wtedy wyswietla
        //------------------------------------
        klawisz = key();  //pobranie klawisz
        //------------------------------------
        poz(pozycja, rozmiar, klawisz, x); //zwrot pozycji
        //------------------------------------
        //system("clear");
        //------------------------------------
        pliki[pozycja].narys_st();  //narysowanie ramki z gwiazdkami
        //------------------------------------
        ekran.wyswietl();
        //------------------------------------
        if(klawisz == 13)
        {
            if(pozycja == rozmiar) sprmenu(wywolanie);
            else if(wywolanie == 0)
            {
                pol_ang(pliki[pozycja].pokazuje, nazwa_folderu);
                Tmenu_obiekty.clear();
            }
            else if(wywolanie == 1)
            {
                wys_wszystko(pliki[pozycja].pokazuje, nazwa_folderu);
                Tmenu_obiekty.clear();
            }
        }
        //------------------------------------
        x++; //inkrementacja x
    }
}
//*******************************************************************************************************************************
//Funkcja tworząca menu wyboru wczytywania słówek polski czy angielski
void Tmenu::pol_ang(std::string nazwa_pliku, std::string nazwa_folderu)
{
    int pozycja = 0;
    int x = 0;
    int klawisz;
    string sciezka = "Moduly\\" + nazwa_folderu + "\\" + nazwa_pliku;
    while(true)
    {
        ekran.wyczysc();
        Tmenu tek(42, 1, "Opcja wpisywania");

        Tmenu * tab_jez = new Tmenu [3]
        {
            {Tmenu(42,8, "Polski")},
            {Tmenu(42,13, "Angielski")},
            {Tmenu(42, 25, "Powrot")}
        };

        if(x == 0) ekran.wyswietl();

        klawisz = key();

        poz(pozycja, 2, klawisz, x);

        system("cls");

        tab_jez[pozycja].narysuj_gw();

        ekran.wyswietl();

        if(klawisz == 13)
        {
            if(pozycja == 0)
            {
                Tobsluga_slowek wyswietla(sciezka, pozycja);
            }
            else if(pozycja == 1)
            {
                Tobsluga_slowek wyswietla(sciezka, pozycja);
            }
            else if(pozycja == 2)
            {
                sprmenu(0);
            }
        }
        delete []tab_jez;
        x++;
    }
}
//*******************************************************************************************************************************
//Funkcja wyświetlająca wszystkie słówka z wybranego pliku
void Tmenu::wys_wszystko(std::string nazwa_pliku, std::string nazwa_folderu)
{
    string sciezka = "Moduly\\" + nazwa_folderu + "\\" + nazwa_pliku;
    //--------------------
    Tobsluga_slowek wys(sciezka);
}
//*******************************************************************************************************************************
//Funkcja zapisująca słówka
void Tmenu::zapisz_s()
{
    int pozycja = 0;
    int x = 0;
    int klawisz;

    while(true)
    {
        ekran.wyczysc();

        Tmenu * tab_slow = new Tmenu[3]
        {
            {Tmenu(42, 1, "Wybierz Folder")},
            {Tmenu(42, 4, "Utworz nowy")},
            {Tmenu(42, 25, "Powrot")}
        };

        if(x == 0) ekran.wyswietl();

        klawisz = key();

        poz(pozycja, 2, klawisz, x);

        system("cls");

        tab_slow[pozycja].narysuj_gw();

        ekran.wyswietl();

        if(klawisz == 13)
        {
            if(pozycja == 0)
            {
                sprmenu(2);
            }
            else if(pozycja == 1)
            {
                system("cls");
                string nazwa = "Moduly\\";
                string odp;
                int q = 0;
                while (q != 1)
                {
                    cout<<"\n\n\tJesli sie pomyliles napisz end."<<endl;
                    cout<<"\n\n\t\tPodaj nazwe dodawanego folderu: ";
                    getline(cin, odp);
                    if(odp == ""){ q = 0; system("cls");}
                    else {q = 1;}
                }
                q = 0;

                if(odp == "end") Tmenu ob("m");

                nazwa += odp;

                if(access(nazwa.c_str(), F_OK) != 0) //sprawdzenie czy istnieje folder
                    {
                        mkdir(nazwa.c_str() ); //jesli nie stworzenie tego folderu
                    }
                system("cls");
                while (q != 1)
                {
                    system("cls");
                    cout<<"\n\n\tJesli sie pomyliles napisz end."<<endl;
                    cout<<"\n\n\t\tPodaj nazwe pliku: ";
                    getline(cin, odp);
                    if(odp == ""){ q = 0; system("cls");}
                    else {q = 1;}
                }
                if(odp == "end") Tmenu ob("m");

                nazwa += "\\" + odp;

                Tobsluga_slowek dopi(nazwa, 2);
            }
            else if(pozycja == 2)
            {
                mmenu();
            }
        }
        delete []tab_slow;
        x++;
    }
}










