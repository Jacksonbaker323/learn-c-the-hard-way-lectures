#include <stdio.h>
#include "logger.h"
#include <string.h>
#include <stdlib.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256
#define INITIAL_CAPACITY 10

//For this function we get a pointer to a variable holding a list of files.
int load_file_list(char ***files_out) {
  //Create a pointer to the contents of the file that we want to read.
  FILE *file_ptr = fopen(".logfind", "r");

  //If that pointer fails for some reason then write out an error message and return -1
  if (!file_ptr) {
    log_error("Failed to open configuration file.\n");
    return -1;
  }

  //We're dynamically allocating the storage for the list of files
  //Set a size_t value that will hold the capacity of a my list of strings.
  size_t capacity = INITIAL_CAPACITY;
  int line_count = 0;

  //Allocate the memory for a series of pointers to file path strings.
  char **files = malloc(capacity * sizeof(char *));
  if (!files) {
    fclose(file_ptr);
    return -1;
  }

  char *line = NULL;
  size_t len = 0;

  while (getline(&line, &len, file_ptr) != -1) {
    line[strcspn(line, "\r\n")] = '\0';

    if (strlen(line) == 0) {
      continue;
    }
    
    if (line_count >= capacity) {
      capacity *=2;
      char **temp = realloc(files, capacity * sizeof(char *));
      if (!temp) {
        for (int i = 0; i < line_count; i++) {
          free(files[i]);
        }
        free(files);
        free(line);
        fclose(file_ptr);
        return -1;
      }
      files = temp;
    }
    files[line_count] = strdup(line);
    line_count++;
  }
  free(line);
  fclose(file_ptr);
  *files_out = files;
  return line_count;
}

int load_and_search(const char *file, char *search_terms[], int length) {
  //Debugging
printf("[DEBUG] Entering load_and_search for: '%s'\n", file);
    fflush(stdout);

  
  //Open the file that we want to search
  FILE *file_ptr = fopen(file, "r");

  //Check to make sure the file is open
  if (!file_ptr) {
    log_error("Failed to open log file.\n");
    return -1;
  }

  //Setting up some variables to store lines and track line count
  char *line = NULL;
  size_t len = 0;
  int line_num = 0;

  //New search function path - looking for ALL instances
  while (getline(&line, &len, file_ptr) != -1) {
    int all_matched = 1; //Set a flag to store the match indicator

    line_num++;
    for (int i = 0; i < length; i++) {
      if (strstr(line, search_terms[i]) == NULL) {
        all_matched = 0;
        break; //Drop out of the loop if 1 search term is missing to prevent unnecessary searches.
      }
      if (all_matched) {
        printf("Found a match in %s for all terms ", file);
        for (int j = 0; j < length; j++) {
          printf("%s ", search_terms[j]);
        }
        printf("on line %d. \n", line_num);
      }
    }
  }

  free(line);
  fclose(file_ptr);

  //DEBUGGING
  printf("[DEBUG] Finished load_and_search for: '%s'\n", file);
    fflush(stdout);
  return 0;
}

int main(int argc, char *argv[]) {
  //Bump the executable name out of the arguments so we can use this information a little more easily.
  argc--;
  argv++;

  //Instantiating an empty array of strings so we can store our file names.
  //We don't know how big this is going to be so we're not sizing it yet e.g. char *files[10]
  char **files = NULL;
  //Getting a count of the number of files - might have a better variable name here tbh.
  int line_count = load_file_list(&files);


  //Checking to make sure the file has a list of files in it
  if (line_count <= 0 || !files) {
    return 1;
  }

  //DEBUGGING
  printf("[DEBUG] Total files loaded from .logfind: %d\n", line_count);
for (int k = 0; k < line_count; k++) {
    printf("[DEBUG] File %d: '%s'\n", k, files[k]);
}
fflush(stdout);

  
  for (int i =0; i < line_count; i++) {
    load_and_search(files[i], argv, argc);
  }

  for (int i = 0; i < line_count; i++) {
    free(files[i]);
  }
  free(files);

  return 0;
}
