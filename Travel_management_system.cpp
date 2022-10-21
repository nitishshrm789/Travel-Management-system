#include <iostream>
#include <fstream>
#include <iomanip>
#include <windows.h>

using namespace std;

void menu();

class ManageMenu
{
    protected:
        string userName;

    public:
        ManageMenu()
        {
            system("color 0A"); //Change terminal color
            cout<<"\n\n\n\n\n\n\n\n\n\n\t Enter Your name to continue as an Admin : ";
            cin>>userName;
            system("cls");
            menu();
        }
        ~ManageMenu(){}
};

class customers{
    public:
        string name,gender,address;
        int age, mobileNo;
        static int cusId;
        char all[999];

        void getDetails()
        {
            ofstream out("old-customers.txt",ios::app);
            {
                cout<<"Enter customer I'd : ";
                cin>>cusId;
                cout<<"Enter Name : ";
                cin>>name;
                cout<<"Enter Age : ";
                cin>>age;
                cout<<"Enter Mobile No. : ";
                cin>>mobileNo;
                cout<<"Enter Address : ";
                cin>>address;
                cout<<"Enter Gender : ";
                cin>>gender;
            }
            out<<"\nCustomer I'D: "<<cusId<<"\nName : "<<name<<"\nAge : "<<age<<"\nMobile No. : "<<mobileNo<<"\nAddress : "<<address<<"\nGender : "<<gender<<endl;
            out.close();
            cout<<"\nSAVED \nNOTE: We save your details record for future purposes\n"<<endl;
        }   

        void showDetails()
        {
            ifstream in("old-customers.txt");
            {
                if(!in)
                {
                    cout<<"File Error!"<<endl;
                }
                while(!(in.eof()))
                {
                    in.getline(all, 999);
                    cout << all<<endl;
                }
                in.close();
            }
        }
};

int customers::cusId;

class cabs{
    public:
        int cabChoice;
        int kilometer;
        float cabCost;
        static float lastCabCost;

        void cabDetails()
        {
            cout<<"We collaborated with fastest, safest, and smartest cab service around the country"<<endl;
            cout<<"------------ABC Cabs------------\n"<<endl;
            cout<<"1. Rent a standard cab - Rs. 15 for 1 KM"<<endl;
            cout<<"2. Rend a Luxury Cab - Rs. 25 per 1 KM"<<endl;

            cout<<"\nTo calculate the cost for your journey : "<<endl;
            cout<<"Enter which kinds of cab you need : ";
            cin>>cabChoice;
            cout<<"Enter Kilometers you have to travel : ";
            cin>>kilometer;

            int hireCab;
            
            if(cabChoice==1){
                cabCost = kilometer * 15;
                cout <<"\nYour tour cost "<<cabCost<<" rupees for a standard cab"<<endl;
                cout<<"Press 1 to hire this cab : or";
                cout<<"press 2 to select another cab : ";
                cin>>hireCab;

                system("cls");

                if(hireCab == 1){
                    lastCabCost = cabCost;
                    cout<<"\nYou have succesfully hired standard cab!"<<endl;
                    cout<<"Goto MENU and take the RECEIPT"<<endl;
                }
                else if(hireCab == 2){
                    cabDetails();
                }
                else{
                    cout<<"Invalid Input! Redirecting to previous MENU \nPlease Wait!"<<endl;
                    Sleep(999);
                    system("cls");
                    cabDetails();
                }
            }
            else if(cabChoice == 2){
                cabCost = kilometer * 25;
                cout <<"\nYour tour will cost "<<cabCost<<" rupees for a luxury cab"<<endl;
                cout<<"Press 1 to hire this cab : or";
                cout<<"press 2 to select another cab : ";
                cin>>hireCab;

                system("cls");

                if(hireCab == 1){
                    lastCabCost = cabCost;
                    cout<<"\nYou have succesfully hired luxury cab!"<<endl;
                    cout<<"Goto MENU and take the RECEIPT"<<endl;
                }
                else if(hireCab == 2){
                    cabDetails();
                }
                else{
                    cout<<"Invalid Input! Redirecting to previous MENU \nPlease Wait!"<<endl;
                    Sleep(1100);
                    system("cls");
                    cabDetails();
                }
            }
            else{
                cout<<"Invalid Input! Redirecting to Main MENU \nPlease Wait!"<<endl;
                Sleep(1100);
                system("cls");
                menu();
            }
            cout<<"\nPress 1 to Redirect Main MENU : ";
            cin>>hireCab;
            system("cls");
            if(hireCab == 1){
                menu();
            }
            else{
                menu();
            }
        }
};

float cabs::lastCabCost;

class Booking{
    public:
        int choiceHotel;
        int packChoice;
        static float hotelCost;

