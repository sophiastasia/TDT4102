#include "std_lib_facilities.h"
#include "Animal.h"

/*
1a: Public betyr at medlemmer kan aksesseres fra utsiden.
Privat betyr medlemmer verken kan aksesseres eller vises 
utenfor klassen.
Protected betyr at medlemmer ikke kan aksesseres utenfor klassen
men de kan bli aksessert gjennom arvede klasser.
*/

int main(){
    Animal a = Animal("Cat", 9);
    string s = a.toString();
    cout << s;
    return 0;
}