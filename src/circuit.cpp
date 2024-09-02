#include <iostream>
#include "circuit.h"
#include "wire.h"
#include "gate.h"
#include <bits/stdc++.h> 

//---CWire Implementation------------------------------------------
CCircuit::CCircuit(int a_num_gates, int a_num_wires, int a_num_ins, int a_num_outs)
{
    m_num_gates = a_num_gates;
    m_num_wires = a_num_wires;
    m_num_ins = a_num_ins;
    m_num_outs = a_num_outs;

    expand_component_lists();
}

//--
CCircuit::~CCircuit(){

    for (int i = 0; i < m_num_gates; i++){
        if (m_gates_in_circuit[i] != NULL){
            delete m_gates_in_circuit[i];
            m_gates_in_circuit[i] = nullptr;
        }
    }
    for (int i = 0; i < m_num_wires; i++){
        if (m_wires_in_circuit[i] != NULL){
            delete m_wires_in_circuit[i];
            m_wires_in_circuit[i] = nullptr;
        }   
    }


    // delete[] m_circuit_outputs;
    // delete[] m_ins;
    // delete[] m_gates_in_circuit;
    // delete[] m_wires_in_circuit;

}

//--
void CCircuit::expand_component_lists(){
    // CGate**      temp_gates = new CGate*     [m_num_gates];
    // CWire**      temp_wires = new CWire*     [m_num_wires];
    // eLogicLevel* temp_outs  = new eLogicLevel[m_num_outs];
    // eLogicLevel* temp_ins   = new eLogicLevel[m_num_ins];



    // m_gates_in_circuit = temp_gates;
    // m_wires_in_circuit = temp_wires;
    // m_circuit_outputs  = temp_outs;
    // m_ins              = temp_ins;

}

//--
void CCircuit::collect_components(){


    //instatiate all NAND gates
    for (int i = 0; i < m_num_NAND; i++){
        m_gates_in_circuit.push_back(new CNandGate());
        // m_gates_in_circuit.push_back(new CNandGate);
    }

    //instatiate all AND gates
    for (int i = 0; i < m_num_AND; i++){
        m_gates_in_circuit.push_back(new CAndGate());
    }

    //instatiate all OR gates
    for (int i = 0; i < m_num_OR; i++){
        m_gates_in_circuit.push_back(new COrGate());
    }

    //instatiate all NOR gates
    for (int i = 0; i < m_num_NOR; i++){
        m_gates_in_circuit.push_back(new CNorGate());//--
    }

    //instatiate all XOR gates
    for (int i = 0; i < m_num_XOR; i++){
        m_gates_in_circuit.push_back(new CXorGate());
    }

    //instatiate all NOT gates
    for (int i = 0; i < m_num_NOT; i++){
        m_gates_in_circuit.push_back(new CNotGate);
    }
           

    //instantiate all wires
    for (int i = 0; i < m_num_wires; i++){
        m_wires_in_circuit.push_back(new CWire);
    }
}


//---C1BitComp Implementation------------------------------------------
C1BitComp::C1BitComp()
    : CCircuit(5, 6, 2, 3)
{
    m_num_NAND  = 0;    
    m_num_OR    = 0;  
    m_num_XOR   = 0;
    m_num_NOT   = 2;
    m_num_AND   = 2;
    m_num_NOR   = 1;


    build_circuit();
}

//--
C1BitComp::~C1BitComp(){

}

//--
void C1BitComp::build_circuit(){

    
    collect_components();

    CGate* and_1 = m_gates_in_circuit[0];
    CGate* and_2 = m_gates_in_circuit[1];

    CGate* nor_1 = m_gates_in_circuit[2];

    CGate* not_1 = m_gates_in_circuit[3];
    CGate* not_2 = m_gates_in_circuit[4];


    m_wires_in_circuit[0]->add_output_connection(not_1, 0);
    m_wires_in_circuit[0]->add_output_connection(and_2, 0);

    m_wires_in_circuit[1]->add_output_connection(not_2, 0);
    m_wires_in_circuit[1]->add_output_connection(and_1, 1);



    not_1->connect_output(m_wires_in_circuit[2]);
    not_2->connect_output(m_wires_in_circuit[3]);


    m_wires_in_circuit[2]->add_output_connection(and_1, 0);
    m_wires_in_circuit[3]->add_output_connection(and_2, 1);



    and_1->connect_output(m_wires_in_circuit[4]);
    and_2->connect_output(m_wires_in_circuit[5]);


    m_wires_in_circuit[4]->add_output_connection(nor_1, 0);
    m_wires_in_circuit[5]->add_output_connection(nor_1, 1);

    return;
}

