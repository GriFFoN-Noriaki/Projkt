#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>


using namespace std;
void rules();

int main()
{
    setlocale(LC_ALL, "Rus");

    string playerName;
    int balance;
    int bettingAmount;
    int guess;
    int dice;
    char choice;

    srand(time(0));

    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "Введите ваше имя: ";
    cin >> playerName;

    cout << "Введите стартовый баланс для игры: $";
    cin >> balance;
    do
    {
        system("cls");
        rules();
        cout << "Ваш текущий баланс - $ " << balance << "\n";

        do
        {
            cout << "Приветствуем, " << playerName << ", введите сумму, которую хотите поставить: $";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "Баланс ставок не может превышать текущий баланс!\n"
                << "Введите баланс заново:\n ";
        } while (bettingAmount > balance);

        do
        {
            cout << "Введите число в промежутке от 1 до 10 :";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "Число должно быть в промежутке от 1 до 10\n"
                << "Введите число заново:\n ";
        } while (guess <= 0 || guess > 10);
        dice = rand() % 10 + 1;
        if (dice == guess)
            {
            cout << "Вам повезло! Вы выйграли " << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
            }
        else
        {
            cout << "Упс, удачи в следующий раз! Вы проиграли $" << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }
        cout << "Выигрышный номер был: " << dice << "\n";
        cout << playerName << ", ваш баланс - $ " << balance << "\n";

        if (balance == 0)
        {
            cout << "У вас нет денег для игры";
            break;
        }
        cout << "-->Хотите сыграть снова? (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\n\n";
    cout << "Спасибо, что поиграли в игру! Ваш баланс - $ " << balance << "\n\n";
    return 0;
}

void rules()
{
    system("cls");
    cout << "\t\t======ПРАВИЛА УГАДЫВАНИЯ ЧИСЕЛ В КАЗИНО!======\n";
    cout << "\t1. Выберите число от 1 до 10\n";
    cout << "\t2. Победитель получает 10-кратную ставку.\n";
    cout << "\t3. Неправильная ставка — и вы потеряете поставленную сумму.\n\n";
}