        void hotels()
        {
            string hotelNo[]={"Avendra", "ChoiceYou","ElephantBay"};
            for(int a=0;a<3;++a){
                cout<<(a+1)<<". Hotel"<<hotelNo[a]<<endl;
            }

            cout<<"\nCurrently we collaborated with above hotels!"<<endl;

            cout<<"Press any key to back or\nEnter number of the hotel you want to book : ";
            cin>>choiceHotel;

            system("cls");

            if(choiceHotel == 1){
                cout<<"----------Welcome to HOTEL AVENDRA----------\n"<<endl;

                cout<<"The Garden, food and beverage. Enjoy all you can drink, stay cool and get chilled in the summer sun."<<endl;

                cout<<"Packages offered by AVENDRA :\n"<<endl;

                cout<<"1. Standard Pack"<<endl;
                cout<<"\tAll basic facillities you need just for : Rs.5000.00"<<endl;
                cout<<"2. Premium Pack"<<endl;
                cout<<"\tEnjoy Premium : Rs.10000.00"<<endl;
                cout<<"3. Luxury Pack"<<endl;
                cout<<"\tLive a Luxury at AVENDRA : Rs.15000.00"<<endl;

                cout<<"\nPress another key to back or\nEnter Package number you want to book : ";
                cin>>packChoice;

                if(packChoice == 1){
                    hotelCost = 5000.00;
                    cout<<"\nYou have successfully booked Standard Pack at AVENDRA"<<endl;
                    cout<<"Goto MENU and take the RECEIPT"<<endl;
                }
                else if(packChoice == 2){
                    hotelCost = 10000.00;
                    cout<<"\nYou have successfully booked Luxury Pack at ChoiceYou"<<endl;
                    cout<<"Goto MENU and take the RECEIPT"<<endl;
                }
                else if(packChoice == 3){
                    hotelCost = 15000.00;
                    cout<<"\nYou have successfully booked Premium Pack at ElephantBay"<<endl;
                    cout<<"Goto MENU and take the RECEIPT"<<endl;
                }
                else{
                    cout<<"Invalid Input! Redirecting to Previous Menu \nPlease wait!"<<endl;
                    Sleep(1100);
                    system("cls");
                    hotels();
                }
                int gotomenu;
                cout<<"\nPress 1 to redirect main MENU : ";
                cin>>gotomenu;
                if(gotomenu == 1){
                    menu();
                }
                else{
                    menu();
                }
            }
            else if(choiceHotel == 2){
                cout<<"----------Welcome to HOTEL ChoiceYou----------\n"<<endl;

                cout<<"Swimming pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar"<<endl;

                cout<<"Packages offered by ChoiceYou :\n"<<endl;

                cout<<"1. Family Pack"<<endl;
                cout<<"\t Rs. 15000.00"<<endl;
                cout<<"2. Couple Pack"<<endl;
                cout<<"\t Rs. 10000.00"<<endl;
                cout<<"3. Single Pack"<<endl;
                cout<<"\t Rs. 5000.00"<<endl;

                cout<<"\nPress another key to back or\nEnter Package number you want to book : ";
                cin>>packChoice;

                if(packChoice == 1){
                    hotelCost = 15000.00;
                    cout<<"\nYou have successfully booked Family Pack at ChoiceYou"<<endl;
                    cout<<"Goto MENU and take the RECEIPT"<<endl;
                }
                else if(packChoice == 2){
                    hotelCost = 10000.00;
                    cout<<"\nYou have successfully booked Couple Pack at ChoiceYou"<<endl;
                    cout<<"Goto MENU and take the RECEIPT"<<endl;
                }
                else if(packChoice == 3){
                    hotelCost = 5000.00;
                    cout<<"\nYou have successfully booked Single Pack at ChoiceYou"<<endl;
                    cout<<"Goto MENU and take the RECEIPT"<<endl;
                }
                else{
                    cout<<"Invalid Input! Redirecting to Previous Menu \nPlease wait!"<<endl;
                    Sleep(1100);
                    system("cls");
                    hotels();
                }
                int gotomenu;
                cout<<"\nPress 1 to redirect main MENU : ";
                cin>>gotomenu;
                if(gotomenu == 1){
                    menu();
                }
                else{
                    menu();
                }
            }
            else if(choiceHotel == 3){
                cout<<"----------Welcome to HOTEL ElephantBay----------\n"<<endl;

                cout<<"Set in tropical gardens on the banks of the Maha Oya river while Seeing Elephants."<<endl;
                cout<<"Amazing offer in this summer: Rs. 5000.00 for a one day!!!"<<endl;

                cout<<"\nPress another key to back or\nPress 1 to book this special package : ";
                cin>>packChoice;

                if(packChoice == 1){
                    hotelCost = 5000.00;
                    cout<<"\nYou have successfully booked ElephantBay Special Pack"<<endl;
                    cout<<"Goto MENU and take the RECEIPT"<<endl;
                }
                else{
                    cout<<"Invalid Input! Redirecting to Previous Menu \nPlease wait!"<<endl;
                    Sleep(1100);
                    system("cls");
                    hotels();
                }
                int gotomenu;
                cout<<"\nPress 1 to redirect main MENU : ";
                cin>>gotomenu;
                system("cls");
                if(gotomenu == 1){
                    menu();
                }
                else{
                    menu();
                }
            }
            else{
                cout<<"Invalid Input! Redirecting to previous Menu \nPlease Wait!"<<endl;
                Sleep(1100);
                system("cls");
                menu();
            }
        }
};

