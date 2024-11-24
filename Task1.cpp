#include <iostream>
#include <string>
#include <sstream>

int main() {

	std::string task1_out(const std::string S);
	int task1_inplace(std::string & S);
	return 0;
}

std::string task1_out(const std::string &S) {
	size_t p1 = S.find(".");
	if (p1 == std::string::npos) {
		return S;
	}
	size_t p2 = S.find(",", p1 + 1);
	if (p2 == std::string::npos) {
		return S.substr(p1 + 1, S.length() - p1);
	}
	return S.substr(p1 + 1, p2 - p1 - 1);

}

int task1_inplace(std::string& S) {
	size_t p1 = S.find(":");
	if (p1 == std::string::npos) {
		return 0;
	}
	S.erase(0, p1 + 1);
	size_t p2 = S.find(",");
	if (p2 == std::string::npos) {
		return 1;
	}
	S.erase(p2, S.length() - p2);
	return 2;
}

std::string task2(const std::string& s) {
    size_t p1 = s.find(".");
    size_t f1 = s.find(" ");
    if (p1 == std::string::npos) {
        // Немає крапок — видаляємо пробіли на початку тексту
        return f1 == std::string::npos ? "" : s.substr(f1 + 1);
    }
    size_t p2 = s.rfind(".");
    if (p1 == p2) {
        return s.substr(p1 + 1);
    }
    return s.substr(0, p1 + 1) + s.substr(p2 + 1);
}

void task3(std::string s) {
    size_t p1 = 0, p2;
    while (p1 < s.length()) {
        p2 = s.find(' ', p1);
        if (p2 == std::string::npos) {
            p2 = s.length();
        }
        for (size_t i = p1; i < p2 - 1; i++) {
            std::cout << s[i];
        }
        std::cout << " ";
        p1 = p2 + 1;
    }
}

void task4(std::string s, int n, char del, double* mas) {
    std::string tmp;
    std::stringstream ss(s);
    int k = 0;
    while (std::getline(ss, tmp, del)) {
        size_t p;
        double x = std::stod(tmp, &p);
        mas[k++] = x;
    }
}

void task5(std::string s, int n, char d, std::string* result) {
    std::stringstream ss(s);
    std::string tmp;
    int count = 0;
    while (std::getline(ss, tmp, d) && count < n) {
        result[count++] = tmp;
    }
}

void task6() {
    std::string s;
    std::cout << "Enter string: " << std::endl;
    std::getline(std::cin, s);
    std::stringstream ss(s);
    std::string word;
    std::string shortestWord;
    int minLength = 1000;
    bool f = false;
    std::string first_word, last_word;
    std::string all_words = "";
    while (ss >> word) {
        int len = word.length();
        if (len < minLength) {
            minLength = len;
            first_word = word;
            last_word = word;
            all_words = word + " ";
            f = true;
        }
        else if (len == minLength) {
            last_word = word;
            all_words += word + " ";
        }
    }
    if (f) {
        std::cout << "First shortest word: " << first_word << std::endl;
        std::cout << "Last shortest word: " << last_word << std::endl;
        std::cout << "All shortest words: " << all_words << std::endl;
    }
    else {
        std::cout << "No words found." << std::endl;
    }
}

int main() {
    std::string s1 = "gdfsg:fg,sg";
    std::string s2 = "sdfg:gfd";
    std::string s3 = "sfghgfh";
    std::cout << "task1_exp_1" << std::endl;
    // Task1 is missing in the provided code

    std::string s1_2 = "gcfhgh.ghjjj.";
    std::string s2_2 = " fdgh";
    std::string s3_2 = "dghj.";
    std::string s4_2 = "dghf.gfdh.fhgd.hfgnb.";

    std::cout << "\ntask2" << std::endl;
    std::cout << task2(s1_2) << std::endl;
    std::cout << task2(s2_2) << std::endl;
    std::cout << task2(s3_2) << std::endl;
    std::cout << task2(s4_2) << std::endl;

    std::cout << "\ntask3" << std::endl;
    std::string s_3 = "Hello World";
    task3(s_3);

    std::cout << "\ntask4" << std::endl;
    int n;
    std::string s;
    char w = ' ';
    double* mas;
    std::cout << "Enter n: " << std::endl;
    std::cin >> n;
    std::cin.ignore();
    mas = new double[n];
    std::cout << "Enter string: " << std::endl;
    std::getline(std::cin, s);
    task4(s, n, w, mas);
    for (int i = 0; i < n; i++) {
        std::cout << mas[i] << " ";
    }
    delete[] mas;

    std::cout << "\ntask5" << std::endl;
    std::string s5;
    int m;
    char d = ' ';
    std::cout << "Enter m: " << std::endl;
    std::cin >> m;
    std::cin.ignore();
    std::cout << "Enter string: " << std::endl;
    std::getline(std::cin, s5);
    std::string* res = new std::string[m];
    task5(s5, m, d, res);
    std::cout << "First " << m << " words: ";
    for (int i = 0; i < m; i++) {
        std::cout << res[i] << " ";
    }
    std::cout << std::endl;
    delete[] res;

    std::cout << "\ntask6" << std::endl;
    task6();
}