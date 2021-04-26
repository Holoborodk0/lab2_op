#include<iostream>
#include<fstream>
#include<string>

using namespace std;

string* ReadTeams(string file1, string file2, int kilk);
int* ReadResults(string file1, string file2, int kilk);
void Out(int* mas, int kilk);

int main()
{
	int teams = 20;
	string path_file1 = "C:\\C++\\lab_op_2\\csv files\\premier_league1.csv";
	string path_file2 = "C:\\C++\\lab_op_2\\csv files\\premier_league2.csv";
	string path_res = "result.csv";
	string* mas_teams = ReadTeams(path_file1, path_file2, teams);
	int* mas_reults = ReadResults(path_file1, path_file2, teams);
	/*Out(mas_reults, teams);*/
}

string* ReadTeams(string file1, string file2, int kilk)
{
	int curr_team = 0;
	string* mas = new string[kilk];
	string mas_files[2] = { file1, file2 };
	for (int i = 0; i < 2; i++)
	{
		ifstream fIn(mas_files[i]);
		if (!fIn.is_open()) cout << "Cannot open";
		else cout << "Open" << endl;
		string s_curr, s_team;
		while (!fIn.eof())
		{
			getline(fIn, s_curr);
			if (s_curr.size() > 2)
			{
				for (int j = 0; j < s_curr.size(); j++)
				{
					if (isalpha(s_curr[j]) || isspace(s_curr[j]))
					{
						s_team += s_curr[j];
					}
				}
				if (s_team.size() != 0)
				{
					mas[curr_team] = s_team;
					curr_team++;
					s_team = "";
				}
			}
		}
		fIn.close();
	}
	return mas;
}

void Out(int* mas, int kilk)
{
	for (int i = 0; i < kilk; i++)
	{
		cout << mas[i] << "  ";
	}
}

int* ReadResults(string file1, string file2, int kilk)
{
	int curr_team_game = 0;
	int* mas = new int[kilk];
	string mas_files[2] = { file1, file2 };
	for (int i = 0; i < 2; i++)
	{
		ifstream fIn(mas_files[i]);
		if (!fIn.is_open()) cout << "Cannot open";
		else cout << "Open" << endl;
		string s_curr, s_team;
		char point = ',';
		while (!fIn.eof())
		{
			getline(fIn, s_curr);
			if (s_curr.size() > 2)
			{
				int sum = 0;
				for (int j = 0; j < s_curr.size(); j++)
				{
					if (!isalpha(s_curr[j]) && !isspace(s_curr[j]) && s_curr[j] != point)
					{
						s_team += s_curr[j];
						if (s_team.size() == 3)
						{
							if (s_team[0] > s_team[2])
							{
								sum += 3;
								s_team = "";
							}
							else if (s_team[0] == s_team[2])
							{
								sum += 1;
								s_team = "";
							}
							else s_team = "";;
						}
					}
				}
				mas[curr_team_game] = sum;
				curr_team_game++;
			}
			else continue;
		}
		fIn.close();
	}
	return mas;
}