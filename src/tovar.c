/*
 * Author: Kudinova Elizaveta, group 12
 * Description: Implementation of TOVAR structure functions
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../include/tovar.h"

/*
 * Приватная функция (не объявлена в .h)
 * Получает текущую дату для сравнений
 */
static void get_current_date(Date *current) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    current->year = tm.tm_year + 1900;
    current->month = tm.tm_mon + 1;
    current->day = tm.tm_mday;
}

/*
 * Function: add_tovar
 * -------------------
 * Добавляет новый товар в массив
 * 
 *   spisok: массив товаров
 *   count: указатель на текущее количество товаров
 */
void add_tovar(Tovar *spisok, int *count) {
    if (*count >= 10) {
        printf("Error: maximum number of goods reached (10)\n");
        return;
    }
    
    printf("\n--- Adding new goods ---\n");
    
    printf("Enter goods name: ");
    scanf("%s", spisok[*count].name);
    
    printf("Enter quantity: ");
    scanf("%d", &spisok[*count].quantity);
    
    printf("Enter price: ");
    scanf("%f", &spisok[*count].price);
    
    printf("Enter receipt date (year month day): ");
    scanf("%d %d %d", 
          &spisok[*count].receipt_date.year,
          &spisok[*count].receipt_date.month,
          &spisok[*count].receipt_date.day);
    
    (*count)++;
    printf("Goods added successfully. Total goods: %d\n", *count);
}

/*
 * Function: calculate_average_price
 * ---------------------------------
 * Вычисляет среднюю стоимость всех товаров
 * 
 *   spisok: массив товаров
 *   count: количество товаров
 *   
 *   returns: средняя стоимость
 */
float calculate_average_price(const Tovar *spisok, int count) {
    if (count == 0) {
        return 0.0f;
    }
    
    float sum = 0.0f;
    for (int i = 0; i < count; i++) {
        sum += spisok[i].price;
    }
    
    return sum / count;
}

/*
 * Function: sort_by_price
 * -----------------------
 * Сортирует товары по возрастанию цены (пузырьковая сортировка)
 * 
 *   spisok: массив товаров
 *   count: количество товаров
 */
void sort_by_price(Tovar *spisok, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (spisok[j].price > spisok[j + 1].price) {
                // Swap
                Tovar temp = spisok[j];
                spisok[j] = spisok[j + 1];
                spisok[j + 1] = temp;
            }
        }
    }
    printf("Goods sorted by price (ascending).\n");
}

