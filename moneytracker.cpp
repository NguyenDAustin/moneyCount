    #include <iostream>
    #include <fstream>
    using namespace std;

    void menu()
    {
        cout << "******************" << endl;
        cout << "1. Balance" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Exit" << endl;
        cout << "*******************" << endl;
    }

    int calculate(int& b, int o, int te, int f, int t, int tt, int ff, int h)
    {
        b = (o + (te*2)+ (f *5) + (t*10) + (tt*20) + (ff*50) + (h*100));

        return b;
    }


    int main ()
    {
        ifstream checkFile("Account.txt"); //checks for file
        bool fileExists = checkFile.good(); 
        checkFile.close();

        ofstream file;


        if (!fileExists){
            file.open("Account.txt");
        }

        ifstream inputFile("Account.txt");
    

        int opt;
        int bal = 0;
        int con;

        int ones = 0;
        int twos = 0;
        int fives = 0;
        int tens = 0;
        int twenties = 0;
        int fifties = 0;
        int hundreds= 0;

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
        system("clear");
        
        switch (opt){
            case 1:
            
            cout << "Balence is: $" << bal << endl;
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
            cout << "withdrawing:" << endl;
            cout <<  "ones: " << endl;
            cin >> tones;
            cout << "twos: " << endl;
            cin >> ttwos;
            cout <<  "fives: " << endl;
            cin >> tfives;
            cout <<  "tens: " << endl;
            cin >> ttens;
            cout << "twenties: " << endl;
            cin >> ttwenties;
            cout << "fifties: " << endl;
            cin >> tfifties;
            cout << "hundreds: " << endl;
            cin >> thundreds;

            ones -= tones;
            twos -= ttwos;
            fives -= tfives;
            tens -= ttens;
            twenties -= ttwenties;
            fifties -= tfifties;
            hundreds -= thundreds;

            bal = calculate(bal, ones, twos, fives, tens, twenties, fifties, hundreds);

            break;
        
        case 3:
            cout << "Depositing:" << endl;
            cout <<  "ones: " << endl;
            cin >> tones;
            cout << "twos: " << endl;
            cin >> ttwos;
            cout <<  "fives: " << endl;
            cin >> tfives;
            cout <<  "tens: " << endl;
            cin >> ttens;
            cout << "twenties: " << endl;
            cin >> ttwenties;
            cout << "fifties: " << endl;
            cin >> tfifties;
            cout << "hundreds: " << endl;
            cin >> thundreds;

            ones += tones;
            twos += ttwos;
            fives += tfives;
            tens += ttens;
            twenties += ttwenties;
            fifties += tfifties;
            hundreds += thundreds;

            bal = calculate(bal, ones, twos, fives, tens, twenties, fifties, hundreds);

            break;

        case 4:
            cout << "thank you" << endl;
            break;
        } 
        } while (opt != 4);
        

        if (!fileExists)
        {
            file << "Total: $" << bal << endl;
            file << "Ones: " << ones << endl;
            file << "Twos: " << twos << endl;
            file << "Fives: " << fives << endl;
            file << "Tens: " << tens << endl;
            file << "Twenties: " << twenties << endl;
            file << "Fifties: " << fifties << endl;
            file << "Hundreds: " << hundreds << endl;

            file.close();
        }
    }
