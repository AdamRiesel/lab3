#include "person.h"
#include "circuit.h"

#include <iostream>

//---CPerson Implementation------------------------------------------
CPerson::CPerson(){
}

//--
CPerson::~CPerson(){

}

//--
void CPerson::add_circuit(CCircuit* a_new_circuit){
    //TODO
    /**
     * choose what type of circuit: 1 bit, 2 bit, etc.
     */
    m_circuits_owned.push_back(a_new_circuit);
}

//--
void CPerson::test_circuit(int a_circuit_idx, eLogicLevel In0, eLogicLevel In1){
    eLogicLevel Ins[2] = {In0, In1};
    eLogicLevel out[3];
    m_circuits_owned[a_circuit_idx]->set_inputs(Ins);
    m_circuits_owned[a_circuit_idx]->get_outputs(out);


}

//--
void CPerson::test_circuit(int a_circuit_idx, eLogicLevel In0, eLogicLevel In1, 
    eLogicLevel In2, eLogicLevel In3){


    std::cout<<"In: "<<In0<<In1<<" "<<In2<<In3;

    //make ins into a 4 bit aray and pass to set_inputs
    eLogicLevel ins[4] = {In0, In1, In2, In3};
 

    m_circuits_owned[2]->set_inputs(ins);

    eLogicLevel bit2_out[3];
    m_circuits_owned[2]->get_outputs(bit2_out);

    std::cout<<"--Out: ";

    for (int i = 0; i < 3; i++){
        std::cout<<bit2_out[i];
    }
    std::cout<<std::endl;


}

//--
void CPerson::test_all_combs(int a_idx){
    if (a_idx == 2){
        
        test_circuit(2, LOGIC_LOW,  LOGIC_LOW,  LOGIC_LOW,  LOGIC_LOW);
        test_circuit(2, LOGIC_LOW,  LOGIC_LOW,  LOGIC_LOW,  LOGIC_HIGH);
        test_circuit(2, LOGIC_LOW,  LOGIC_LOW,  LOGIC_HIGH, LOGIC_LOW);
        test_circuit(2, LOGIC_LOW,  LOGIC_LOW,  LOGIC_HIGH, LOGIC_HIGH);
        test_circuit(2, LOGIC_LOW,  LOGIC_HIGH, LOGIC_LOW,  LOGIC_LOW);
        test_circuit(2, LOGIC_LOW,  LOGIC_HIGH, LOGIC_LOW,  LOGIC_HIGH);
        test_circuit(2, LOGIC_LOW,  LOGIC_HIGH, LOGIC_HIGH, LOGIC_LOW);
        test_circuit(2, LOGIC_LOW,  LOGIC_HIGH, LOGIC_HIGH, LOGIC_HIGH);
        test_circuit(2, LOGIC_HIGH, LOGIC_LOW,  LOGIC_LOW,  LOGIC_LOW);
        test_circuit(2, LOGIC_HIGH, LOGIC_LOW,  LOGIC_LOW,  LOGIC_HIGH);
        test_circuit(2, LOGIC_HIGH, LOGIC_LOW,  LOGIC_HIGH, LOGIC_LOW);
        test_circuit(2, LOGIC_HIGH, LOGIC_LOW,  LOGIC_HIGH, LOGIC_HIGH);
        test_circuit(2, LOGIC_HIGH, LOGIC_HIGH, LOGIC_LOW,  LOGIC_LOW);
        test_circuit(2, LOGIC_HIGH, LOGIC_HIGH, LOGIC_LOW,  LOGIC_HIGH);
        test_circuit(2, LOGIC_HIGH, LOGIC_HIGH, LOGIC_HIGH, LOGIC_LOW);
        test_circuit(2, LOGIC_HIGH, LOGIC_HIGH, LOGIC_HIGH, LOGIC_HIGH);
    }
}
