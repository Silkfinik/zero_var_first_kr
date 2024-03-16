#include "funcs.cpp"
#include <iostream>

int main() {
    try{
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
        std::vector<Character*> characters;
        characters.push_back(new Character("John", NORMAL, HUMAN, true, 10));
        characters.push_back(new MagicCharacter("Gandalf", NORMAL, ELF, true, 1, 1000, 2, {WEAPON, ARMOR}));
        characters.push_back(new Character("Dwarf", NORMAL, DWARF, true, 10));
        characters.push_back(new MagicCharacter("Magican", NORMAL, ELF, true, 1, 100, 2, {WEAPON, ARMOR}));

        std::cout << "| Unsorted all characters |\n" << std::endl;
        printCharacters(characters);
        std::cout << "------------------------------------" << std::endl;

        std::cout << "| Character type amount |\n" << std::endl;
        CharacterTypeAmount(characters);
        std::cout << "------------------------------------" << std::endl;
        std::cout << std::endl;

        std::cout << "| Sorted by name |\n" << std::endl;
        sortByName(characters);
        printCharacters(characters);

        deleteCharacters(characters);
    }
    catch(const std::exception& err){
        std::cerr << err.what() << '\n';
    }
}