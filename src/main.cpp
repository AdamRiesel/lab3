#include <iostream>

#include "gate.h"
#include "wire.h"
#include "circuit.h"
#include "types.h"
#include "person.h"


int main(){

    CPerson adamriesel;

    C1BitComp my_1bit_comp;
    C1BitComp second_comp;


    C2BitComp my_2bit_comp(&my_1bit_comp, &second_comp);
    

    adamriesel.add_circuit(&my_1bit_comp);
    adamriesel.add_circuit(&second_comp);
    adamriesel.add_circuit(&my_2bit_comp);

    
    adamriesel.test_all_combs(2);
    

    return 0;
}