#include "gate.h"
#include "wire.h"
#include "types.h"
#include <iostream>


//-------CGate Implementation--------------
CGate::CGate(){
    m_inputs.resize(2);
    m_inputs[0] = m_inputs[1] = LOGIC_UNDEFINED;
    mp_output_connection = NULL;
    compute_output();
}

//--
CGate::~CGate(){
}

//--
void CGate::compute_output(){}

//--
void CGate::connect_output(CWire* ap_output_connection){
    
    mp_output_connection = ap_output_connection;
}

//--
void CGate::drive_input(int a_input_index, eLogicLevel a_new_level){
    //set the drive level for the specified gate input and compute new output
    m_inputs[a_input_index] = a_new_level;
    compute_output();
}

//--
eLogicLevel CGate::get_output_state(){
    return m_output_value;
}

//-------CNandGate Implementation--------------
void CNandGate::compute_output()
{
  //define the behaviour of a NAND gate
  eLogicLevel NewVal = LOGIC_HIGH;
  if( m_inputs[0] == LOGIC_UNDEFINED || m_inputs[1] == LOGIC_UNDEFINED )
    NewVal = LOGIC_UNDEFINED;
  else if( m_inputs[0] == LOGIC_HIGH && m_inputs[1] == LOGIC_HIGH )
    NewVal = LOGIC_LOW;
  m_output_value = NewVal;
  
  //set drive level for wire connected to output
  if( mp_output_connection != NULL ){
    mp_output_connection->drive_level( m_output_value );
  }
}

//-------CAndGate Implementation--------------
void CAndGate::compute_output(){

    //define the behaviour of a AND gate
    eLogicLevel new_val = LOGIC_LOW;

    if( m_inputs[0] == LOGIC_UNDEFINED || m_inputs[1] == LOGIC_UNDEFINED )
        new_val = LOGIC_UNDEFINED;
    else if (m_inputs[0] == LOGIC_HIGH && m_inputs[1] == LOGIC_HIGH){
        new_val = LOGIC_HIGH;
    }
    m_output_value = new_val;

    //set drive level for wire connected to output
    if( mp_output_connection != NULL ){
      mp_output_connection->drive_level( m_output_value );
  }
}

//-------COrGate Implementation--------------
void COrGate::compute_output(){

    //define the behaviour of a OR gate
    eLogicLevel new_val = LOGIC_HIGH;

    if( m_inputs[0] == LOGIC_UNDEFINED || m_inputs[1] == LOGIC_UNDEFINED )
        new_val = LOGIC_UNDEFINED;
    else if (m_inputs[0] == 0 && m_inputs[1] == 0){
        new_val = LOGIC_LOW;
    }
    m_output_value = new_val;

    //set drive level for wire connected to output
    if( mp_output_connection != NULL ){
      mp_output_connection->drive_level( m_output_value );
  }
}

//-------CNorGate Implementation--------------
void CNorGate::compute_output(){

    //define the behaviour of a NOR gate
    eLogicLevel new_val = LOGIC_LOW;

    if( m_inputs[0] == LOGIC_UNDEFINED || m_inputs[1] == LOGIC_UNDEFINED )
        new_val = LOGIC_UNDEFINED;
    else if (m_inputs[0] == LOGIC_LOW && m_inputs[1] == LOGIC_LOW){
        new_val = LOGIC_HIGH;
    }
    m_output_value = new_val;

    //set drive level for wire connected to output
    if( mp_output_connection != NULL ){
      mp_output_connection->drive_level( m_output_value );
  }
}

//-------XorGate Implementation--------------
void CXorGate::compute_output(){

    //define the behaviour of a XOR gate
    eLogicLevel new_val = LOGIC_HIGH;

    if( m_inputs[0] == LOGIC_UNDEFINED || m_inputs[1] == LOGIC_UNDEFINED )
        new_val = LOGIC_UNDEFINED;
    else if (m_inputs[0] == m_inputs[1]){
        new_val = LOGIC_LOW;
    }
    m_output_value = new_val;

    //set drive level for wire connected to output
    if( mp_output_connection != NULL ){
      mp_output_connection->drive_level( m_output_value );
  }
}

//-------CNotGate Implementation--------------
CNotGate::CNotGate(){
  m_inputs[0] = LOGIC_UNDEFINED;
  mp_output_connection = NULL;
  compute_output();
}

//--
void CNotGate::compute_output(){

  //define the behaviour of a NOT gate
  eLogicLevel new_val = LOGIC_UNDEFINED;
  if (m_inputs[0] == LOGIC_HIGH){
    new_val = LOGIC_LOW;
  }
  else if (m_inputs[0] == LOGIC_LOW){
    new_val = LOGIC_HIGH;
  }
  m_output_value = new_val;

  //set drive level for wire connected to output
  if( mp_output_connection != NULL ){
    mp_output_connection->drive_level( m_output_value );
  }
}

