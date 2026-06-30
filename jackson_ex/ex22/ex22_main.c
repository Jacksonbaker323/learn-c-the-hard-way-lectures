#include "ex22.h"
#include "debug.h"

const char *MY_NAME = "Jackson A. Baker";

void scope_demo(int count) {
  log_msg(LOG_INFO, "Count is: %d", count);

  if (count > 10) {
    int count = 100;

    log_msg(LOG_INFO, "Count in this scope is: %d", count);
  }
  log_msg(LOG_INFO, "Count is at exit: %d", count);

  count = 3000;

  log_msg(LOG_INFO, "Count after assign: %d", count);
}

int main(int argc, char *argv[]) {
  //37
  log_msg(LOG_INFO, "My name: %s, age: %d", MY_NAME, get_age());
  
  set_age(100);

  //100
  log_msg(LOG_INFO, "My age is now: %d", get_age());

  //1000
  log_msg(LOG_INFO, "THE_SIZE is: %d", THE_SIZE);
  //1000
  print_size();

  THE_SIZE = 9;

  //9
  log_msg(LOG_INFO, "THE SIZE is now: %d", THE_SIZE);

  //9
  print_size();

  //1
  log_msg(LOG_INFO, "Ratio at first: %f", update_ratio(2.0));

  //2
  log_msg(LOG_INFO, "Ratio again: %f", update_ratio(10.0));

  //10
  log_msg(LOG_INFO, "Ratio once more: %f", update_ratio(300.0));

  int count = 4;
  //4
  scope_demo(count);
  //3000
  scope_demo(count * 20);

  //4
  log_msg(LOG_INFO, "Count after calling scope_demo: %d", count);

  return 0;
}
