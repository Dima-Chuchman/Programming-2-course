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
//		std::cout << "Введіть ім'я: ";
//		std::cin >> name;
//		std::cout << "Введіть рік народження: ";
//		std::cin >> byear;
//	}
//
//	void show() const {
//		cout << "Ім'я: " << name << endl;
//		cout << "Рік народження: " << byear << endl;
//		int age = 2024 - byear;
//		cout << "Вік: " << age << " років" << endl;
//
//		if (age > 100) {
//			cout << "Ця особа має вік більше ніж 100 років!" << endl;
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
//			outFile << "Ім'я: " << name << endl;
//			outFile << "Рік народження: " << byear << endl;
//			outFile << "Вік: " << age() << " років" << endl;
//			outFile.close();
//			cout << "Дані збережено в файл person_data.txt" << endl;
//		}
//		else {
//			cout << "Не вдалося відкрити файл для запису!" << endl;
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
//		cout << "Введіть номер телефону: ";
//		cin >> phoneNumber;
//	}
//
//	void showPhoneNumber() const {
//		cout << "Номер телефону: " << phoneNumber << endl;
//	}
//
//	void savePhoneNumberToFile() const {
//		ofstream outFile("person_data.txt", ios::app);
//		if (outFile.is_open()) {
//			outFile << "Номер телефону: " << phoneNumber << endl;
//			outFile.close();
//			cout << "Номер телефону збережено в файл person_data.txt" << endl;
//		}
//		else {
//			cout << "Не вдалося відкрити файл для запису номера телефону!" << endl;
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
//		cout << "Інформація про особу не збережена через надмірний вік!" << endl;
//	}
//
//	return 0;
//}