#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

#define START_UP_CAPITAL 1000


float EMA_value(vector<float> temp_data,int N,int Now)
{
	float alfa = 2 / (N + 1);
	float denominator = 0;
	float numerator = 0;
	int iterator = Now;

	for (int i = 0; i < N; i++)
	{
		//if (N == 10)
		numerator = numerator + temp_data[Now] * pow((1 - alfa), i);
		denominator = denominator + pow((1 - alfa), i);
		Now--;
		
	}
	return numerator/denominator;
};
int main()
{
	ifstream file_in("Dane_in.csv");
	ofstream file_out("MACDiSignal.csv");
	string line;
	string token;
	vector<float> MACD,temp_data;
	int signal_iterator = 0;
	float last_macd_value = 0; //m�g�bym po prostu wykorzystywa� vector macd ale tak b�dzie �adniej
	float last_singal_value = 0; //do sprawdzenia z kt�rej strony linie sie przeciely
	float macd_value = 0;
	float signal_value = 0;

	float budget = START_UP_CAPITAL;
	float income = 0;
	int number_of_actions = 0;

	if (!file_in.is_open()) // sprawdzenie czy uda�o si� otworzy� plik
	{
		cout << "Nie uda�o si� otworzy� pliku!" << endl;
		return 1;
	}
	getline(file_in,line); //pierwsza linijka zawieraj�ce opis kolumn


	for (int i = 0;getline(file_in, line);i++) //pobieranie kolejnych linii z pliku
	{
		istringstream ss(line);
		for (int j = 0; getline(ss, token, ';'); j++) //pobieranie kolejnych wyra�e� rozdzielonych �rednikiem
		{
			if (i > 25 && j==0) //zapisanie dat w pierwszej kolumnie outputu
			{
				file_out << token << ';';
			}
			if (j == 2) //wzi�cie trzeciej kolumny
			{	
				temp_data.push_back(stof(token));
				if (i>25)
				{
					last_macd_value = macd_value;

					macd_value = EMA_value(temp_data, 13, i) - EMA_value(temp_data, 27, i);
					MACD.push_back(macd_value);
					file_out << macd_value << ';'; //zapisanie w drugiej kolumnie warto�ci MACD
					if (i > 34) //zapisanie w outputcie w 3 kolumnie warto�ci z signala, dla startu b�d� to zera poniewa� jest liczony na podstawie macd
					{
						last_singal_value = signal_value;

						signal_value = EMA_value(MACD, 10, MACD.size() - 1);
						file_out << signal_value << endl;
					}
					else
					{
						file_out << 0 << endl; 
					}

						if (last_singal_value > last_macd_value && signal_value < macd_value) //Kupowanie akcji
						{
							number_of_actions = budget / temp_data.back();
							budget = budget - temp_data.back() * number_of_actions;
						}
						if(last_singal_value < last_macd_value && signal_value > macd_value) //sprzedaz akcji
						{
							budget = budget + number_of_actions * temp_data.back();
							number_of_actions = 0;
						}

					
				}
				
			}
		}
	}

	income = budget - START_UP_CAPITAL;
	cout << income << endl;
	file_out.close();
	file_in.close();
}

