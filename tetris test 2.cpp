#include "pch.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include <conio.h>
#include "windows.h"
#include <cstdlib> 
using namespace std;

const int ROW_VERTICAL = 3;
const int COL_VERTICAL = 2;
const int ROW_HORIZONTAL = 2;
const int COL_HORIZONTAL = 3;

//-----------------------------------------

int figure1[ROW_VERTICAL][COL_VERTICAL];
int figure2[ROW_HORIZONTAL][COL_HORIZONTAL];

//-----------------------------------------

int ClearFigureVertical(int fig1[][2], const int ROW, const int COL);
bool CheckFigureVertical(int fig1[][2]);

//-----------------------------------------

int ClearFigureHorizontal(int fig2[][3], int ROW, int COL);
bool CheckFigureHorizontal(int fig2[][3]);

//-----------------------------------------

int CreateVertical();
int CreateHorizontal();

int main()
{

	srand(time(NULL));
	setlocale(LC_ALL, ".866");
	


	
	CreateVertical();
	cout << endl << endl;
	CreateHorizontal();
	
	


}


int CreateHorizontal()
{
FigureCreateHorizontal:
	ClearFigureHorizontal(figure2, 2, 3);

	int n = 4; //для того чтобы цикл повторялся и в результате заполняется ровно 4 поля
	for (int i = 0; i < n; i++) // "создание" фигуры
	{

		int x = 0; int y = 0;
		x = rand() % 2;
		y = rand() % 3;
		if (figure2[x][y] != -1)
		{
			n++;
		}
		else
		{
			figure2[x][y] = 1;

		}
	}


	if (CheckFigureHorizontal(figure2) == false) // проверка на исключение и переделывание фигуры
	{
		ClearFigureHorizontal(figure2, 2, 3);
		goto FigureCreateHorizontal;
	}
	cout << endl << endl;

	cout << "the shown figure: " << endl << endl;

	for (int i = 0; i < ROW_HORIZONTAL; i++)		// Вывод фигуры
	{
		for (int j = 0; j < COL_HORIZONTAL; j++)
		{
			if (figure2[i][j] == 1)
			{
				cout << char(254);
			}
			else if (figure2[i][j] == -1)
			{
				
			}
		}
		cout << endl; 
	}
	cout << endl<< "(0 = empty space)";
	return 0;

}

int CreateVertical()
{
FigureCreateVertical:
	ClearFigureVertical(figure1, 3, 2);

	int n = 4; //для того чтобы цикл повторялся и в результате заполняется ровно 4 поля
	for (int i = 0; i < n; i++) // "создание" фигуры
	{

		int x = 0; int y = 0;
		x = rand() % 3;
		y = rand() % 2;
		if (figure1[x][y] != -1)
		{
			n++;
		}
		else
		{
			figure1[x][y] = 1;

		}
	}


	if (CheckFigureVertical(figure1) == false) // проверка на исключение и переделывание фигуры
	{
		ClearFigureVertical(figure1, 3, 2);
		goto FigureCreateVertical;
	}
	cout << endl << endl;

	cout << "the shown figure: " << endl << endl;

	for (int i = 0; i < ROW_VERTICAL; i++)		// Вывод фигуры
	{
		for (int j = 0; j < COL_VERTICAL; j++)
		{
			if (figure1[i][j] == 1)
			{
				cout << char(254);
			}
			else if (figure1[i][j] == -1)
			{

			}
		}
		cout << endl;
	}
	return 0;
}

//-------------------------------------------------

int ClearFigureVertical(int fig1[][2], const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++) // зачистка массива для фигуры (вертикальная фигура)
	{
		for (int j = 0; j < COL; j++)
		{
			fig1[i][j] = -1;
		}
	}
	return fig1[ROW][COL];
}

int ClearFigureHorizontal(int fig2[][3], int ROW, int COL)
{
	for (int i = 0; i < ROW; i++) // зачистка массива для фигуры (горизонтальная фигура)
	{
		for (int j = 0; j < COL; j++)
		{
			fig2[i][j] = -1;
		}
	}
	return fig2[ROW][COL];

}




//------------------------------------------------

bool CheckFigureVertical(int fig1[][2])
{
	if (fig1[0][0] == 1 && fig1[0][1] == 1 && fig1[1][0] == 1 && fig1[2][1] == 1) return false;
	else if (fig1[0][0] == 1 && fig1[1][1] == 1 && fig1[0][1] == 1 && fig1[2][0] == 1) return false;
	else if (fig1[0][1] == 1 && fig1[1][0] == 1 && fig1[2][0] == 1 && fig1[2][1] == 1) return false;
	else if (fig1[0][0] == 1 && fig1[1][1] == 1 && fig1[2][0] == 1 && fig1[2][1] == 1) return false;
	else if (fig1[0][1] == 1 && fig1[0][1] == 1 && fig1[2][0] == 1 && fig1[2][1] == 1) return false;

}

bool CheckFigureHorizontal(int fig2[][3])
{
	if (fig2[0][0] == 1 && fig2[1][0] == 1 && fig2[0][1] == 1 && fig2[1][2] == 1) return false;
	else if (fig2[0][0] == 1 && fig2[1][0] == 1 && fig2[1][1] == 1 && fig2[0][2] == 1) return false;
	else if (fig2[1][0] == 1 && fig2[0][1] == 1 && fig2[0][2] == 1 && fig2[1][2] == 1) return false;
	else if (fig2[0][0] == 1 && fig2[1][1] == 1 && fig2[0][2] == 1 && fig2[1][2] == 1) return false;
	else if (fig2[0][0] == 1 && fig2[0][1] == 1 && fig2[0][2] == 1 && fig2[1][2] == 1) return false;

}





