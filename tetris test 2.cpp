int main()
{

	srand(time(NULL));
	setlocale(LC_ALL, ".866");
	int count = 0;
	int counterForBufferCheck = 0;


	for (int m = 0; m < 5; m++)
	{
		CreateVertical();
	}
//______________________________________________________________________________________________________________
//______________________________________________________________________________________________________________


}

int CreateVertical()
{
FigureCreate:
	ClearFigure(figure1, 3, 2);

	int n = 4;
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


	if (CheckFigure(figure1) == false) // проверка на исключение и переделывание фигуры
	{
		ClearFigure(figure1, 3, 2);
		goto FigureCreate;
	}
	cout << endl << endl;

	cout << "the shown figure: " << endl << endl;

	for (int i = 0; i < ROW; i++)		// Вывод фигуры
	{
		for (int j = 0; j < COL; j++)
		{
			if (figure1[i][j] == 1)
			{
				cout << char(219);
			}
			else if (figure1[i][j] == -1)
			{

			}
		}
		cout << endl;
	}
	return 0;
}

int ClearFigure(int figure[][COL], const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++) // зачистка массива для фигуры
	{
		for (int j = 0; j < COL; j++)
		{
			figure[i][j] = -1;
		}
	}
	return figure[ROW][COL];
}


bool CheckFigure(int fig[][COL])
{
	if (fig[0][0] == 1 && fig[0][1] == 1 && fig[1][0] == 1 && fig[2][1] == 1) return false;
	else if (fig[0][0] == 1 && fig[1][1] == 1 && fig[0][1] == 1 && fig[2][0] == 1) return false;
	else if (fig[0][1] == 1 && fig[1][0] == 1 && fig[2][0] == 1 && fig[2][1] == 1) return false;
	else if (fig[0][0] == 1 && fig[1][1] == 1 && fig[2][0] == 1 && fig[2][1] == 1) return false;
	else if (fig[0][1] == 1 && fig[0][1] == 1 && fig[2][0] == 1 && fig[2][1] == 1) return false;

}
