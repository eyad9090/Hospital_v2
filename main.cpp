#include<bits/stdc++.h>
using namespace std;
struct Helper
{
    char to_upper(char c)
    {
        if(is_lower(c))
        {
            c=(char)(c-'a'+'A');
        }
        return c;
    }
    char to_lower(char c)
    {
        if(is_upper(c))
        {
            c=(char)(c-'A'+'a');
        }
        return c;
    }
    char is_lower(char c)
    {
        if(c>='a'&&c<='z')
            return true;
        return false;
    }
    char is_upper(char c)
    {
        if(c>='A'&&c<='Z')
            return true;
        return false;
    }

    string to_lower(string str)
    {
        for(char &c:str)
        {
            if(is_upper(c))
            {
                c=to_lower(c);
            }
        }
        return str;
    }


    int string_to_integer(string number)
    {
        int ans=0;
        for(int i=0; i<number.size(); i++)
        {
            if(number[i]>='0'&&number[i]<='9')
            {
                ans=ans*10+(number[i]-'0');
            }
            else
                return -1;
        }
        return ans;
    }

    int get_integer_in_range(int range_start,int range_end)
    {
        string choice;
        cin>>choice;
        int ans=-1;
        while(ans==-1)
        {
            ans=string_to_integer(choice);
            if(ans>=range_start&&ans<=range_end)
            {
                return ans;
            }
            else
            {
                cout<<"Invalid\n";
                cout<<"Please enter valid number in range["
                    <<range_start<<"-"<<range_end<<"]: ";
                cin>>choice;
                ans=-1;
            }
        }
    }

    bool is_only_character_space(string str)
    {
        for(char c:str)
        {
            if( (c>='a'&&c<='z') || (c>='A'&&c<='Z')||c==' ' )
            {
                continue;
            }
            return false;
        }
        return true;
    }
    string get_character_space(string message)
    {
        cout<<message;
        string str;
        fflush(stdin);
        getline(cin,str);
        while(!is_only_character_space(str))
        {
            cout<<"invalid\n";
            cout<<message;
            cin>>str;
        }
        str=to_lower(str);
        return str;
    }
};

Helper helper;

struct Patient
{
    string name;
    int status;
    void print()
    {
        cout<<"Name:"<<name
            <<"\tstatus:"<<(status==0?"Normal":"Urgent")
            <<"\n";
    }
    void read_name()
    {
        name=helper.get_character_space("please enter name:");
    }
    void read_status()
    {
        cout<<"Please enter the status:";
        status=helper.get_integer_in_range(0,1);
    }
    string get_name()
    {
        return name;
    }
    int get_status()
    {
        return status;
    }
    void read()
    {
        read_name();
        read_status();
    }
};
struct Queue
{
    int idx=0;
    Patient patient[5];
    bool is_full()
    {
        return idx==5;
    }
    bool is_empty()
    {
        return idx==0;
    }
    bool add_end(Patient _patient)
    {
        if(is_full())
        {
            return false;
        }
        patient[idx++]=_patient;
        return true;
    }
    bool add_front(Patient _patient)
    {
        if(is_full())
        {
            return false;
        }

        for(int i=idx; i>0; i--)
        {
            patient[i]=patient[i-1];
        }
        patient[0]=_patient;
        idx++;
        return true;
    }
    Patient remove_front()
    {
        Patient ans;
        if(is_empty())
        {
            return ans;
        }
        ans=patient[0];
        for(int i=0; i<idx-1; i++)
        {
            patient[i]=patient[i+1];
        }
        idx--;
        return ans;
    }
    bool add_patient(Patient _patient)
    {
        if(_patient.status==0)
        {
            return add_end(_patient);
        }
        else
        {
            return add_front(_patient);
        }
    }
    int get_size()
    {
        return idx;
    }
    void print_patient()
    {
        for(int i=0; i<idx; i++)
        {
            patient[i].print();
        }
    }
};



//------data
Queue specializations[21];
//--------main functions
void specializations_list();
void add_new_patient();
void print_patients();
void get_next_patient();
void menu();
void start_program();


int main()
{
    start_program();
    return 0;
}










////main functions
void start_program()
{
    while(true)
    {
        cout<<"-------menu-----------\n\n";
        menu();
        cout<<"Please enter you choice:";
        int choice=helper.get_integer_in_range(1,4);
        if(choice==1)
        {
            add_new_patient();
        }
        else if(choice==2)
        {
            print_patients();
        }
        else if(choice==3)
        {
            get_next_patient();
        }
        else if(choice==4)
        {
            return ;
        }
    }
}

void menu()
{
    cout<<"1) Add new patient\n"
        <<"2) Print all patients\n"
        <<"3) Get next patient\n"
        <<"4) Exit program\n";
}
void specializations_list()
{
    cout<<"1) Cardiologist\n"
        <<"2) Gynecologist\n"
        <<"3) Neurologist\n"
        <<"4) Dermatologist\n"
        <<"5) Family Medicine\n"
        <<"6) Pediatrician\n"
        <<"7) Endocrinologist\n"
        <<"8) Gastroenterologist\n"
        <<"9) Oncologist\n"
        <<"10) Psychiatrist\n"
        <<"11) Internist\n"
        <<"12) Allergist\n"
        <<"13) Nephrologist\n"
        <<"14) Emergency Medicine\n"
        <<"15) Radiologist\n"
        <<"16) Ophthalmologist\n"
        <<"17) Geriatrician\n"
        <<"18) Infectious Disease Specialist\n"
        <<"19) Otolaryngologist\n"
        <<"20) Pulmonologist\n";
}
void add_new_patient()
{
    cout<<"-----add patient option-------\n\n";
    specializations_list();
    cout<<"Please enter your specialization:";
    int spec=helper.get_integer_in_range(1,20);
    if(specializations[spec].is_full())
    {
        cout<<"This specialization is full of patients\n";
        return;
    }
    Patient patient;
    patient.read();
    specializations[spec].add_patient(patient);
}
void print_patients()
{
    cout<<"-----Print patient option-------\n\n";
    specializations_list();
    cout<<"Please enter your specialization:";
    int spec=helper.get_integer_in_range(1,20);
    if(specializations[spec].is_empty())
    {
        cout<<"There is not any patients\n";
        return;
    }
    cout<<"There are "
    <<specializations[spec].get_size()
    <<" patients\n";
    specializations[spec].print_patient();
}
void get_next_patient()
{
    cout<<"-----get the next patient option-------\n\n";
    specializations_list();
    cout<<"Please enter your specialization:";
    int spec=helper.get_integer_in_range(1,20);
    if(specializations[spec].is_empty())
    {
        cout<<"There is not patient\n";
        return ;
    }
    Patient current_patient=specializations[spec].remove_front();
    cout<<"Patient:"<<current_patient.get_name()
    <<" please go with the doctor\n";
}
