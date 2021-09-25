#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>

using namespace std;

struct Personal_info {

    string name;
    string id;
    string email;
    string dob;                 //date of birth
    string gender;
    string phoneNumber;         //phone number
    string lnumber;             //land line phone number
};

//-------------------------------------------------

void print (vector <Personal_info> information,int size);
void create (vector<Personal_info> &information, int size);
void print1 (vector <Personal_info> information,int index);
void read (vector <Personal_info> information,int size);
void update (vector <Personal_info> &information,int size);
void remove (vector<Personal_info> &information);
void updateFile (vector <Personal_info> information, int size);
void sort1 (vector<Personal_info> &information, int size);
void sort2 (vector <Personal_info> &information, int size);
bool checkName (string fname, string lname);
bool check(string birthdate);
bool checkNumber (string number);

//-------------------------------------------------

int main()
{
    fstream phonebook ("./Phonebook.txt",ios::in|ios::out);
    Personal_info temp;
    vector <Personal_info> information;
    string name,id,email,dob,gender,phonenumber,lnumber;

    if (!phonebook) {

        cerr << endl << "==== Not Found! ====" << endl << endl;
    }

    else {

        while (!phonebook.eof()) {

            getline(phonebook,name);
            temp.name = name;
            getline(phonebook,id);
            temp.id = id;
            getline(phonebook,email);
            temp.email = email;
            getline(phonebook,dob);
            temp.dob = dob;
            getline(phonebook,gender);
            temp.gender = gender;
            getline(phonebook,phonenumber);
            temp.phoneNumber = phonenumber;
            getline(phonebook,lnumber);
            temp.lnumber = lnumber;

            information.push_back(temp);
        }

        print(information,information.size());
        system("pause");
        system("cls");

        while (true) {

            int choice = 0;

            cout << endl << "Please choose one of the options : " << endl;
            cout << endl << "1 : Create" << endl;
            cout << endl << "2 : Read" << endl;
            cout << endl << "3 : Update" << endl;
            cout << endl << "4 : Remove" << endl;
            cout << endl << "5 : Sort" << endl;
            cout << endl << "6 : Print" << endl;
            cout << endl << "7 : Exit" << endl << endl;
            cin >> choice;

            if (choice == 1) {

                create(information,information.size());
                cout << endl;
                print(information,information.size());
                system("pause");
                system("cls");
            }

            else if (choice == 2) {

                read (information,information.size());
                system("pause");
                system("cls");
            }

            else if (choice == 3) {

                update(information,information.size());
                system("pause");
                system("cls");

            }

            else if (choice == 4) {

                remove(information);
                system("pause");
                system("cls");

            }

            else if (choice == 5) {

                int order = 0;

                cout << endl << "In which order do you want to sort data?" << endl;
                cout << endl << "1 : Ascending" << endl;
                cout << endl << "2 : Descending" << endl << endl;
                cin >> order;

                if (order == 1) {

                    sort1(information,information.size());
                    updateFile(information,information.size());
                    print(information,information.size());
                    system("pause");
                    system("cls");
                }

                else if (order == 2) {

                    sort2(information,information.size());
                    updateFile(information,information.size());
                    print(information,information.size());
                    system("pause");
                    system("cls");
                }

                else {

                    cerr << endl << "Error : Invalid Order!" << endl << endl;
                    system("pause");
                    system("cls");
                }
            }

            else if (choice == 6) {

                print(information,information.size());
                system("pause");
                system("cls");
            }

            else if (choice == 7) {

                updateFile(information,information.size());

                return 0;
            }

            else {

                cerr << endl << "Please choose one of the options above!" << endl << endl;
            }
        }
    }

    phonebook.close();
    return 0;
}

//printing information of everyone on the list

