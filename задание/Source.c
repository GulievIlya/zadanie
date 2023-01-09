#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
int Int(int* i1);
int Float(float* m);
int Double(double* m);
int Char(int *m);
int ShortInt(int *m);
int UnsignedshortInt(int* m);
int UnsignedChar(int* m);
int UnsignedInt(unsigned int *m);
int UnsignedlonglongInt(unsigned long long int*m);

int main() {
	vivod();
}
int vivod() {
	clock_t begin = clock();
	setlocale(LC_ALL, "RU");
	int i[7],C[3], K[2],N[2], L[2];
	unsigned int V[2];
	unsigned long long int J[2];
	float f[7];
	double d[7];
	double time_spent = 0.0;
	Int(i);
	Float(f);
	Double(d);
	Char(C);
	ShortInt(K);
	UnsignedshortInt(N);
	UnsignedChar(L);
	UnsignedInt(V);
	UnsignedlonglongInt(J);
	clock_t end = clock();
	time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
	printf("\nTime programm %lf sec\n", time_spent);
	printf("|Тип данных|Размер|Минимальное Значение|Максимальное значение|");
	printf("\n| int      | байт |%d\t       | %d\t     |", i[3], i[2]);
	printf("\n| double   | байт |%.0lf\t       | %.0lf\t     |", d[3], d[2]);
	printf("\n| float    | байт |%.0f\t       | %.0f\t     |",f[3], f[2]);
	printf("\n| char     | байт |%d\t               | %d\t             |",C[1],C[0]);
	printf("\n| Short Int| байт |%d\t       | %d\t             |",K[1],K[0]);
	printf("\n| UnsShtInt| байт |%d\t               | %d\t             |",N[1],N[0]);
	printf("\n| UnsChar  | байт |%d\t               | %d\t             |",L[1],L[0]);
	printf("\n| UnsInt   | байт |%u\t               | %u\t     |",V[1],V[0]);
	printf("\n| UnsLLInt | байт |%llu\t               | %llu|",J[1],J[0]);
	printf("\n|__________|______|____________________|_____________________|");
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
	i1[2] = ptrmax;
	i1[3] = ptrmin;
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
	m[3] = (i1 - i2) * 4;
}
int Double(double* m) {
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
	m[0] = (i1 - i2) * 8;
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
	m[1] = (i1 - i2) * 8;
}
int Char(int *m) {
	char x,n,n2;
	char *a,*b;
	n = 0,b = 0, a = &x;
	int sum = 0;
	while (1) {
		n2 = (char*)(b)-(char*)a;
		sum += 1;
		b = (a + sum);
		n = (char*)(b)-(char*)a;
		if ( n < 0) break;
	}
	m[0] = n2;
	char x1, n1, n11;
	char* a1, * b1;
	n1 = 0, b1 = 0, a1 = &x;
	int sum1 = 0;
	while (1) {
		n11 = (char*)(b1)-(char*)a1;
		sum1 -= 1;
		b1 = (a1 + sum1);
		n1 = (char*)(b1)-(char*)a1;
		if (n1 > 0) break;
	}
	m[1] = n11;
}
int ShortInt(int *m) {
	short int n,n2;
	short int x, * a, * b;//line 1
	a = &x;
	b = (a + 1);
	n = 0, b = 0, a = &x;
	int sum = 0;
	while (1) {
		n2 = (char*)(b)-(char*)a;
		sum += 1;
		b = (a + sum);
		n = (char*)(b)-(char*)a;
		if (n < 0) break;
	}
	m[0] = n2;
	short int  x1, n1, n11;
	short int * a1, * b1;
	n1 = 0, b1 = 0, a1 = &x;
	int sum1 = 0;
	while (1) {
		n11 = (char*)(b1)-(char*)a1;
		sum1 -= 1;
		b1 = (a1 + sum1);
		n1 = (char*)(b1)-(char*)a1;
		if (n1 > 0) break;
	}
	m[1] = n11;
}
int UnsignedshortInt(int *m) {
	unsigned short int n,n2;
	unsigned short int x, * a, * b;//line 1
	a = &x;
	b = (a + 1);
	n = 0, b = 0, a = &x;
	int sum = 0;
	while (1) {
		sum += 1000;
		b = (a + sum);
		n = (char*)(b)-(char*)a;
		if (n < (char*)((a + sum)) - (char*)a) {
			for (int l = 0;l < 1000;l++) {
				sum -= 1;
				b = (a + sum);
				n = (char*)(b)-(char*)a;
				n2 = (char*)(b -=1) - (char*)a;
				if (n < n2) break;
			}
			break;
		}
		}
	m[0] = n2;
	m[1] = 0;
	}
int UnsignedChar(int *m) {
	unsigned char x, n, n2;
	unsigned char* a, * b;
	n = 0, b = 0, a = &x;
	int sum = 0;
	while (1) {
		n2 = (char*)(b)-(char*)a;
		sum += 1;
		b = (a + sum);
		n = (char*)(b)-(char*)a;
		if (n < sum-1) break;
	}
	m[0] = n2;
	m[1] = 0;
} 
int UnsignedInt(unsigned int* m){
	unsigned int n, n2;
	unsigned int x, * a, * b;//line 1
	a = &x;
	b = (a + 1);
	n = 0, b = 0, a = &x;
	unsigned int sum = 0;
	while (1) {
		n2 = (char*)(b)-(char*)a;
		sum += 100000;
		b = (a + sum);
		n = (char*)(b)-(char*)a;
		//printf("\n%u", n);
		if (n < (char*)((a + sum)) - (char*)a) {
			for (unsigned int l = 0;l < 100000;l++) {
				sum -= 1;
				b = (a + sum);
				n = (char*)(b)-(char*)a;
				n2 = (char*)(b -= 1) - (char*)a;
				if (n < n2) break;
			}
			break;
		}
	}
	m[0] = n2;
	m[1] = 0;
}
int UnsignedlonglongInt(unsigned long long int*m) {
	unsigned long long int n, n2;
	unsigned long long int x, * a, * b;//line 1
	a = &x;
	b = (a + 1);
	n = 0, b = 0, a = 0;
	unsigned long long int sum = 0;
	while (1) {
		n2 = (char*)(b)-(char*)a;
		sum += 1190000000000000;
		b = (a + sum);
		n = (char*)(b)-(char*)a;
		if (n2 > n) {
			while (1) {
				n2 = (char*)(a + sum) - (char*)a;
				sum -= 119000000000;
				b = (a + sum);
				n = (char*)(b)-(char*)a;
				if (n2 < n) {
					while (1) {
						n2 = (char*)(a + sum) - (char*)a;
						sum += 1190000;
						b = (a + sum);
						n = (char*)(b)-(char*)a;
						if (n2 > n) { 
							while (1) {
								n2 = (char*)(a + sum) - (char*)a;
								sum -= 1;
								b = (a + sum);
								n = (char*)(b)-(char*)a;
								if (n2 < n) break;
							}
						break;
						}
					}
					break;
				}
			}
			break;
		}
	}
	m[0] = n;
	m[1] = 0;
}
