#include <iostream>
using namespace std;

struct Tablica
{
	char symbol;
	bool odwiedzony;
};

class Plansza
{
private:
	Tablica **P;
	Tablica **W;
	int szerokosc;
	int wysokosc;
	int y; //wyskosc
	int x; //szerokosc
	int wynik;
	int licz;
public:
	Plansza(int szer, int wys)
	{
		szerokosc = szer;
		wysokosc = wys;
		x = 0;
		y = 0;
		wynik = 0;

		P = new Tablica*[wysokosc];
		for (int i = 0; i < wysokosc; i++) P[i] = new Tablica[szerokosc];

		for (int i = 0; i < wysokosc; i++)
			for (int j = 0; j < szerokosc; j++)
			{
				P[i][j].symbol = '.';
				P[i][j].odwiedzony = false;
			}
				


		W = new Tablica*[wysokosc];
		for (int i = 0; i < wysokosc; i++) W[i] = new Tablica[szerokosc];

		for (int i = 0; i < wysokosc; i++)
			for (int j = 0; j < szerokosc; j++)
				W[i][j].symbol = '.';
	}
	~Plansza()
	{
		for (int i = 0; i < wysokosc; i++)
		{
			delete P[i];
			delete W[i];
		}
		delete[] P;
		delete[] W;
	}
	void pokaz()
	{
		for (int i = 0; i < wysokosc; i++)
		{
			for (int j = 0; j < szerokosc; j++)
			{
				cout << P[i][j].symbol << " ";
			}
			cout << "\n";
		}
	}
	void wypelnij(char znak)
	{
		if (x < szerokosc)
		{
			P[y][x].symbol = znak;
			x++;
		}
		if (x == szerokosc)
		{
			y++;
			x = 0;
		}
	}
	void wykonaj_ture(int tura)
	{
		while (tura--)
		{
			for (int i = 0; i < wysokosc; i++)
			{
				for (int j = 0; j < szerokosc; j++)
				{
					int licznik = 0;

					if ((i == 0) && (j == 0))
						{
							if (P[i][j + 1].symbol == '#') licznik++;
							if (P[i + 1][j].symbol == '#') licznik++;
							if (P[i + 1][j + 1].symbol == '#') licznik++;
							zmien(i, j, licznik);
						}
					else if ((i == 0) && (j == szerokosc - 1))
						{
							if (P[i][j - 1].symbol == '#') licznik++;
							if (P[i + 1][j].symbol == '#') licznik++;
							if (P[i + 1][j - 1].symbol == '#') licznik++;
							zmien(i, j, licznik);
						}
					else if ((i == wysokosc - 1) && (j == 0))
						{
							if (P[i][j + 1].symbol == '#') licznik++;
							if (P[i - 1][j].symbol == '#') licznik++;
							if (P[i - 1][j + 1].symbol == '#') licznik++;
							zmien(i, j, licznik);
						}
					else if ((i == wysokosc - 1) && (j == szerokosc - 1))
						{
							if (P[i][j - 1].symbol == '#') licznik++;
							if (P[i - 1][j].symbol == '#') licznik++;
							if (P[i - 1][j - 1].symbol == '#') licznik++;
							zmien(i, j, licznik);
						}

					else if ((i == 0) && (j != 0 || j != szerokosc))
						{
							if (P[i][j - 1].symbol == '#') licznik++;
							if (P[i][j + 1].symbol == '#') licznik++;
							if (P[i + 1][j - 1].symbol == '#') licznik++;
							if (P[i + 1][j].symbol == '#') licznik++;
							if (P[i + 1][j + 1].symbol == '#') licznik++;
							zmien(i, j, licznik);
						}
					else if ((i == wysokosc - 1) && (j != 0 || j != szerokosc - 1))
						{
							if (P[i][j - 1].symbol == '#') licznik++;
							if (P[i][j + 1].symbol == '#') licznik++;
							if (P[i - 1][j - 1].symbol == '#') licznik++;
							if (P[i - 1][j].symbol == '#') licznik++;
							if (P[i - 1][j + 1].symbol == '#') licznik++;
							zmien(i, j, licznik);
						}
					else if ((j == 0) && (i != 0 || i != wysokosc - 1))
						{
							if (P[i - 1][j].symbol == '#') licznik++;
							if (P[i + 1][j].symbol == '#') licznik++;
							if (P[i - 1][j + 1].symbol == '#') licznik++;
							if (P[i][j + 1].symbol == '#') licznik++;
							if (P[i + 1][j + 1].symbol == '#') licznik++;
							zmien(i, j, licznik);
						}
					else if ((j == szerokosc - 1) && (i != 0 || i != wysokosc - 1))
						{
							if (P[i - 1][j].symbol == '#') licznik++;
							if (P[i + 1][j].symbol == '#') licznik++;
							if (P[i - 1][j - 1].symbol == '#') licznik++;
							if (P[i][j - 1].symbol == '#') licznik++;
							if (P[i + 1][j - 1].symbol == '#') licznik++;
							zmien(i, j, licznik);
						}

					else
						{
							if (P[i - 1][j - 1].symbol == '#') licznik++;
							if (P[i - 1][j].symbol == '#') licznik++;
							if (P[i - 1][j + 1].symbol == '#') licznik++;
							if (P[i][j - 1].symbol == '#') licznik++;
							if (P[i][j + 1].symbol == '#') licznik++;
							if (P[i + 1][j - 1].symbol == '#') licznik++;
							if (P[i + 1][j].symbol == '#') licznik++;
							if (P[i + 1][j + 1].symbol == '#') licznik++;
							zmien(i, j, licznik);
						}
				}
			}
			zamiana_pol();
		}
	}
	void zamiana_pol()
	{
		for (int i = 0; i < wysokosc; i++)
		{
			for (int j = 0; j < szerokosc; j++)
			{
				P[i][j].symbol = W[i][j].symbol;
			}
		}
	}
	void zmien(int i, int j, int licznik)
	{
		if (licznik == 3) W[i][j].symbol = '#';
		else if (licznik == 2) W[i][j].symbol = P[i][j].symbol;
		else W[i][j].symbol = '.';
	}
	void sprawdzenie_grup()
	{
		for (int i = 0; i < wysokosc; i++)
		{
			for (int j = 0; j < szerokosc; j++)
			{
				if ((P[i][j].symbol == '#') && (P[i][j].odwiedzony == false))
				{
					licz = 1;
					szukaj(i, j);
					if (wynik < licz) wynik = licz;
				}
			}
		}
		cout << wynik;
	}
	void szukaj(int a, int b)
	{
		P[a][b].odwiedzony = true;
		for (int i = -2; i < 3; i++)
		{
			for (int j = -2; j < 3; j++)
			{
				if (((a + i) < 0) || ((a + i) >= wysokosc) || ((b + j) < 0) || ((b + j) >= szerokosc));
				//cout << "Wychodze poza tablice";
				else
					if ((P[a + i][b + j].symbol == '#') && (P[a + i][b + j].odwiedzony == false))
					{
						szukaj(a + i, b + j);
						licz++;
					}
			}
		}
	}
	
};

int main()
{
	int szer, wys;
	int liczba_tur;
	char znak;

	cin >> szer;
	cin >> wys;
	cin >> liczba_tur;
	Plansza plansza(szer, wys);
	//plansza.pokaz();

	while (cin >> znak)
	{
		plansza.wypelnij(znak);
	}
	/*cout << "\n";
	plansza.pokaz();*/
	plansza.wykonaj_ture(liczba_tur);
	//cout << "\n";
	//plansza.pokaz();
	//cout << "\n";
	plansza.sprawdzenie_grup();
	/*cout << "\n";*/

	/*system("PAUSE");*/
	return 0;
}