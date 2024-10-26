#include <iostream>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

// Функция для имитации вращения барабана
int spinReel() {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 7); // Генерируем числа от 1 до 7 (можно изменить диапазон и количество символов)
    return dist(gen);
}

int main() {
    // Символы на барабанах (можно заменить на любые другие)
    vector<char> symbols = { '$', '7', '@', '#', '&', '%', '+' };

    // Приветствие
    cout << "Добро пожаловать в игру \"Однорукий бандит\"!" << endl;

    while (true) {
        cout << "Нажмите Enter для вращения барабанов (или q для выхода): ";
        char input;
        cin.get(input);

        if (input == 'q' || input == 'Q') {
            break;
        }

        // Вращаем барабаны
        int reel1 = spinReel();
        int reel2 = spinReel();
        int reel3 = spinReel();

        // Выводим результат вращения
        cout << "Результат: " << symbols[reel1 - 1] << " " << symbols[reel2 - 1] << " " << symbols[reel3 - 1] << endl;

        // Проверяем выигрышные комбинации (примеры)
        if (reel1 == reel2 && reel2 == reel3) {
            cout << "Джекпот! Вы выиграли 100 монет!" << endl;
        }
        else if (reel1 == reel2 || reel2 == reel3 || reel1 == reel3) {
            cout << "Вы выиграли 10 монет!" << endl;
        }
        else {
            cout << "Попробуйте еще раз!" << endl;
        }
    }

    cout << "Спасибо за игру!" << endl;

    return 0;
}
