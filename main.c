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
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    case 0:
      break;
    }

    return 0;
  }