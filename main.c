#include "database_definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

  Student *baza = NULL;
  int rozmiar = 0;
  int wybor = 0;

  do {
    printf("\n==== SYSTEM BAZY STUDENTÓW ====\n");
    printf("Aktualna liczba studentów: %i\n", rozmiar);
    printf("Co chcesz zrobić?\n");
    printf("1. Dodaj studenta\n");
    printf("2. Wypisz wszystkich studentów\n");
    printf("3. Usuń studenta\n");
    printf("4. Zapisz zmiany do pliku\n");
    printf("5. Posortuj studentów.\n");
    printf("6. Znajdź studenta.\n");
    printf("7. Przydziel studenta do grupy.\n");
    printf("8. Usuń studenta z grupy.\n");
    printf("9. Edytuj studenta.\n");
    printf("---------------------------------------------\n");
    printf("0. Wyjdź i zapisz.\n");
    printf("----------------------------------------------\n");
    printf("Twój wybór: ");

    scanf("%d", &wybor);

    while (getchar() != '\n')
      ;

    switch (wybor) {
    case 1:
      dodaj_studenta(&baza, &rozmiar);
      break;
    case 2:
      int wWypisanie;
        printf("Wybierz sposób wypisania studentów: \n");
        printf("1. Cała baza studentów \n");
        printf("2. Studenci z poszczegolnego kierunku\n");
      do{
        printf("Wybór(1 lub 2): ");
        scanf(" %i", &wWypisanie);
      if(wWypisanie == 1){
        printf("\n--- LISTA STUDENTÓW ---\n");
        wypisz_cala_baze(baza, rozmiar);
      }
      else if(wWypisanie == 2){
        int wybor_kierunku;
        printf("Podaj kierunek (0-Informatyka, 1-Matematyka, 2-Fizyka, 3-Elektronika, 4-Elektrotechnika): ");
        scanf("%i", &wybor_kierunku);
        while(getchar() != '\n');
        wypisz_kierunek(baza, rozmiar, (Kierunek)wybor_kierunku); //pstatni argument za pomocą rzutowania na enum
      }
      else{
        printf("Błąd wyboru - spróbuj jeszcze raz!!!\n");
      }
      }while(wWypisanie != 1 && wWypisanie != 2);        
      break;
    case 3:
      int wyborUsuwania;
      if (rozmiar > 0) {
        printf("Czy chcesz usunąć ostatniego studenta (1) czy wybranego (2)? ");
        scanf("%i", &wyborUsuwania);
        if (wyborUsuwania == 1) {
          usun_ostatniegoStudenta(&baza, &rozmiar);
        } 
        else if (wyborUsuwania == 2) {
          usun_wybranegoStudenta(&baza, &rozmiar);
        } 
        else {
          printf("Nieprawidłowy wybór usuwania.\n");
        }
        } 
        else {
          printf("\nBaza jest pusta! Nie ma kogo usunąć.\n");
        } 
      break;
    case 4:
      zapisz_baze("baza.dat", baza, rozmiar);
      break;
    case 5:
      int wyborSortowania;
      printf("Wybierz czy chcesz sortować po indeksie (1) czy nazwisku (2): ");
      scanf("%i", &wyborSortowania);
      if (wyborSortowania == 1) {
        sortuj_bazeIndex(baza, rozmiar);
        printf("Studenci zostali posortowani po indeksie.\n");
      } 
      else if (wyborSortowania == 2) {
        sortuj_bazeNazwisko(baza, rozmiar);
        printf("Studenci zostali posortowani po nazwisku.\n");
      } 
      else {
        printf("Nieprawidłowy wybór sortowania.\n");
      }
      break;
    case 6:
      int wyborZnajdowania;
      int indexStudenta;
        printf("Wybierz czy chcesz znaleźć studenta po indeksie (1) czy nazwisku (2): ");
        scanf("%i", &wyborZnajdowania);
      if (wyborZnajdowania == 1) {
        printf("Podaj numer indeksu do znalezienia: ");
        scanf("%i", &indexStudenta);
      Student *znajdzStudenta = szukaj_studentaIndex(baza, rozmiar, indexStudenta);
      if (znajdzStudenta != NULL) {
        printf("Znaleziono studenta:\n");
        wypisz_studenta(znajdzStudenta);
      } 
      else {
       printf("Nie znaleziono studenta o podanym numerze indeksu.\n");
      }
      } 
      else if (wyborZnajdowania == 2) {
      char nazwiskoStudenta[MAX_STR];
        printf("Podaj nazwisko do znalezienia: ");
        scanf("%s", nazwiskoStudenta);
      Student *znajdzStudenta = szukaj_studentaNazwisko(baza, rozmiar, nazwiskoStudenta);
      if (znajdzStudenta != NULL) {
        printf("Znaleziono studenta:\n");
        wypisz_studenta(znajdzStudenta);
      } else {
        printf("Nie znaleziono studenta o podanym nazwisku.\n");
      }
      } else {
        printf("Nieprawidłowy wybór wyszukiwania.\n");
      }
      break;
    case 7:
      int wyborPrzydzialu;
      printf("Wybierz czy chcesz przydzielić studenta do grupy po indeksie (1) czy nazwisku (2): ");
      scanf("%i", &wyborPrzydzialu);
      switch(wyborPrzydzialu) {
        case 1:
          
          break;
        case 2:
          break;
        default:
          printf("Nieprawidłowy wybór przydziału.\n");
          break;
      }
      break;
    case 8:
    
      break;
    case 9:
      printf("Edytor danych studentów \n");
      edytuj_studenta(baza, rozmiar);
      break;
    case 0:
      printf("\nBaza została zamknięta.\n");
      zapisz_baze("baza.dat", baza, rozmiar);
      zwolnij_pamiec(&baza, &rozmiar);

      break;
    default:
      printf("Nieprawidłowy wybór, spróbuj ponownie.\n");
      break;
  } while (wybor != 0);
  }
}