#include "funcs.cpp"

int main() {
    // Character c1("John", NORMAL, HUMAN, true, 10);
    // Character c2(c1);
    // std::cout << c1 << std::endl << c2 << std::endl;
    // Character c3(std::move(c1));
    // std::cout << c1 << std::endl << c3 << std::endl;

    // MagicCharacter mc1("Gandalf", NORMAL, ELF, true, 1, 100, 2, {WEAPON, ARMOR});
    // std::cout << mc1 << std::endl;

    // MagicCharacter mc2(mc1);
    // std::cout << mc2 << std::endl;

    // MagicCharacter mc3(std::move(mc1));
    // std::cout << mc1 << std::endl << mc3 << std::endl;
    std::vector<Person*> characters;
    characters.push_back(new Character("John", NORMAL, HUMAN, true, 10));
    characters.push_back(new MagicCharacter("Gandalf", NORMAL, ELF, true, 1, 100, 2, {WEAPON, ARMOR}));
    characters.push_back(new Character("Dwarf", NORMAL, DWORF, true, 10));
    characters.push_back(new MagicCharacter("Magican", NORMAL, ELF, true, 1, 100, 2, {WEAPON, ARMOR}));

    printCharacters(characters);

    CharacterTypeAmount(characters);
}