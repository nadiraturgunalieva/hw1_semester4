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

    
}
int main()
{
    setlocale(LC_ALL, "Rus");
    std::cout << "\n";
}
