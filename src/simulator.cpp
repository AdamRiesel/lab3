
#include <iostream>
#include <string>

#include "../include/simulator.h"

CSimulator::CSimulator(){
    //TODO
    // Create a person into m_test_subject
}

CSimulator::~CSimulator(){}

void CSimulator::read_circuit_file(){

  while( true )
  {
    std::string Request;

    std::cin >> Request;  // get the next word from the input stream
    std::cout << "Processing input token: " << Request << std::endl;
    
    if( Request[0] == '#' )
    {
      // a comment line
      // get the rest of the line and ignore it
      std::string DummyVar;
      getline( std::cin, DummyVar );
    }
    else if( Request.compare( "component" ) == 0 )
    {
      std::string GateType;
      std::string GateName;
      std::cin >> GateType;
      std::cin >> GateName;
      std::cout << "Adding gate of type " << GateType << " named " << GateName << std::endl;
      // TODO : add the gate
      // A hash table to store my gates and one for my wires?
      // A circuit will have a hash table and use an appropriate hash function

    }
    else if( Request.compare( "wire" ) == 0 )
    {
    
      // TODO: implement wire command
      // Add Wire_x to my hash table
    
    }
    
    else if (Request.compare("input") == 0){
      //implement input. Connect a wire to the input of a gate
      //addoutputconnection
      //get a wire from a circuit's has table and add an output

    }

    else if(Request.compare("output") == 0){
      //implement outout. connect the output of a gate to a wire
      //wire.drivelevel
      // get a gate from a circuit, and a wire (from the hash table), drive the wire
    }
    // TODO: add whatever other commands you need
    
    else if( Request.compare( "end" ) == 0 )
    {
      break; // end of file
    }
    else
    {
      std::cout << "Unrecognised command " << Request << std::endl;
      std::cout << "Continuing to next line" << std::endl;
      // get the rest of the line and ignore it
      std::string DummyVar;
      getline( std::cin, DummyVar );
    }
  }
}

