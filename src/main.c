/*
 * Author: Kudinova Elizaveta, group 12
 * Description: Main program to demonstrate TOVAR structure functions
 */

#include <stdio.h>
#include "../include/tovar.h"

/*
 * Function: print_menu
 * --------------------
 * Выводит меню программы
 */
void print_menu(void) {
    printf("\n=== MENU ===\n");
    printf("1. Add goods\n");
    printf("2. Show all goods\n");
    printf("3. Calculate average price\n");
    printf("4. Sort goods by price\n");
    printf("5. Show goods received >10 months ago\n");
    printf("0. Exit\n");
    printf("Your choice: ");
}

/*
 * Main function
 */
int main(void) {
    Tovar spisok[10];  // Массив не более 10 записей
    int count = 0;      // Текущее количество записей
    int choice;
    
    printf("=== Goods Management System ===\n");
    printf("Maximum 10 goods can be stored.\n");
    
    do {
        print_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                add_tovar(spisok, &count);
                break;
                
            case 2:
                print_all_goods(spisok, count);
                break;
                
            case 3: {
                float avg = calculate_average_price(spisok, count);
                if (count > 0) {
                    printf("Average price of all goods: %.2f\n", avg);
                } else {
                    printf("No goods to calculate average.\n");
                }
                break;
            }
                
            case 4:
                if (count > 0) {
                    sort_by_price(spisok, count);
                    printf("Sorted list:\n");
                    print_all_goods(spisok, count);
                } else {
                    printf("No goods to sort.\n");
                }
                break;
                
            case 5:
                print_old_goods(spisok, count);
                break;
                
            case 0:
                printf("Exiting program. Goodbye!\n");
                break;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}
