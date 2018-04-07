#include <iostream>
#include <random>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

vector<int> wylosowane;
vector<int> opanowane;
int counter=0;
int n;
int randomInt(int max) 
{
	static default_random_engine e{};
	uniform_int_distribution<int> d(1, max);
	return d(e);
}
bool czypelne(const vector <int> &wektor, int n)
{
	if (wektor.size()==n)
	{
		return true;
	}
	return false;
}
bool zawiera(vector<int> &wektor, int a)
{
	
	for (int i = 0; i < wektor.size(); i++)
	{
		if (wektor[i] == a)
		{
			return true;
			break;
		}
	}
	wektor.push_back(a);
	return false;
}
void zapis(int n)
{
	std::ofstream plik;
	plik.open("stan.txt");
	if (plik)
	{
		plik << counter << endl;
		plik << n << endl;
		plik << wylosowane.size() << endl;
		for (int i = 0; i < wylosowane.size(); i++)
		{
			plik << wylosowane[i] << endl;
		}
		plik << opanowane.size() << endl;
		for (int i = 0; i < opanowane.size(); i++)
		{
			plik << opanowane[i] << endl;
		}
	}
	plik.close();
}
void odczyt()
{
	int temp;
	int temp2;
	std::ifstream in("stan.txt");
	in >> counter;
	in >> n;
	in >> temp;
	for (int i = 0; i < temp; i++)
	{
		in >> temp2;
		wylosowane.push_back(temp2);
	}
	in >> temp;
	for (int i = 0; i < temp; i++)
	{
		in >>temp2;
		opanowane.push_back(temp2);
	}
	in.close();
}

int main()
{
	char znak;
	cout << "Zaczynasz (n)owe, czy (k)ontynuujesz poprzednie?(n/k)";
	cin >> znak;
	if (znak == 'n')
	{


		cout << "Od zera do: ";
		cin >> n;
	}
	else if (znak=='k')
	{
		odczyt();
	}
	do {
		do {
			do {
				int a;
				do {
					
					a = randomInt(n);
				} while (zawiera(wylosowane, a));
				cout << a << endl;
				cout << "Umiesz to zagadnienie?(t/n)";
				cin >> znak;
				if (znak == 't')
				{
					opanowane.push_back(a);
				}
				cout << "Czy chcesz kontynuowac?(t/n)";
				cin >> znak;
				if (znak == 'n')
				{
					zapis(n);
					cout << "zapisane, mozesz wylaczyc";
				}
			}while (czypelne(wylosowane, n)==false);
			wylosowane = opanowane;
		}while (!czypelne(opanowane, n));
		counter++;
		wylosowane.clear();
		opanowane.clear();
	} while (counter < 5);
	cout << "DZIK!";
	return 0;
}