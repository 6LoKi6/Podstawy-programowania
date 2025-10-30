#include <iostream>

using namespace std;

size_t dlugosc(const char *src)
{
    // Funkcja przyjmuję za argument tablicę znaków i zwraca jej długość

    size_t size = 0;                                            // Tworzymy zmienną lokalną do przechowania długości tablicy

    while (src[size] != '\0')
        size ++;                                                // Iterujemy zmienną size do momentu gdy nie napotkamy się na '\0' czyli koniec stringa
    
    return size;                                                // Zwracamy zmienną size
}

char *kopiuj(const char *src)
{
    /*
        Funkcja przyjmuje za argument stringa bazowego i robi jego kopie

        Dlaczego funkcja zwraca wskaźnik?

        Gdybyśmy zwrócili wartość zamiast wskaźnika to zmienna w mainie mogłaby przyjąć
        jedynie pierwszy znak naszego stringa a nie zakres

    */
    char *copy = new char[dlugosc(src) + 1];                        // Alokujemy pamięć dla kopii dodając 1 dla null'a

    for(size_t i = 0; i < dlugosc(src); i++)
        copy[i] = src[i];                                           // Kopiujemy wartości 

    copy[dlugosc(src)] = '\0';                                      // Dodajemy null'a na końcu
    return copy;                                                    // Zwracamy kopię jako wskaźnik
}

char *dolacz(const char *src, const char *ins, const size_t n)
{
        // Funkcja ma wkleić pierwsze n znaków z ins'a a resztę z src

    char *temp = new char[dlugosc(src) + n + 1];                    // Alokujemy pamięć dla tablicy z dołączeniami + 1 dla null'a

    size_t j = 0;                                                   // Tworzymy dodatkowy counter
    for(size_t i = 0; i < dlugosc(src) + n; i++)
    {
        if(i < dlugosc(src))                                        // Jeżeli i jest w obrębie source, kopiujemy
            temp[i] = src[i];

        else
            temp[i] = ins[j++];                                     // Gdy skończy się source doklejamy na koniec znaki z ins'a, drugi counter był potrzebny żeby po skończeniu iteracji przez source, insa liczyć od 0
    }

        temp[dlugosc(src) + n] = '\0';                              // Dodajemy null'a
        return temp;                                                // Zwracamy tablice temp
}

char *wstaw(const char *src, char s)
{
    // Funkcja wstawia podany znak co trzeci index

    char *temp = new char[dlugosc(src) + dlugosc(src) / 3 + 1];      // Alokujemy pamięć dla stringa który potrzebyuje więcej pamięci przez znak co trzeci index + 1 dla null'a

    size_t j = 0;                                                   // Tworzymy pomocniczy counter
    for(size_t i = 0; i < dlugosc(src); i++)
    {
        if(i % 3 == 0)
            temp[j++] = s;
                                                                    // Sprawdzamy czy i jest podzielne przez 3, ale cały czas iterujemy dla temp żeby nie dostać Xla Xa kXta
        temp[j++] = src[i];
    }

    temp[dlugosc(src) + dlugosc(src) / 3] = '\0';                   // dodajemy null'a
    return temp;                                                    // zwracamy jakko wskaźnik
}

int porownaj(const char* str1, const char* str2)
{
    // Funkcja sprawdza czy podane stringi są takie same

    size_t count = 0;                                               // Tworzymy licznik

    while ((str1[count] != '\0') || (str1[count] != '\0'))          // Nie mamy pewności czy oba stringi są tej samej długości, więc będziemy iterować po obu dopóki nie napotkamy null'a
    {                                                               
        if(int(str1[count]) > int(str2[count]))                     // Jeżeli ASCI danego znaku w str1 jest większe od znaku w str2 zwracamy 1
            return 1;

        if(int(str1[count]) < int(str2[count]))                     // Jeżeli jest mniejsze zwracamy -1
            return -1;
    }
    
    return 0;                                                       // Jeżeli oba stringi są takie same to żaden z warunków nie zostanie spełniony więc returna piszemy bez if'a
}

int szukaj(const char *src, const char toFind)
{
    int sum = 0;                                                    // Tworzymy zmienną przechowującą liczbę wystąpień danego znaku

    for(size_t i = 0; i < dlugosc(src); i++)
    {
        if(src[i] == toFind)                                        // Jeżeli znak w tablicy o danym indexie jest równy znakowi którego szukamy podnosimy sumę
            sum ++;
    }

    return sum;                                                     // Zwracamy sumę
}

char *naMale(const char *src)
{
    char *temp = new char[dlugosc(src) + 1];                        // Alokujemy pamięć dla nowej tablicy

    for(size_t i = 0; i < dlugosc(src); i ++)
        temp[i] = tolower(src[i]);                                  // Kpiujemy tablicę src używając funkcji tolower

    temp[dlugosc(src)] = '\0';                                      // Dodajemy null'a
    return temp;                                                    // Zwracamy tablice
}

char *naDuze(const char *src)
{
    char *temp = new char[dlugosc(src) + 1];                        // Alokujemy pamięć dla nowej tablicy

    for(size_t i = 0; i < dlugosc(src); i ++)                       // Kpiujemy tablicę src używając funkcji upper
        temp[i] = toupper(src[i]);

    temp[dlugosc(src)] = '\0';                                      // Dodajemy null'a
    return temp;                                                    // Zwracamy tablice
}

void usun(char *tab)
{
    if(tab)
    {
        delete[] tab;
        tab = nullptr;
    }
}

int main()
{
    char origin[] = "Ala ma kota";
    char ins[] = "Ola ma psa";
    int toReplace = 5;
    char replaceChar = 'X';
    char toSearch = 'm';
   
    cout << "Oryginal: " << origin << endl;

    char *copy = kopiuj(origin);
    cout << "Kopia: " << copy << endl;

    char *added = dolacz(origin, ins, toReplace);
    cout << "Dolaczone: " << added << endl;

    char *inserted = wstaw(origin, replaceChar);
    cout << "Wstawione:" << inserted << endl;

    cout << "Wynik porownania: " << porownaj(origin, ins) << endl;

    cout << "Liczba wystapien " << toSearch << ": " << szukaj(origin, toSearch) << endl;

    char *upper = naDuze(origin);
    cout << "Zmienione na duze: " << upper << endl;

    char *lower = naMale(origin);
    cout << "Zmienione na male: " << lower << endl;

    usun(copy);
    usun(added);
    usun(inserted);
    usun(upper);
    usun(lower);
    
    cout << endl;
    return 0;
}