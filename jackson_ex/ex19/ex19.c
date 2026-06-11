#include "debug.h"
#include <stdlib.h>
#include <stdio.h>

void test_debug() {
  log_msg(LOG_DEBUG, "I have brown hair.");

  log_msg(LOG_DEBUG, "I am %d years old.", 38);

  log_msg(LOG_DEBUG, "How many things can I put in here? %d %d %d %d", 1, 2, 3, 4);
}

void test_log_err() {
  log_msg(LOG_ERROR, "I believe everything is broken.");
  log_msg(LOG_ERROR, "There are %d problems in %s", 0, "space");
}

void test_log_warn() {
  log_msg(LOG_WARN, "You can safely ignore this!");
  log_msg(LOG_WARN, "Maybe consider looking at: %s", "/etc/passwd");
}

void test_log_info() {
  log_msg(LOG_INFO, "Well, I did something mundane");
  log_msg(LOG_INFO, "It happened %f times today.", 1.3f);
}
/*
int test_check(char *file_name) {
  FILE *input = NULL;
  char *block = NULL;

  block = malloc(100);
  check_mem(block);

  input = fopen(file_name, "rb");
  check(input, "Failed to open %s", file_name);

  free(block);
  fclose(input);
  return 0;

 error:
  if (block) free(block);
  if (input) fclose(input);
  return -1;
}

int test_sentinel(int code) {
  char *temp = malloc(100);
  check_mem(temp);

  switch (code) {
  case 1:
    log_info("It worked!");
    break;
  default:
    sentinel(temp, "I shouldn't run.");
  }

  free(temp);
  return 0;

 error:
  if (temp) {
    free(temp);
  }
  return -1;
}

int test_check_mem() {
  char *test = NULL;
  check_mem(test);

  free(test);
  return 1;

 error:
  return -1;
}

int test_check_debug() {
  int i = 0;
  check_debug(i !=0, "Oops, I was a 0");

  return 0;
 error:
  return -1;
}
*/
int main(int argc, char *argv[]) {
  //check(argc == 2, "Need an argument");

  test_debug();
  test_log_err();
  test_log_warn();
  test_log_info();
  /*
  check(test_check("ex19.c") == 0, "Failed with ex19.c");
  check(test_check(argv[1]) == 1, "failed with argv");
  check(test_sentinel(1) == 0, "test_sentinel failed");
  check(test_sentinel(100) == -1, "test_sentinel failed");
  check(test_check_mem() == -1, "test_check_mem failed");
  check(test_check_debug() == -1, "test_check_debug failed");
  */
  return 0;

 error:
  return 1;
}
