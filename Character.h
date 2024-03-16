#ifndef CHARACTER_H
#define CHARACTER_H


#include "Person.h"

#include <string>

// перечисление для расы
enum Race {
    HUMAN,
    DWARF,
    ELF
};

// перечисление для состояния
enum Condition { 
    NORMAL,
    PARALYZED,
    DEAD
};

class Character : public Person{
    private:
        static __int16 idCounter;

    protected:
        const __int16 id;
        std::string name;
        Condition condition;
        const Race race;
        bool isMovable;
        __int16 quantity;

    public:
        // конструктор
        Character(std::string _name, const Condition& _cond, const Race& _race, const bool& _isMov, const __int16& _quant) :
        id(idCounter++), name(std::move(_name)), condition(_cond), race(_race), isMovable(_isMov), quantity(_quant) {};

        // конструктор копирования
        Character (const Character& other) : id(idCounter++), name(other.name), condition(other.condition), race(other.race),
        isMovable(other.isMovable), quantity(other.quantity) {};

        // конструктор перемещения
        Character (Character&& other) noexcept :
        id(idCounter++), name(std::move(other.name)), condition(std::move(other.condition)), 
        race(std::move(other.race)), isMovable(std::move(other.isMovable)), quantity(std::move(other.quantity)) {};

        // перегрузка оператора присваивания
        Character& operator=(const Character& other);
        Character& operator=(Character&& other) noexcept;

        // геттеры
        __int16 getId() const { return id; }
        std::string getName() const { return name; }
        Condition getCondition() const { return condition; };
        Race getRace() const { return race; };
        bool getIsMovable() const { return isMovable; };
        __int16 getQuantity() const { return quantity; };

        // сеттеры
        void setName(std::string _name) { name = std::move(_name); };
        void setCondition(Condition _cond) { condition = _cond; };
        void setIsMovable(bool _isMov) { isMovable = _isMov; };
        void setQuantity(__int16 _quant) { quantity = _quant; };

        // перегрузка оператора сравнения
        bool operator<(const Character& other) const { return id < other.id; };
};


#endif // CHARACTER_H