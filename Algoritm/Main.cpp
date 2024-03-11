#include<iostream>
#include<vector>
#include<set>
#include<algorithm> // Алгоритм позволяет обработать часть коллекции

int main() {
	std::vector<int> collection(10); // Указываем, что в векторе изначально 10 элементов, по умолчанию инициализированны нулём
	for (auto& el : collection) // Вывод коллекции "до" с помощью цикла range base for (использует не int i, а объекты, что позволяет \
		избежать ошибок по типу выхода хза пределы диапазона)
		std::cout << el << ' '; // должны быть нули
	std::cout << std::endl;

	// Заполняем числом 10 все элементы коллекции за искл. крайних элементов (арифметика укеазателей для методов begin и end)
	std::for_each(collection.begin() + 1, collection.end() - 1, [](int &a)->void{ a = 10; }); // для обработки коллекции без первого и последнего элементов\
	если убрать ссылку у анонимной функции (не [](int &a), а [](int a)), то элементы не заменятся на 10 потому, что передаются копии числа 10, \
	которые потом удаляются, & передаёт истинный адрес

	for (auto& el : collection) // Вывод коллекции "после"
		std::cout << el << ' ';
	std::cout << std::endl;

	// Создаём две одинаковые коллекции collection2 и collection3 для проверки ф.equal (возвращает true или false)
	std::vector<int> collection2(10);
	std::for_each(collection2.begin(), collection2.end(), [](int& a)->void { 
		static int i{ 1 }; // Статическая переменная (каждая итерация цикла увеличивает её на 1, эквивалентно ++i)
		a = i++; // Заполняем коллекцию от 0 до 10 с помощью статической переменной 
		});
	for (auto& el : collection2) // Вывод в консоль
		std::cout << el << ' ';
	std::cout << std::endl;

	std::vector<int> collection3(10);
	std::for_each(collection3.begin(), collection3.end(), [](int& a)->void {
		static int i{ 1 };
		a = i++; 
		});
	for (auto& el : collection3) // Вывод в консоль
		std::cout << el << ' ';
	std::cout << std::endl;

	// Сравниваем коллекции 2 и 3 на одинаковость элементов, в метод equal передаём указатели сравниваемых коллекций
	if (std::equal(collection2.begin(), collection2.end(), collection3.begin(), collection3.end())) // Если одинаковы, то 
		std::cout << "equal collections" << std::endl; // выводим сообщение
	
	// Нас интересует, чтобы у коллекций совпадали пары чётный/нечётный, то можно в equal закинуть 5-ый праметр - предикант XXXXX :-) не успел записать
	/*if (std::equal(collection2.begin(), collection2.end(), collection3.begin(), collection3.end()), XXXXXXXXXXX)
		std::cout << "equal collections" << std::endl;*/
	
	// С помощью библиотеки algorithm можно создавать новую коллекцию collection4 копированием с помощью методов rbegin и rend
	std::vector<int> collection4(collection.rbegin(), collection.rend());
	for (auto& el : collection4)
		std::cout << el << ' ';

	return 0;
}