void print (vector <Personal_info> information,int size) {

    cout << endl << ".:.:.:.:.:.:.:.: The Information are :.:.:.:.:.:.:.:. " << endl;

    for (int i = 0; i < size; i++) {

        cout << endl << "Name : " << information[i].name << endl;
        cout << endl << "ID : " << information[i].id << endl;
        cout << endl << "Email : " << information[i].email << endl;
        cout << endl << "Date of Birth : " << information[i].dob << endl;
        cout << endl << "Gender : " << information[i].gender << endl;
        cout << endl << "Phone Number : " << information[i].phoneNumber << endl;
        cout << endl << "Land Line Phone Number : " << information[i].lnumber << endl << endl;
        cout << endl << "------------------------------------" << endl;
    }

    cout << endl;
}

//printing information of a person

void print1 (vector <Personal_info> information,int index) {

    cout << endl << ".:.:.:.:.:.:.:.: The Information are :.:.:.:.:.:.:.:. " << endl;
    cout << endl << "Name : " << information[index].name << endl;
    cout << endl << "ID : " << information[index].id << endl;
    cout << endl << "Email : " << information[index].email << endl;
    cout << endl << "Date of Birth : " << information[index].dob << endl;
    cout << endl << "Gender : " << information[index].gender << endl;
    cout << endl << "Phone Number : " << information[index].phoneNumber << endl;
    cout << endl << "Land Line Phone Number : " << information[index].lnumber << endl;
    cout << endl << "----------------------------------------------------- " << endl << endl;

}

//adding information of a new person

void create (vector <Personal_info> &information,int size) {

    string fn               //first name
            ,ln             //last name
            ,d              //id
            ,e              //email
            ,b              //date of birth
            ,g              //gender
            ,p              //phone number
            ,l              //land line number
            ,name;          //first name + last name


    bool temp = true;

    Personal_info vect;

    fstream phonebook ("./Phonebook.txt",ios::in|ios::app);

    cout << endl << ".:.:.:.:.:.:.:.: Fill the form :.:.:.:.:.:.:.:.:. " << endl << endl;

    while (temp) {

        bool flag = true;
        char ch;
        cin.get(ch);

        cout << endl << "First Name : ";
        getline (cin,fn);
        cout << endl;

        cout << endl << "last Name : ";
        getline (cin,ln);
        cout << endl;

        if (checkName(fn,ln)) {

            name = fn + ' ' + ln;

            for (int i = 0; i < size && flag; i++) {

                if (name.compare(information[i].name) == 0) {

                    cerr << endl << "Error : Information exists already!" << endl << endl;

                    flag = false;
                }
            }

            if (flag) {

                vect.name = name;
                temp = false;
            }
        }
    }

    temp = true;

    while (temp) {

        bool flag = true;

        cout << endl << "ID : ";
        getline (cin,d);
        cout << endl;

        if (d.size() == 10) {

            for (int i = 0; i < size && flag; i++) {

                if (d.compare(information[i].id) == 0) {

                    cerr << endl << "Error : Information exists already!" << endl << endl;

                    flag = false;
                }
            }

            if (flag) {

                vect.id = d;
                temp = false;
            }
        }

        else {

            cerr << endl << "Error : The ID must be 10 characters! " << endl << endl;
        }
    }

    temp = true;

    while (temp) {

        bool flag = true;

        cout << endl << "Email : ";
        getline (cin,e);
        cout << endl;

        for (int i = 0; i < size && flag; i++) {

            if (e.compare(information[i].email) == 0) {

                cerr << endl << "Error : Information exists already!" << endl << endl;

                flag = false;
            }
        }

        if (flag) {

            vect.email = e;
            temp = false;
        }
    }

    temp = true;

    while (temp) {

        cout << endl << "Date of Birth (use slashes) : ";
        getline (cin,b);
        cout << endl;

        if (b.size() == 10) {

            if (check(b)) {

                vect.dob = b;
                temp = false;
            }
        }

        else {

            cerr << endl << "Error : Invalid input!" << endl << endl;
        }
    }

    temp = true;

    while (temp) {

        cout << endl << "Gender : ";
        getline (cin,g);
        cout << endl;

        if (g == "male" || g == "Male" || g == "Female" || g == "female") {

            vect.gender = g;
            temp = false;
        }

        else {

            cerr << endl << "Error : Invalid input!" << endl << endl;
        }
    }

    temp = true;

    while (temp) {

        bool flag = true;

        cout << endl << "Phone Number : ";
        getline (cin,p);
        cout << endl;

        if (checkNumber(p)) {

            if (p.size() == 11) {

                for (int i = 0; i < size && flag; i++) {

                    if (p.compare(information[i].phoneNumber) == 0) {

                        cerr << endl << "Error : Information exists already!" << endl << endl;

                        flag = false;
                    }
                }

                if (flag) {

                    vect.phoneNumber = p;
                    temp = false;
                }
            }

            else {

                cerr << endl << "Error : Invalid input!" << endl << endl;
            }
        }
    }

    temp = true;

    while (temp) {

        bool flag = true;

        cout << endl << "Land Line Phone Number : ";
        getline (cin,l);
        cout << endl;

        if (checkNumber(l)) {

            if (l.size() == 11) {

                for (int i = 0; i < size && flag; i++) {

                    if (l.compare(information[i].lnumber) == 0) {

                        cerr << endl << "Error : Information exists already!" << endl << endl;

                        flag = false;
                    }
                }

                if (flag) {

                    vect.lnumber = l;
                    temp = false;
                }
            }

            else {

                cerr << endl << "Error : Invalid input!" << endl << endl;
            }
        }
    }

    information.push_back(vect);
    phonebook << endl
              << name << endl
              << d << endl
              << e << endl
              << b << endl
              << g << endl
              << p << endl
              << l;
}

