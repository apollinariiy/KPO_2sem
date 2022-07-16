#pragma once


#include <Windows.h>
#include <iostream>

#define DICTNAMEMAXSIZE 20	// максимальный размер названия словаря
#define DICTMAXSIZE 6		// размер словаря
#define ENTRYNAMEMAXSIZE 20 // макс длина имени словаря
#define THROW1 "Create: превышен размер имени словаря"
#define THROW2 "Create: превышен размер максимальной ёмкости словаря"
#define THROW3 "AddEntry: переполнение словаря"
#define THROW4 "AddEntry: дублирование идентификатора"
#define THROW5 "GetEntry: не найден элемент"
#define THROW6 "DelEntry: не найден элемент"
#define THROW7 "UpdEntry: не найден элемент"
#define THROW8 "UpdEntry: дублирование идентификатора"

namespace Dictionary {
	struct Entry { // элемент словаря
		int		id;						// идентификатор (уникальный)
		char	name[ENTRYNAMEMAXSIZE];	// название элемента
	};

	struct Instance {
		char name[DICTNAMEMAXSIZE];		// название словаря
		int maxsize;					// максимальный размер словаря
		int size;						// текущий размер
		Entry* dictionary[DICTMAXSIZE];			// элементы словаря
	};

	Instance Create( //создать словарь
		char name[DICTNAMEMAXSIZE],
		int size
	);

	void AddEntry( //добавить элемент словаря 
		Instance& inst,
		Entry ed //элемент
	);

	void DelEntry( //удалить элемент словаря
		Instance& inst,
		int id
	);

	void UpdEntry(//изменить элемент словаря
		Instance& inst,//экзепляр
		int id,
		Entry new_ed
	);

	Entry GetEntry(//получить
		Instance& inst,
		int id
	);

	void Print(Instance& d);		// Печать словаря
	void Delete(Instance& d);	// Удалитb словарь

}
