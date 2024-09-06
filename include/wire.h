#ifndef _WIRE_H
#define _WIRE_H

#include <vector>
#include "types.h"

class CGate;


//---CPerson Interface----------------------------------------
class CWire
{
  public:
    /**
     * @brief initialises a new wire, setting its output connections to 0
     * 
     */
    // void Init();
    CWire();
    ~CWire();
    
  


    /**
     * @brief adds to the list of outputs that this wire drives
     * 
     * @param ap_gate_to_drive a pointer to the NAND gate whose input 
     * should be driven
     * @param a_gate_input2drive the index specifying which of the 
     * gate's inputs should be driven
     */
    void add_output_connection(CGate* ap_gate_to_drive, int a_gate_input2drive);
    

    /**
     * @brief drives the wire's value, and sets each of its connected 
     * outputs to the corresponding level
     * 
     * @param a_new_level the new logic level which the wire should set
     * it's  output to
     */
    void drive_level(eLogicLevel a_new_level);

    eLogicLevel get_drive_value();


  private:
    eLogicLevel m_drive_value;
    std::vector<CGate*> mp_gates2drive;     // list of connected gates
    std::vector<int> m_gate_input_indices; // list of input to drive in each gate

};


#endif