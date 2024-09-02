#include <iostream>
#include "../include/gate.h"
#include "../include/soft_circuit.h"


CSoftCircuit::CSoftCircuit(){};

CSoftCircuit::~CSoftCircuit(){

}

//read the text file
void CSoftCircuit::build_circuit(){
    while( true )
  {
    std::string request;

    std::cin >> request;  // get the next word from the input stream
    std::cout << "Processing input token: " << request << std::endl;
    
    if( request[0] == '#' )
    {
      // a comment line
      // get the rest of the line and ignore it
      std::string DummyVar;
      getline( std::cin, DummyVar );
    }
    else if( request.compare( "component" ) == 0 )
    {
        std::string gate_type;
        std::string gate_name;
        std::cin >> gate_type;
        std::cin >> gate_name;
        std::cout << "Adding gate of type " << gate_type << " named " << gate_name << std::endl;

        CGate* temp_gate;

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

        m_gates_in_circuit.insert({gate_name, temp_gate});
    
      // TODO : add the gate
      // A hash table to store my gates and one for my wires?
      // A circuit will have a hash table and use an appropriate hash function

    }
    else if( request.compare( "wire" ) == 0 )
    {
    
      // TODO: implement wire command
      // Add Wire_x to my hash table
    
    }
    
    else if (request.compare("input") == 0){
      //implement input. Connect a wire to the input of a gate
      //addoutputconnection
      //get a wire from a circuit's has table and add an output

    }

    else if(request.compare("output") == 0){
      //implement outout. connect the output of a gate to a wire
      //wire.drivelevel
      // get a gate from a circuit, and a wire (from the hash table), drive the wire
    }
    // TODO: add whatever other commands you need
    
    else if( request.compare( "end" ) == 0 )
    {
      break; // end of file
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