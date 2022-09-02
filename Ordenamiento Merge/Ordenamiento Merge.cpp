// Ordenamiento Merge.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Alfredo Jordano Anaya Hernández

#include <iostream>

using namespace std;

void imp(int x[], int n);
void mSort(int* A, int n);
void merge(int* izq, int nIzq, int* der, int nDer, int* A, int n);

int main()
{
	int Arr[20];
	int c, R;

	do
	{
		do
		{
			system("cls");
			cout << " Ingresa la longitud del arreglo " << endl;
			cin >> c;
		} while (c < 2 || c>20);

		for (int i = 0; i < c; i++)
		{
			cout << " Ingresa el numero de la posicion " << i + 1 << " del arreglo " << endl;
			cin >> Arr[i];
		}
		system("cls");

		mSort(Arr, c);
		cout << " El arreglo ordenado es " << endl;
		imp(Arr, c);
		system("pause");
		cout << " ¿Deseas repetir el programa ? " << endl << " 1.- Si " << endl << " 2.- No " << endl;
		cin >> R;

	} while (R == 1);
	system("pause");

	return 0;

}

void imp(int x[], int n)
{
	for (int i = 0; i < n; i++)
		cout << x[i] << " ";
	cout << endl;

}

void mSort(int* A, int n)
{

	if (n == 1)return;

	int mitad = n / 2;
	int* izq = new int[mitad];
	int* der = new int[n - mitad];

	for (int i = 0; i < mitad; i++)

		izq[i] = A[i];

	for (int i = mitad; i < n; i++)

	der[i - mitad] = A[i];

	mSort(izq, mitad);
	mSort(der, n - mitad);
	merge(izq, mitad, der, n - mitad, A, n);

}

void merge(int* izq, int nIzq, int* der, int nDer, int* A, int c)
{
	int i = 0, j = 0, k = 0;

	while ((i < nIzq) && (j < nDer))
	{
		if (izq[i] <= der[j])
		{
			A[k] = izq[i];
			i++;
		}
		else
		{
			A[k] = der[j];
			j++;
		}
		k++;
	}

	while (i < nIzq)
	{
		A[k] = izq[i];
		i++; k++;
	}
	while (j < nDer)
	{
		A[k] = der[j];
		j++; k++;
	}
}