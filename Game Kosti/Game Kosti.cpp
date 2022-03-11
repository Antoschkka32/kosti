#include<stdio.h>
#include<locale>
#include<ctime>


void generk(int* kubiki) {
	for (int i = 0; i < 5; i++)
	{
		kubiki[i] = 1 + rand() % (6 - 1 + 1);
	}
}

void vivod(int* kubiki)
{
	printf("\n");
	printf(" -------    -------    -------    -------    ------- \n");
	for (int i=0; i < 5; i++) {
		switch (kubiki[i])
		{
		case 1:printf("|       |  "); break;
		case 2:printf("|     * |  "); break;
		case 3:printf("| *     |  "); break;
		case 4:printf("| *   * |  "); break;
		case 5:printf("| *   * |  "); break;
		case 6:printf("| * * * |  "); break;
		default:
			break;
		}
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		switch (kubiki[i])
		{
		case 1:printf("|   *   |  "); break;
		case 2:printf("|       |  "); break;
		case 3:printf("|   *   |  "); break;
		case 4:printf("|       |  "); break;
		case 5:printf("|   *   |  "); break;
		case 6:printf("|       |  "); break;
		default:
			break;
		}
	}
	printf("\n");
	for (int i = 0; i < 5; i++) {
		switch (kubiki[i])
		{
		case 1:printf("|       |  "); break;
		case 2:printf("| *     |  "); break;
		case 3:printf("|     * |  "); break;
		case 4:printf("| *   * |  "); break;
		case 5:printf("| *   * |  "); break;
		case 6:printf("| * * * |  "); break;
		default:
			break;
		}
	}
	printf("\n");
	printf(" -------    -------    -------    -------    ------- \n");

}

int obrabotka(int* mas) 
{
	int count = 0;
	for (int k = 0; k < 6; k++) {
		if (mas[k] > 2) {
			switch (mas[k])
			{
			case 3: count += (k + 1) * 10;
				if (k == 0) count *= 10;
				break;
			case 4: count += (k + 1) * 20;
				if (k == 0) count *= 10;
				break;
			case 5: count += (k + 1) * 100;
				if (k == 0) count *= 10;
				break;
			default:
				break;
			}
		}
		else if (k == 0) count += (k + 1) * 10 * mas[k];
		else if (k == 4) count += (k + 1) * mas[k];
	}
	return count;
}

void obnull( int* mas) {
	for (int k = 0; k < 6; k++)mas[k] = 0;
}

int main() {
	setlocale(0, "");
	srand(time(0));
	int regim=1,n =1;
	int mas[6] = {0};
	int kubiki[5] = { 0 };
	int countmen = 0, countcom = 0;
	int f=1;
	char prav;

	printf("Это игра в Кости\n\n");

	printf("Хотите ознакоомиться с правилами игры ?\ny или n : "); scanf("%s", &prav);

	if (prav == 'y') {
		printf("Каждый ход начинается с броска сразу 5 кубиков.\nПосле того бросок анализируется на наличие очковых комбинаций.\nОчки приносят кубики достоинством 1 (10 очков) и 5 (5 очков),\nа также 3 и более кубика одного достоинства, выпавшие в текущем броске.\n");
		printf("При этом 3 одинаковых кубика дают очки по номиналу кубика умноженного на 10\n(т.е. три четверки дадут 40 очков, а три единицы 100),\nчетыре  на 20, пять на 100\n\n");
	}

	printf("Выберите противника\nпротив компьютера - 1\nпротив другого игрока - 2\nВаш выбор: ");
	do {
		if (regim < 1 || regim>2)printf("Требуется повторный ввод: ");
		scanf("%d", &regim);
	} while (regim < 1 || regim>2);

	printf("\n");

	switch(regim)
	{
	case 1: 
		char name[20];
		
		printf("Введите ник игрока: ");
		scanf("%s", &name);
		printf("\n");
		do {
			printf("Бросок номер %d.\nВведите 1 чтобы бросить кубик: ", n);
			do {
				if (f != 1)printf("Повторите ввод: ");
				scanf("%d", &f);
			} while (f != 1);
			printf("\n");
			printf("Бросок %s\n", name);
			generk(kubiki);
			printf("Выпавшие кости: ");
			vivod(kubiki);
			for (int k = 0; k < 5; k++)  mas[kubiki[k]-1] += 1;
			printf("\n");

			countmen += obrabotka(mas);

			printf("Количество очков набранных %s: %d\n",name, countmen);
			printf("\n");
			obnull(mas);


			printf("Бросок компьютера \n");
			generk(kubiki);
			printf("Выпавшие кости: ");
			vivod(kubiki);
			for (int k = 0; k < 5; k++)  mas[kubiki[k] - 1] += 1;

			printf("\n");
			countcom += obrabotka(mas);

			printf("Количество очков набранных компьютером: %d\n", countcom);
			printf("\n");
			obnull(mas);
			n++;
		} while (countmen < 1000 && countcom < 1000);
		if (countmen > 1000 && countcom > 1000)printf("Победила дружба человека и компьютера !");
		else if (countcom > 1000)printf("Победил компьютер");
		else printf("Победил %s!!!", name);
		
		break;
	case 2:
		char name1[20], name2[20];

		printf("Введите никнейм первого игрока: ");
		scanf("%s", &name1);
		printf("\n");

		printf("Введите никнейм второго игрока: ");
		scanf("%s", &name2);
		printf("\n");
		do {
			printf("Бросок номер %d для игрока %s.\nВведите 1 чтобы бросить кубик: ", n, name1);
			do {
				if (f != 1)printf("Повторите ввод: ");
				scanf("%d", &f);
			} while (f != 1);
			
			generk(kubiki);
			printf("Выпавшие кости: ");
			vivod(kubiki);
			for (int k = 0; k < 5; k++)  mas[kubiki[k] - 1] += 1;
			printf("\n");

			countmen += obrabotka(mas);

			printf("Количество очков набранных игроком %s: %d\n", name1, countmen);
			printf("\n");
			obnull(mas);


			printf("Бросок номер %d для игрока %s.\nВведите 1 чтобы бросить кубик: ", n, name2);
			do {
				if (f != 1)printf("Повторите ввод: ");
				scanf("%d", &f);
			} while (f != 1);

			generk(kubiki);
			printf("Выпавшие кости: ");
			vivod(kubiki);
			for (int k = 0; k < 5; k++)  mas[kubiki[k] - 1] += 1;

			printf("\n");
			countcom += obrabotka(mas);

			printf("Количество очков набранных игроком %s: %d\n", name2,countcom);
			printf("\n");
			obnull(mas);
			n++;
			
		} while (countmen < 1000 && countcom < 1000);
		if (countmen > 1000 && countcom > 1000)printf("Победила дружба!!!");
		else if (countcom > 1000)printf("Победил игрок %s!!!", name2);
		else printf("Победил игрок %s!!!", name1);

		break;
	default:
		break;
	}
	return 1;
}
