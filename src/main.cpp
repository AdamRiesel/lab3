#include <iostream>

#include "../include/gate.h"
#include "../include/wire.h"
#include "../include/circuit.h"
#include "../include/types.h"
#include "../include/person.h"
#include "../include/soft_circuit.h"

int main(){


    // CSoftCircuit my_soft_circuit;

    // my_soft_circuit.build_circuit();
    CPerson adamriesel;

    C1BitComp my_1bit_comp;
    C1BitComp second_comp;


    C2BitComp my_2bit_comp(&my_1bit_comp, &second_comp);
    

    adamriesel.add_circuit(&my_1bit_comp);
    adamriesel.add_circuit(&second_comp);
    adamriesel.add_circuit(&my_2bit_comp);

    
    adamriesel.test_all_combs(2);

    std::vector<CGate*> my_vector;

    my_vector.push_back(new CNandGate);
    my_vector[0]->drive_input(0, LOGIC_HIGH);
    my_vector[0]->drive_input(1, LOGIC_LOW);

    eLogicLevel out = my_vector[0]->get_output_state();

    std::cout<<"My output is: "<<out<<std::endl;
    
    // while (true){
    //     int x = 1;
    // }
    return 0;
}