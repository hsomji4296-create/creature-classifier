#include <iostream>
#include <string>
using namespace std;

int main() {
    string size;
    int magicLevel;
    int numHorns;
    int isFriendly;
    string creature;

    cout << "Welcome to the Fantasy Creature Classifier!" << endl << endl;

    cout << "Enter the size (small, medium, large): ";
    cin >> size;
    cout << "Enter the magic level (1-10): ";
    cin >> magicLevel;
    cout << "Enter the number of horns: ";
    cin >> numHorns;
    cout << "Is it friendly? (1 for yes, 0 for no): ";
    cin >> isFriendly;

    // Compound condition: reject anything that is not valid input
    if ((size != "small" && size != "medium" && size != "large") ||
        magicLevel < 1 || magicLevel > 10 ||
        numHorns < 0 ||
        (isFriendly != 0 && isFriendly != 1)) {
        cout << "Invalid input. Please run the program again." << endl;
        return 1;
    }

    // Decide the creature
    if (size == "large") {
        // Nested decision for large creatures
        if (magicLevel >= 8 && isFriendly == 0) {
            creature = "Dragon";
        } else if (magicLevel <= 3 && isFriendly == 0) {
            creature = "Troll";
        } else {
            creature = "Mystery Creature";
        }
    } else if (size == "medium" && numHorns == 1 && isFriendly == 1 && magicLevel >= 7) {
        creature = "Unicorn";
    } else if (size == "small") {
        // Nested decision for small creatures
        // EXTRA CREDIT - Fairy: the creature must be small, friendly,
        // have a magic level of 6 or higher, and have no horns.
        if (isFriendly == 1 && magicLevel >= 6 && numHorns == 0) {
            creature = "Fairy";
        } else if (isFriendly == 0) {
            creature = "Goblin";
        } else {
            creature = "Mystery Creature";
        }
    } else {
        creature = "Mystery Creature";
    }

    cout << endl << "--- Creature Result ---" << endl << endl;
    cout << "Your creature is a " << creature << "!" << endl;

    return 0;
}
