#include <stdio.h>
#include "debug.h"

#define MAX_DATA 100

typedef enum EyeColor {
  BLUE, GREEN, BROWN, BLACK, OTHER
} EyeColor;

const char *EYE_COLOR_NAMES[] = {"Blue", "Green", "Brown", "Black", "Other" };

typedef struct Person {
  int age;
  char first_name[MAX_DATA];
  char last_name[MAX_DATA];
  EyeColor eyes;
  float income;
} Person;

int main(int argc, char *argv[]) {
  Person you = {.age = 0};
  int i = 0;
  char *in = NULL;

  printf("What's your first name? ");
  in = fgets(you.first_name, MAX_DATA - 1, stdin);
  check(in != NULL && in[0] !='\n', "Failed to read first name.");

  printf("What's your last name? ");
  in = fgets(you.last_name, MAX_DATA -1, stdin);
  check(in !=NULL && in[0] !='\n', "Failed to read last name.");

  printf("How old are you? ");
  int rc = fscanf(stdin, "%d", &you.age);
  check(rc > 0, "You have to enter a number.");


  printf("What color are your eyes:\n");
  for (i = 0; i <= OTHER; i++) {
    printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
  }
  printf("> ");
  return 0;
 error:
  return -1;
}
