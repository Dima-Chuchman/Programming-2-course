//#include <iostream>
//#include <string>
//#include <Windows.h>
//#include <fstream>
//
//using namespace std;
//
//class Person {
//	std::string name;
//	unsigned byear;
//public:
//	void input() {
//		std::cout << "������ ��'�: ";
//		std::cin >> name;
//		std::cout << "������ �� ����������: ";
//		std::cin >> byear;
//	}
//
//	void show() const {
//		cout << "��'�: " << name << endl;
//		cout << "г� ����������: " << byear << endl;
//		int age = 2024 - byear;
//		cout << "³�: " << age << " ����" << endl;
//
//		if (age > 100) {
//			cout << "�� ����� �� �� ����� �� 100 ����!" << endl;
//		}
//	}
//
//	int age() const {
//		return 2024 - byear;
//
//	}
//
//	void saveToFile() const {
//		ofstream outFile("person_data.txt");
//		if (outFile.is_open()) {
//			outFile << "��'�: " << name << endl;
//			outFile << "г� ����������: " << byear << endl;
//			outFile << "³�: " << age() << " ����" << endl;
//			outFile.close();
//			cout << "��� ��������� � ���� person_data.txt" << endl;
//		}
//		else {
//			cout << "�� ������� ������� ���� ��� ������!" << endl;
//		}
//	}
//};
//
//class Familiar : public Person {
//private:
//	string phoneNumber;
//
//
//public:
//	void inputPhoneNumber() {
//		cout << "������ ����� ��������: ";
//		cin >> phoneNumber;
//	}
//
//	void showPhoneNumber() const {
//		cout << "����� ��������: " << phoneNumber << endl;
//	}
//
//	void savePhoneNumberToFile() const {
//		ofstream outFile("person_data.txt", ios::app);
//		if (outFile.is_open()) {
//			outFile << "����� ��������: " << phoneNumber << endl;
//			outFile.close();
//			cout << "����� �������� ��������� � ���� person_data.txt" << endl;
//		}
//		else {
//			cout << "�� ������� ������� ���� ��� ������ ������ ��������!" << endl;
//		}
//	}
//
//};
//
//int main() {
//	SetConsoleOutputCP(1251);
//	SetConsoleCP(1251);
//
//	Familiar familiar;
//	familiar.input();
//	familiar.inputPhoneNumber();
//	familiar.show();
//	familiar.showPhoneNumber();
//
//	if (familiar.age() <= 100) {
//		familiar.saveToFile();
//		familiar.savePhoneNumberToFile();
//	}
//	else {
//		cout << "���������� ��� ����� �� ��������� ����� �������� ��!" << endl;
//	}
//
//	return 0;
//}