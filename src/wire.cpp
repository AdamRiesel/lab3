#include "wire.h"
#include "gate.h"
#include <iostream>


//---CWire Implementation------------------------------------------
CWire::CWire(){

}

//--
CWire::~CWire(){

}

//---
void CWire::add_output_connection( CGate* ap_gate_to_drive, 
            int a_gate_input2drive )
{ 

  mp_gates2drive.push_back(ap_gate_to_drive);
  m_gate_input_indices.push_back(a_gate_input2drive);
}

//---
void CWire::drive_level( eLogicLevel a_new_level )
{
  for( int i=0; i < int(mp_gates2drive.size()); ++i ){
    mp_gates2drive[i]->drive_input( m_gate_input_indices[i], a_new_level );
  }
}