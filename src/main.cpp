#include <iostream>
#include <string>
#include <unordered_map>

#include "gate.h"
#include "wire.h"
#include "types.h"
#include "person.h"
#include "soft_circuit.h"

int main(){


    CSoftCircuit my_soft_circuit;

    //allow user to create a circuit
    my_soft_circuit.build_circuit();

    //create a person to own the circuit
    CPerson adamriesel;
    adamriesel.add_circuit(&my_soft_circuit);

    //person who owns the circuit tests the circuit
    adamriesel.test_circuit(0);

    return 0;
}