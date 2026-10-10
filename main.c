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
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
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