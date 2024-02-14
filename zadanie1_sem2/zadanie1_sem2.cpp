#include <iostream>

class cashRegister {
private:
    int cashOnHand;
public:
    cashRegister() {
        cashOnHand = 500;
    }
    cashRegister(int cash) {
        cashOnHand = cash;
    }
    int getCurrentBalance() {
        return cashOnHand;
    }
    void acceptAmount(int amount) {
        cashOnHand += amount;
    }
 
};

class dispenserType {
private:
    int numberOfItems;
    int cost;

public:
    dispenserType() {
        numberOfItems = 50;
        cost = 50;
    }
    dispenserType(int items, int price) {
        numberOfItems = items;
        cost = price;
    }
    int getNoOfItems() {
        return numberOfItems;
    }
    int getCost() {
        return cost;
    }
    void makeSale() {
        numberOfItems--;
    }
};

void showSelection() {
    std::cout << "Меню: " << std::endl;
    std::cout << "1. Конфеты" << std::endl;
    std::cout << "2. Чипсы" << std::endl;
    std::cout << "3. Жвачка" << std::endl;
    std::cout << "4. Печеньки" << std::endl;
    std::cout << "Выберите номер продукта: ";
}

void sellProduct(dispenserType& dispenser, cashRegister& cashReg) {
    int amount;
    switch (dispenser.getNoOfItems()) {
        case 0:
            std::cout << "К сожалению, продукт закончился. \n";
            std::cout << "Выберите другой продукт. \n";
            return;
    }
    int cost = dispenser.getCost();
    std::cout << "Стоимость товара: " << cost << " руб. \n";
    std::cout << "Введите сумму: ";
    std::cin >> amount;
    while (amount < dispenser.getCost()) {
        std::cout << "Недостаточно средств. Попробуйте ещё раз: ";
        std::cin >> amount;
    }
    dispenser.makeSale();
    cashReg.acceptAmount(dispenser.getCost());
    std::cout << "Вы внесли: " << amount << " руб.\n";
    amount -= dispenser.getCost();
    std::cout << "Ваша сдача: " << amount << " руб.\n";
    std::cout << "Продукт выдан.\n";
    
}
int main() {
    setlocale(LC_ALL, "Rus");

    dispenserType candy(2, 67);
    dispenserType chips(23, 120);
    dispenserType gum(78, 10);
    dispenserType cookies(50, 45);

    cashRegister cashReg;

    int choice;

    while (true) {
        showSelection();
        std::cin >> choice;

        switch (choice) {
        case 1:
            sellProduct(candy, cashReg);
            break;
        case 2:
            sellProduct(chips, cashReg);
            break;
        case 3:
            sellProduct(gum, cashReg);
            break;
        case 4:
            sellProduct(cookies, cashReg);
            break;
        default:
            std::cout << "Некорректный выбор. Пожалуйста, попробуйте ещё раз. \n";
            break;
        }
    }

    return 0;
}
