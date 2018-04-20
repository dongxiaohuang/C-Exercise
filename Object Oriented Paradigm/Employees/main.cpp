#include "Employee.h"
#include "Manager.h"
#include "Office.h"
#include "Boss.h"
#include "EmployeeList.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    /* code */
    Office* o = new Office();
    Boss* new_boss;// will not create object ie construct
    Office& o_ref = *o;//will not create object ie construct as well as copy

    Manager Scrooge(5, "Scrooge MacDuck", *o);
    Employee Donald(13456, "Donald Duck", *o);
    Boss Don("Don", *o);
    cout << Scrooge << endl;
    cout << Donald << endl;
    cout << Don << endl;
    Scrooge.paycut(100);
    Donald.paycut(100);
    cout << Scrooge << endl;
    cout << Donald << endl;

    Employee* emp_ptr = &Scrooge;
    Employee& emp_ref = Scrooge;
    Employee emp_obj = Scrooge;
    Scrooge.payrise(100); // static binding because not pointer
    emp_ptr -> paycut(100); // dynamic binding only when pointer/reference and virtual functions
    emp_ref.paycut(100);// static binding because not pointer
    cout << *emp_ptr << endl;// static binding
    cout << Scrooge << endl;// static binding
    cout << emp_ref << endl;// static binding

    cout << endl <<  "====================" << endl;;

    Scrooge.payrise(100);// 49000 static binding
    emp_ptr -> payrise(100);//static binding
    emp_ref.payrise(100);//static binding
    // all deal in the Scrooge address

    Scrooge.scoldEmploy();
    // emp_ptr -> scoldEmploy(); //llegal!
    // emp_ref.scoldEmploy();   //illegal!
    // emp_obj.scoldEmploy(); // illegal
    //deal in another address copy from Scrooge
    emp_obj.payrise(100);//static binding

    cout << *emp_ptr << endl;// static binding
    cout << Scrooge << endl;// static binding
    cout << emp_ref << endl;// static binding
    cout << emp_obj << endl;// static binding

    cout << "Donald "; Donald.holiday();// binding for local calls
    cout << "Scrooge "; Scrooge.holiday();

    //difference between dynamic binding and static binding
    Employee* new_emp;

    new_emp -> sayhi(); // ok because it is static binding and have no  memory access
    cout << "__";
    // new_emp -> paycut(100); //segmentation fault, it is dynamic binding and need to check type of new_emp


    cout << endl <<  "=========Employee List===========" << endl;
    EmployeeList disneyList(
        new Manager(5, "Scrooge Mac Duck", *o)
    );
    disneyList.insert(
        new Employee(12533, "Sam Dim", *o)
    );
    disneyList.insert(
        new Employee(23533, "May Timberson", *o)
    );

    cout << disneyList;
    disneyList.paycut(100);
    cout << disneyList;

    //TODO: delete all the dynamic list

    delete o;
    return 0;
}
