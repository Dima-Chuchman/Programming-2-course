// Classwork 19

#include <iostream>
#include <vector>

using namespace std;
vector <double> intput_vect(int dimension);
double norm(const vector<double>& v);

vector<double> input_vect(int dimension) {
	vector <double> r;
	for (int i = 0; i < d; i++) {
		double x;
		cin >> x;
		r.push_back(x);
	}
	return r;
}

double norm(const vector<double>& v) {
	double s = 0;
	for (int i = 0; i < v.size(); i++) {
		s += v[i]*v[i];
	}
	return sqrt(s);
}

int main() {
	int d;
	int n;
	cin >> d;
	vector <double> a = input_vect(d);
	cin >> n;
	vector <vector<double>> matrix;
	for (int i = 0; i < n; i++) {
		a = input_vect(d);
		matrix.push_back(a);
	}

	double s = 0;
	for (const vector<double>v : matrix) {
		s += norm(v);
	}
	cout << s;
}