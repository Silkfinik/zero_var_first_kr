#include <iostream>
#include <typeinfo>
#include <algorithm>

#include "MCharacter.h"


// перегрузка оператора вывода для класса Character
std::ostream& operator<<(std::ostream& os, const Character& character) {
    os << "ID: " << character.getId() << "\n";
    os << "Name: " << character.getName() << "\n";

    std::string* cond_enum = new std::string[3]{"Normal", "Paralyzed", "Dead"};
    os << "Condition: " << cond_enum[character.getCondition()] << "\n";
    delete[] cond_enum;
    
    std::string* race_enum = new std::string[3]{"Human", "DWARF", "Elf"};
    os << "Race: " << race_enum[character.getRace()] << "\n";
    delete[] race_enum;
    
    os << "Movable: " << (character.getIsMovable() ? "Yes" : "No") << "\n";
    os << "Quantity: " << character.getQuantity() << "\n";
    
    return os;
}

// перегрузка оператора вывода для класса MagicCharacter
std::ostream& operator<<(std::ostream& os, const MagicCharacter& mcharacter) {
    os << "ID: " << mcharacter.getId() << "\n";
    os << "Name: " << mcharacter.getName() << "\n";

    std::string* cond_enum = new std::string[3]{"Normal", "Paralyzed", "Dead"};
    os << "Condition: " << cond_enum[mcharacter.getCondition()] << "\n";
    delete[] cond_enum;

    std::string* race_enum = new std::string[3]{"Human", "DWARF", "Elf"};
    os << "Race: " << race_enum[mcharacter.getRace()] << "\n";
    delete[] race_enum;
    os << "Movable: " << (mcharacter.getIsMovable() ? "Yes" : "No") << "\n";
    os << "Quantity: " << mcharacter.getQuantity() << "\n";
    os << "Mana: " << mcharacter.getMana() << "\n";
    os << "Artefacts amount: " << mcharacter.getArtefactsAmount() << "\n";
    os << "Artefacts: ";
    
    std::vector<ArtefactType> artefacts = mcharacter.getArtefacts();
    for (auto& artefact : artefacts) {
        switch (artefact) {
            case WEAPON:
                os << "Weapon ";
                break;
            case ARMOR:
                os << "Armor ";
                break;
            case POTION:
                os << "Potion ";
                break;
        }
    
    }
    
    os << "\n";
    
    return os;
}

// функция для вывода всех персонажей
void printCharacters(std::vector<Character*> characters) {
    for (auto& character : characters) {
        std::string type = typeid(*character).name();
        type = type.substr(1);

        if (type == "Character") {
            std::cout << *dynamic_cast<Character*>(character) << std::endl;
        } else {
            std::cout << *dynamic_cast<MagicCharacter*>(character) << std::endl;
        }
    }
}

// функция для вывода количества персонажей каждого типа
void CharacterTypeAmount(std::vector<Character*> characters) {
    __int16 Default = 0;
    __int16 Magic = 0;

    for (auto& character : characters) {
        std::string type = typeid(*character).name();
        type = type.substr(1);

        if (type == "Character") {
            Default++;
        } else {
            Magic++;
        }
    }

    std::cout << "Default characters: " << Default << std::endl;
    std::cout << "Magic characters: " << Magic << std::endl;
}

// функция для сортировки персонажей по имени
void sortByName(std::vector<Character*>& characters) {
    std::sort(characters.begin(), characters.end(), [](Character* a, Character* b) {
        return a->getName() < b->getName();
    });
}

// функция для удаления всех персонажей
void deleteCharacters(std::vector<Character*>& characters) {
    for (auto& character : characters) {
        delete character;
    }
}