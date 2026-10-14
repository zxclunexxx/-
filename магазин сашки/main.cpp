#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	srand(time(NULL));

	int CategoryChoice = 0;
	int JuiceChoice = 0;

	//ппеременные для хранения количества литров каждого товара
	double appleQty = 0, orangeQty = 0, apricotQty = 0, pearQty = 0;
	double tomatoQty = 0, onionQty = 0, cucumberQty = 0;
	double garlicQty = 0, petrushaQty = 0;
	double hawthornQty = 0;

	//переменная для проверкки наличия фруктовго сока в корзине
	bool hasFruitJuice = false;

	//временная переменная для ввода количества литров
	double inputQty = 0;

	bool IsRunning = true;

	std::cout << "-----------------------------------\n";
	std::cout << "Добро пожаловать в Соки Александра.\n";
	std::cout << "-----------------------------------\n";

	while (IsRunning)
	{
		hasFruitJuice = (appleQty > 0 || orangeQty > 0 || apricotQty > 0 || pearQty > 0);

		std::cout << "===============================\n";
		std::cout << "         Главное меню.\n";
		std::cout << "===============================\n";
		std::cout << "Выбрите категорию меню: \n";
		std::cout << "1. Фруктовые соки\n";
		std::cout << "2. Овощные соки\n";
		std::cout << "3. Чаи\n";
		std::cout << "4. Настойки\n";
		std::cout << "5. Посмотреть корзину и сделать заказ\n";
		std::cout << "6. Выход\n";
		std::cout << "\nВведите номер категории (1-6): ";
		std::cin >> CategoryChoice;
		std::cout << "\n";

		if (CategoryChoice == 1)
		{
			std::cout << "Вы выбрали Фруктовые соки.\n\n";
			std::cout << "Выберите сок: \n";
			std::cout << "1. Яблочный (200 рублей/л)\n";
			std::cout << "2. Апельсиновый (150 рублей/л)\n";
			std::cout << "3. Абрикосовый (180 рублей/л)\n";
			std::cout << "4. Грушевый (160 рублей/л)\n\n";
			std::cout << "Введите номер сока (1-4): ";
			std::cin >> JuiceChoice;
			std::cout << "\n";

			if (JuiceChoice >= 1 && JuiceChoice <= 4)
			{
				std::cout << "Сколько литровых банок хотите взять? ";
				std::cin >> inputQty;

				if (inputQty > 0)
				{
					if (JuiceChoice == 1)
					{
						appleQty += inputQty; std::cout << "Вы заказали яблочный сок.\n";
					}
					else if (JuiceChoice == 2)
					{
						orangeQty += inputQty; std::cout << "Вы заказали апельсиновый сок.\n";
					}
					else if (JuiceChoice == 3)
					{
						apricotQty += inputQty; std::cout << "Вы заказали абрикосовый сок.\n";
					}
					else if (JuiceChoice == 4)
					{
						pearQty += inputQty; std::cout << "Вы заказали грушевый сок.\n";
					}

					std::cout << "Покупка добавлена в корзину.\n";

					if (hawthornQty > 0)
					{
						std::cout << "(!) Внимание: покупка фруктового сока аннулировала купленный боярышник!\n";
						hawthornQty = 0;
					}
				}
				std::cout << "\n";
			}
			else
			{
				std::cout << "Некорректный ввод. Пожалуйста, выберите номер сока от 1 до 4.\n\n";
			}
		}

		else if (CategoryChoice == 2)
		{
			std::cout << "Вы выбрали Овощные соки.\n";
			std::cout << "1. Томатный (120 рублей/л)\n";
			std::cout << "2. Луковый (200 рублей/л)\n";
			std::cout << "3. Огуречный (120 рублей/л)\n\n";
			std::cout << "Введите номер сока (1-3): ";
			std::cin >> JuiceChoice;

			if (JuiceChoice >= 1 && JuiceChoice <= 3)
			{
				std::cout << "\nСколько литровых банок хотите взять? ";
				std::cin >> inputQty;

				if (JuiceChoice == 1)
				{
					tomatoQty += inputQty;
				}
				else if (JuiceChoice == 2)
				{
					onionQty += inputQty;
				}
				else if (JuiceChoice == 3)
				{
					cucumberQty += inputQty;
				}

				std::cout << "Покупка добавлена в корзину.\n\n";
			}
			else
			{
				std::cout << "\nНекорректный ввод. Пожалуйста, выберите номер сока от 1 до 3.\n\n";
			}
		}

		else if (CategoryChoice == 3)
		{
			std::cout << "Вы выбрали Чаи.\n";
			std::cout << "1. Чесночный (120 рублей/л)\n";
			std::cout << "2. Петрушевый (150 рублей/л)\n\n";
			std::cout << "Введите номер чая (1-2): ";
			std::cin >> JuiceChoice;

			if (JuiceChoice == 1 || JuiceChoice == 2)
			{
				std::cout << "\nСколько литровых банок хотите взять? ";
				std::cin >> inputQty;

				if (JuiceChoice == 1)
				{
					garlicQty += inputQty;
				}
				else if (JuiceChoice == 2)
				{
					petrushaQty += inputQty;
				}

				std::cout << "Покупка добавлена в корзину.\n\n";
			}
			else
			{
				std::cout << "\nНекорректный ввод. Пожалуйста, выберите номер от 1 до 2.\n\n";
			}
		}

		else if (CategoryChoice == 4)
		{
			if (hasFruitJuice)
			{
				std::cout << "Ошибка! Доступ к настойкам заблокирован, так как в корзине есть фруктовый сок.\n\n";
			}
			else
			{
				std::cout << "Вы выбрали Настойки.\n";
				std::cout << "1. Боярышник (120 рублей/л)\n\n";
				std::cout << "Введите номер настойки (1-1): ";
				std::cin >> JuiceChoice;

				if (JuiceChoice == 1)
				{
					std::cout << "\nСколько литровых банок хотите взять? ";
					std::cin >> inputQty;
					if (inputQty > 0)
					{
						hawthornQty += inputQty;
						std::cout << "Вы заказали настойку Боярышника.\n";
						std::cout << "Покупка добавлена в корзину.\n\n";
					}
				}
				else
				{
					std::cout << "\nНекорректный ввод. Пожалуйста, выберите 1.\n\n";
				}
			}
		}


		else if (CategoryChoice == 5)
		{
			std::cout << "====================================\n";
			std::cout << "         ОФОРМЛЕНИЕ ЗАКАЗА          \n";
			std::cout << "====================================\n";

			//стоимость без скпаидок
			double appleCost = appleQty * 200;
			double orangeCost = orangeQty * 150;
			double apricotCost = apricotQty * 180;
			double pearCost = pearQty * 160;
			double tomatoCost = tomatoQty * 120;
			double onionCost = onionQty * 200;
			double cucumberCost = cucumberQty * 120;
			double garlicCost = garlicQty * 120;
			double petrushaCost = petrushaQty * 150;
			double hawthornCost = hawthornQty * 120;

			//стоиомость всего без скидок
			double totalBeforeDiscounts = appleCost + orangeCost + apricotCost + pearCost +
				tomatoCost + onionCost + cucumberCost + garlicCost + petrushaCost + hawthornCost;

			if (totalBeforeDiscounts == 0) {
				std::cout << "Ваша корзина пуста!\n\n";
				continue;
			}

			//скидка 5% на петрушевый чай при покупке от 3 литров
			double petrushaDiscount = 0.0;
			if (petrushaQty >= 3.0)
			{
				petrushaDiscount = petrushaCost * 0.05;
			}

			//каждый четвертый литр лукового сока бесплатно
			double onionDiscount = 0.0;
			if (onionQty >= 4.0)
			{
				int freeLiters = onionQty / 4.0;

				onionDiscount = freeLiters * 200.0;
			}


			double totalProductDiscounts = petrushaDiscount + onionDiscount;
			double subTotal = totalBeforeDiscounts - totalProductDiscounts;

			//скика 13% на весь чек, если сумма > XXX рублей
			double checkDiscount = 0.0;
			double threshold = 1000.0;

			if (subTotal > threshold)
			{
				checkDiscount = subTotal * 0.13;
			}

			double finalTotalDiscount = totalProductDiscounts + checkDiscount;
			double finalPrice = subTotal - checkDiscount;

			//вывод состава корзины, итоговой суммы и скидок
			std::cout << "Ваша корзина:\n";
			if (appleQty > 0)
			{
				std::cout << "- Яблочный сок: " << appleQty << " л. (" << appleCost << " руб.)\n";
			}
			if (orangeQty > 0)
			{
				std::cout << "- Апельсиновый сок: " << orangeQty << " л. (" << orangeCost << " руб.)\n";
			}
			if (apricotQty > 0)
			{
				std::cout << "- Абрикосовый сок: " << apricotQty << " л. (" << apricotCost << " руб.)\n";
			}
			if (pearQty > 0)
			{
				std::cout << "- Грушевый сок: " << pearQty << " л. (" << pearCost << " руб.)\n";
			}
			if (tomatoQty > 0)
			{
				std::cout << "- Томатный сок: " << tomatoQty << " л. (" << tomatoCost << " руб.)\n";
			}
			if (onionQty > 0)
			{
				std::cout << "- Луковый сок: " << onionQty << " л. (" << onionCost << " руб.)\n";
			}
			if (cucumberQty > 0)
			{
				std::cout << "- Огуречный сок: " << cucumberQty << " л. (" << cucumberCost << " руб.)\n";
			}
			if (garlicQty > 0)
			{
				std::cout << "- Чесночный чай: " << garlicQty << " л. (" << garlicCost << " руб.)\n";
			}
			if (petrushaQty > 0)
			{
				std::cout << "- Петрушевый чай: " << petrushaQty << " л. (" << petrushaCost << " руб.)\n";
			}
			if (hawthornQty > 0)
			{
				std::cout << "- Настойка боярышника: " << hawthornQty << " л. (" << hawthornCost << " руб.)\n";
			}

			std::cout << "------------------------------------\n";
			std::cout << "Сумма без скидок: " << totalBeforeDiscounts << " рублей.\n";

			if (finalTotalDiscount > 0) {
				std::cout << "Примененные скидки:\n";
				if (petrushaDiscount > 0)
				{
					std::cout << "  * Скидка 5% на Петрушевый чай: -" << petrushaDiscount << " руб.\n";
				}
				if (onionDiscount > 0)
				{
					std::cout << "  * Акция «Каждый 4-й литр в подарок»: -" << onionDiscount << " руб.\n";
				}
				if (checkDiscount > 0)
				{
					std::cout << "  * Скидка 13% на весь чек: -" << checkDiscount << " руб.\n";
				}
				std::cout << "Общая сумма скидок: " << finalTotalDiscount << " рублей.\n";
			}
			else {
				std::cout << "Скидки не применялись.\n";
			}

			std::cout << "------------------------------------\n";
			std::cout << "ИТОГО К ОПЛАТЕ: " << finalPrice << " рублей.\n";
			std::cout << "====================================\n";
			std::cout << "Спасибо, что заглянули к Александру!\n";



			IsRunning = false;

			// Очищаем корзину после оформления заказа
			appleQty = 0;
			orangeQty = 0;
			apricotQty = 0;
			pearQty = 0;

			tomatoQty = 0;
			onionQty = 0;
			cucumberQty = 0;

			garlicQty = 0;
			petrushaQty = 0;
			hawthornQty = 0;

			// Сбрасываем остальные переменные
			CategoryChoice = 0;
			JuiceChoice = 0;
			inputQty = 0;
			hasFruitJuice = false;

			// Продолжаем работу программы
			IsRunning = true;

			std::cout << "\nКорзина очищена! Можете сделать новый заказ.\n\n";

		}


		else if (CategoryChoice == 6)
		{
			std::cout << "До свидания! Ждем вас снова.\n";
			IsRunning = false;
		}

		else
		{
			std::cout << "Некорректный ввод. Пожалуйста, выберите номер категории от 1 до 6.\n";
			std::cout << "\n";
		}
	}
	return 0;
}