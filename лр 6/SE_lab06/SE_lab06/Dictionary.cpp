#include "Dictionary.h"

namespace Dictionary {
	Instance Create(char name[DICTNAMEMAXSIZE], int size) { //создает экземпляр словаря
		Instance newDict;
		if (strlen(name) > DICTNAMEMAXSIZE)
			throw (char*)THROW1;
		for (int i = 0; i < strlen(name); i++) {
			newDict.name[i] = name[i];
		}
		newDict.name[strlen(name)] = '\0';
		if (size > DICTMAXSIZE)
			throw (char*)THROW2;
		newDict.name[strlen(name)] = '\0';

		newDict.maxsize = size;
		newDict.size = 0;

		return newDict;
	}

	void AddEntry(Instance& inst, Entry ed) {  //добавление элемента в словарь
		if (inst.size == inst.maxsize) throw (char*)THROW3;
		for (int i = 0; i < inst.size; i++) {
			if (ed.id == inst.dictionary[i]->id) throw (char*)THROW4;
		}
		inst.dictionary[inst.size] = new Entry(); //выделение памяти в куче(динамическая память)
		inst.dictionary[inst.size]->id = ed.id;
		for (int i = 0; i < strlen(ed.name); i++) {
			inst.dictionary[inst.size]->name[i] = ed.name[i];
		}
		inst.dictionary[inst.size]->name[strlen(ed.name)] = '\0';
		inst.size++;
	}

	void DelEntry(Instance& inst, int id) { // удаление
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i]->id == id) {
				if (i == inst.size - 1)
					inst.dictionary[i] = NULL;
				else {
					for (int j = i; j < inst.size - 1; j++) {
						inst.dictionary[j] = inst.dictionary[j + 1];
					}
					inst.dictionary[inst.size - 1] = NULL;
				}
				inst.size--;
				return;
			}
		}
		throw (char*)THROW6;
	}

	Entry GetEntry(Instance& inst, int id) { //получение элемента по ID
		Entry getElement;
		for (int i = 0; i < inst.size; i++) {
			if (id == inst.dictionary[i]->id) {
				getElement.id = inst.dictionary[i]->id;
				for (int j = 0; j < strlen(inst.dictionary[i]->name); j++)
					getElement.name[j] = inst.dictionary[i]->name[j];
				getElement.name[strlen(inst.dictionary[i]->name)] = '\0';
				return getElement;
			}
		}
		throw (char*)THROW5;
	}

	void UpdEntry(Instance& inst, int id, Entry new_ed) { // замена элемента
		int prob = 0;
		for (int i = 0; i < inst.size; i++) {
			if (inst.dictionary[i]->id == id) {
				if (inst.dictionary[i]->id == new_ed.id)
					throw (char*)THROW8;
				inst.dictionary[i]->id = new_ed.id;
				short clearName = 0;
				while (inst.dictionary[i]->name[clearName] != '\0') {
					inst.dictionary[i]->name[clearName] = NULL;
					clearName++;
				}
				inst.dictionary[i]->name[clearName] = NULL;
				for (int j = 0; j < strlen(new_ed.name); j++) {
					inst.dictionary[i]->name[j] = new_ed.name[j];
				}
				inst.dictionary[i]->name[strlen(new_ed.name)] = '\0';
				prob++;
			}
		}
		if (prob == 0)
		{
			throw (char*)THROW7;
		}
	}

	void Delete(Instance& d) { // удаление словаря
		for (int i = 0; i < d.size; i++) {
			delete d.dictionary[i];
		}
		d.maxsize = NULL;
		d.size = NULL;
		memset(d.name, strlen(d.name), '\0');
	}

	void Print(Instance& d) { // печать слоаваря
		std::cout << "-------" << d.name << "-------" << std::endl;
		for (int i = 0; i < d.size; i++) {
			std::cout << d.dictionary[i]->id << " ";
			for (int j = 0; j < strlen(d.dictionary[i]->name); j++)
				std::cout << d.dictionary[i]->name[j];
			std::cout << std::endl;
		}
	}
}