//--
void CCircuit::get_outputs(eLogicLevel outputs[3]){
    for (int i = 0; i < 3; i++){
        outputs[i] = m_circuit_outputs[i];
    }
}

//--
void CCircuit::set_inputs(eLogicLevel* a_ins){

    m_ins.resize(m_num_ins);
    for (int i = 0; i < m_num_ins; i++){
        eLogicLevel temp = a_ins[i];

        m_ins[i] = temp;

        m_wires_in_circuit[i]->drive_level(m_ins[i]);
    }


    m_circuit_outputs.resize(3);

    m_circuit_outputs[0] = m_gates_in_circuit[0]->get_output_state();
    m_circuit_outputs[1] = m_gates_in_circuit[2]->get_output_state();
    m_circuit_outputs[2] = m_gates_in_circuit[1]->get_output_state();
}

//---C2BitComp Implementation------------------------------------------
void C2BitComp::set_inputs(eLogicLevel* a_ins){

    eLogicLevel out_0[3];
    eLogicLevel out_1[3];
    eLogicLevel ins_3[6];

    //set the inputs of each sub circuit
    for (int i = 0; i < 2; i++){
        eLogicLevel ins[2] = {a_ins[i], a_ins[i + 2]};
        m_sub_circuits[i]->set_inputs(ins);
    }

    //get and store the inputs of each sub circuit
    m_sub_circuits[0]->get_outputs(out_0);
    m_sub_circuits[1]->get_outputs(out_1);


    //concatenate the outputs of the sub circuits as the inputs of the 2 bit comp
    for (int i = 0; i < 3; i++){
        ins_3[i] = out_0[i];
    }
    for (int i = 0; i < 3; i++){
        ins_3[3 + i] = out_1[i];
    }

    m_ins.resize(m_num_ins);
    //set the inputs of each input for the 2 bit comp
    for (int i = 0; i < m_num_ins; i++){
        eLogicLevel temp = ins_3[i];

        m_ins[i] = temp;

        m_wires_in_circuit[i]->drive_level(m_ins[i]);
    }

    m_circuit_outputs.resize(3);
    //store the new circuit outputs
    m_circuit_outputs[0] = m_gates_in_circuit[3]->get_output_state();
    m_circuit_outputs[1] = m_gates_in_circuit[1]->get_output_state();
    m_circuit_outputs[2] = m_gates_in_circuit[4]->get_output_state();
}

// --
C2BitComp::C2BitComp(CCircuit* a_1bit_0, CCircuit* a_1bit_1)
    : CCircuit(5, 8, 6, 3)   
{

    m_sub_circuits[0] = a_1bit_0;
    m_sub_circuits[1] = a_1bit_1;
    
    m_num_NAND  = 0;    
    m_num_OR    = 2;  
    m_num_XOR   = 0;
    m_num_NOT   = 0;
    m_num_AND   = 3;
    m_num_NOR   = 0;

    build_circuit();
}

//--
C2BitComp::~C2BitComp(){

    }

//--
void C2BitComp::build_circuit(){


    collect_components();

    CGate* and_0 = m_gates_in_circuit[0];
    CGate* and_1 = m_gates_in_circuit[1];
    CGate* and_2 = m_gates_in_circuit[2];

    CGate* or_0  = m_gates_in_circuit[3];
    CGate* or_1  = m_gates_in_circuit[4];

    m_wires_in_circuit[0]->add_output_connection(or_0, 0);

    m_wires_in_circuit[1]->add_output_connection(and_0, 0);
    m_wires_in_circuit[1]->add_output_connection(and_1, 0);
    m_wires_in_circuit[1]->add_output_connection(and_2, 0);

    m_wires_in_circuit[2]->add_output_connection(or_1, 0);

    m_wires_in_circuit[3]->add_output_connection(and_0, 1);

    m_wires_in_circuit[4]->add_output_connection(and_1, 1);

    m_wires_in_circuit[5]->add_output_connection(and_2, 1);

    
    and_0->connect_output(m_wires_in_circuit[6]);
    and_2->connect_output(m_wires_in_circuit[7]);

    m_wires_in_circuit[6]->add_output_connection(or_0, 1);
    m_wires_in_circuit[7]->add_output_connection(or_1, 1);
}

