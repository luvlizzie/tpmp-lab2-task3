/*
 * Author: Kudinova Elizaveta, group 12
 */

#ifndef TOVAR_H
#define TOVAR_H

/*
 * Structure for date
 */
typedef struct {
    int year;
    int month;
    int day;
} Date;

/*
 * Structure for goods (TOVAR)
 */
typedef struct {
    char name[100];
    int quantity;
    float price;
    Date receipt_date;
} Tovar;

/*
 * Function prototypes
 * Все функции получают данные через параметры (никаких глобальных переменных)
 */
void add_tovar(Tovar *spisok, int *count);
float calculate_average_price(const Tovar *spisok, int count);
void sort_by_price(Tovar *spisok, int count);
void print_old_goods(const Tovar *spisok, int count);
void print_all_goods(const Tovar *spisok, int count);

#endif
