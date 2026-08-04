#include <stdio.h>
#include <glib.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

//char files[MAX_LINES][MAX_LINE_LENGTH];


int load_file_list(char files[MAX_LINES][MAX_LINE_LENGTH]) {
  int line_count = 0;
  
  // Open the file that has the location of all the logs
  FILE* file_ptr = fopen(".logfind", "r");

  //If that file doesn't exist then fail
  g_return_val_if_fail(file_ptr != NULL, FALSE);

  //Get a list of all the files that we should look for values in and stick it in an array
  while (line_count < MAX_LINES && fgets(files[line_count], MAX_LINE_LENGTH, file_ptr)) {

    g_strchomp(files[line_count]);
    line_count++;
  }

  //cloes the file
  fclose(file_ptr);
  return line_count;
}

//debugging function to look at the list of files in the array and make sure we got em all. 
void print_file_list(char files[MAX_LINES][MAX_LINE_LENGTH], int line_count) {
  for (int i = 0; i < line_count; i++) {
    printf("%s", files[i]);
  }
}

//Load up the file and scan it for the search term - right now we're just looking at one word but in the future we'll add the ability to look for an arbitrary N set of words. 
int load_file_and_search(const char *file, char *search_term) {
  printf("[%s]", file);

  FILE* file_ptr = fopen(file, "r");

  
  //If that file doesn't exist then fail
  g_return_val_if_fail(file_ptr != NULL, FALSE);

  char line[MAX_LINE_LENGTH];
  while(fgets(line, sizeof(line), file_ptr) != NULL) {
    if(strstr(line, search_term) != NULL) {
      printf("Found a match in %s at %s", file, line);
    }
  }
  
  printf("%s", file);
  fclose(file_ptr);

  return 0;
}

int main(void) {
  int line_count;
  char files[MAX_LINES][MAX_LINE_LENGTH];
  line_count = load_file_list(files);
  print_file_list(files, line_count);

  load_file_and_search(files[0], "asdf");
}
