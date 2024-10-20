///*
//
//Homework(10) 20.10.2024
//
//Tasks: 10.6(e); 10.13(g,d)
//
//*/
//
//#include <stdio.h>
//#include <Windows.h>
//
//
//typedef struct {
//
//    int shifr;
//    char author[50];
//    char title[100];
//
//} Book;
//
//typedef struct {
//
//    int ticketNumber;
//    char surname[50];
//
//} Reader;
//
//typedef struct {
//
//    Book book;
//    Reader reader;
//    char orderDate[11];
//
//} OrderForm;
//
//
//// Функція введення інформації про книгу
//void inputBook(Book* book) {
//
//    printf("Введіть шифр книги: ");
//    scanf_s("%d", &book->shifr);
//    printf("Введіть автора книги: ");
//    scanf_s(" %[^\n]s", book->author, sizeof(book->author));
//    printf("Введіть назву книги: ");
//    scanf_s(" %[^\n]s", book->title, sizeof(book->title));
//
//}
//
//// Функція введення інформації про читача
//void inputReader(Reader* reader) {
//
//    printf("Введіть номер читацького квитка: ");
//    scanf_s("%d", &reader->ticketNumber);
//    printf("Введіть прізвище читача: ");
//    scanf_s(" %[^\n]s", reader->surname, sizeof(reader->surname));
//
//}
//
//// Функція введення інформації про замовлення
//void inputOrderForm(OrderForm* order) {
//
//    printf("Введення інформації про книгу:\n");
//    inputBook(&order->book);
//    printf("\nВведення інформації про читача:\n");
//    inputReader(&order->reader);
//    printf("\nВведіть дату замовлення (YYYY-MM-DD): ");
//    scanf_s(" %[^\n]s", order->orderDate, sizeof(order->orderDate));
//
//}
//
//
//// Функція виведення інформації про книгу
//void printBook(const Book* book) {
//
//    printf("Шифр книги: %d\n", book->shifr);
//    printf("Автор: %s\n", book->author);
//    printf("Назва: %s\n", book->title);
//
//}
//
//// Функція виведення інформації про читача
//void printReader(const Reader* reader) {
//
//    printf("Номер читацького квитка: %d\n", reader->ticketNumber);
//    printf("Прізвище читача: %s\n", reader->surname);
//
//}
//
//// Функція виведення інформації про замовлення
//void printOrderForm(const OrderForm* order) {
//
//    printf("\nІнформація про книгу:\n");
//    printBook(&order->book);
//    printf("\nІнформація про читача:\n");
//    printReader(&order->reader);
//    printf("\nДата замовлення: %s\n", order->orderDate);
//
//}
//
//int main() {
//
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    OrderForm order;
//
//    inputOrderForm(&order);
//
//    printf("\n\n--- Бланк вимог на книгу ---\n");
//    printOrderForm(&order);
//
//}
