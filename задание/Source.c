#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Int(int *i1);
int Float(float*m);
int Double(double*m);
int main() {
	vivod();
}
int vivod() {
	setlocale(LC_ALL, "RU");
	int* i1=0;
	float *i2 = 0;
	double* i3 = 0;
	i3 += 1;
	i2 += 1;
	i1 += 1;
	int i[7];
	float f[7];
	double d[7];
	Int(i);
	Float(f);
	Double(d);
	printf("|Тип данных|Размер|Минимальное Значение|Максимальное значение|Максимальное кол-во байт|Минимальное кол-во байт|");
	printf("\n| int      |%d байт|  %d\t       | %d\t     | %d             | %d           |",i1, i[1], i[0],i[2],i[3]);
	printf("\n| double   |%d байт| %.0lf\t       | %.0lf\t     | %.0lf            | %.0lf          |",i3, d[1], d[0],d[2],d[3]);
	printf("\n| float    |%d байт| %.0f\t       | %.0f\t     | %.0f            | %.0f          |",i2, f[1], f[0],f[2],f[3]);
	printf("\n|__________|______|____________________|_____________________|________________________|_______________________|");
	//printf("%d %d %d %d",i[0], i[1],i[2],i[3]);
	//printf("\n\n %.0f %.0f %.0f %.0f\n", f[0], f[1], f[2], f[3]);
	//printf("\n\n %.0lf %.0lf %.0lf %.0lf\n", d[0], d[1], d[2], d[3]);
}
int Int(int* i1) {
	int* ptrmin = 0, * ptrmax = 0, sze, sze1;
	while (1) {
		ptrmax += 100000;
		if ((int)ptrmax < 0) break;
	}
	while (1) {
		ptrmax -= 1;
		if ((int)ptrmax > 0) break;
		sze = ~((int)ptrmax / 4);
	}
	while (1) {
		ptrmin -= 100000;
		if ((int)ptrmin > 0) break;
	}
	while (1) {
		ptrmin += 1;
		if ((int)ptrmin < 0) break;
		sze1 = ~((int)ptrmin / 4);
	}
	i1[0] = sze;
	i1[1] = sze1;
	i1[2] = ptrmax ;
	i1[3] = ptrmin ;
}
int Float(float* m) {
	int sum = 0;
	float i = 1, i1;
	float i2 = (size_t)(&(i));
	while (1) {
		sum += 100000;
		i1 = ((size_t)(&(i)+sum));
		if (((size_t)(&(i)-sum)) > i1) {
			for (int k = 1;k < 10000;k) {
				sum--;
				i1 = ((size_t)(&(i)+sum));
				if ((float)(i1 - i2) > 0) break;
			}
			break;
		}
	}
	//printf("\n %lf", (i1 - i2));
	m[0] = (i1 - i2);
	//printf("\n%f", (i1 - i2) / 4);
	m[2] = (i1 - i2) * 4;
	while (1) {
		sum -= 100000;
		i1 = ((size_t)(&(i)+sum));
		if (((size_t)(&(i)-sum)) < i1) {
			for (int k = 1;k < 10000;k) {
				sum++;
				i1 = ((size_t)(&(i)+sum));
				if ((float)(i1 - i2) < 0) break;
			}
			break;
		}
	}
	//printf("\n %f", (i1 - i2));
	//printf("\n %f", (float)(i1 - i2) / 4);
	m[1] = i1 - i2;
	m[3]=(i1 - i2) * 4;
}
int Double(double*m) {
	int sum = 0;
	double i = 1, i1;
	double i2 = (size_t)(&(i));
	while (1) {
		sum += 100000;
		i1 = ((size_t)(&(i)+sum));
		if (((size_t)(&(i)-sum)) > i1) {
			for (int k = 1;k < 10000;k) {
				sum--;
				i1 = ((size_t)(&(i)+sum));
				if ((double)(i1 - i2) > 0) break;
			}
			break;
		}
	}
	m[2] = i1 - i2;
	m[0] = (i1 - i2) / 8;
	while (1) {
		sum -= 100000;
		i1 = ((size_t)(&(i)+sum));
		if (((size_t)(&(i)-sum)) < i1) {
			for (int k = 1;k < 10000;k) {
				sum++;
				i1 = ((size_t)(&(i)+sum));
				if ((double)(i1 - i2) < 0) break;
			}
			break;
		}
	}
	m[3] = i1 - i2;
	m[1] = (i1 - i2)/8;
}
