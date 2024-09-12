/*

Task 1.7

Ввести дійсне число x та підрахуйте без та з допомогою математичних функцій мови C його цілу та дробову частину, найменше ціле число,
що більше x та найбільше ціле, що менше x, а також його округлене значення. Перевірте результат роботи для від'ємного числа.

*/

//#include <stdio.h>
//#include <Windows.h>
//
//
//int main() {
//
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    double x;
//    printf("Введіть дійсне число: ");
//    scanf_s("%lf", &x);
//
//    // Ціла частина
//    int int_part = (int)x;
//    printf("Ціла частина: %d\n", int_part);
//
//    // Дробова частина
//    double frac_part = x - int_part;
//    printf("Дробова частина: %.10lf\n", frac_part);
//
//    // Найменше ціле, більше за x
//    int ceil_value = (int)(x + (x > int_part ? 1 : 0));
//    printf("Найменше ціле, більше за x: %d\n", ceil_value);
//
//    // Найбільше ціле, менше за x
//    int floor_value = (int)(x - (x < int_part ? 1 : 0));
//    printf("Найбільше ціле, менше за x: %d\n", floor_value);
//
//    // Округлене значення
//    int rounded_value = (int)(x >= 0 ? x + 0.5 : x - 0.5);
//    printf("Округлене значення: %d\n", rounded_value);
//
//}
