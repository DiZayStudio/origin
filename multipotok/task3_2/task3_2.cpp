//Задание 2
//«for_each»
//Реализовать параллельный вариант оператора for_each.
//Функция должна принимать итераторы на начало и конец контейнера и ссылку обрабатывающую функцию.
//При реализации необходимо рекурсивно разделить контейнер на несколько блоков и
//для каждого блока запустить отдельную задачу, применяющую обрабатывающую функцию к части контейнера.
#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <future>
#include <numeric>


template<typename It, typename T>
T par_sum(It first, It last, T init) {
	unsigned long size = distance(first, last);
	if (size >= 5)
	{
		It mid = first;
		std::advance(mid, size / 2);
		std::future<T> result = std::async(par_sum<It, T>, first, mid, init);
	
		T second_result = par_sum(mid, last, T());

		return result.get() + second_result;
	//	return result.get() + par_sum(mid, last, T());
	}
	else
	{
		return accumulate(first, last, init);
	}
}

int main()
{
    setlocale(LC_ALL, "Rus");

    std::vector<int> v {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	auto  res = par_sum(v.begin(), v.end(), 0);
	std::cout << "Сумма элементов: " << res << std::endl;

}
