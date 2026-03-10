#include "customer.h"

int main(void) {
    Customer customers[MAX_CUSTOMERS];
    int count = 0;
    int choice;
    const char *inputFile = "data/input.txt";
    const char *outputFile = "data/pinsk_output.txt";
    
    printf("   Лабораторная работа №2, Задание 4\n");
    
    printf("   Тема: Покупатели из города Пинск\n");
   
    
    while (1) {
        printf("\n-------- МЕНЮ --------\n");
        printf("1. Прочитать данные из файла data/input.txt\n");
        printf("2. Вывести покупателей из Пинска\n");
        printf("3. Сохранить результаты в файл data/pinsk_output.txt\n");
        printf("4. Вывести всех покупателей\n");
        printf("0. Выход\n");
        printf("----------------------\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);
        clearInputBuffer();
        
        switch (choice) {
            case 1:
                count = readCustomersFromFile(inputFile, customers, MAX_CUSTOMERS);
                break;
                
            case 2:
                if (count > 0) {
                    printCustomersFromPinsk(customers, count);
                } else {
                    printf("Сначала прочитайте данные из файла (пункт 1).\n");
                }
                break;
                
            case 3:
                if (count > 0) {
                    savePinskCustomersToFile(customers, count, outputFile);
                } else {
                    printf("Сначала прочитайте данные из файла (пункт 1).\n");
                }
                break;
                
            case 4:
                if (count > 0) {
                    printf("\n--- Все покупатели ---\n");
                    for (int i = 0; i < count; i++) {
                        printf("\n--- Покупатель %d ---\n", i + 1);
                        printCustomer(&customers[i]);
                    }
                } else {
                    printf("Сначала прочитайте данные из файла (пункт 1).\n");
                }
                break;
                
            case 0:
                printf("Программа завершена.\n");
                return 0;
                
            default:
                printf("Неверный выбор. Попробуйте снова.\n");
        }
    }
    
    return 0;
}
