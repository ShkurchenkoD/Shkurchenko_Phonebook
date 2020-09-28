#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

struct user
{
    string name;
    string email;
    string phone;
};

user* Add(user* first, int& count)
{
    int dog_present = 0;
    int point_after_dog = 0;
    if (count == 0)
    {
        first = new user[count + 1];
    }
    else
    {
        user* temp = new user[count + 1];
        for (int i = 0; i < count; i++)
        {
            temp[i] = first[i];
        }
        delete[]first;
        first = temp;
    }
NAME:
    cout << "Enter full name of subscriber:" << endl;
    getline(cin, first[count].name);
    for (int j = 0; j < first[count].name.length(); j++)
    {
        if (isdigit(first[count].name[j]))
        {
            cout << "Subscriber name cant include digits!" << endl;
            goto NAME;
        }
    }

EMAIL:
    dog_present = 0;
    point_after_dog = 0;
    cout << "Enter subscriber email:" << endl;
    getline(cin, first[count].email);
    for (int j = 0; j < first[count].email.length(); j++)
    {
        if (first[count].email[j] == '@')
        {
            dog_present = 1;
        }
        else if (first[count].email[j] == '.')
        {
            point_after_dog = 1;
        }
    }

    if (dog_present != 1)
    {
        cout << "Subscriber email have not @!" << endl;
        goto EMAIL;
    }

    if (point_after_dog == 0)
    {
        cout << "Subscriber email have not any point!" << endl;
        goto EMAIL;
    }
PHONE:
    cout << "Enter subscriber phone number:" << endl;
    getline(cin, first[count].phone);
    for (int k = 0; k < first[count].phone.length(); k++)
    {
        if (isalpha(first[count].phone[k]))
        {
            cout << "Subscriber phone number can`t include alphabet symbols!" << endl;
            goto PHONE;
        }
    }
    count++;
    return first;
}

user* Del(user* first, int& count)
{
    int del_num;
    if (count == 0)
    {
        cout << "There is no subscriber!" << endl;
        return 0;
    }
    else
    {
    DEL_AGAIN:
        cout << "Enter subscriber number which you want to delete:" << endl;
        cin >> del_num;
        del_num--;
        if (del_num < 0 || del_num > count - 1)
        {
            cout << "There is no subscriber in this number!\n" << endl;
            goto DEL_AGAIN;
        }
        else
        {
            user* temp = new user[count - 1];
            for (int i = 0; i < count; i++)
            {
                if (i < del_num)
                {
                    temp[i] = first[i];
                }
                else if (i == del_num)
                {
                    continue;
                }
                else if (i > del_num)
                {
                    temp[i - 1] = first[i];
                }
            }
            delete[] first;
            count--;
            first = temp;
            cout << "Subscriber number " << del_num + 1 << " delete successfully!" << endl;
            return first;
        }
    }
}

void Sort(user* first, int count)
{
    for (int i = count - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (first[j].name[0] > first[j + 1].name[0])
            {
                swap(first[j], first[j + 1]);
            }
        }
    }
    cout << "Your subscribers was sort successfully!" << endl;
}

void Search(user* first, int count)
{
    string serching_for_user;
    cout << "Enter name of subscriber you wish to find:" << endl;
    cin >> serching_for_user;
    for (int i = 0; i < count; i++)
    {
        if (first[i].name == serching_for_user)
        {
            cout << "\n" << i + 1 << ". Subscriber full name:\n" << first[i].name << "\nSubscriber email:\n" << first[i].email << "\nSubscriber phone number:\n" << first[i].phone << "\n=================" << endl;
        }
        else
        {
            cout << "There is no subscriber with this name..." << endl;
        }
    }
}

void ShowData(user* first, int count)
{
    for (int i = 0; i < count; i++)
    {
        cout << "\n" << i + 1 << ". Subscriber full name:\n" << first[i].name << "\nSubscriber email:\n" << first[i].email << "\nSubscriber phone number:\n" << first[i].phone << "\n=================" << endl;
    }
}

user* Edit(user*& first, int count)
{
    cout << "Choose subscriber that you want to change:" << endl;
    cin >> count;
    count--;
    cout << "Choose parametr you want to change.\n1. Change subscriber full name.\n2. Change subscriber email.\n3. Change subscriber phone number.\n0.Back to main menu.\n" << endl;
    int choose_parametr;
    bool play_edit = true;
    while (play_edit)
    {
        cin >> choose_parametr;
        switch (choose_parametr)
        {
        case 1:
        {
        NAME_EDIT:
            cout << "Change subscriber full name:" << endl;
            cin.ignore();
            getline(cin, first[count].name);
            for (int j = 0; j < first[count].name.length(); j++)
            {
                if (isdigit(first[count].name[j]))
                {
                    cout << "Subscriber name can`t include digits!" << endl;
                    goto NAME_EDIT;
                }
            }
            cout << "Changes was saved." << endl;
            break;
        }
        case 2:
        {
        EMAIL_EDIT:
            int dog_present_edit = 0;
            int point_after_dog_edit = 0;
            cout << "Change subscriber email:" << endl;
            cin.ignore();
            getline(cin, first[count].email);
            for (int j = 0; j < first[count].email.length(); j++)
            {
                if (first[count].email[j] == '@')
                {
                    dog_present_edit = 1;
                }
                else if (first[count].email[j] == '.')
                {
                    point_after_dog_edit = 1;
                }
            }

            if (dog_present_edit != 1)
            {
                cout << "Subscriber email have not @!" << endl;
                goto EMAIL_EDIT;
            }

            if (point_after_dog_edit == 0)
            {
                cout << "Subscriber email have not any point!" << endl;
                goto EMAIL_EDIT;
            }
            cout << "Changes was saved." << endl;
            break;
        }
        case 3:
        {
        PHONE_EDIT:
            cout << "Change subscriber phone number:" << endl;
            cin.ignore();
            getline(cin, first[count].phone);
            for (int k = 0; k < first[count].phone.length(); k++)
            {
                if (isalpha(first[count].phone[k]))
                {
                    cout << "Subscriber phone number can`t include alphabet symbols!" << endl;
                    goto PHONE_EDIT;
                }
            }
            cout << "Changes was saved." << endl;
            break;
        }
        case 0:
        {
            play_edit = false;
            break;
        }
        default:
        {
            cout << "Wrong choice." << endl;
            break;
        }
        }
    }
    return first;
}