//searching for a user

void read (vector <Personal_info> information,int size){

    while (true) {

        int choice = 0;

        cout << endl << "Choose one of The options " << endl;
        cout << endl <<  "1 : Search based on name" << endl;
        cout << endl <<  "2 : Search based on ID" << endl;
        cout << endl <<  "3 : Search based on Email" << endl;
        cout << endl <<  "4 : Search based on Phone Number" << endl;
        cout << endl <<  "5 : Search based on Land Line Phone Number" << endl;
        cout << endl <<  "6 : Return" << endl << endl;

        cin >> choice;

        if (choice == 1) {

            bool flag = true;
            string fname,
                    lname,
                    name;

            char ch;
            cin.get(ch);

            cout << endl << "First Name : ";
            getline(cin , fname);
            cout << endl;

            cout << endl << "Last Name : ";
            getline (cin , lname);
            cout << endl;

            name = fname + ' ' + lname;

            for (int i = 0; i < size && flag; i++) {

                if (name.compare(information[i].name) == 0) {

                    print1(information,i);

                    flag = false;
                    return ;
                }
            }

            if (flag) {

                cerr << endl << "Error : Not Found!" << endl << endl;
            }
        }

        else if (choice == 2) {

            string id;
            bool flag = true;

            char ch;
            cin.get(ch);

            cout << endl << "ID : ";
            getline (cin , id);
            cout << endl;

            for (int i = 0; i < size && flag; i++) {

                if (id.compare(information[i].id) == 0) {

                    print1(information,i);

                    flag = false;
                    return ;
                }
            }

            if (flag) {

                cerr << endl << "Error : Not Found!" << endl << endl;
            }
        }

        else if (choice == 3) {

            string email;
            bool flag = true;

            char ch;
            cin.get(ch);

            cout << endl << "Email : ";
            getline (cin , email);
            cout << endl;

            for (int i = 0; i < size && flag; i++) {

                if (email.compare(information[i].email) == 0) {

                    print1(information,i);

                    flag = false;
                    return ;
                }
            }

            if (flag) {

                cerr << endl << "Error : Not Found!" << endl << endl;
            }
        }

        else if (choice == 4) {

            string pN;
            bool flag = true;

            char ch;
            cin.get(ch);

            cout << endl << "Phone Number : ";
            getline (cin , pN);
            cout << endl;

            for (int i = 0; i < size && flag; i++) {

                if (pN.compare(information[i].phoneNumber) == 0) {

                    print1(information,i);

                    flag = false;
                    return ;
                }
            }

            if (flag) {

                cerr << endl << "Error : Not Found!" << endl << endl;
            }
        }

        else if (choice == 5) {

            string ln;
            bool flag = true;

            char ch;
            cin.get(ch);

            cout << endl << "Land Line Phone Number : ";
            getline (cin , ln);
            cout << endl;

            for (int i = 0; i < size && flag; i++) {

                if (ln.compare(information[i].lnumber) == 0) {

                    print1(information,i);

                    flag = false;
                    return ;
                }
            }

            if (flag) {

                cerr << endl << "Error : Not Found!" << endl << endl;
            }
        }

        else if (choice == 6) {

            return ;
        }

        else {

            cerr << endl << "Error : choose one of the options above!" << endl << endl;
            return ;
        }
    }
}

