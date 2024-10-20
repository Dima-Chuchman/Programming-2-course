#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#define LEN 255


//-----------------------------> Task1

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

void outputDate(Date d) {
    printf("%02d/%02d/%04d\n", d.day, d.month, d.year);
}

int inputDate(Date* d) {
    printf("Input year, month, day: ");
    return scanf("%d %d %d", &d->year, &d->month, &d->day);
}

void task1_a() {
    Date today;

    if (inputDate(&today) == 3) {
        outputDate(today);
    }
    else {
        printf("Invalid input. \n");
    }
}

typedef struct Chess_board {
    unsigned char horisontal;
    char vertical;
} Chess_board;

void output_cell(Chess_board c) {
    printf("Cell: %c%d\n", c.vertical, c.horisontal);
}

int input_cell(Chess_board* c) {
    printf("Enter vertical (a-h or A-H): ");
    scanf(" %c", &c->vertical);
    printf("Enter horisontal (1-8): ");
    scanf("%hhu", &c->horisontal);
    if ((c->vertical >= 'a' && c->vertical <= 'h' || c->vertical >= 'A' && c->vertical <= 'H') &&
        (c->horisontal >= 1 && c->horisontal <= 8)) {
        return 0;
    }
    return 1;
}

void task1_b() {
    Chess_board cell;
    if (input_cell(&cell) == 0) {
        output_cell(cell);
    }
    else {
        printf("Invalid input. \n");
    }
}

typedef struct Vertex {
    long double x;
    long double y;
} Vertex;

void output_vectex(Vertex v) {
    printf("%Lg %Lg", v.x, v.y);
};

Vertex inputvertex() {
    Vertex res;
    printf("x, y = ");
    scanf("%Lg %Lg", &res.x, &res.y);
    return res;
}

typedef struct Rectangle {
    Vertex v1;
    Vertex v2;
} Rectangle;

void outputRectangle(const Rectangle* r) {
    output_vectex(r->v1);
    printf("\t");
    output_vectex(r->v2);
    printf("\n");
}

int inputRectangle(Rectangle* r) {
    r->v1 = inputvertex();
    r->v2 = inputvertex();
    return 0;
}

void task1_c() {
    Rectangle rect;
    inputRectangle(&rect);
    outputRectangle(&rect);
}

typedef struct Poly
{
    unsigned n;
    double* a;
} Poly;

void output_pol(Poly p) {
    for (int i = 0; i < p.n; i++) {
        printf("%lf * x^%d + ", p.a[i], i);
    }
    printf("%lf * x^%d \n", p.a[p.n], p.n);
}

int inputPoly(Poly* p) {
    printf("Enter n: ");
    scanf("%d", &(p->n));
    p->a = (double*)calloc(p->n + 1, sizeof(*(p->a)));

    for (int i = 0; i <= p->n; i++) {
        printf("Enter x^%d: ", i);
        scanf("%lf", &(p->a[i]));
    }
    return 0;
}

void deletePoly(Poly* p) {
    if (p->a) {
        free(p->a);
    }
}

void task1_g() {
    Poly p;
    inputPoly(&p);
    output_pol(p);
    deletePoly(&p);
}

bool hitQueen(Chess_board f1, Chess_board f2) {
    return (f1.horisontal == f2.horisontal) ||
        (f1.vertical == f2.vertical) ||
        (abs(f1.vertical - f2.vertical) == abs(f1.horisontal - f2.horisontal));
}


//---------------------> Task 2

struct Chess_board {
	unsigned char horisontal;
	char vertical;
};

void output_cell(struct Chess_board c) {
	printf("%C %ssh", c.vertical, c.horisontal);
}

int input_cell(struct Chess_board* c) {
	printf("enter vertical: ");
	scanf_s("%c", &c->vertical);
	if (c->vertical >= 'a'
		&& c->vertical <= 'h'
		|| c->vertical >= "A"
		&& c->vertical <= 'H'
		&& c->horisontal >= 1
		&& c->horisontal <= 8) {
		return 0;
	}
	return 1;
}

//---------------------> Task 3

typedef struct Vertex {
	long double x;
	long double y;
};

void outputVertex(Vertex v) {
	printf("(%lg, %lg)", v.x, v.y);
}

Vertex inputVertex() {
	Vertex res;
	printf("x,y= ");
	scanf_s("%lf %lf", res.x, res.y);
	return res;
}

typedef struct Rectangle{
	Vertex v1;
	Vertex v2;
} Rectangle;

void outputRectangle(const Rectangle *r) {
	outputVertex(r->v1);
	printf("/t");
	outputVertex(r->v2);
}

int inputrectangle(Rectangle* r) {
	r->v1 = inputVertex();
	r->v2 = inputVertex();
	return 0;
}

//---------------------> Task 4

typedef struct Poly {
	unsigned n;
	double *a ;	// n+1
}; Poly;

int output_Poly(Poly p) {
	for (int i = 1; i < p.n; i++) {
		printf("%lf *x^%df", p.a[i],i);
		printf("%lf *x^%d\n", p.a[n], n);
	}
}

int intput_Poly(Poly p) {
	printf("Enter n: ");
	scanf_s("%d", p->n);
	p->a = (double*);
	calloc(p->n + 1, sizeof(*(p->a)));
	for (int i = 0; i < p->n + 1; i++);
	printf("a[%df]", i);
	scanf_s("%lf", &p->a[i]);
}

void deletePoly(Poly* p) {
	if (p->a)
		free(p->a);
}

int main() {
	Poly p:
	intput_Poly(&p);
	output_Poly(p);
	deletePoly(&p);
}


//---------------------->

bool hitQueen(Cell fi; Cell fz) {
	return
		(fi.hor == fz.hor) ||
		(f ver == fz.ver) ||
		(fabs(fi.ver - fz.ver) = fabs(fz.hor - fz.hor));
}


//--------------------->

int Mon_Dayth[] = {
	31, 30, 31, 30, 31,
	30, 31, 31, 30, 31,
	30, 31
};

if (d.day > Mon_Dayth[d.mounth - 1]) {

}