void Write(const char* filename, user* first, int count)
{
    ofstream fout;
    fout.open("Users data.txt");
    if (!fout)
    {
        cout << "I can`t open the file!" << endl;
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            fout << "\n" << i + 1 << ". Subscriber full name:\n" << first[i].name << "\nSubscriber email:\n" << first[i].email << "\nSubscriber phone number:\n" << first[i].phone << "\n=================" << endl;
        }
    }
    fout.close();
}

void WriteBin(const char* filename, user* first, int count)
{
    ofstream fout;
    fout.open("Users data.bin", ios::out | ios::binary);
    if (!fout.is_open())
    {
        cout << "I can`t open the file!" << endl;
    }
    else
    {
        fout.write((char*)&count, sizeof(int));
        for (int i = 0; i < count; i++)
        {
            int len_name = first[i].name.length() + 1;
            fout.write((char*)&len_name, sizeof(int));
            fout.write(first[i].name.c_str(), sizeof(char) * len_name);
            int len_email = first[i].email.length() + 1;
            fout.write((char*)&len_email, sizeof(int));
            fout.write(first[i].email.c_str(), sizeof(char) * len_email);
            int len_phone = first[i].phone.length() + 1;
            fout.write((char*)&len_phone, sizeof(int));
            fout.write(first[i].phone.c_str(), sizeof(char) * len_phone);
        }
    }
    fout.close();
}

void Read(const char* filename, user*& first, int& count)
{
    ifstream fin;
    fin.open("Users data.txt");
    if (!fin.is_open())
    {
        cout << "Error with opening the file!" << endl;
    }
    else
    {
        cout << "File is open!" << endl;
        string read;

        int ent_count = 0;
        while (!fin.eof())
        {
            getline(fin, read);
            ent_count++;

            //cout << read << endl;
            if (ent_count % 8 == 0)
            {
                count++;
                first = new user[count];
            }
        }
        fin.close();
        ent_count = 0;
        count = 0;
        fin.open("Users data.txt");
        while (!fin.eof())
        {
            read = "";
            getline(fin, read);

            ent_count++;
            if (ent_count == 3)
            {
                first[count].name = read;
            }
            if (ent_count == 5)
            {
                first[count].email = read;
            }
            if (ent_count == 7)
            {
                first[count].phone = read;
            }
            if (ent_count % 8 == 0)
            {
                count++;
                ent_count = 0;
            }
        }
    }
    fin.close();
}

void ReadBin(const char* filename, user*& first, int& count)
{
    ifstream fin;
    fin.open("Users data.bin", ios::in | ios::binary);
    if (!fin.is_open())
    {
        cout << "Error with opening the file!" << endl;
    }
    else
    {
        cout << "File is open!" << endl;
        fin.read((char*)&count, sizeof(int));
        first = new user[count];
        for (int i = 0; i < count; i++)
        {
            int len_name = 0;
            fin.read((char*)&len_name, sizeof(int));
            char* name = new char[len_name];
            fin.read(name, sizeof(char) * len_name);
            int len_email = 0;
            fin.read((char*)&len_email, sizeof(int));
            char* email = new char[len_email];
            fin.read(email, sizeof(char) * len_email);
            int len_phone = 0;
            fin.read((char*)&len_phone, sizeof(int));
            char* phone = new char[len_phone];
            fin.read(phone, sizeof(char) * len_phone);

            first[i].name = name;
            first[i].email = email;
            first[i].phone = phone;

        }
    }
    fin.close();
}


int main()
{
    user* first = 0;
    int count = 0;
    int choice;
    bool play = true;
    while (play)
    {
        cout << "Main menu:\n1 - Add new subscriber.\n2 - Edit subscriber.\n3 - Show all subscribers.\n4 - Sort all subscribers by surname.\n5 - Searching for user by name.\n6 - Write subscribers to telephone book.txt.\n7 - Read subscribers from telephone book.txt.\n8 - Write subscribers to telephone book.bin.\n9 - Read subscribers from telephone book.bin.\n10 - Delete subscriber.\n0 - Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cin.ignore();
            first = Add(first, count);
            break;
        }
        case 2:
        {
            Edit(first, count);
            break;
        }
        case 3:
        {
            ShowData(first, count);
            break;
        }
        case 4:
        {
            Sort(first, count);
            break;
        }
        case 5:
        {
            Search(first, count);
            break;
        }
        case 6:
        {
            Write("Users data.txt", first, count);
            break;
        }
        case 7:
        {
            Read("Users data.txt", first, count);
            ShowData(first, count);
            break;
        }
        case 8:
        {
            WriteBin("Users data.bin", first, count);
            break;
        }
        case 9:
        {
            ReadBin("Users data.bin", first, count);
            ShowData(first, count);
            break;
        }
        case 10:
        {
            first = Del(first, count);
            break;
        }
        case 0:
        {
            play = false;
            break;
        }
        default:
        {
            cout << "Wrong choice!" << endl;
        }
        }
    }
}
