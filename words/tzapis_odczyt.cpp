#include "tzapis_odczyt.h"
#include "trim.h"

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                            //Konstruktory
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Tzapis_odczyt::Tzapis_odczyt()
{
    odczyt_fol();
}
Tzapis_odczyt::Tzapis_odczyt(std::string sciezka)
{
    odczyt_slow(sciezka);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                            //Funkcje
//*******************************************************************************************************************************
//Funkcja odczytująca z folderu listę folderów
void Tzapis_odczyt::odczyt_fol()
{
    int i = 0;

        DIR *dir;
          struct dirent *ent;
          if ((dir = opendir ("Moduly")) != nullptr) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != nullptr) {
                if (ent->d_name[0] != '.' && ent->d_name[strlen(ent->d_name)-1] != '~'){
                 foldery.push_back(ent->d_name); //przypisanie nazwy do vectora
                }
                i++;
            }
            closedir (dir);
          } else {
            /* could not open directory */
              cout<<"ERROR otwarcie folderu"<<endl;
              exit(0);
          }
}
//*******************************************************************************************************************************
//Funkcja odczytująca z folderu pliki
void Tzapis_odczyt::odczyt_plik(string nazwa)
{
    int i = 0;
    string sciezka = "Moduly\\" + nazwa;

        DIR *dir;
          struct dirent *ent;
          if ((dir = opendir (sciezka.c_str())) != nullptr) {
            /* print all the files and directories within directory */
            while ((ent = readdir (dir)) != nullptr) {
                if (ent->d_name[0] != '.' && ent->d_name[strlen(ent->d_name)-1] != '~'){
                 pliki.push_back(ent->d_name); //przypisanie nazwy do vectora
                }
                i++;
            }
            closedir (dir);
          } else {
            /* could not open directory */
              cout<<"ERROR otwarcie folderu z plikami"<<endl;
              exit(0);

          }

}
//*******************************************************************************************************************************
//Funkcja odczytująca z pliku słówka
void Tzapis_odczyt::odczyt_slow(std::string sciezka)
{
    fstream slowka; //uchwyt do pliku
    string linia;   //zmienna na line
    //-------------------------------
    slowka.open(sciezka, ios::in );  //otwarcie pliku
    if(slowka.good() == false) cout<<"Error otwarcie pliku ze slowkami"<<endl;  //sprawdzenie prawidlowe otwracie pliku
    //-------------------------------
    while(!slowka.eof())  //petla dodaja do vectora linie i odczytujaca po calej linii
    {
        getline(slowka, linia);
        //-------------------------------
        if(linia != "")
        {
            vec_slowka.push_back(linia); //dodanie do vectora linii
        }

    }
    slowka.close(); //zamknięcie pliku
    //-------------------------------
    random_shuffle(vec_slowka.begin(), vec_slowka.end()); //przemieszanie słówek
}
//*******************************************************************************************************************************


























