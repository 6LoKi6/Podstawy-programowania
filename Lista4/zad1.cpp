#include <iostream>

using namespace std;

size_t dlugosc(const char *src)
{
        // Funkcja przyjmuję za argument tablicę znaków i zwraca jej długość

    size_t size = 0;                            // Tworzymy zmienną lokalną do przechowania długości tablicy

    while (src[size] != '\0')
        size ++;                                // Iterujemy zmienną size do momentu gdy nie napotkamy się na '\0' czyli koniec stringa
    
    return size;                                // Zwracamy zmienną size
}

char *kopiuj(const char *src)
{
    /*
        Funkcja przyjmuje za argument stringa bazowego i robi jego kopie

        Dlaczego funkcja zwraca wskaźnik?

        Gdybyśmy zwrócili wartość zamiast wskaźnika to zmienna w mainie mogłaby przyjąć
        jedynie pierwszy znak naszego stringa a nie zakres

    */
    char *copy = new char[dlugosc(src) + 1];    // Alokujemy pamięć dla kopii dodając 1 dla null'a

    for(size_t i = 0; i < dlugosc(src); i++)
        copy[i] = src[i];                       // Kopiujemy wartości 

    copy[dlugosc(src)] = '\0';                  // Dodajemy null'a na końcu
    return copy;                                // Zwracamy kopię jako wskaźnik
}

char *dolacz(const char *src, const char *ins, const size_t n)
{
        // Funkcja ma wkleić podany znak na pierwsze n znaków

    char *temp = new char[dlugosc(src) + 1];    // Alokujemy pamięć dla tablicy z dołączeniami + 1 dla null'a

    for(size_t i = 0; i < dlugosc(src); i++)
    {
        if(i <= n)
            temp[i] = *ins;     // Wyłuskanie
                                                // Iterujemu przez całą tablicę i sprawdzamy czy i jes mniejsze lub równe n,
                                                // jeżeli tak, wklejamy znak, jeżeli nie, kopiujemy
        else
            temp[i] = src[i];
    }

        temp[dlugosc(src)] = '\0';              // Dodajemy null'a
        return temp;                            // Zwracamy temp jako wskaźnik
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

void usun(char *tab)
{
    if(tab)
    {
        delete[] tab;
        tab = nullptr;
    }
}

int main(int argc, char *argv[])
{
    char ins = 'X';

    char origin[] = "Ala ma kota";
    cout << "Oryginal: " << origin << endl;

    char *copy = kopiuj(origin);
    cout << "Kopia: " << copy << endl;

    char *added = dolacz(origin, &ins, 5);
    cout << "Dolaczone: " << added << endl;

    char *inserted = wstaw(origin, ins);
    cout << "Wstawione:" <<inserted << endl;

    usun(copy);
    usun(added);
    usun(inserted);
    
    cout << endl;
    return 0;
}