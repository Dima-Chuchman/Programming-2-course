#include <iostream>
#include <vector>
#include <list>
#include <cmath>

using namespace std;

bool compare_pairs(const pair<double, int>& a, const pair<double, int>& b);

vector<list<double> > input_matrix(int n, int m) {
	vector<list<double> > matrix(n);
	for (int i = 0; i < n; i++) {
		cout << "Row " << i + 1 << ":\n";
		list<double> l;
		double temp;
		for (int j = 0; j < m; j++) {
			cout << "V[" << j + 1 << "]: ";
			cin >> temp;
			l.push_back(temp);
		}
		matrix[i] = l;
	}
	return matrix;
}

	
list<pair<double, int>>M(n);
int j = 0;
for (auto row &: matrix) {
	double max = row[0];
	for (int i = 0; i < row.size(); i++) {
		if (row[i] > max) {
			max = row[i];
		}
		M[j].first = max;
		M[j].second = j;
		j++;
	}
	M.sort();
}

double norm(const vector<double>& v) {
	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += pow(v[i], 2);
	}
	return sqrt(sum);
}

vector<list<double> > input_matrix(int n, int m) {
	vector<list<double> > matrix(n);
	for (int i = 0; i < n; i++) {
		cout << "Row " << i + 1 << ":\n";
		list<double> l;
		double temp;
		for (int j = 0; j < m; j++) {
			cout << "V[" << j + 1 << "]: ";
			cin >> temp;
			l.push_back(temp);
		}
		matrix[i] = l;
	}
	return matrix;
}

double norm(const vector<double>& v) {
	double sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += pow(v[i], 2);
	}
	return sqrt(sum);
}

bool compare_pairs(const pair<double, int>& a, const pair<double, int>& b) {
	return a.first > b.first;
}

int main() {
	int n, m;
	cout << "Enter number of rows (n): ";
	cin >> n;
	cout << "Enter number of columns (m): ";
	cin >> m;
	vector<list<double> > matrix = input_matrix(n, m);
	list<pair<double, int> > M;

	for (int j = 0; j < n; j++) {
		double max_value = *matrix[j].begin();
		for (list<double>::const_iterator it = matrix[j].begin(); it != matrix[j].end(); it++) {
			if (*it > max_value) {
				max_value = *it;
			}
		}
		M.push_back(make_pair(max_value, j));
	}