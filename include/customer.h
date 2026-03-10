#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CUSTOMERS 100
#define MAX_STRING 50
#define MAX_ADDRESS 200


typedef struct {
    char postalCode[10];      // почтовый индекс
    char country[MAX_STRING];  // страна
    char region[MAX_STRING];   // область
    char district[MAX_STRING]; // район
    char city[MAX_STRING];     // город
    char street[MAX_STRING];   // улица
    char house[10];            // дом
    char apartment[10];        // квартира
} Address;


typedef struct {
    int year;
    int month;
    int day;
} BirthDate;


typedef struct {
    char lastName[MAX_STRING];      // фамилия
    char firstName[MAX_STRING];     // имя
    char patronymic[MAX_STRING];    // отчество
    char gender;                     // пол (M/F)
    char nationality[MAX_STRING];    // национальность
    int height;                      // рост (в см)
    float weight;                     // вес (в кг)
    BirthDate birthDate;              // дата рождения
    char phoneNumber[15];             // номер телефона
    Address address;                   // домашний адрес
    char creditCard[20];               // номер кредитной карточки
    char bankAccount[30];              // банковский счет
} Customer;


int readCustomersFromFile(const char *filename, Customer customers[], int maxCount);

void printCustomersFromPinsk(const Customer customers[], int count);

int savePinskCustomersToFile(const Customer customers[], int count, const char *filename);

void printCustomer(const Customer *c);
void clearInputBuffer(void);

#endif

