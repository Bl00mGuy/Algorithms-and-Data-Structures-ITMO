#include <iostream>
using namespace std;

struct fridge {
    int l_milk;
    int kg_meat;
    int pieces_cheese;
    int beer_bottles;
};

int main() {
    int choice1, choice2;
    int infinity = 1;
    fridge my_fridge = {0, 0, 0, 0,};
    for (;;) {
        do {
            cout << "In your fridge: \n";
            cout << "Liters of milk: " << my_fridge.l_milk << " \n";
            cout << "Kilogram of meat: " << my_fridge.kg_meat << " \n";
            cout << "Pieces of cheese: " << my_fridge.pieces_cheese << " \n";
            cout << "Beer bottles: " << my_fridge.beer_bottles << " \n";
            cout << "If you want to add something enter \"1\"" << " \n";
            cout << "If you want to remove something enter \"0\"" << " \n";
            cin >> choice1;
            if (choice1 == 1) {
                cout << "What you want to put in fridge ?" << " \n";
            }
            if (choice1 == 0) {
                cout << "What you want to remove from fridge ?" << " \n";
            }
            cout << "1. Milk" << " \n";
            cout << "2. Meat" << " \n";
            cout << "3. Cheese" << " \n";
            cout << "4. Beer" << " \n";
            cin >> choice2;
            // Фун-я добавления предметов
            if (choice1 == 1 && choice2 == 1) {
                my_fridge.l_milk = ++my_fridge.l_milk;
            }
            if (choice1 == 1 && choice2 == 2) {
                my_fridge.kg_meat = ++my_fridge.kg_meat;
            }
            if (choice1 == 1 && choice2 == 3) {
                my_fridge.pieces_cheese = ++my_fridge.pieces_cheese;
            }
            if (choice1 == 1 && choice2 == 4) {
                my_fridge.beer_bottles = ++my_fridge.beer_bottles;
            }
            // Фун-я удаления предметов
            if (choice1 == 0 && choice2 == 1) {
                my_fridge.l_milk = --my_fridge.l_milk;
            }
            if (choice1 == 0 && choice2 == 2) {
                my_fridge.kg_meat = --my_fridge.kg_meat;
            }
            if (choice1 == 0 && choice2 == 3) {
                my_fridge.pieces_cheese = --my_fridge.pieces_cheese;
            }
            if (choice1 == 0 && choice2 == 4) {
                my_fridge.beer_bottles = --my_fridge.beer_bottles;
            }
        } while (infinity > 0);
    }
    return 0;
}
