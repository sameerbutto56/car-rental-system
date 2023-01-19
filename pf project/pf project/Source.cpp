#include<iostream>
#include<istream>
#include<fstream>
using namespace std;
void login();
void registration();
void forgotton();
void wedding();
void tour();
void vehicle2();
void drivers();
void abaid1();
void abaid();
void driver();
void vehicles();
int main()
{
    //program designing interface for login and reistration 
    cout << "\t\t\t\t\t\t\t\t      ................**................\n\n";
    cout << "\t\t\t\t\t\t\t\t     ....WELCOME TO BUDDY TRAVELS....\n\n";
    cout << "\t\t\t\t\t\t\t\t      ................**................\n\n";
    //selection area for user for different options
    cout << "\t\t     .......MENU.......\n\n";
    cout << "\t\t|. Select 1 For Login                |" << endl;
    cout << "\t\t|. Select 2 For Registration         |" << endl;
    cout << "\t\t|. Select 3 For Forgotten Password   |" << endl;
    cout << "\t\t|. Select 4 For Exit                 |\n\n" << endl;
    //declaring variable for taking value from user for selction number
    int selection;
    cout << "\t\t Enter the number :";
    cin >> selection;
    cout << endl;
    //using switch statement for selecting 1 number from above 4 numbers 
    switch (selection)
    {
        //if user will press 1 it will take him to login function
    case 1:
        login();
        break;
        //if user will press 2 it will take him to registration function
    case 2:
        registration();
        break;
        /*if user will press 3 it will take him for finding his password
        or email to forgotton function*/
    case 3:
        forgotton();
        break;
        //if user want to exit 
    case 4:
        cout << "Tanks For Your Time\n\n";
        break;
        /*if user will not press any key from 0 to 4 it will clear the screen
        and will ask the user to enter valid number*/
    default:
        system("cls");
        cout << "Enter valid Selection" << endl;
        main();
    }
}
//this funtion for login the code
void login()
{
    int count = 0;
    //email and password is used for user to login the program
    //emailFile and passFile is used for taking email and password from .txt file
    string email, password, emailFile, passFile;
    system("cls");
    cout << "\n\n\t\t|...... Give Your Detail Here......|\n" << endl;
    cout << "\t\t\t ENTER YOUR EMAIL :";
    cin >> email;
    cout << "\t\t\t ENTER YOUR PASSWORD :";
    cin >> password;
    //reading file name database.txt
    ifstream read("database.txt");
    while (read >> emailFile >> passFile)
    {
        if (emailFile == email && passFile == password)

        {
            count = 1;
            system("cls");
        }
    }
    //closing the file after readimg data from it
    read.close();
    //if count==1 it means user successfully login the program 
    if (count == 1)
    {
        cout << "\n \t\t\t ASSALAM U ALAIKUM---->" << email << "\n \t\t\t <---THANKS FOR LOGGING IN--->\n";
        cout << "\t\t\t\t\t\t\t\t      ................**................\n\n";
        cout << "\t\t\t\t\t\t\t\t     ....WELCOME TO BUDDY TRAVELS....\n\n";
        cout << "\t\t\t\t\t\t\t\t      ................**................\n\n";
        //displaying content of our services
        cout << "\t\t     .......SERVICES.......\n\n";
        cout << "\t\t|. Select 1 For Wedding Purpose |" << endl;
        cout << "\t\t|. Select 2 For Tours           |" << endl;
        cout << "\t\t|. Select 3 For Exit            |\n\n" << endl;
        //our services of vehicles
        //declaring variable and taking selection from the user for his desire 
        int service;
        cout << "\t\t Enter the number :";
        cin >> service;
        cout << endl;
        //clearing the screen
        system("cls");
        //switch statement is used for selecting 1 option from our services content 
        switch (service)
        {
        case 1:
            //if user will press 1 it will take him to wedding function
            //for further details of wedding
            wedding();
            break;
        case 2:
            //if user will press 2 it will tek him to tour function for
            //further detail of tour
            tour();
            break;
        case 3:
            //if user will press 3 we will thank him for visiting us
            cout << "Tanks For Your Time\n\n";
            break;
        default:
            //if user will enter number except 1 to 3 it will ask him to enter
            //valid number and then clearing the screen and will go to main
            system("cls");
            cout << "Enter valid Selection" << endl;
            main();
        }
        //if user email id will not match with his registration it will take him to main
        main();
    }
    else
    {
        //for wrong email password it will take him to main
        cout << "\n \t\t\t Your Email Or Password Is Incorrect\n";
        main();
    }
}
// registeration of user
void registration()
{
    //emailReg and passReg is declared for taking user email and password for registraion
    //and storing the data in txt file for next login use
    string emailReg, passReg;
    system("cls");
    cout << "Enter Email :";
    cin >> emailReg;
    cout << "\nEnter the password :";
    cin >> passReg;
    //entering the user data in database.txt file for login use
    ofstream Enter("database.txt", ios::app);
    Enter << emailReg << " " << passReg << endl;
    system("cls");
    cout << "\n \t\t\t <---------Registration Sucessful-------->\n";
    main();
}
//if user will forget his password or email if he remembered one from both he can
//find the other one 
void forgotton()
{
    int forgot;
    system("cls");
    //displaying content for finding the email or password
    cout << "\n\n\t\t\t 1.Find password by Email" << endl;
    cout << " \t\t\t 2.Find Email by Password" << endl;
    cout << " \t\t\t 3.Return Back To Main menu" << endl;
    cout << "Enter Option :";
    cin >> forgot;
    //switch statement is used for selecting 1 option from above 3
    switch (forgot)
    {
    case 1:
        //if user will press 1 it will take him to find his password by using his email
    {
        int count = 0;
        string findEmail, EmailId, passId;
        cout << "\n \t\t\t ENTER EMAIL :";
        cin >> findEmail;

        ifstream findE("database.txt");
        while (findE >> EmailId >> passId)
        {
            if (EmailId == findEmail)
            {
                count = 1;
            }
        }
        findE.close();
        if (count == 1)
        {
            cout << "\n \t\t\t |.....Your Account is Found Congrats.....|";
            cout << "\n \t\t\t |.....Your password is :" << passId << "     |";
            cout << "\n\nPress Enter For Return Back To Main Menu";
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "\n \t\t\t Your Email Id is not matched\n";
            cout << "Press Enter For Return Back To Main Menu\n";
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        break;
    }
    case 2:
    {
        int count = 0;
        string findpass, email_id, pass_id;
        cout << "\n \t\t\tEnter the remembered password :";
        cin >> findpass;

        ifstream findP("database.txt");
        while (findP >> email_id >> pass_id)
        {
            if (pass_id == findpass)
            {
                count = 1;
            }
        }
        findP.close();
        if (count == 1)
        {
            cout << "\n \t\t\t |.....Congratulations your password is matched.....| ";
            cout << "\n \t\t\t |.....Your Id is : " << email_id << "    |";
            cout << "\n\nPress Enter For Return Back To Main Menu";
            cin.get();
            cin.get();
            system("cls");
            main();
        }
        else
        {
            cout << "\n \t\t\t Unfortunately Your Password Is Not Matched";
            cout << "\nPress Enter For Return Back To Main Menu";
            cin.get();
            cin.get();
            main();
        }

        break;
    }

    case 3:
    {
        // cin.get();
        main();
    }
    default:
        cout << "\n \t\t\t |.....Enter Valid Number......|" << endl;
        forgotton();
    }
}void tour() {
    system("cls");
    cout << "\t\t|. Assalamualaikum Our Respectable costomer       |\n\n" << endl;
    cout << "\t\t|. Here You Get All vehicle Related to Tour    |\n\n" << endl;
    cout << "\t\t|. Select 1 For Continue |" << endl;
    cout << "\t\t|. Select 2 For Exit     |" << endl;
    int vehicles2;

    cout << "\t\t Enter the number :";
    cin >> vehicles2;
    cout << endl;
    system("cls");
    switch (vehicles2)
    {
    case 1:
        vehicle2();
        break;
    case 2:
        cout << "Tanks For Your Time\n\n";
        break;

    default:
        system("cls");
        cout << "Enter valid Selection" << endl;

        break;
    }
    main();
}
void vehicle2() {
    cout << "\t\t|. Select 1 For Coster 2020 (white without AC)         |" << endl;
    cout << "\t\t|. Select 2 For Coster 2020 (white with AC/Heater)     |" << endl;
    cout << "\t\t|. Select 3 For BUS (With AC/Heater)                   |" << endl;
    cout << "\t\t|. Select 4 For Bus Sleeper ( With AC/Heater)          |" << endl;
    cout << "\t\t|. Select 5 For Van (18 seats without AC)              |" << endl;
    cout << "\t\t|. Select 6 For Van ( 18 Seats with AC)                |" << endl;
    cout << "\t\t|. Select 7 For Cars                                   |" << endl;
    cout << "\t\t|. Select 7 For Jeeps                                  |" << endl;
    cout << "\t\t|. Select 11 Exit                                      |" << endl;
    int tourdriver;
    cout << "\t\t Enter the number :";
    cin >> tourdriver;
    cout << endl;
    system("cls");

    switch (tourdriver)
    {
    case 1:
        drivers();
        break;
    case 2:
        drivers();
        break;
    case 3:
        drivers();
        break;
    case 4:
        drivers();
        break;
    case 5:
        drivers();
        break;
    case 6:
        drivers();
        break;
    case 7:
        drivers();
        break;
    case 8:
        drivers();
        break;
    case 9:
        drivers();
        break;
    case 10:
        drivers();
        break;

    case 11:
        cout << "Tanks For Your Time\n\n";
        break;

    default:
        system("cls");
        cout << "Enter valid Selection" << endl;
        main();

        break;
    }
    main();


}
void drivers() {
    cout << "\t\t|. Select 1 For Service With Driver     |" << endl;
    cout << "\t\t|. Select 2 For Service Without Driver  |" << endl;
    cout << "\t\t|. Select 3 For Exit                    |" << endl;

    int sameerfinal1;
    cout << "\t\t Enter the number :";
    cin >> sameerfinal1;
    cout << endl;
    system("cls");

    switch (sameerfinal1)
    {
    case 1:
        abaid1();

    case 2:
        abaid1();
        break;
    case 11:
        cout << "Tanks For Your Time\n\n";
        break;

    default:
        system("cls");
        cout << "Enter valid Selection" << endl;
        main();

        break;
    }
    main();
}
void abaid1() {
    cout << "\t\t\t\t\t\t\t\t     ....Your Request is Submitted....                         \n\n";
    cout << "\t\t\t\t\t\t\t\t     ....Come to over office to recive your selected vehicle....\n\n";
    cout << "\t\t\t\t\t\t\t\t     ....Come with your original CNIC card....                   \n\n";
    cout << "\t\t\t\t\t\t\t\t     ....You will come to over office at 9am to 5pm....           \n\n";
    cout << "\t\t\t\t\t\t\t\t     .....................THANKS.....................              \n\n";



}

void wedding() {
    system("cls");
    cout << "\t\t|. Assalamualaikum Our Respectable costomer       |\n\n" << endl;
    cout << "\t\t|. Here You Get All vehicle Related to Wedding    |\n\n\n\n\n" << endl;
    cout << "\t\t|. Select 1 For Continue |" << endl;
    cout << "\t\t|. Select 2 For Exit     |" << endl;
    int vehicle;
    cout << "\t\t Enter the number :";
    cin >> vehicle;
    cout << endl;
    system("cls");

    switch (vehicle)
    {
    case 1:
        vehicles();
        break;
    case 2:
        cout << "Tanks For Your Time\n\n";
        break;

    default:
        system("cls");
        cout << "Enter valid Selection" << endl;
        main();

        break;
    }
    main();
}
void vehicles() {
    cout << "\t\t|. Select 1 For Honda civic 2022 (White)            |" << endl;
    cout << "\t\t|. Select 2 For Honda Civic 2020 (Black)            |" << endl;
    cout << "\t\t|. Select 3 For Toyota Corolla 2022(white)          |" << endl;
    cout << "\t\t|. Select 4 For Toyota Corolla 2018 (Balack)        |" << endl;
    cout << "\t\t|. Select 5 For Toyota Corolla Grandy 2022  (White) |" << endl;
    cout << "\t\t|. Select 6 For Toyota Fortuner 2022(white)         |" << endl;
    cout << "\t\t|. Select 7 For Toyota Fortuner 2022(Black)         |" << endl;
    cout << "\t\t|. Select 8 For Van (18 seats)                      |" << endl;
    cout << "\t\t|. Select 9 For Coster (28 Seats)                   |" << endl;
    cout << "\t\t|. Select 10 For Bus (72 Seats)                     |" << endl;
    cout << "\t\t|. Select 11 Exit                                   |" << endl;


    int driver1;
    cout << "\t\t Enter the number :";
    cin >> driver1;
    cout << endl;
    system("cls");

    switch (driver1)
    {
    case 1:
        driver();
        break;
    case 2:
        driver();
        break;
    case 3:
        driver();
        break;
    case 4:
        driver();
        break;
    case 5:
        driver();
        break;
    case 6:
        driver();
        break;
    case 7:
        driver();
        break;
    case 8:
        driver();
        break;
    case 9:
        driver();
        break;
    case 10:
        driver();
        break;

    case 11:
        cout << "Tanks For Your Time\n\n";
        break;

    default:
        system("cls");
        cout << "Enter valid Selection" << endl;
        main();

        break;
    }
    main();

}
void driver() {
    cout << "\t\t|. Select 1 For Service With Driver     |" << endl;
    cout << "\t\t|. Select 2 For Service Without Driver  |" << endl;
    cout << "\t\t|. Select 3 For Exit                    |" << endl;

    int sameerfinal;
    cout << "\t\t Enter the number :";
    cin >> sameerfinal;
    cout << endl;
    system("cls");

    switch (sameerfinal)
    {
    case 1:
        abaid();

    case 2:
        abaid();
        break;
    case 11:
        cout << "Tanks For Your Time\n\n";
        break;

    default:
        system("cls");
        cout << "Enter valid Selection" << endl;
        main();

        break;
    }
    main();


}


void abaid() {
    cout << "\t\t\t\t\t\t\t\t     ....Your Request is Submitted....                         \n\n";
    cout << "\t\t\t\t\t\t\t\t     ....Come to over office to recive your selected vehicle....\n\n";
    cout << "\t\t\t\t\t\t\t\t     ....Come with your original CNIC card....                   \n\n";
    cout << "\t\t\t\t\t\t\t\t     ....You will come to over office at 9am to 5pm....           \n\n";
    cout << "\t\t\t\t\t\t\t\t     .....................THANKS.....................              \n\n";


}