// Electricity Bill System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"graphics.h"
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<chrono>
#include<thread>
#include<windows.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
#pragma warning(disable : 4996)
#pragma comment(lib,"graphics.lib")
using namespace std;

class electricity {
    char name[20], cat;
    double pmr, cmr, cu;
    long cnum;
    double ba;
    public:
    void get();
    void show();
    void calc();
    void StoreToFile();
};
void electricity::get() {
    system("Color E5");
    cout << "-----------------------------------------------------------------------------------------";
    cout << "\n";
    cout << "                         ELECTRICITY BILL SYSTEM            \n\n";
    cout << "-----------------------------------------------------------------------------------------";
    cout << "\n";
    cout << "Enter customer name: ";
    cin >> name;
    cout << "Enter previous meter reading (kWh): ";
    cin >> pmr;
    cout << "Enter current meter reading (kWh): ";
    cin >> cmr;
    cout << "Enter customer Bill number: ";
    cin >> cnum;
    cout << "Enter customer category (Select (A/a) = T20 ,Select (B/b)= M40 ,Select (C/c)= B40): ";
    cin >> cat;
    cout << "------------------------------------------------------------------------------------------";
    
}
void electricity::calc() {
    cu = cmr - pmr;
    double a, b, c;
    switch (cat) {
    case 'a': //T20
    case 'A':
        a = 100 * 2;//current price
        b = 150 * 3;
        c = 100 * 5;
        if (cu > 300)
            ba = a + b + c + ((cu - 300) * 10);
        else if (cu <= 300 && cu > 200)
            ba = a + b + ((cu - 200) * 5);
        else if (cu <= 200 && cu > 100)
            ba = a + ((cu - 100) * 3);
        else
            ba = cu * 2;
        break;
    case 'b': //m40
    case 'B':
        a = 100 * 1;//current price
        b = 150 * 2;
        c = 100 * 3;
        if (cu > 300)
            ba = a + b + c + ((cu - 300) * 4);
        else if (cu <= 300 && cu > 200)
            ba = a + b + ((cu - 200) * 3);
        else if (cu <= 200 && cu > 100)
            ba = a + ((cu - 100) * 2);
        else
            ba = cu;
        break;
    case'c': //b40
    case'C':
        a= 100 * 0.80;//current price
        b = 150 * 1.90;
        c = 100 * 3.40;
        if (cu > 300)
            ba = a + b + c + ((cu - 300) * 7);
        else if (cu <= 300 && cu > 200)
            ba = a + b + ((cu - 200) * 3.40);
        else if (cu <= 200 && cu > 100)
            ba = a + ((cu - 100) * 1.90);
        else
            ba = cu * 0.80;
        break;
    default:
        cout << "Wrong entry";


    }
}
void electricity::show() {
    cout << "-";
    cout << "\n";
    cout << "ELECTRICITY BILL INFORMATION\n\n";
    cout << "\nCustomer name            :" << name;
    cout << "\nCustomer Bill number     :" << cnum;
    cout << "\nCustomer category        :" << cat;
    cout << "\nPrevious meter reading   :" << pmr<<" kWh";
    cout << "\nCurrent  meter reading   :" << cmr<<" kWh";
    cout << "\nConsumed units           :" << cu;
    cout << "\nTotal bill amount        :RM " << ba;
}
void electricity::StoreToFile() {
    ofstream outFile("ElectricityRecord.txt", std::ios_base::app);  // Open file 
    if (outFile.is_open()) {
        outFile << "--------------------------------------\n";
        outFile << "ELECTRICITY BILL INFORMATION:\n\n";
        outFile << "Customer name            :" << name << '\n';
        outFile << "Customer Bill number     :" << cnum << '\n';
        outFile << "Customer category        :" << cat << '\n';
        outFile << "Previous meter reading   :" << pmr <<"kWh"<< '\n';
        outFile << "Current meter reading    :" << cmr <<"kWh"<< '\n';
        outFile << "Consumed units           :" << cu << '\n';
        outFile << "Total bill amount        :RM " << ba << "\n\n";
        outFile.close();
        cout << endl;
        cout << "Data successfully written to ElectricityRecord.txt" << endl;
    }
    else {
        cout << "Unable to open file for writing." << endl;
    }
}
void Animation(const string& animation, int delay) {
    for (char c : animation) {
      cout << c << flush;
      this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << "\r" << string(animation.length(), ' ') << "\r" << flush;
}

void displayWelcomeMessage() {
   string welcomeMessage = "WELCOME!!!";
    for (char c : welcomeMessage) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(200));
    }
    cout << endl;
}
void bicycleAnimation() {
    string bicycle = "   __o\n _ \\<,_\n   ( O )";
    for (char c : bicycle) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(100));
    }
}



int main(){
    time_t tt;
    struct tm* ti;
    time(&tt);
    ti = localtime(&tt);
    cout << "Current Day,Date And Time is: " << asctime(ti);

    cout << endl;
    string animation = "Loading...";
    int delay = 200; 

    Animation(animation, delay);

    this_thread::sleep_for(chrono::seconds(1));
    PlaySound(TEXT("Welcome Song.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
    
    displayWelcomeMessage();

    char choice = 'y';


    while (choice == 'y' || choice == 'Y') {

        electricity e;
        e.get();
        e.calc();
        e.show();
        e.StoreToFile();


        cout << "\nDo you want to process another electricity bill? (Y/y Or N/n): ";
        cin >> choice;

        bicycleAnimation();


    } 
    int sml = 1, i, limit;
    char ch = sml;
    cout << endl;
    cout << "How many smiley face you want to print from scale 1-10  (Feedback) ? : ";
    cin >> limit;
    for (i = 0; i < limit; i++)
    {
        cout << ch << " ";

    }
    cout << endl;
    cout << "Thank You!!!" << endl;
    return 0;
}


