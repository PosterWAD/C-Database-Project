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

#endif // DATABASE_DEFINITIONS_H