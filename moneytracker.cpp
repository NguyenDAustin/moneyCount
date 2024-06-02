#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void menu() {
    cout << "******************" << endl;
    cout << "1. Balance" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Deposit" << endl;
    cout << "4. Exit" << endl;
    cout << "*******************" << endl;
}

int calculate(int o, int te, int f, int t, int tt, int ff, int h) {
    return (o + (te * 2) + (f * 5) + (t * 10) + (tt * 20) + (ff * 50) + (h * 100));
}

void acc(int b, int o, int te, int f, int t, int tt, int ff, int h) {
    fstream file;

    file.open("Accounts.txt", ios::out);
    if (file.is_open()) {
        file << "Total: $" << b << endl;
        file << "Ones: " << o << endl;
        file << "Twos: " << te << endl;
        file << "Fives: " << f << endl;
        file << "Tens: " << t << endl;
        file << "Twenties: " << tt << endl;
        file << "Fifties: " << ff << endl;
        file << "Hundreds: " << h << endl;

        file.close();
    }
}

void val(int &bal, int &ones, int &twos, int &fives, int &tens, int &twenties, int &fifties, int &hundreds) {
    fstream file;
    file.open("Accounts.txt", ios::in);

    if (file.is_open()) {
        string line;

        getline(file, line);
        bal = stoi(line.substr(line.find("$") + 1));

        getline(file, line);
        ones = stoi(line.substr(line.find(":") + 2));

        getline(file, line);
        twos = stoi(line.substr(line.find(":") + 2));

        getline(file, line);
        fives = stoi(line.substr(line.find(":") + 2));

        getline(file, line);
        tens = stoi(line.substr(line.find(":") + 2));

        getline(file, line);
        twenties = stoi(line.substr(line.find(":") + 2));

        getline(file, line);
        fifties = stoi(line.substr(line.find(":") + 2));

        getline(file, line);
        hundreds = stoi(line.substr(line.find(":") + 2));
    }

    file.close();
}

int main() {
    int bal = 0;
    int ones = 0;
    int twos = 0;
    int fives = 0;
    int tens = 0;
    int twenties = 0;
    int fifties = 0;
    int hundreds = 0;

    val(bal, ones, twos, fives, tens, twenties, fifties, hundreds);

    int opt;

    int tones;
    int ttwos;
    int tfives;
    int ttens;
    int ttwenties;
    int tfifties;
    int thundreds;

    do {
        menu();
        cin >> opt;

        switch (opt) {
        case 1:
            cout << "Balance is: $" << bal << endl;
            cout << ones << " ones" << endl;
            cout << twos << " twos" << endl;
            cout << fives << " fives" << endl;
            cout << tens << " tens" << endl;
            cout << twenties << " twenties" << endl;
            cout << fifties << " fifties" << endl;
            cout << hundreds << " hundreds" << endl;
            cout << endl;
            break;

        case 2:
            cout << "Withdrawing:" << endl;
            cout << "ones: "; cin >> tones;
            cout << "twos: "; cin >> ttwos;
            cout << "fives: "; cin >> tfives;
            cout << "tens: "; cin >> ttens;
            cout << "twenties: "; cin >> ttwenties;
            cout << "fifties: "; cin >> tfifties;
            cout << "hundreds: "; cin >> thundreds;

            ones -= tones;
            twos -= ttwos;
            fives -= tfives;
            tens -= ttens;
            twenties -= ttwenties;
            fifties -= tfifties;
            hundreds -= thundreds;

            bal = calculate(ones, twos, fives, tens, twenties, fifties, hundreds);

            break;

        case 3:
            cout << "Depositing:" << endl;
            cout << "ones: "; cin >> tones;
            cout << "twos: "; cin >> ttwos;
            cout << "fives: "; cin >> tfives;
            cout << "tens: "; cin >> ttens;
            cout << "twenties: "; cin >> ttwenties;
            cout << "fifties: "; cin >> tfifties;
            cout << "hundreds: "; cin >> thundreds;

            ones += tones;
            twos += ttwos;
            fives += tfives;
            tens += ttens;
            twenties += ttwenties;
            fifties += tfifties;
            hundreds += thundreds;

            bal = calculate(ones, twos, fives, tens, twenties, fifties, hundreds);

            break;

        case 4:
            cout << "Thank you" << endl;
            break;
        }
    } while (opt != 4);

    acc(bal, ones, twos, fives, tens, twenties, fifties, hundreds);

    return 0;
}
