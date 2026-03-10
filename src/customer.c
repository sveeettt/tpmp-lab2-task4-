#include "customer.h"

void clearInputBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int readCustomersFromFile(const char *filename, Customer customers[], int maxCount) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Ошибка открытия файла %s\n", filename);
        return 0;
    }
    
    char buffer[1024];
    int count = 0;
    
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        printf("Файл пуст или имеет неверный формат\n");
        fclose(file);
        return 0;
    }
    
    while (fgets(buffer, sizeof(buffer), file) != NULL && count < maxCount) {
        Customer *c = &customers[count];
        
        
        int parsed = sscanf(buffer, "%[^;];%[^;];%[^;];%c;%[^;];%d;%f;%d;%d;%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]",
               c->lastName,
               c->firstName,
               c->patronymic,
               &c->gender,
               c->nationality,
               &c->height,
               &c->weight,
               &c->birthDate.year,
               &c->birthDate.month,
               &c->birthDate.day,
               c->phoneNumber,
               c->address.postalCode,
               c->address.country,
               c->address.region,
               c->address.district,
               c->address.city,
               c->address.street,
               c->address.house,
               c->address.apartment,
               c->creditCard,
               c->bankAccount);
        
        if (parsed == 21) {
            count++;
        } else {
            printf("Ошибка парсинга строки %d\n", count + 1);
        }
    }
    
    fclose(file);
    printf("Прочитано %d записей из файла %s\n", count, filename);
    return count;
}

void printCustomersFromPinsk(const Customer customers[], int count) {
    int pinskCount = 0;
    
    printf("\n========================================\n");
    printf("Покупатели из города Пинск:\n");
    printf("========================================\n");
    
    for (int i = 0; i < count; i++) {
        if (strcmp(customers[i].address.city, "Пинск") == 0) {
            pinskCount++;
            printf("\n--- Покупатель %d ---\n", pinskCount);
            printCustomer(&customers[i]);
        }
    }
    
    if (pinskCount == 0) {
        printf("Покупатели из Пинска не найдены.\n");
    } else {
        printf("\n========================================\n");
        printf("Всего найдено: %d покупателей из Пинска\n", pinskCount);
    }
}


int savePinskCustomersToFile(const Customer customers[], int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Ошибка создания файла %s\n", filename);
        return 0;
    }
    
    
    fprintf(file, "Фамилия;Имя;Отчество;Пол;Национальность;Рост;Вес;Дата рождения;Телефон;Город;Улица;Дом;Квартира;Кредитка;Счет\n");
    
    int pinskCount = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(customers[i].address.city, "Пинск") == 0) {
            pinskCount++;
            fprintf(file, "%s;%s;%s;%c;%s;%d;%.1f;%d-%02d-%02d;%s;%s;%s;%s;%s;%s;%s\n",
                    customers[i].lastName,
                    customers[i].firstName,
                    customers[i].patronymic,
                    customers[i].gender,
                    customers[i].nationality,
                    customers[i].height,
                    customers[i].weight,
                    customers[i].birthDate.year,
                    customers[i].birthDate.month,
                    customers[i].birthDate.day,
                    customers[i].phoneNumber,
                    customers[i].address.city,
                    customers[i].address.street,
                    customers[i].address.house,
                    customers[i].address.apartment,
                    customers[i].creditCard,
                    customers[i].bankAccount);
        }
    }
    
    fclose(file);
    printf("\nРезультаты сохранены в файл %s (найдено %d записей)\n", filename, pinskCount);
    return pinskCount;
}


void printCustomer(const Customer *c) {
    printf("ФИО: %s %s %s\n", c->lastName, c->firstName, c->patronymic);
    printf("Пол: %s\n", c->gender == 'M' ? "Мужской" : "Женский");
    printf("Национальность: %s\n", c->nationality);
    printf("Рост: %d см, Вес: %.1f кг\n", c->height, c->weight);
    printf("Дата рождения: %d-%02d-%02d\n", c->birthDate.year, c->birthDate.month, c->birthDate.day);
    printf("Телефон: %s\n", c->phoneNumber);
    printf("Адрес: %s, %s, %s, %s %s, ул.%s д.%s кв.%s\n",
           c->address.postalCode,
           c->address.country,
           c->address.region,
           c->address.district,
           c->address.city,
           c->address.street,
           c->address.house,
           c->address.apartment);
    printf("Кредитная карта: %s\n", c->creditCard);
    printf("Банковский счет: %s\n", c->bankAccount);
}