float Booking::hotelCost;

class Charges : public Booking, cabs, customers
{
    public:
        void printBill()
        {
            ofstream outf("receipt.txt");
            {
                outf<<"------------ABC Travel Agency------------"<<endl;
                outf<<"-----------------RECEIPT-----------------"<<endl;
                outf<<"_________________________________________"<<endl;

                cout<<"Customer I'D : "<<customers::cusId<<endl<<endl;
                outf<<"Description\t\t Total"<<endl;
                outf<<"Hotel cost:\t\t "<<fixed<<setprecision(2)<<Booking::hotelCost <<endl;
                outf<<"Travel (cab) cost :\t "<<fixed<<setprecision(2)<<cabs::lastCabCost<<endl;

                outf<<"_________________________________________"<<endl;
                outf<<"Total Charge:\t\t "<<fixed<<setprecision(2)<<Booking::hotelCost+cabs::lastCabCost<<endl;
                outf<<"_________________________________________"<<endl;
                outf<<"----------------Thank You----------------"<<endl;
            }

            outf.close();
        }

        void showBill()
        {
            ifstream inf("receipt.txt");
            {
                if(!inf)
                {
                    cout<<"File opening error!"<<endl;
                }
                while(!(inf.eof()))
                {
                    inf.getline(all,999);
                    cout<< all <<endl;
                }
            }
            inf.close();
        }
};

void menu()
{
    int mainChoice;
    int inChoice;
    int gotomenu;

    cout<<"\t\t     ' ABC Travels '\n"<<endl;
    cout<<"----------------Main MENU----------------"<<endl;

    cout<<" _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ "<<endl;
    cout<<"|\t\t\t\t\t|" <<endl;
    cout<<"|\tCustomer Management -> 1\t|"<<endl;
    cout<<"|\tCabs Management     -> 2\t|"<<endl;
    cout<<"|\tBookings Management -> 3\t|"<<endl;
    cout<<"|\tCharges & Bill      -> 4\t|"<<endl;
    cout<<"|\tExit                -> 5\t|"<<endl;
    cout<<"|\t\t\t\t\t|"<<endl;
    cout<<"|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _| "<<endl;

    cout<<"\nEnter Your Choice : ";
    cin>>mainChoice;

    system("cls");

    customers a2;
    cabs a3;
    Booking a4;
    Charges a5;

    if(mainChoice == 1){
        cout<<"----------Customers----------\n"<<endl;
        cout<<"1. Enter New Customers"<<endl;
        cout<<"2. See Old Customers"<<endl;

        cout<<"\nEnter Choice : ";
        cin>>inChoice;

        system("cls");
        if(inChoice == 1){
            a2.getDetails();
        }
        else if(inChoice == 2){
            a2.showDetails();
        }
        else{
            cout<<"Invalid Input! Redirecting to Main MENU \nPlease Wait!"<<endl;
            Sleep(1100);
            system("cls");
            menu();
        }

        cout<<"\nPress 1 to Redirect Main MENU : ";
        cin>>gotomenu;

        system("cls");

        if(gotomenu == 1){
            menu();
        }
        else{
            menu();
        }

    }
    else if(mainChoice == 2){
        a3.cabDetails();
    }
    else if(mainChoice == 3){
        cout<<"--> Book a luxury Hotel using the system <-- "<<endl;
        a4.hotels();
    }
    else if(mainChoice == 4){
        cout<<"--> Get your receipt <-- "<<endl;
        a5.printBill();

        cout<<"Your receipt is already printed you can get it from file path\n"<<endl;
        cout<<"To display your receipt in the screen, Enter 1, or Enter another key to back Main MENU : ";
        cin>>gotomenu;

        if(gotomenu == 1){
            system("cls");
            a5.showBill();
            cout<<"\nPress 1 to redirect Main MENU : ";
            cin>>gotomenu;
            system("cls");
            if(gotomenu == 1){
                menu();
            }
            else{
                menu();
            }
        }
        else{
            system("cls");
            menu();
        }
    }
    else if(mainChoice == 5){
        cout<<"--GOOD BYE--"<<endl;
        Sleep(999);
        system("cls");
        menu();
    }
    else{
        cout<<"Invalid Input! Redirecting to previous MENU \nPlease Wait!"<<endl;
        Sleep(1100);
        system("cls");
        menu();
    }
}

int main()
{
    ManageMenu startObj;

    return 0;
}