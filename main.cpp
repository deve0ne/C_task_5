#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Car {
    string carNumber;
    string model;
    int type;

    union {
        struct {
            int passengerCount;
        } passengerCar;
        struct {
            int weightLimit;
        } truck;
    };
    string owner;
};

Car createCar() {
    Car newCar;

    cout << "Номер авто: " << endl;
    cin >> newCar.carNumber;
    cout << "Марка авто: " << endl;
    cin >> newCar.model;

    cout << "Автомобиль является легковым или грузовым? (0 - легковой или 1 - грузовой): " << endl;
    cin >> newCar.type;

    if (newCar.type == 0) {
        cout << "Введите максимальное кол-во пассажиров: " << endl;
        cin >> newCar.passengerCar.passengerCount;
    } else {
        cout << "Введите максимальный вес груза: " << endl;
        cin >> newCar.truck.weightLimit;
    }

    cout << "Укажите имя владельца автомобиля: " << endl;
    cin >> newCar.owner;

    return newCar;
}

void printCar(Car car) {
    cout << "Номер авто: " << car.carNumber << endl;
    cout << "Марка авто: " << car.model << endl;

    if (car.type == 0) {
        cout << "Тип: легковой автомобиль" << endl;
        cout << "Максимальное количество пассажиров: " << car.passengerCar.passengerCount << endl;
    } else {
        cout << "Тип: грузовой автомобиль" << endl;
        cout << "Максимальный вес груза: " << endl;
    }

    cout << "Владелец автомобиля: " << car.owner << endl;
}

int main() {
    vector<Car> objects;

    while (true) {
        cout << "0 - Добавить элемент" << "\n";
        cout << "1 - Удалить элемент" << "\n";
        cout << "2 - Вывести элемент" << "\n";
        cout << "3 - Вывести количество элементов" << "\n";
        cout << "4 - Завершить программу" << "\n\n";

        int choose = -1;

        cout << "Выберите действие: ";
        cin >> choose;

        switch (choose) {
            case 0: {
                objects.push_back(createCar());
                break;
            }
            case 1: {
                int index = -1;
                cout << "Введите номер элемента для удаления: ";
                cin >> index;
                index--;

                if (index > objects.size() - 1 || index < 0) {
                    cout << "Такого элемента не существует\n";
                    break;
                }

                if (objects.empty()) {
                    cout << "Вектор объектов пуст\n";
                    break;
                }

                objects.erase(objects.begin() + index);
                break;
            }
            case 2: {
                int index = -1;
                cout << "Введите номер элемента: ";
                cin >> index;
                index--;

                if (index > objects.size() - 1 || index < 0) {
                    cout << "Такого элемента не существует\n";
                    break;
                }

                if (objects.empty()) {
                    cout << "Вектор объектов пуст\n";
                    break;
                }

                printCar(objects.at(index));
                break;
            }
            case 3: {
                cout << "Количество элементов: " << objects.size() << "\n";
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                cout << "Вы ввели некорректное число, повторите попытку";
            }
        }

        cout << "\n";
    }
}
