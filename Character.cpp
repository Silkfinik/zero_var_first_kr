#include "Character.h"

__int16 Character::idCounter = 1;

Character& Character::operator=(const Character& other) {
    name = other.name;
    condition = other.condition;
    isMovable = other.isMovable;
    quantity = other.quantity;
    return *this;
}

Character& Character::operator=(Character&& other) noexcept {
    name = std::move(other.name);
    condition = std::move(other.condition);
    isMovable = std::move(other.isMovable);
    quantity = std::move(other.quantity);
    return *this;
}

