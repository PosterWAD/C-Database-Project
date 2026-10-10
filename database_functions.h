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