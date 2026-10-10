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
void wypisz_studentow(Student *baza, int ilosc);
void usun_studenta(Student **baza, int *ilosc);
void zapisz_do_pliku(Student *baza, int ilosc, const char *nazwa_pliku);
void sortuj_studentow(Student *baza, int ilosc);
void znajdz_studenta(Student *baza, int ilosc);
void przydziel_studenta_do_grupy(Student *baza, int ilosc);
void usun_studenta_z_grupy(Student *baza, int ilosc);

//void znajdz_studenta
Student *znajdz_studenta_po_indexie(Student *baza, int ilosc, int nr_indeksu);
Student *znajdz_studenta_po_nazwisku(Student *baza, int ilosc, const char *nazwisko);

void edytuj_studenta(Student *baza, int ilosc);

void wyjdz_i_zapisz(Student *baza, int ilosc);


#endif // DATABASE_DEFINITIONS_H