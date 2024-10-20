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
//// ������� �������� ���������� ��� �����
//void inputBook(Book* book) {
//
//    printf("������ ���� �����: ");
//    scanf_s("%d", &book->shifr);
//    printf("������ ������ �����: ");
//    scanf_s(" %[^\n]s", book->author, sizeof(book->author));
//    printf("������ ����� �����: ");
//    scanf_s(" %[^\n]s", book->title, sizeof(book->title));
//
//}
//
//// ������� �������� ���������� ��� ������
//void inputReader(Reader* reader) {
//
//    printf("������ ����� ���������� ������: ");
//    scanf_s("%d", &reader->ticketNumber);
//    printf("������ ������� ������: ");
//    scanf_s(" %[^\n]s", reader->surname, sizeof(reader->surname));
//
//}
//
//// ������� �������� ���������� ��� ����������
//void inputOrderForm(OrderForm* order) {
//
//    printf("�������� ���������� ��� �����:\n");
//    inputBook(&order->book);
//    printf("\n�������� ���������� ��� ������:\n");
//    inputReader(&order->reader);
//    printf("\n������ ���� ���������� (YYYY-MM-DD): ");
//    scanf_s(" %[^\n]s", order->orderDate, sizeof(order->orderDate));
//
//}
//
//
//// ������� ��������� ���������� ��� �����
//void printBook(const Book* book) {
//
//    printf("���� �����: %d\n", book->shifr);
//    printf("�����: %s\n", book->author);
//    printf("�����: %s\n", book->title);
//
//}
//
//// ������� ��������� ���������� ��� ������
//void printReader(const Reader* reader) {
//
//    printf("����� ���������� ������: %d\n", reader->ticketNumber);
//    printf("������� ������: %s\n", reader->surname);
//
//}
//
//// ������� ��������� ���������� ��� ����������
//void printOrderForm(const OrderForm* order) {
//
//    printf("\n���������� ��� �����:\n");
//    printBook(&order->book);
//    printf("\n���������� ��� ������:\n");
//    printReader(&order->reader);
//    printf("\n���� ����������: %s\n", order->orderDate);
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
//    printf("\n\n--- ����� ����� �� ����� ---\n");
//    printOrderForm(&order);
//
//}
