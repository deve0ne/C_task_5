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

    cout << "����� ���: " << endl;
    cin >> newCar.carNumber;
    cout << "��ઠ ���: " << endl;
    cin >> newCar.model;

    cout << "��⮬����� ���� ������� ��� ��㧮��? (0 - �������� ��� 1 - ��㧮���): " << endl;
    cin >> newCar.type;

    if (newCar.type == 0) {
        cout << "������ ���ᨬ��쭮� ���-�� ���ᠦ�஢: " << endl;
        cin >> newCar.passengerCar.passengerCount;
    } else {
        cout << "������ ���ᨬ���� ��� ��㧠: " << endl;
        cin >> newCar.truck.weightLimit;
    }

    cout << "������ ��� �������� ��⮬�����: " << endl;
    cin >> newCar.owner;

    return newCar;
}

void printCar(Car car) {
    cout << "����� ���: " << car.carNumber << endl;
    cout << "��ઠ ���: " << car.model << endl;

    if (car.type == 0) {
        cout << "���: �������� ��⮬�����" << endl;
        cout << "���ᨬ��쭮� ������⢮ ���ᠦ�஢: " << car.passengerCar.passengerCount << endl;
    } else {
        cout << "���: ��㧮��� ��⮬�����" << endl;
        cout << "���ᨬ���� ��� ��㧠: " << endl;
    }

    cout << "�������� ��⮬�����: " << car.owner << endl;
}

int main() {
    vector<Car> objects;

    while (true) {
        cout << "0 - �������� �����" << "\n";
        cout << "1 - ������� �����" << "\n";
        cout << "2 - �뢥�� �����" << "\n";
        cout << "3 - �뢥�� ������⢮ ����⮢" << "\n";
        cout << "4 - �������� �ணࠬ��" << "\n\n";

        int choose = -1;

        cout << "�롥�� ����⢨�: ";
        cin >> choose;

        switch (choose) {
            case 0: {
                objects.push_back(createCar());
                break;
            }
            case 1: {
                int index = -1;
                cout << "������ ����� ����� ��� 㤠�����: ";
                cin >> index;
                index--;

                if (index > objects.size() - 1 || index < 0) {
                    cout << "������ ����� �� �������\n";
                    break;
                }

                if (objects.empty()) {
                    cout << "����� ��ꥪ⮢ ����\n";
                    break;
                }

                objects.erase(objects.begin() + index);
                break;
            }
            case 2: {
                int index = -1;
                cout << "������ ����� �����: ";
                cin >> index;
                index--;

                if (index > objects.size() - 1 || index < 0) {
                    cout << "������ ����� �� �������\n";
                    break;
                }

                if (objects.empty()) {
                    cout << "����� ��ꥪ⮢ ����\n";
                    break;
                }

                printCar(objects.at(index));
                break;
            }
            case 3: {
                cout << "������⢮ ����⮢: " << objects.size() << "\n";
                break;
            }
            case 4: {
                return 0;
            }
            default: {
                cout << "�� ����� �����४⭮� �᫮, ������ ������";
            }
        }

        cout << "\n";
    }
}
