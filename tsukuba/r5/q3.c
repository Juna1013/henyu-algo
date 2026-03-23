#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct frequency_list_type {
  char symbol;
  int frequency;
  struct frequency_list_type *next;
};

struct frequency_list_type *frequency_list;

char *sym_sort;
int num_symbols;
char comp_code[1000];

void encode(char str[]) {
  int str_len = strlen(str);
  frequency_list = NULL;
  struct frequency_list_type *curr, *prev;
  num_symbols = 0;

  int i, j;
  for (i = 0; i < str_len; i++) {
    if (frequency_list == NULL) {
      frequency_list =
          (struct frequency_list_type *)malloc(sizeof(struct frequency_list_type));
      num_symbols++;
      frequency_list->symbol = str[i];
      frequency_list->frequency = 1;
      frequency_list->next = NULL;
    }
    else {
      curr = frequency_list;
      while (1) {
        if (curr->symbol == str[i]) {
          curr->frequency++;
          break;
        }
        if (curr->next != NULL) curr = curr->next;
        else {
          curr->next =
              (struct frequency_list_type *)malloc(sizeof(struct frequency_list_type));
          num_symbols++;
          curr = curr->next;
          curr->symbol = str[i];
          curr->frequency = 1;
          curr->next = NULL;
          break;
        }
      }
    }
  }

  sym_sort = (char *)malloc(sizeof(char) * num_symbols);
  char max_sym;
  int max_freq;
  struct frequency_list_type *max_curr, *max_prev;

  i = 0;
  while (frequency_list != NULL) {
    curr = frequency_list;
    prev = frequency_list;
    max_freq = curr->frequency;
    max_sym = curr->symbol;
    max_curr = curr;
    max_prev = prev;
    while (curr->next != NULL) {
      prev = curr;
      curr = curr->next;
      if (curr->frequency > max_freq) {    /* ・・・・・・(Y) */
        max_freq = curr->frequency;
        max_sym = curr->symbol;
        max_curr = curr;
        max_prev = prev;
      }
    }
    sym_sort[i] = max_curr->symbol;
    i++;
    if (max_curr == frequency_list) frequency_list = max_curr->next;
    else max_prev->next = max_curr->next;
    free(max_curr);
  }
  /* ・・・・・(X) */
  int comp_code_count = 0;
  for (i = 0; i < str_len; i++) {
    for (j = 0; j < num_symbols; j++) {
      if (str[i] == sym_sort[j]) {
        putchar('1');
        comp_code[comp_code_count] = '1';
        comp_code_count++;
        break;
      }
      else {
        putchar('0');
        comp_code[comp_code_count] = '0';
        comp_code_count++;
      }
    }
  }
  comp_code[comp_code_count] = '\0';
}

void decode(char str[]) {
  int str_len = strlen(str);
  int i, j;
  j = 0;
  for (i = 0; i < str_len; i++) {
    if (str[i] == '0') j++;
    else {
      putchar(sym_sort[j]);
      j = 0;
    }
  }
}

int main() {
  char str[] = "ABACAABBCDEABBCCADEDCDCC";
  encode(str);
  decode(comp_code);
  printf("%s\n", str);
  return 1;
}