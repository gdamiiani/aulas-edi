#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char name[100];
  char nickname[50];
  char date[11];
} Contact;

typedef struct {
  Contact *contacts;
  int index;
  int size;
} List;

void initialize(List *list, int size);

void insert(List *list, Contact contact, int index);

Contact delete(List *list, int index);

void print_contacts_list(List list);

int main() {
  List list;
  Contact c1;
  Contact c2;

  strncpy(c1.name, "William", 8);
  strncpy(c1.nickname, "wil", 4);
  strncpy(c1.date, "12/12/2012", 11);

  strncpy(c2.name, "Michael", 8);
  strncpy(c2.nickname, "mick", 5);
  strncpy(c2.date, "11/12/2012", 11);

  initialize(&list, 2);
  
  insert(&list, c1, 0);
  insert(&list, c2, 1);

  print_contacts_list(list);

  delete(&list, 0);

  print_contacts_list(list);
}

void initialize(List *list, int size) {
  list->contacts = malloc(sizeof(Contact) * size);
  list->index = -1;
  list->size = size;
}

void insert(List *list, Contact contact, int index) {
  if (index < 0 || list->index + 1 == list->size) {
    return;
  }

  ++list->index;

  if (index >= list->index) {
    list->contacts[list->index] = contact;
    return;
  }

  for (int i = list->index; i >= index; --i) {
    list->contacts[i + 1] = list->contacts[i];
  }

  list->contacts[index] = contact;
}

Contact delete(List *list, int index) {
  Contact out = list->contacts[index];

  if (list->index == -1) {
    return out;
  }

  --list->index;

  for (int i = index; i <= list->index; ++i) {
    list->contacts[i] = list->contacts[i + 1];
  }

  return out;
}

void print_contacts_list(List list) {
  for (int i = 0; i <= list.index; ++i) {
    printf("Name: %s\tNickname: %s\tDate:%s\n", list.contacts[i].name, list.contacts[i].nickname, list.contacts[i].date);
  }
}