//change information of a user 

void update (vector <Personal_info> &information,int size) {

    fstream phonebook ("./Phonebook.txt",ios::in|ios::out|ios::app);
    Personal_info vect;
    string id;
    bool flag = true;

    char ch;
    cin.get(ch);
    cout << endl << "Tell us the id : ";
    getline (cin , id);
    cout << endl;

    for (int i = 0; i < size && flag; i++) {

        if (id.compare(information[i].id) == 0) {

            bool temp = true;
            int choice = 0;

            while (temp) {

                cout << endl << "choose the one you want to change " << endl;
                cout << endl << "1 : Name" << endl;
                cout << endl << "2 : Email" << endl;
                cout << endl << "3 : Phone Number" << endl;
                cout << endl << "4 : Land Line Phone Number" << endl;
                cout << endl << "5 : return" << endl << endl;
                cin >> choice;

                if (choice == 1) {

                    string fname,
                            lname,
                            name;
                    bool check = true;

                    char ch;
                    cin.get(ch);
                    cout << endl << "Tell us First Name : ";
                    getline (cin , fname);

                    cout << endl << "Tell us Last Name : ";
                    getline (cin , lname);

                    if (checkName(fname,lname)) {

                        name = fname + ' ' + lname;

                        for (int j = 0; j < size && check; j++) {

                            if (name.compare(information[j].name) == 0) {

                                cerr << endl << "Error : This name has been taken!" << endl << endl;
                                check = false;
                            }
                        }

                        if (check) {

                            vect.name = name;
                            information[i].name.swap(vect.name);
                            cout << endl << "*** Mission Completed! ***" << endl << endl;
                        }
                    }
                }

                else if (choice == 2) {

                    string email;
                    bool check = true;

                    char ch;
                    cin.get(ch);
                    cout << endl << "Tell us the new email : ";
                    getline (cin , email);

                    for (int j = 0; j < size && check; j++) {

                        if (email.compare(information[j].email) == 0) {

                            cerr << endl << "Error : This email has been used!" << endl << endl;
                            check = false;
                        }
                    }

                    if (check) {

                        vect.email = email;
                        information[i].email.swap(vect.email);
                        cout << endl << "*** Mission Completed! ***" << endl << endl;
                    }
                }

                else if (choice == 3) {

                    string pN;
                    bool check = true;

                    char ch;
                    cin.get(ch);
                    cout << endl << "Tell us the new Phone Number : ";
                    getline (cin , pN);

                    if (checkNumber(pN)) {

                        if (pN.size() == 11) {

                            for (int j = 0; j < size && check; j++) {

                                if (pN.compare(information[j].phoneNumber) == 0) {

                                    cerr << endl << "Error : This phone number has been taken!" << endl << endl;
                                    check = false;
                                }
                            }

                            if (check) {

                                vect.phoneNumber = pN;
                                information[i].phoneNumber.swap(vect.phoneNumber);
                                cout << endl << "*** Mission Completed! ***" << endl << endl;
                            }
                        }

                        else {

                            cerr << endl << "Error : Invalid Input!" << endl << endl;
                        }
                    }
                }

                else if (choice == 4) {

                    string ln;
                    bool check = true;

                    char ch;
                    cin.get(ch);
                    cout << endl << "Tell us the new Number : ";
                    getline (cin , ln);

                    if (checkNumber(ln)) {

                        if (ln.size() == 11) {

                            for (int j = 0; j < size && check; j++) {

                                if (ln.compare(information[j].lnumber) == 0) {

                                    cerr << endl << "Error : This number has been taken!" << endl << endl;
                                    check = false;
                                }
                            }

                            if (check) {

                                vect.lnumber = ln;
                                information[i].lnumber.swap(vect.lnumber);
                                cout << endl << "*** Mission Completed! ***" << endl << endl;
                            }
                        }

                        else {

                            cerr << endl << "Error : Invalid Input!" << endl << endl;
                        }
                    }
                }

                else if (choice == 5) {

                    updateFile(information,information.size());

                    cout << endl << "***************** Mission Completed *****************" << endl << endl;
                    print1(information,i);

                    temp = false;
                }

                else {

                    cerr << endl << "Please choose one of the options above!" << endl << endl;
                    temp = false;
                }
            }

            flag = false;
        }
    }

    if (flag) {

        cerr << endl << "Error : Invalid Input!" << endl << endl;
    }
}

