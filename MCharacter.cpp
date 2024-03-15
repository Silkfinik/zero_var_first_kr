#include "Mcharacter.h"

MagicCharacter& MagicCharacter::operator=(const MagicCharacter& other) {
    Character::operator=(other);
    mana = other.mana;
    artefactsAmount = other.artefactsAmount;
    artefacts = other.artefacts;
    return *this;
}

MagicCharacter& MagicCharacter::operator=(MagicCharacter&& other) noexcept {
    Character::operator=(std::move(other));
    mana = std::move(other.mana);
    artefactsAmount = std::move(other.artefactsAmount);
    artefacts = std::move(other.artefacts);
    return *this;
}