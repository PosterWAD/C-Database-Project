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
