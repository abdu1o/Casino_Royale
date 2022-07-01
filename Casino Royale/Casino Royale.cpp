#include <iostream>
#include <ctime>
#include <random>
#include <algorithm>
#include <stdlib.h>
#include <windows.h>
#include <iomanip>
#pragma comment(lib, "winmm.lib")
using namespace std;

//(1)---------------------------------------
//int main()
//{
//	srand(time(NULL));
//	int arr_rand[10], arr_new[10], num = 0;
//
//	for (int j = 0; j < 10; j++)
//	{
//		arr_rand[j] = - 10 + rand() % 51;
//	}
//
//	cout << "Ur array: ";
//	for (int i : arr_rand)
//	{
//		cout << i << " ";
//		if (i < 0)
//		{
//			arr_new[num] = i;
//			num++;
//		}
//	}
//
//	for (int i : arr_rand)
//	{
//		if (i == 0)
//		{
//			arr_new[num] = i;
//			num++;
//		}
//	}
//
//	for (int i : arr_rand)
//	{
//		if (i > 0)
//		{
//			arr_new[num] = i;
//			num++;
//		}
//	}
//
//	cout << "\nUr new array: ";
//	for (int i : arr_new)
//	{
//		cout << i << " ";
//	}
//}
//------------------------------------------


//(2)---------------------------------------
//int main()
//{
//    int arr1[1], arr2[2], arr3[10];
//
//    for (int j = 0; j < 5; j++)
//	{
//        arr1[j] = rand() % 10;
//        arr2[j] = rand() % 10;
//	}
//
//    cout << "First array: ";
//    for (int i : arr1)
//    {
//        cout << i << " ";
//    }
//    cout << "\nSecond array: ";
//    for (int i : arr2)
//    {
//        cout << i << " ";
//    }
//
//    int num1 = 0, num2 = 0, num3 = 0;
//
//    while (num1 < 5)
//    {
//        for (int i = 0; i < 5; i++)
//        {                     
//            if (arr1[i] == arr2[num1])
//            {
//                for (int k = 0; k < 10; k++)
//                {
//                    if (arr1[i] == arr3[k])
//                    {
//                        num2++;
//                    }    
//                }   
//                if (num2 == 0) 
//                {
//                    arr3[num3] = arr1[i];
//                    num3++;
//                }
//            }
//        }
//        num1++;
//    }
//
//    cout << "\n\nGeneral array: ";
//    for (int i : arr3)
//    {
//        cout << i << " ";
//    }
//}
//------------------------------------------






//(3)------Casino         Royale------------

//MUSIC=====================================
DWORD WINAPI Music_Menu(void* param)
{
	PlaySoundA("menu.WAV", NULL, SND_ASYNC | SND_LOOP);
	return 0;
}
//==========================================

//FUNCTIONS=================================
void Menu();
void EasyGame();
void MediumGame();
void HardGame();
void Stats();
//==========================================

//VARIABLES=================================
double money = 1500;
int win = 0;
int lose = 0;
int arr_rand1[10];
int arr_rand2[10];
int arr_rand3[10];
//==========================================

int main()
{
	system("title Casino Royale");
	CreateThread(0, 0, Music_Menu, 0, 0, 0);
	Menu();
}

void Menu()
{
	system("cls");

	int choice;
	cout << "Welcome to our lottery! \nChoose the difficulty you want to play on: \n";
	cout << "\n$=====--=====--=====$\n";
	cout << "\n[1] Easy (x1.5 money boost) \n[2] Medium (x3 money boost) \n[3] Daddy lend me (x10 money boost) \n[4] Stats  \n[5] Author \n";
	cout << "\n$=====--=====--=====$\n";
	cin >> choice;

	switch (choice)
	{
	case(1):
		system("cls");
		EasyGame();
		break;

	case(2):
		system("cls");
		MediumGame();
		break;

	case(3):
		system("cls");
		HardGame();
		break;

	case(4):
		system("cls");
		Stats();
		break;

	case(5):
		system("cls");
		system("start https://github.com/abdu1o");
		Menu();
		break;

	default:
		system("cls");
		Menu();
		break;
	}

	system("pause");
}

void EasyGame()
{
	system("cls");

	if (money < 200)
	{
		cout << "\n$=====--=====--=====$\n";
		cout << "\nSorry, but you can't play this game (not enough money)\n";
		system("pause");
		Menu();
	}

	char easy_pay;
	cout << "\n$=====--=====--=====$\n";
	cout << "\nYour cash >> " << money << "$";
	cout << "\n\n$=====--=====--=====$\n";
	cout << "\n10 numbers are guessed in the range from 1 to 20. \nTo collect your winnings, guess at least 3 numbers (the number of attempts is 5).";
	cout << "\nEntry for easy play - $200 \nDo you want to continue? [y/n]\n";
	cin >> easy_pay;

	if (easy_pay == 'y')
	{
		money = money - 200;
		srand(time(NULL));

		int random;

		for (int i = 0; i < 10; i++)
		{
			arr_rand1[i] = 0;
		}


		for (int i = 0; i < 10; i++)
		{
			random = 1 + rand() % 21;

			for (int j = 0; j < 10; j++)
			{
				if (random == arr_rand1[j])
				{
					while (random == arr_rand1[j])
					{
						random = 1 + rand() % 21;
					}
				}
				else
				{
					continue;
				}
			}
			arr_rand1[i] = random;
		}

		system("cls");

		int num = 0, win_count = 0, arr_num[5];

		cout << "\n$=====--=====--=====$\n";
		cout << "\nEnter your numbers: ";

		for (int i = 0; i < 5; i++)
		{
			cin >> arr_num[i];
		}

		for (int i : arr_rand1)
		{
			for (int j : arr_num)
			{
				if (i == j && j != num)
				{
					num = j;
					win_count++;
				}
			}
		}

		if (win_count == 3)
		{
			system("cls");
			cout << "Congratulations, You win! \n$=====--=====--=====$\n Your cash: " << money << " + " << 200 * 1.5 << "$\n\n";
			money = money + 200 * 1.5;
			win++;
			system("pause");
			Menu();
		}
		else
		{
			system("cls");
			cout << "Better luck next time \n$=====--=====--=====$\n Your cash: " << money << "$\n\n";
			lose++;
			system("pause");
			Menu();
		}

	}
	else if (easy_pay == 'n')
	{
		system("cls");
		Menu();
	}
	else
	{
		system("cls");
		MediumGame();
	}
}

