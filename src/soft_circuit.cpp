#include <iostream>

#include "gate.h"
#include "soft_circuit.h"
#include "wire.h"

//-------SoftCircuit Implementation--------------
CSoftCircuit::CSoftCircuit(){}
CSoftCircuit::~CSoftCircuit(){}

//--
void CSoftCircuit::build_circuit(){
    while( true )
  {
    std::string request;

    // get the next word from the input stream
    std::cin >> request;  
    std::cout << "Processing input token: " << request << std::endl;
    
    //ignore comments marked with a '#'
    if( request[0] == '#' )
    {
      // get the rest of the line and ignore it
      std::string DummyVar;
      getline( std::cin, DummyVar );
    }

    //add a gate component of any type e.g. NAND, NOT etc
    else if( request.compare( "component" ) == 0 )
    {
        std::string gate_type;
        std::string gate_name;
        std::cin >> gate_type;
        std::cin >> gate_name;
        std::cout << "Adding gate of type " << gate_type << " named " 
                  << gate_name << std::endl;

        CGate* temp_gate;

        //determine which type of gate to add to has table
        if (gate_type == "NAND"){
            temp_gate = new CNandGate;
        }
        else if (gate_type == "AND"){
            temp_gate = new CAndGate;
        }
        else if (gate_type == "NOT"){
            temp_gate = new CNotGate;
        }
        else if (gate_type == "OR"){
            temp_gate = new COrGate;
        }
        else if (gate_type == "NOR"){
            temp_gate = new CNorGate;
        }
        else if (gate_type == "XOR"){
            temp_gate = new CXorGate;
        }
        else {
            std::cout<<"you fool, bad gate type"<<std::endl;
        }

        //add gate to hash table
        m_gates_in_circuit.insert({gate_name, temp_gate});
    }

    //add a wire to the circuit
    else if( request.compare( "wire" ) == 0 )
    {
        std::string wire_name;
        std::cin >> wire_name;
        std::cout << "Adding a wire with name: " << wire_name << std::endl;

      CWire* temp_wire;
      temp_wire = new CWire;

      m_wires_in_circuit.insert({wire_name, temp_wire});    
    }

    //connect wire output to gate input
    else if (request.compare("input") == 0){
      std::string wire_name;
      std::string gate_name;
      std::string input_idx_str;

      std::cin >> wire_name;
      std::cin >> gate_name;
      std::cin >> input_idx_str;

      int input_idx = stoi(input_idx_str);

      std::cout << "Connecting the output of wire: " << wire_name
                << " to the input of gate: " << gate_name <<std::endl;

      CWire* temp_wire = m_wires_in_circuit.find(wire_name)->second;
      CGate* temp_gate = m_gates_in_circuit.find(gate_name)->second;

      temp_wire->add_output_connection(temp_gate, input_idx);
    }

    //connect a wire to the output of a gate
    else if(request.compare("output") == 0){
      std::string gate_name;
      std::string wire_name;

      std::cin >> gate_name;
      std::cin >> wire_name;
      
      CWire* temp_wire = m_wires_in_circuit.find(wire_name)->second;
      CGate* temp_gate = m_gates_in_circuit.find(gate_name)->second;

      temp_gate->connect_output(temp_wire);
    }
    
    //end the process of building the circuit
    else if( request.compare( "end" ) == 0 )
    {
      break; 
    }
    else
    {
      std::cout << "Unrecognised command " << request << std::endl;
      std::cout << "Continuing to next line" << std::endl;

      // get the rest of the line and ignore it
      std::string DummyVar;
      getline( std::cin, DummyVar );
    }
  }

}

//--
void CSoftCircuit::set_inputs(std::vector<std::string> names, 
                std::vector<CGate::eLogicLevel> values){

  CWire* temp_wire;

  //set the logic level of each wire specified
  for (int i = 0; i < int(names.size()); i++){
    temp_wire = m_wires_in_circuit.find(names[i])->second;
    temp_wire->drive_level(values[i]);
  }
}

//--
void CSoftCircuit::get_outputs(std::vector<std::string> names, 
          std::vector<CGate::eLogicLevel> &outs){

  CWire* temp_wire;

  //retrieve the logic level of each output wire epcified
  for (int i = 0; i < int(names.size()); i++){
    temp_wire = m_wires_in_circuit.find(names[i])->second;

    //store the logic value into the output vector
    CGate::eLogicLevel drive_value = temp_wire->get_drive_value();
    outs.push_back(drive_value);

  }
}