//removing information of a user

void remove (vector <Personal_info> &information) {

    string d;
    bool flag = true;

    char ch;
    cin.get(ch);
    cout << endl << "Tell us the id : ";
    getline (cin , d);
    cout << endl;

    for (unsigned int i = 0; i < information.size() && flag; i++) {

        if (d.compare(information[i].id) == 0) {

            information.erase(information.begin()+i);

            updateFile(information,information.size());

            cout << endl << "**************** Mission Completed ****************" << endl << endl;
            print(information,information.size());

            flag = false;
        }
    }

    if (flag) {

        cerr << endl << "Error : Not Found!" << endl << endl;
    }
}

//make changes to the File

void updateFile (vector <Personal_info> information, int size) {

    fstream phonebook ("./Phonebook.txt",ios::in|ios::out|ios::trunc);

    for (int i = 0; i < size-1; i++) {

        phonebook << information[i].name << endl;
        phonebook << information[i].id << endl;
        phonebook << information[i].email << endl;
        phonebook << information[i].dob << endl;
        phonebook << information[i].gender << endl;
        phonebook << information[i].phoneNumber << endl;
        phonebook << information[i].lnumber << endl;

    }

    phonebook << information[size-1].name << endl;
    phonebook << information[size-1].id << endl;
    phonebook << information[size-1].email << endl;
    phonebook << information[size-1].dob << endl;
    phonebook << information[size-1].gender << endl;
    phonebook << information[size-1].phoneNumber << endl;
    phonebook << information[size-1].lnumber;

    phonebook.close();
}

//sort in Ascending order

void sort1 (vector <Personal_info> &information, int size) {

    Personal_info hold;

    for (int j = 0; j < size-1; j++) {

        for (int i = 0; i < size-1; i++) {

            if (information[i].name > information[i+1].name) {

                hold.name = information[i].name;
                information[i].name = information[i+1].name;
                information[i+1].name = hold.name;

                hold.id = information[i].id;
                information[i].id = information[i+1].id;
                information[i+1].id = hold.id;

                hold.email = information[i].email;
                information[i].email = information[i+1].email;
                information[i+1].email = hold.email;

                hold.dob = information[i].dob;
                information[i].dob = information[i+1].dob;
                information[i+1].dob = hold.dob;

                hold.gender = information[i].gender;
                information[i].gender = information[i+1].gender;
                information[i+1].gender = hold.gender;

                hold.phoneNumber = information[i].phoneNumber;
                information[i].phoneNumber = information[i+1].phoneNumber;
                information[i+1].phoneNumber = hold.phoneNumber;

                hold.lnumber = information[i].lnumber;
                information[i].lnumber = information[i+1].lnumber;
                information[i+1].lnumber = hold.lnumber;
            }
        }
    }
}