void MediumGame()
{
	system("cls");

	if (money < 350)
	{
		cout << "\n$=====--=====--=====$\n";
		cout << "\nSorry, but you can't play this game (not enough money)\n";
		system("pause");
		Menu();
	}

	char medium_pay;
	cout << "\n$=====--=====--=====$\n";
	cout << "\nYour cash >> " << money << "$";
	cout << "\n\n$=====--=====--=====$\n";
	cout << "\n10 numbers are guessed in the range from 1 to 44. \nTo collect your winnings, guess at least 3 numbers (the number of attempts is 6).";
	cout << "\nEntry for easy play - $350 \nDo you want to continue? [y/n]\n";
	cin >> medium_pay;

	if (medium_pay == 'y')
	{
		money = money - 350;
		srand(time(NULL));

		int random;

		for (int i = 0; i < 10; i++)
		{
			arr_rand2[i] = 0;
		}


		for (int i = 0; i < 10; i++)
		{
			random = 1 + rand() % 45;

			for (int j = 0; j < 10; j++)
			{
				if (random == arr_rand2[j])
				{
					while (random == arr_rand2[j])
					{
						random = 1 + rand() % 45;
					}
				}
				else
				{
					continue;
				}
			}
			arr_rand2[i] = random;
		}

		system("cls");

		int num = 0, win_count = 0, arr_num[6];


		cout << "\nEnter your numbers: ";

		for (int i = 0; i < 6; i++)
		{
			cin >> arr_num[i];
		}

		for (int i : arr_rand2)
		{
			for (int j : arr_num)
			{
				if (i == j && j != num)
				{
					num = j;
					win_count++;
				}
			}
		}

		if (win_count == 3)
		{
			system("cls");
			cout << "Congratulations, You win! \n$=====--=====--=====$\n Your cash: " << money << " + " << 350 * 3 << "$\n\n";
			money = money + 350 * 3;
			win++;
			system("pause");
			Menu();
		}
		else
		{
			system("cls");
			cout << "Better luck next time \n$=====--=====--=====$\n Your cash: " << money << "$\n\n";
			lose++;
			system("pause");
			Menu();
		}

	}
	else if (medium_pay == 'n')
	{
		system("cls");
		Menu();
	}
	else
	{
		system("cls");
		MediumGame();
	}
}

void HardGame()
{
	system("cls");

	if (money < 500)
	{
		cout << "\n$=====--=====--=====$\n";
		cout << "\nSorry, but you can't play this game (not enough money)\n";
		system("pause");
		Menu();
	}

	char hard_pay;
	cout << "\n$=====--=====--=====$\n";
	cout << "\nYour cash >> " << money << "$";
	cout << "\n\n$=====--=====--=====$\n";
	cout << "\n10 numbers are guessed in the range from 1 to 69. \nTo collect your winnings, guess at least 3 numbers (the number of attempts is 9).";
	cout << "\nEntry for easy play - $500 \nDo you want to continue? [y/n]\n";
	cin >> hard_pay;

	if (hard_pay == 'y')
	{
		money = money - 500;
		srand(time(NULL));

		int random;

		for (int i = 0; i < 10; i++)
		{
			arr_rand3[i] = 0;
		}


		for (int i = 0; i < 10; i++)
		{
			random = 1 + rand() % 70;

			for (int j = 0; j < 10; j++)
			{
				if (random == arr_rand3[j])
				{
					while (random == arr_rand3[j])
					{
						random = 1 + rand() % 70;
					}
				}
				else
				{
					continue;
				}
			}
			arr_rand3[i] = random;
		}

		system("cls");

		int num = 0, win_count = 0, arr_num[9];


		cout << "\nEnter your numbers: ";

		for (int i = 0; i < 9; i++)
		{
			cin >> arr_num[i];
		}

		for (int i : arr_rand3)
		{
			for (int j : arr_num)
			{
				if (i == j && j != num)
				{
					num = j;
					win_count++;
				}
			}
		}

		if (win_count == 3)
		{
			system("cls");
			cout << "Congratulations, You win! \n$=====--=====--=====$\n Your cash: " << money << " + " << 500 * 10 << "$\n\n";
			money = money + 350 * 3;
			win++;
			system("pause");
			Menu();
		}
		else
		{
			system("cls");
			cout << "Better luck next time \n$=====--=====--=====$\n Your cash: " << money << "$\n\n";
			lose++;
			system("pause");
			Menu();
		}

	}
	else if (hard_pay == 'n')
	{
		system("cls");
		Menu();
	}
	else
	{
		system("cls");
		MediumGame();
	}
}

void Stats()
{
	cout << "\n$=====--=====--=====$\n";
	cout << "\nYour cash: " << money << "$\n";
	cout << "Your wins: " << win << endl;
	cout << "Your losses: " << lose << endl;
	cout << "\n$=====--=====--=====$\n";

	system("pause");
	Menu();
}