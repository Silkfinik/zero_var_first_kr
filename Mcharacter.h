#ifndef MCHARACTER_H
#define MCHARACTER_H


#include <stdexcept>
#include <vector>

#include "Character.h"

enum ArtefactType {
    WEAPON,
    ARMOR,
    POTION
};

class MagicCharacter final : public Character {
    private:
        const __int16 maxMana = 1000;
        unsigned __int16 mana;
        __int16 artefactsAmount;
        std::vector<ArtefactType> artefacts;

    public:
        // конструктор
        MagicCharacter(std::string _name, const Condition& _cond, const Race& _race, const bool& _isMov, const __int16& _quant,
        const __int16 _mana, const __int16&  _artAmount, std::vector<ArtefactType> _artefacts) : 
        Character(_name, _cond, _race, _isMov, _quant), mana(_mana), artefactsAmount(_artAmount),
        artefacts(std::move(_artefacts)) { if (mana > maxMana) throw std::invalid_argument("Error: mana > maxMana(1000)"); };

        // конструктор копирования
        MagicCharacter (const MagicCharacter& other) :
        Character(other), mana(other.mana), artefactsAmount(other.artefactsAmount),artefacts(other.artefacts) {};

        // конструктор перемещения
        MagicCharacter (MagicCharacter&& other) noexcept :
        Character(std::move(other)), mana(std::move(other.mana)), artefactsAmount(std::move(other.artefactsAmount)),
        artefacts(std::move(other.artefacts)) {};

        // перегрузка оператора присваивания
        MagicCharacter& operator=(const MagicCharacter& other);
        MagicCharacter& operator=(MagicCharacter&& other) noexcept;

        // геттеры
        unsigned __int16 getMana() const { return mana; };
        __int16 getArtefactsAmount() const { return artefactsAmount; };
        std::vector<ArtefactType> getArtefacts() const { return artefacts; };
        
        // сеттеры
        void setMana(unsigned __int16 _mana){ if (_mana > maxMana) throw std::invalid_argument("Error: mana > maxMana(1000)"); mana = _mana; };
        void setArtefactsAmount(__int16 _artAmount) { artefactsAmount = _artAmount; };
        void setArtefacts(std::vector<ArtefactType> _artefacts) { artefacts = std::move(_artefacts); };
};


#endif // MCHARACTER_H