//sort in Descending order

void sort2 (vector <Personal_info> &information, int size) {

    Personal_info hold;

    for (int j = 0; j < size-1; j++) {

        for (int i = 0; i < size-1; i++) {

            if (information[i].name < information[i+1].name) {

                hold.name = information[i].name;
                information[i].name = information[i+1].name;
                information[i+1].name = hold.name;

                hold.id = information[i].id;
                information[i].id = information[i+1].id;
                information[i+1].id = hold.id;

                hold.email = information[i].email;
                information[i].email = information[i+1].email;
                information[i+1].email = hold.email;

                hold.dob = information[i].dob;
                information[i].dob = information[i+1].dob;
                information[i+1].dob = hold.dob;

                hold.gender = information[i].gender;
                information[i].gender = information[i+1].gender;
                information[i+1].gender = hold.gender;

                hold.phoneNumber = information[i].phoneNumber;
                information[i].phoneNumber = information[i+1].phoneNumber;
                information[i+1].phoneNumber = hold.phoneNumber;

                hold.lnumber = information[i].lnumber;
                information[i].lnumber = information[i+1].lnumber;
                information[i+1].lnumber = hold.lnumber;
            }
        }
    }
}

//check if the date of birth is valid (date of birth is based on Persian Calender in this program)

bool check (string birthdate) {

    if (birthdate.at(4) != '/' || birthdate.at(7) != '/') {

        cerr << endl << "Error : Invalid Input!"
             << endl << "Please Use Slash!" << endl << endl;

        return false;
    }

    if (
            (birthdate.at(0) != 49) ||
            (birthdate.at(1) < 50 || birthdate.at(1) > 52) ||
            (birthdate.at(2) < 48 || birthdate.at(2) > 57) ||
            (birthdate.at(3) < 48 || birthdate.at(3) > 57) ||
            (birthdate.at(5) < 48 || birthdate.at(5) > 49) ||
            (birthdate.at(6) < 48 || birthdate.at(6) > 57) ||
            (birthdate.at(5) == 49 && birthdate.at(6) > 50)||
            (birthdate.at(8) < 48 || birthdate.at(8) > 51) ||
            (birthdate.at(9) < 48 || birthdate.at(9) > 57) ||
            (birthdate.at(5) == 48 && birthdate.at(6) < 55 && birthdate.at(8) == 51 && birthdate.at(9) > 49) ||
            (birthdate.at(5) == 49 && birthdate.at(6) < 51 && birthdate.at(8) == 51 && birthdate.at(9) > 48)
            )
    {
        cerr << endl << "Error : Invalid Input!" << endl << endl;
        return false;
    }

    return true;
}

//check if the given name is valid (not using any other character but alphabet)

bool checkName (string fname, string lname) {

    if ((fname.at(0) < 65 || fname.at(0) > 90) ||
            (lname.at(0) < 65 || lname.at(0) > 90 )) {

        cerr << endl << "Error : Start the parts of the name with captial letters!" << endl << endl;
        return false;
    }

    for (unsigned int i = 1, j = 1; i < fname.length() && j < lname.length(); i++,j++) {

        if ((fname.at(i) < 97 || fname.at(i) > 122) ||
                (lname.at(j) < 97 || lname.at(j) > 122)) {

            cerr << endl << "Invalid Input!" << endl << endl;
            return false;
        }
    }

    return true;
}

//check if the number starts with 0

bool checkNumber (string number) {

    if (number.at(0) != 48) {

        cerr << endl << "Error : Enter '0' at the first of the number!" << endl << endl;
        return false;
    }

    return true;
}
