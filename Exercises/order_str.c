/**
 * Program Name: Order List Of String By First Name
 * Author: taiprogramer
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show_data(char** data, int number_of_data);
void get_data(char** data, int number_of_data);
void str_wrap(char** data, unsigned int f_pos, unsigned int s_pos);
void str_order(char** data, int number_of_data);
void free_memory(char** data, int number_of_data);
char* get_first_name(char* data);

int main(void) {

  int number_of_name;
  char** names;

  scanf("%d", &number_of_name);
  // clear '\n' character left by scanf()
  getchar();

  // memory allocation for n names;
  names = (char**)malloc(number_of_name * sizeof(char*));

  if (!names) {
    printf("Error: Can not do memory allocation.\n");
    exit(1);
  }

  get_data(names, number_of_name);
  str_order(names, number_of_name);
  printf("\n--------------------------\n");
  show_data(names, number_of_name);
  free_memory(names, number_of_name);

  return 0;
}

void show_data(char** data, int number_of_data) {
  for (int i = 0; i < number_of_data; i++) {
    printf("%d. %s\n", i + 1, data[i]);
  }
};

void get_data(char** data, int number_of_data) {
  // assume that, each name is less than 200 characters
  char str_buffer[200];
  // get user input
  for (int i = 0; i < number_of_data; i++) {
    fgets(str_buffer, 200, stdin);
    // trim '\n' character
    str_buffer[strlen(str_buffer) - 1] = '\0';
    // memory allocation for each array of character,
    // include the terminating null character
    data[i] = (char*)malloc((strlen(str_buffer) + 1) * sizeof(char));
    // null check
    if (!data[i]) {
      printf("Error: Can not do memory allocation.\n");
      exit(1);
    }
    // perform string copy
    strcpy(data[i], str_buffer);
  }
};

void free_memory(char** data, int number_of_data) {
  for (int i = 0; i < number_of_data; i++) {
    free(data[i]);
  }
  free(data);
};

void str_wrap(char** data, unsigned int f_pos, unsigned int s_pos) {
  /* ======== Arguments ========= */
  // f_pos: first position
  // s_pos: second position
  /*==============================*/
  char str_buffer[200];
  // copy first array of character to str_buffer
  strcpy(str_buffer, data[f_pos]);
  // re-allocation at f_pos
  data[f_pos] =
      (char*)realloc(data[f_pos], (strlen(data[s_pos]) + 1) * sizeof(char));
  if (!data[f_pos]) {
    printf("Error: Can not do memory allocation.\n");
    exit(1);
  }
  // copy second array of character to first array of character
  strcpy(data[f_pos], data[s_pos]);
  // re-allocation at s_pos
  data[s_pos] =
      (char*)realloc(data[s_pos], (strlen(str_buffer) + 1) * sizeof(char));
  if (!data[s_pos]) {
    printf("Error: Can not do memory allocation.\n");
    exit(1);
  }
  // copy str_buffer to second array of character
  strcpy(data[s_pos], str_buffer);
};

char* get_first_name(char* data) {
  char* output = NULL;
  char str_buffer[200];
  int index = 0;
  for (int i = strlen(data) - 1; i >= 0; i--) {
    if (data[i] == ' ') {
      for (int j = i + 1; j < strlen(data); j++) {
        str_buffer[index] = data[j];
        index++;
      }
      str_buffer[index] = '\0';
      break;
    }
  }
  output = (char*)malloc((strlen(str_buffer) + 1) * sizeof(char));
  if (!output) {
    printf("Error: Can not do memory allocation.\n");
    exit(1);
  }
  strcpy(output, str_buffer);
  return output;
};

void str_order(char** data, int number_of_data) {
  // Based on Selection Sort
  // i just know only one way for sorting an array :D
  // you can use some sorting algorithms
  // Quick Sort, Bubble Sort, ...
  for (int i = 0; i < number_of_data - 1; i++)
    for (int j = i + 1; j < number_of_data; j++) {
      char* first_name1 = get_first_name(data[i]);
      char* first_name2 = get_first_name(data[j]);
      if (strcmp(first_name1, first_name2) > 0)
        str_wrap(data, i, j);
      free(first_name1);
      free(first_name2);
    }
};
