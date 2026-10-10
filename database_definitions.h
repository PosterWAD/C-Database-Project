#ifndef DATABASE_DEFINITIONS_H
#define DATABASE_DEFINITIONS_H

#define MAX_STR 50

typedef enum {
  INFORMATYKA,
  MATEMATYKA,
  FIZYKA,
  ELEKTRONIKA,
  ELEKTROTECHNIKA,
  INNY
} Kierunek;

typedef struct {
  char imie[MAX_STR];
  char nazwisko[MAX_STR];
  int nr_indeksu;
  Kierunek kierunek;
  float srednia;
} Student;

// --- FUNKCJE --- //
void dodaj_studenta(Student **baza, int *ilosc); 
void zapisz_baze(const char *filename, Student *baza, int ilosc);
void wczytaj_baze(const char *filename, Student **baza, int *ilosc);
void zwolnij_pamiec(Student **baza, int *ilosc);
void wypisz_studenta(const Student* s);
void wypisz_cala_baze(const Student *baza, int rozmiar);
void sortuj_bazeIndex(Student *baza, int rozmiar);
void sortuj_bazeNazwisko(Student *baza, int rozmiar);
void wypisz_kierunek(const Student *baza, int rozmiar, Kierunek zKierunku);
void usun_ostatniegoStudenta(Student **baza, int *ilosc);
void usun_wybranegoStudenta(Student **baza, int *ilosc);

void edytuj_studenta(Student *baza, int rozmiar);

Student* znajdz_studenta_po_indexie(Student *baza, int rozmiar, int nr_indeksu);
Student* znajdz_studenta_po_nazwisku(Student *baza, int rozmiar, const char* nazwisko);
#endif // DATABASE_DEFINITIONS_H