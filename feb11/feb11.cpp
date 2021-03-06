﻿/*Настали тяжелые времена. Мир опустился во мрак, казалось бы самого страшного развития событий. 
В те времена у людей не было ни веры, ни надежды на успешное завершение всех усилий, что были потрачены в течении такого длительного срока.
Казалось, что испытания были настолько суровы, что скромные доспехи, состоящии из одной прочитанной статьи на хабре и учебника по С++, в которые был облачен автор, в момент начала этой удивительной итории - точно не смогут спасти его и удержать от самого крупного сражения в его жизни, от которого зависела бы его судьба.

*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <random>
#include <Windows.h>
using::std::cout;
using::std::cin;
namespace shooters_task//тут лежат все функции, которые участвует в состязании по стрельбе:)
{
	void results(int** n, int* n1, int a, int b)//эта штука выводит результаты, подсчитывая сумму всех выстрелов
	{
		int s;
		for (int i = 0; i < a; i++)//цикл, который заполняет массив n1 результатами
		{
			s = 0;
			for (int j = 0; j < b; j++)//цикл, который заполняет массив n1 результатами
				s += n[i][j];
			n1[i] = s;
		}
		cout << "\nResults: ";
		for (int i = 0; i < a; i++)//выводит массив n1 с результами
			cout << n1[i] << " ";
	}
	void winners(int* n, int a) //Туть выводится номер виннера
	{
		int max, maxI;
		max = n[0];//номер победителя
		for (int i = 0; i < a; i++) //проверяет массив на максимальный результат
		{
			if (n[i] > max)
				max = n[i];
		}
		cout << "\n" << max << "\nWINNERS:\n";
		for (int i = 0; i < a; i++) //выводит и проверяет номер стрелка с максимальным результом
		{
			if (n[i] == max)
			{
				cout << "Shooter number " << i + 1 << std::endl;
			}
		}

	}
}
namespace first_task // туть лежат все функции из первого задания в варианте:)
{
	void enter_values(int& rows, int& cols, int& a, int& b) //в зал входят значения для рандома и количество строк\колонок
	{
		cout << "Левая граница значений = ";
		cin >> a;
		cout << "Правая граница значений = ";          // Левая и правая граница значений в матрице
		cin >> b;
		cout << "Сколько столбцов X строк = ";
		cin >> rows;
		cout << "\n";
		cols = rows;                        //Количество столбиков в матрице
	}
	void show_arr(int** arr, int rows, int cols) // на экран объявляется массивчек
	{
		cout << "Матрица:\n";

		for (int i = 0; i < rows; i++) //"напиши здесь: объявляется массивчек"
		{
			arr[i] = new int[cols];
		}
	}
	void fill_arr(int** arr, int rows, int cols, int a, int b) //На экран со свитой выходит массивчек и заполняет себя вкусностями(ну, значениями, ну шучу я так, да ладно вам)
	{
		for (int i = 0; i < rows; i++) 
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = a + rand() % (b - a + 1); //МУЗЫКА ГРОМЧЕ ГЛАЗА ЗАКРЫТЫ ЭТО РАНДОМ
				cout << arr[i][j] << "\t";
			}
			cout << std::endl;
		}
	}
	void red_area_analyze(int** arr, int rows) //Это был большой красный зал. А в центре виднелись 2 больших красных треугольника, которые содержали в себе все значения ниже главной диагонали. Это и было целью нашего визита. 
	{
		cout << "Ниже главной диагонали:\n";
		//За руку в залу вошли все значения ниже главной диагонали.
		for (int i = 0; i < rows; i++) 
		{ 
			for (int j = 0; j < rows; j++)
			{
				if (i >= rows - j)  cout << arr[i][j] << " ";
			}
		}
		cout << std::endl;
		system("pause");//внезапно все замирает, зал погружается в тишину. Все ждали следующего действия.
	}
	//Из дальней двери появляется небольшой белый элемент. Существо было причудливое, похожее на пушистое облачко, и заняло свое законное место в этом огромном красном зале.
	void red_area_show_element(int** arr, int rows, int& min, int& imin, int& jmin) 
	{
		cout << "Минимальный положительный элемент: ";
		for (int i = 0; i < rows; i++) //Все вокруг внимательно смотрят на него
		{
			for (int j = 0; j < rows; j++)
			{
				if (i >= rows - j)
				{


					if (arr[i][j] > 0) //каждый посчитал должным, сравнить свою величину с ним, но не нашлось ничего меньшего, чем это таинственное облако
					{
						if (arr[i][j] < min)
						{
							min = arr[i][j];
							imin = i;
							jmin = j;
						}
					}
				}
			}
		}
		if (min > 0 && min != INT_MAX) //Оставалось последнее испытание. Хватит ли существу массы, чтобы выдержать ношу, что выпала на его долю? 
		{
			//Открывается занавес. Таинственное искомое существо появляется на экране
			cout << min << "\n";; //Вывод минимального положительного числа выше гланой диагонали
			system("pause");
		}
		else {
			//Пол залы раскалывается, и тьма поглощает его. Всё было зря.
			cout << "There aren`t positive elements\n";
		}

	}
	void green_area_analyze(int** arr, int cols) //В это же время, небольшая группа существ, облаченных в кислотно зеленые тона таинственно перешептывались
	{
		cout << "Выше побочной и главной:\n";

		for (int i = 0; i < cols; i++) // Надменно развернувшись, они проникают сквозь черный занавес, выходя на экран, словно призраки, пришедшие из таинственного будущего
			for (int j = i + 1; j < cols - i - 1; j++)
				cout << arr[i][j] << " ";
	}
	//Среди присутствующих пробежал таинственный слабый шопот. Резко похолодало, как будто на комнату раньше положенного срока опустилась ночь. Приглушенное освещение стало ещё тише и слабее, все положительное оставалось за гранью черты, что возникла, казалось бы, изнеоткуда.
	void green_area_show_element(int** arr, int cols, int a, int& max, int& imax, int& jmax) 
	{
		cout << "Максимальный отрицательный: ";

		for (int i = 0; i < cols; i++) //все присутсующие в зеленой зоне оказались по двум берегам, разделенные и расставленные.
			for (int j = i + 1; j < cols - i - 1; j++)
				if (arr[i][j] < 0)
				{
					if (arr[i][j] > max) //и только у того, в ком остались ещё хоть какие-то стремления к теплому, положительному есть шанс, чтобы спастись и остаться в живых.
					{

						max = arr[i][j];
						imax = i;
						jmax = j;
					}
				}
		if (max < 0 && max != a) // его искали, представляя идеалом, но никто понятия не имел, кто он и как выглядит... Миссия затягивалась, а в это время, судьба несчастного автора этой лабы была под угрозой, ведь если бы он так и не смог найти искомое - ему грозило бы сразиться с самым страшным зверем - собственным страхом.
		{
			cout << max << "\n";; //Вывод максимального отрицательного

		}
		else {
			cout << "Отрицательных нету\n";

		}
		system("pause"); //атмосфера была крайне напряжена. Никто не мог предугадать, что будет дальше.
	}
	void modification(int** arr, int cols, int a, int max, int min, int jmax, int imax, int imin, int jmin, int rows) //На экране было два трона, и два народа, чья судьба решалась в режиме реального времени. Сражение, обещало быть долгим и кровавым, но...
	{
		if (max < 0 && max != a && min > 0 && min != INT_MAX) {
			cout << "Новая матрица: \n";
			int extra; 
			extra = arr[imin][jmin];
			arr[imin][jmin] = arr[imax][jmax];
			arr[imax][jmax] = extra; //Бой был парирован, и в качестве примерения, две абсолютные противоположности - обменялись своими подданными, для того чтобы лучше понять позицию друг друга. Именно так и решаются дела в этом жестоком взрослом мире.
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << arr[i][j] << "\t";

				}
				cout << std::endl;
			}
		}
		else if (max >= 0 || max == a) //Но что будет, если вселенная не совершенна? И каждому положительному, не соответствует отрицательное значение, для заключения мира?
		{
			cout << "Нету отрицательных значений для реализации";
		}
		else if (min <= 0 || min == INT_MAX) // Или же наоборот?
		{
			cout << "Нету положительных значений для реализации";
		}
		else //А может вселенная достигла самого совершенного из своих обличий?
		{
			cout << "Нету как отрицательных, так и положительных значений";
		}
		//Нам никогда никогда этого не узнать. Но такова жизнь и с этим, увы, ничего не поделаешь.
	}
	void show_test_variables() //Мы видели эту историю в трех разных сюжетных линиях. И поверь на слово, дорогой читатель, это стоит того.
	{
		cout << "\n\t\t\t\t\tТестовые значения:\n"
			<< "\t\t\t\t\t\ a = -40, b = 40, rows = 4\n"
			<< "\t\t\t\t\t\ a = -40, b = 20, rows = 4\n"
			<< "\t\t\t\t\t\ a = -40, b = 20, rows = 5\n";
	}
}
namespace menu //Священный список гласил: чтобы избежать кары небесной, необходимо пройти множество самых тяжелых испытаний, из тех, что мы могли представить. Но священный список не говорил, что порядок соблюдать обязательно. 
{
	void all_menu() //Ни одно из этих испытаний не легче другого. Но у тебя, читатель, есть выбор, по какой дороге пройти первой.
	{
		cout << "1. Задания варианта (Вариант 11)\n"
			<< "2. Состязания по стрельбе\n"
			<< "3. Метод Гаусса\n"
			<< "4. Игра - жизнь\n"
			<< "5. Крестики-нолики"
			<< "0 - Выход\n"
			<< ">>> ";
	}
	void variant_menu()// но не удивляйся, если в некоторых дорогах будут ответвления
	{
		cout << "Вариант 11\n"
			<< "1. Первое задание\n"
			<< "2. Второе задание\n"
			<< "0 - Выход\n"
			<< ">>> ";
	}
	void shooters_menu()//Они будут казаться приветливыми и дружелюбными, но это только до того момента, пока ты не выпустишь свои священные тест-кейсы, что захотят сломать их и понять устройство. 
	{
		cout << "\t!Приветствую в состязании!\n";
		cout << "Есть только два выбора:\n";
		cout << std::endl;
		cout << "1 - Рандомное заполнение\n";
		cout << "2 - Заполнение вручную\n";
		cout << "0 - Выход\n";

	}
	void gl_menu() //А некоторые даже попытаются отнять твою жизнь
	{
		cout << "\t!Приветствую в игра-жизнь!\n";
		cout << "Есть только два выбора:\n";
		cout << std::endl;
		cout << "1 - Рандомное заполнение\n";
		cout << "2 - Заполнение вручную\n";
		cout << "0 - Выход\n";

	}
}
namespace second_task //Автору хотелось верить, что на этом его муки и страдания были бы окончены, но жизнь уготовила ему новые испытания, с которыми он долго не мог справится.
{

	//в этом саду росло всего два дерева. Плоды одного могли исцелить просящего от любых болезней, плоды другого же дарили иммунитет ко всем заразам, что в те далекие времена стали встречаться все чаще
	void input_size(int& n, int& m) 
	{
		cout << "Введите m:\n"; cin >> m;
		cout << "Введите n:\n"; cin >> n;
		cout << std::endl;
	}
	void arr_decl(int** arr_A, int** arr_C, int m, int n) //каждую весну деревья расцветали и плоды появлялись по всей кроне, куда бы ни упал человеческий взгляд
	{
		//arr_A
		for (int i = 0; i < m; i++)
		{
			arr_A[i] = new int[n];
		}
		//arr_C
		for (int i = 0; i < n; i++)
		{
			arr_C[i] = new int[n];
		}
		

	}
	void input_file(int** arr_A, int** arr_C, int* vec_B, int* vec_D, int m, int n) //в их генетическом коде были прописаны значения, благодаря которым, по непонятным наукам причинам их плоды стали настоящим чудом для человечества
	{
		std::string way = "D:\\moa-195\\yaziki_progi\\2_sem\\input.txt";
		std::ifstream file_in;
		file_in.open(way);
		//arr_A
		cout << "A(m,m):\n\n";
		for (int i = 0; i < m; i++) //это не могло не удивлять. По началу люди думали, что это просто сбой в матрице, но когда это стало происходить каждый год - перед наукой возникли новые задачи.
		{
			for (int j = 0; j < m; j++)
			{
				file_in >> arr_A[i][j];
				cout << arr_A[i][j] << "\t";
			}
			cout << std::endl;
		}
		system("pause");
		cout << std::endl;
		//arr_C
		cout << "C(n,m):\n\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				file_in >> arr_C[i][j];
				cout << arr_C[i][j] << "\t";
			}
			cout << std::endl;
		}
		system("pause");
		cout << std::endl;
		//vec_B
		cout << "B(m):\n\n";
		for (int i = 0; i < m; i++) //Привыкнув, людям стало мало этого чуда, и они решили, что пришло время проявить все имеющиеся навыки и создать ещё более мощную версию, чем простое лечение всех болезней. Люди хотели предугадывать их.
		{
			file_in >> vec_B[i];
			cout << vec_B[i] << " ";
		}
		system("pause");
		cout << std::endl;
		//vec_D
		cout << "D(n):\n\n";
		for (int i = 0; i < n; i++) //А может быть даже убивать их в других....
		{
			file_in >> vec_D[i];
			cout << vec_D[i] << " ";
		}
		system("pause");
		cout << std::endl;
	}
	void transp_vec_B(int* vec_B, int* t_vec_B, int& n, int& m) //Для этого ученые вытащили генетический код из плодов первого дерева и перевернули его. Записав в таком виде, у них появилась возможность внедрять новшества, которых они хотели добиться.
	{
		cout << "\nТранспонированный vec_B(m)\n";
		cout << std::endl;
		for (int i = 0; i < m; i++)
			t_vec_B[i] = vec_B[m - i - 1];
		for (int i = 0; i < m; i++)
		{
			cout << t_vec_B[i] << " ";
		}
		cout << std::endl;
	}
	void BxDxC(int** arr_C, int* tt_vec_B, int* New, int n, int m)// На свой страх и риск, люди скрестили все полученные данные, умоляя небеса, чтобы задумка была осуществимой
	{
		for (int i = 0; i < n; i++)
		{
			New[i] = 0;
			for (int j = 0; j < m; j++)
			{
				New[i] += arr_C[i][j] * tt_vec_B[j];
			}
		}
		cout << "BxDxC: " << std::endl;
		for (int i = 0; i < m; i++) cout << New[i] << std::endl;
		system("pause");
	}
	void B_x_two(int* t_vec_B, int* tt_vec_B, int n, int m) //И даже попытались в два раза увеличить действие уже имеющихся способностей
	{
		cout << "Умножение Bx2:\n";
		for (int i = 0; i < m; i++)
		{
			tt_vec_B[i] = 0;
			tt_vec_B[i] += t_vec_B[i] * 2;
		}
		for (int i = 0; i < m; i++)
		{
			cout << tt_vec_B[i] << " ";
		}

		system("pause");
	}
	void BxDt(int* tt_vec_B, int* vec_D, int* New_1, int n, int m) // Они перепробовали самые разные варианты улучшения, и теперь представляют лучшие из них
	{
		for (int i = 0; i < n; i++)
		{
			New_1[i] = 0;
			New_1[i] += tt_vec_B[i] * vec_D[i];
			if (n < m) m = n; else n = m;
		}
		cout << "BxDt: " << std::endl;
		for (int i = 0; i < m; i++) cout << New_1[i] << std::endl;
		system("pause");
	}
	
}

//Это была странная вселенная. Проблемой существ в них - было сплошное одиночество. Оставаясь один - ты вынужден был умереть.
namespace game_life_task //Добро пожаловать, это игра в жизнь. Попробуй выжить. 
{
	//Выходя на улицу, вы попадаете на площадь, где каждое мгновение исчезают люди. Повсюду шум и крик, ведь остаться одному хоть на мгновение - значит совершить самоубийство.
	void fieldView(int** a, int n, int m) //вывод поля
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (a[i][j] == 1)
					cout << '*';
				else
					cout << ' ';
				cout << ' ';
			}
			cout << std::endl;
		}
	}
	//На экране непрерывно висит счетчик. Тебе жутко повезло, если ты видишь на нем нечетное число. 
	int livingPoints(int** a, int n, int m) //счет живых точек
	{
		int count = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a[i][j] == 1)
					count++;
		return count;
	}

	void neighborhood(int nb[][2], int x, int y) //координаты соседей точки
		//Нийти свое спасение не так просто, как казалось бы. Ты должен обладать умом, силой и скоростью. 
	{
		int k = 0;
		for (int i = x - 1; i <= x + 1; i++)
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (i == x && j == y)
					continue;
				nb[k][0] = i;
				nb[k][1] = j;
				k++;
			}
	}

	int amountLivingNB(int** a, int n, int m, int x, int y) //кол-во живых соседей у клетки[x][y]
		//Ты должен попробовать остаться в живых, ища тех, кто рядом. Интроверту не выжить в этом мире. Будь улыбчивым и дружелюбным, тогда ты сможешь спасти себя.
	{
		int count = 0;
		int nb[8][2];
		int x_, y_;
		neighborhood(nb, x, y);
		for (int i = 0; i < 8; i++)
		{
			x_ = nb[i][0];
			y_ = nb[i][1];
			if (x_ < 0 || y_ < 0)
				continue;
			if (x_ >= n || y_ >= m)
				continue;
			if (a[x_][y_] == 1)
				count++;
		}
		return count;
	}

	void NextGen(int** a, int** a1, int n, int m) //следующее поколение точек
	
	//Поколения здесь сменяются слишком быстро, как и в целом проходит жизнь. Правительство ведет подсчет выживших.
	{
		int livingNB, p;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				p = a1[i][j];
				livingNB = amountLivingNB(a1, n, m, i, j);
				if (p == 0)
				{
					if (livingNB == 3)
						a[i][j] = 1;
				}
				else
					if (livingNB < 2 || livingNB > 3)
						a[i][j] = 0;
			}
	}

	void CopyCopy(int** a, int** a1, int n, int m) //копирование прошлого поля
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				a1[i][j] = a[i][j];
	}
	int FieldsCompare(int** a, int** a1, int n, int m) //сравнение полей
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (a != a1)
					return -1;
		return 0;
		//Аналитики беспрерывно проводили сравнение с предыдущей секундой, и их данные не могли не нагнетать.
		//Но мы знаем, что впереди никому из них не суждено жить. Рискни доказать, что это не так. 
	}
}
namespace gauss_task // тут у нас метод гауса, и автор без вдохновения
{
	void sys_cin(float** arr, float* y, int length)//ввод значений
	{
		for (size_t i = 0; i < length; i++)
		{
			arr[i] = new float[length];
			for (size_t j = 0; j < length; j++)//вводим кол-во уравнений 
			{
				cout << "arr[" << i << "][" << j << "]= ";
				cin >> arr[i][j];
			}
		}
		for (size_t i = 0; i < length; i++)
		{
			cout << "y[" << i << "]=";
			cin >> y[i];

		}
	}
	void sys_out(float** arr, float* y, int length)//вывод значений
	{
		for (int i = 0; i < length; i++)
		{
			for (int j = 0; j < length; j++)
			{
				cout << arr[i][j] << "*x" << j;//выводим ответ
				if (j < length - 1)
					cout << " + ";
			}
			cout << " = " << y[i] << std::endl;
		}
		return;
	}
	float* gausses_method(float** arr, float* y, int length)
	{
		float* x, max;
		int k, index;
		const float eps = 0.00001;  // точность
		x = new float[length];
		k = 0;
		while (k < length)
		{
			max = abs(arr[k][k]);
			index = k;
			for (int i = k + 1; i < length; i++)//метод гаусса использует прямой ход. мы используем приведение к ступенчатому виду.
			{
				if (abs(arr[i][k]) > max)
				{
					max = abs(arr[i][k]);
					index = i;
				}
			}
			// Перестановка строк
			if (max < eps)
			{
				// нет ненулевых диагональных элементов
				cout << "Решение получить невозможно из-за нулевого столбца ";
				cout << index << " матрицы A" << std::endl;
				return 0;
			}
			for (int j = 0; j < length; j++)
			{
				float temp = arr[k][j];
				arr[k][j] = arr[index][j];
				arr[index][j] = temp;
			}
			float temp = y[k];
			y[k] = y[index];
			y[index] = temp;

			for (int i = k; i < length; i++)//
			{
				float temp = arr[i][k];
				if (abs(temp) < eps) continue;
				for (int j = 0; j < length; j++)
					arr[i][j] = arr[i][j] / temp;
				y[i] = y[i] / temp;
				if (i == k)  continue;
				for (int j = 0; j < length; j++)
					arr[i][j] = arr[i][j] - arr[k][j];
				y[i] = y[i] - y[k];
			}
			k++;
		}

		for (k = length - 1; k >= 0; k--)//обратный ход
		{
			x[k] = y[k];
			for (int i = 0; i < k; i++)
				y[i] = y[i] - arr[i][k] * x[k];
		}
		return x;
	}


}
namespace tictac// крестики нолики
{
	void pole_view(char** pole) //показывает поле, которое для удобство разделено палками и ограничено 3х3
	{
		for (int i = 0; i < 3; i++)
		{
			cout << pole[i][0] << " | " << pole[i][1] << " | " << pole[i][2];
			if (i != 2) cout << "\n \n";
		}
		cout << std::endl;
	}


	void player(char** pole) //ход игрока.
	{
		int x, y;
		cout << "Выберите клетку\nСтрока:"; cin >> x;
		cout << "Столбец: "; cin >> y;
		x--; y--;
		if (x < 0 || y < 0 || x>2 || y>2 || pole[x][y] != ' ') //если вводятся некорректные условия, такие как 0-0, или числа меньше нуля, или больше трех
		{
			cout << "Ошибка\n";
			player(pole);
		}
		else pole[x][y] = 'X';
	}


	void compuhter(char** pole) //ход компухтера.
	{
		int i, j;
		for (i = 0; i < 3; i++) 
		{
			for (j = 0; j < 3; j++)
				if (pole[i][j] == ' ') break;
			if (pole[i][j] == ' ') break; //нужно, чтобы выйти из цикла по i.
		}
		if (i * j == 9) //Если ничья
		{
			cout << "GAME OVER\n";
			exit(0);
		}
		else
			pole[i][j] = 'O';//Компьютер играет за ноль, да, кстати
	}


	char who_is_the_winner(char** pole) //Кто выйграл, а?
	{
		int i;
		for (i = 0; i < 3; i++)
			if (pole[i][0] == pole[i][1] && pole[i][0] == pole[i][2]) //проверка строк.
				return pole[i][0];
		for (i = 0; i < 3; i++)
			if (pole[0][i] == pole[1][i] && pole[0][i] == pole[2][i]) //проверка столбцов.
				return pole[0][i];
		if (pole[0][0] == pole[1][1] && pole[1][1] == pole[2][2]) //проверка главной диагонали.
			return pole[0][0];
		if (pole[0][2] == pole[1][1] && pole[1][1] == pole[2][0]) //проверка второстепенной диагонали.
			return pole[0][2];
		return ' ';
	}

}
int main()//Про сердце. 
{
	setlocale(LC_ALL, "");
	menu::all_menu();
	int main_num;
	cin >> main_num;
	switch (main_num)//Разделение на 5 кейсов, что выводятся в главном меню
	{
	case 1://Касательно номеров варианта
	{
		int var_num;
		menu::variant_menu();
		cin >> var_num;

		switch (var_num)//Разделение между заданиями
		{

		case 1://1 задание
		{
			int rows, cols, a, b;
			first_task::show_test_variables();
			first_task::enter_values(rows, cols, a, b);
			int** arr = new int* [rows];
			int max = a;
			int imax = 0, jmax = 0;
			int imin = 0, jmin = 0;
			int min = INT_MAX;
			first_task::show_arr(arr, rows, cols);
			first_task::fill_arr(arr, rows, cols, a, b);
			first_task::red_area_analyze(arr, rows);
			first_task::red_area_show_element(arr, rows, min, imin, jmin);
			first_task::green_area_analyze(arr, cols);
			first_task::green_area_show_element(arr, cols, a, max, imax, jmax);
			first_task::modification(arr, cols, a, max, min, jmax, imax, imin, jmin, rows);
			delete[] arr;
			break;
		}
		case 2://2 задание
		{
			int m, n, num;//2v
			second_task::input_size(n, m);
			int** arr_A = new int* [m];//2v
			int** arr_C = new int* [n];//2v
			int* vec_B = new int[m];//2v
			int* vec_D = new int[m];//2v
			int* t_vec_B = new int[m];//2v
			int* New = new int[m];//2v
			int* New_1 = new int[m];//2v
			int* tt_vec_B = new int[m];
			second_task::arr_decl(arr_A, arr_C, m, n);
			second_task::input_file(arr_A, arr_C, vec_B, vec_D, m, n);
			second_task::transp_vec_B(vec_B, t_vec_B, n, m); //OK
			second_task::B_x_two(t_vec_B, tt_vec_B, n, m);
			second_task::BxDt(tt_vec_B, vec_D, New_1, n, m);
			second_task::BxDxC(arr_C, tt_vec_B, New, n, m);
			//second_task::subtraction(arr_A, New, n, m);
		}
		default:
			break;
		}
		break;
	}
	case 2://Состязание по стрельбе
	{
		menu::shooters_menu();
		int n, m = 1;
		int sh_num;
		cin >> sh_num;
		switch (sh_num)
		{
		case 1://Ввод рандомных значений
		{
			n = rand() % 31;
			m = rand() % 11;
			break;
		}
		case 2://ввод вручную
		{
			cout << "Enter n and m\n";
			cin >> n;
			cin >> m;
			break;
		}
		default:
			break;
		}
		srand(time(NULL));//отвечает за стрелков и их выстрелы
		while (n == 0 || m == 0 || n == 1 || m == 1);
		cout << "number of shooters:" << n << "\nnumber of shots:" << m << "\n";
		int** a;
		a = new int* [n];
		for (int i = 0; i < n; i++)//объявление одномерного массива
			a[i] = new int[m];
		for (int i = 0; i < n; i++)//двумерного
			for (int j = 0; j < m; j++)
				a[i][j] = rand() % 11;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				printf("%5d", a[i][j]);
			}
			cout << std::endl;
		}
		int* res;
		res = new int[n];
		shooters_task::results(a, res, n, m);//вызов функции из именного пространства
		shooters_task::winners(res, n);
		break;
	}
	case 3://метод гаусса
	{
		/*
		Тестовые данные просто для проверки работоспособности:
			3
			2
			4
			1
			5
			2
			1
			2
			3
			4
			36
			47
			37
		*/

		float** arr, * y, * x;
		int length;
		cout << "Введите количество уравнений: ";
		cin >> length;
		arr = new float* [length];
		y = new float[length];
		gauss_task::sys_cin(arr, y, length);
		gauss_task::sys_out(arr, y, length);
		//ineedmoreammo!!11!
		x = gauss_task::gausses_method(arr, y, length);
		for (int i = 0; i < length; i++)
			cout << "x[" << i << "]=" << x[i] << std::endl;
		return 0;

		break;
	}
	case 4://игра в жизнь
	{
		menu::gl_menu();
		int n, m, gl_num;
		cin >> gl_num;
		switch (gl_num)
		{
		case 1://рандомный ввод
		{
			n = rand() % 21;
			m = rand() % 21;
			break;
		}
		case 2://ручной ввод(лапками)
		{
			cout << "Введите n и m";
			cin >> n;
			cin >> m;
		}
		default:
			break;
		}
		while (n < 4 || m < 4);//ввод данных менее 4 не возможен
		cout << "\nРазмерность Вселенной: " << n << " Строки и " << m << " колонки\n";
		int** field; //задаем поле (многомерный массив)
		field = new int* [n];
		for (int i = 0; i < n; i++)
			field[i] = new int[m];
		std::random_device rd; //заполнение случайно точками
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(1, 10000);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				int num = dis(gen);
				if (num % 2 == 0)
					field[i][j] = 1;
				else
					field[i][j] = 0;
			}
		int** PreviousField; //задаем поле для запоминания предыдущего поколения
		PreviousField = new int* [n];
		for (int i = 0; i < n; i++)
			PreviousField[i] = new int[m];
		int livingpoints = -1;
		bool Edem = false; //Проверка на выживших
		do
		{
			game_life_task::fieldView(field, n, m);                                   //показ поля
			game_life_task::CopyCopy(field, PreviousField, n, m);                     //копируем поле
			game_life_task::NextGen(field, PreviousField, n, m);                      //генерируем новое
			Edem = game_life_task::FieldsCompare(field, PreviousField, n, m) == 0;    //сравниваем поля
			livingpoints = game_life_task::livingPoints(field, n, m);                 //проверяем количество живых клеток
			if (Edem)
				cout << "Эдемов сад\n";                              //Эдемов сад
			if (livingpoints == 0)
				cout << "ВЫ МЕРТВЫ\n";                                 //все cдохли. конец.
			Sleep(2000); //прерывание цикла, чтобы пользователь успел увидеть поле
		} while (livingpoints != 0 || !Edem);
		return 0;
	}
	case 5://Крестики нолики
	{
		char round;
		round = ' ';
		cout << "Это игра Крестики-Нолики\nВы будете играть против компьютера\n";
		char** pole;
		pole = new char* [3];
		for (int i = 0; i < 3; i++)
			pole[i] = new char[3];
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				pole[i][j] = ' ';
		do
		{
			tictac::pole_view(pole);
			tictac::player(pole);
			round = tictac::who_is_the_winner(pole);
			if (round != ' ')
				break;
			tictac::compuhter(pole);
			round = tictac::who_is_the_winner(pole);
		} while (round == ' ');
		if (round == 'X')
			cout << "Поздравляем, вы победили!\n";
		else
			cout << "Вас победил компьютер... Теперь живите с этим.\n";
		tictac::pole_view(pole);
		break;
	}
	default:
		cout << "До свидания.";
		break;
	}
	return 0;
}
