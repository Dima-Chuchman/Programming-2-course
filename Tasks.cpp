#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>
#include <Windows.h>

//-----------------------> Task1

int Task1() {
    char fname[] = "Text4.txt";
    std::fstream f(fname);
    if (!f) {
        std::cerr << "Error reading file: " << fname << std::endl;
        return -1;
    }

    char c;
    int num = 0;
    int num2 = 0;
    int summ = 0;
    int prev_sign = 0;

    while (f >> c) {
        if (std::isdigit(c)) {
            int d = c - '0';
            num = num * 10 + d;
        }
        else if (c == '-') {
            num2 = num;
            num = 0;
            if (prev_sign == 1 || prev_sign == 0) {
                summ += num2;
            }
            else if (prev_sign == 2) {
                summ -= num2;
            }
            prev_sign = 2;
        }
        else if (c == '+') {
            num2 = num;
            num = 0;
            if (prev_sign == 1 || prev_sign == 0) {
                summ += num2;
            }
            else if (prev_sign == 2) {
                summ -= num2;
            }
            prev_sign = 1;
        }
        else if (c == '=') {
            num2 = num;
            if (prev_sign == 1) {
                summ += num2;
            }
            else if (prev_sign == 2) {
                summ -= num2;
            }
            std::cout << "Sum = " << summ << std::endl;
        }
        else {
            std::cout << "Not required format: uncorrect symbol\n";
        }
    }
    return 0;
}

//-----------------------> Task2

int Task2() {
    char fname[20] = "input.txt";
    std::ifstream input(fname);
    std::string Articles[] = { "der", "die", "das" };
    std::string buf;
    bool isArticle = false;
    std::ofstream input2("tmp.txt");

    while (input >> buf) {
        if (isArticle) {
            buf[0] = std::toupper(buf[0]);
        }
        std::clog << buf << " ";
        input2 << buf << " ";
        isArticle = false;

        for (int i = 0; i < 3; i++) {
            if (buf == Articles[i]) {
                isArticle = true;
                break;
            }
        }
    }

    input.close();
    input2.close();
    std::rename("tmp.txt", fname);
    return 0;
}

//-----------------------> Task3

void Task3(char* str) {
    int n = std::strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char tup = str[i];
        str[i] = str[n - 1 - i];
        str[n - i - 1] = tup;
    }
}

bool checkTags(std::ifstream& f1, const std::string& openTD = "<td>", const std::string& closeTD = "</td>") {
    int opentag = 0;
    int closetag = 0;
    std::string buf;

    while (f1 >> buf) {
        if (buf == openTD) {
            opentag++;
        }
        else if (buf == closeTD) {
            closetag++;
            if (closetag > opentag) {
                return false;
            }
        }
    }
    return closetag == opentag;
}

//-----------------------> Task4

void Task4() {
    const char* fname = "t.txt";
    std::ifstream f1(fname);

    if (!f1) {
        std::cerr << "Error opening " << fname << std::endl;
        return;
    }

    std::cout << "\nCheck: " << std::boolalpha << checkTags(f1);
    f1.close();
}

void create_student_file(const char* fname) {
    std::ofstream f1(fname);
    if (!f1) {
        std::cerr << "Error opening file: " << fname << std::endl;
        return;
    }

    int N;
    std::cout << "Enter N: ";
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::string surname;
        int course;
        std::string group;
        std::string marks;

        std::cout << "Enter surname: ";
        std::cin >> surname;
        std::cout << "Enter course: ";
        std::cin >> course;
        std::cout << "Enter group: ";
        std::cin >> group;
        std::cout << "Enter marks: ";
        std::cin >> marks;

        f1 << std::setw(8) << surname << std::setw(8) << course
            << std::setw(8) << group << std::setw(20) << marks << std::endl;
    }
    f1.close();
}

double average_mark(const std::string& marks) {
    double sum = 0.0;
    int counter = 0;
    int tmp;
    char coma = ',';
    std::stringstream str(marks);

    while (str >> tmp) {
        sum += tmp;
        counter++;
        str >> coma;
    }
    return sum / counter;
}

std::string find_student(const char* fname) {
    std::ifstream f1(fname);
    std::string loser;
    double min_mark = 101;

    while (!f1.eof()) {
        std::string surname, course, group, marks;
        f1 >> surname >> course >> group >> marks;

        double worst = average_mark(marks);
        if (worst < min_mark) {
            min_mark = worst;
            loser = surname;
        }
    }
    return loser;
}

//-----------------------> Task4

void Task5() {
    create_student_file("task5.txt");
    std::cout << "Student with the worst average mark: " << find_student("task5.txt") << std::endl;
}

int main() {
    int task = 1;
    std::cout << "task = ";
    std::cin >> task;

    if (task == 1) {
        Task1();
    }
    else if (task == 2) {
        Task2();
    }
    else if (task == 3) {
        char str[100];
        std::cout << "Enter string: ";
        std::cin >> str;
        Task3(str);
        std::cout << "Reversed string: " << str << std::endl;
    }
    else if (task == 4) {
        Task4();
    }
    else if (task == 5) {
        Task5();
    }
    return 0;
}
