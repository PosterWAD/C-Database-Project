#include "database_definitions.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *pobierz_nazwe_kierunku(Kierunek k) {
  switch (k) {
    case INFORMATYKA:
      return "Informatyka";
    case MATEMATYKA:
      return "Matematyka";
    case FIZYKA:
      return "Fizyka";
    case ELEKTRONIKA:
      return "Elektronika";
    case ELEKTROTECHNIKA:
      return "Elektrotechnika";
    case INNY:
      return "Inny";
    default:
      return "Nieznany";
  }
}

void dodaj_studenta(Student **baza, int *ilosc) {
    int nowy_rozmiar = *ilosc + 1;
    int podany_indeks;          
    bool wynik_wyszukiwania; 

    Student *nowa_baza = realloc(*baza, nowy_rozmiar * sizeof(Student)); 
    if(nowa_baza == NULL){
        printf("Błąd pamięci - brak wystarczajacego miejsca.");
    }else{
        *baza = nowa_baza;
    }
    (*ilosc)++; 
    printf("Podaj imię studenta: ");
    scanf("%49s", (*baza)[*ilosc - 1].imie); 
    scanf("%49s", (*baza)[*ilosc - 1].nazwisko
    );

    //dodanie funkcjonalności uniemożliwiającej dodanie indeksu który jest już w bazie
    //za pomoca funkcji znajdz_studenta_po_indexie
    do{
        printf("Podaj numer indeksu studenta: ");
        scanf("%i", &podany_indeks);
        
        wynik_wyszukiwania = znajdz_studenta_po_indexie(*baza, *ilosc-1, podany_indeks);

        if(wynik_wyszukiwania){
            printf("Podany indeks jest juz przypisany dla innego studenta w bazie danych!!!\n");
        }

    }while(wynik_wyszukiwania);
    (*baza)[*ilosc - 1].nr_indeksu = podany_indeks;
    /*
        printf("Podaj numer indeksu studenta: ");
        scanf("%i", &(*baza)[*ilosc - 1].nr_indeksu);
    */

    int wybor_kierunku;
    printf("Wybierz kierunek studenta (0 - Informatyka, 1 - Matematyka, 2 - Fizyka, 3 - Elektronika, 4 - Elektrotechnika): ");
    scanf("%i", &wybor_kierunku);
    (*baza)[*ilosc - 1].kierunek = (Kierunek)wybor_kierunku; 
    printf("Podaj średnią ocen studenta: ");
    scanf("%f", &(*baza)[*ilosc - 1].srednia);

    printf("Student został dodany pomyślnie!\n");

}

void wypisz_studenta(const Student* s)
{
    // (*s).imie = s->imie
    printf("\nImie: %s \n", s->imie);
    printf("Nazwisko: %s \n", s->nazwisko);
    printf("Nr indeksu: %d \n", s->nr_indeksu);
    printf("Kierunek: %s \n", pobierz_nazwe_kierunku(s->kierunek));
    printf("Srednia ocen: %.3f\n", s->srednia);
}

void wypisz_cala_baze(const Student *baza, int rozmiar) {
    if (baza == NULL || rozmiar == 0) {
        printf("Baza jest obecnie pusta. Dodaj studentów, aby ich zobaczyć!\n");
        return;
    }

    for (int i = 0; i < rozmiar; i++) {
        printf("\nStudent %d z %d:", i + 1, rozmiar);
        wypisz_studenta(&baza[i]);
    }
}

void wypisz_kierunek(const Student *baza, int rozmiar, Kierunek zKierunku) {
    if (baza == NULL || rozmiar == 0) {
        printf("Baza jest obecnie pusta. Dodaj studentów, aby ich zobaczyć!\n");
        return;
    }
    bool znaleziono = false;
    
    printf("Studenci z kierunku: %s  \n", pobierz_nazwe_kierunku(zKierunku));

    for (int i = 0; i < rozmiar; i++) {
        if(baza[i].kierunek == zKierunku){
            wypisz_studenta(&baza[i]);
            znaleziono = true;
        }
    }
    if(!znaleziono){
        printf("Brak studentów na danym kierunku");
    }
}

void usun_ostatniegoStudenta(Student **baza, int *ilosc) {
    if (*ilosc > 0) {
        (*ilosc)--; 
        printf("Student %s %s został usunięty.\n", (*baza)[*ilosc].imie, (*baza)[*ilosc].nazwisko);
    } else {
        printf("Baza jest pusta! Nie ma kogo usunąć.\n");
    }
}


void usun_wybranegoStudenta(Student **baza, int *ilosc) {
    if (*ilosc == 0) {
        printf("Baza jest pusta! Nie ma kogo usunąć.\n");
        return;
    }

    int nr_indeksu;
    printf("Podaj numer indeksu studenta do usunięcia: ");
    scanf("%i", &nr_indeksu);

    int index_do_usuniecia = -1;
    for (int i = 0; i < *ilosc; i++) {
        if ((*baza)[i].nr_indeksu == nr_indeksu) {
            index_do_usuniecia = i;
            break;
        }
    }

    if (index_do_usuniecia != -1) {
        printf("Student %s %s został usunięty.\n", (*baza)[index_do_usuniecia].imie, (*baza)[index_do_usuniecia].nazwisko);
        for (int j = index_do_usuniecia; j < *ilosc - 1; j++) {
            (*baza)[j] = (*baza)[j + 1];
        }
        (*ilosc)--;
        *baza = realloc(*baza, (*ilosc) * sizeof(Student));
    } else {
        printf("Nie znaleziono studenta z numerem indeksu %d.\n", nr_indeksu);
    }
}

void zapisz_baze(const char *filename, Student *baza, int ilosc) {
    FILE *plik = fopen(filename, "wb"); // "wb" = write binary
    
    if (plik == NULL) {
        printf("Błąd: Nie udało się otworzyć pliku do zapisu!\n");
        return;
    }

    if (ilosc > 0) {
        fwrite(baza, sizeof(Student), ilosc, plik);
    }
    
    fclose(plik);
    printf("Baza danych została pomyślnie zapisana do pliku %s.\n", filename);
}

void wczytaj_baze(const char *filename, Student **baza, int *ilosc) {
    FILE *plik = fopen(filename, "rb"); // "rb" = read binary
    
    if (plik == NULL) {
        printf("Brak pliku bazy danych. Tworzę nową, pustą bazę.\n");
        *baza = NULL;
        *ilosc = 0;
        return;
    }

    fseek(plik, 0, SEEK_END);
    long rozmiar_pliku = ftell(plik);
    rewind(plik);

    *ilosc = rozmiar_pliku / sizeof(Student);

    if (*ilosc > 0) {
        *baza = malloc(*ilosc * sizeof(Student));
        fread(*baza, sizeof(Student), *ilosc, plik);
        printf("Pomyślnie wczytano %d studentów z bazy.\n", *ilosc);
    } else {
        *baza = NULL;
    }

    fclose(plik);
}

void zwolnij_pamiec(Student **baza, int *ilosc){
    free(*baza);
    *baza = NULL; 
    *ilosc = 0;
}

void sortuj_bazeIndex(Student *baza, int rozmiar){
    for (int i = 0; i < rozmiar - 1; i++) {
        for (int j = 0; j < rozmiar - i - 1; j++) {
            if (baza[j].nr_indeksu > baza[j + 1].nr_indeksu) {
                Student temp = baza[j];
                baza[j] = baza[j + 1];
                baza[j + 1] = temp;
            }
        }
    }
