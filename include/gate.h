#ifndef _GATE_H
#define _GATE_H

#include "types.h"

#include <vector>
#include <iostream>

class CWire;

//-----gate interface----------
class CGate{
  public:
    CGate();
    ~CGate();

    enum eLogicLevel      
    {
      LOGIC_UNDEFINED = -1,
      LOGIC_LOW,
      LOGIC_HIGH
    };
    /**
     * @brief sets which wire the output of the  gate should drive
     * 
     * @param ap_output_connection a pointer to the wire which needs to 
     * be driven
     */
    void connect_output(CWire* ap_output_connection);

    /**
     * @brief sets the logic level of one input of a  gate
     * 
     * @param a_input_index the index specifying which of the gate's 
     * inputs should be driven
     * @param a_new_level the logic level to se the input to
     */
    void drive_input(int a_input_index, eLogicLevel a_new_level);

    /**
     * @brief retrieves the output value of the gate
     * 
     * @returns m_output_value the output value of the NandGate
     */
    eLogicLevel get_output_state();

  protected:

    /**
     * @brief determines the logic output of the gate
     * 
     */
    virtual void compute_output();

    //dynamic array of input values
    std::vector<eLogicLevel> m_inputs;
    //output value of the gate
    eLogicLevel m_output_value;
    //pointer to the wire connected to the output
    CWire* mp_output_connection;

};

//---CAndGate Interface----------------------------------------
/**
 * CAndGate is used as a logic device which has 2 inputs and an output
 * It computes the output according to a standard AND Gate truth table
 */
class CAndGate: public CGate
{   
  protected:
    /**
     * @brief determines the logic output of the AND gate
     * 
     */
    void compute_output();
};

//---CNandGate Interface----------------------------------------
/**
 * CNandGate is used as a logic device which has 2 inputs and an output
 * It computes the output according to a standard NAND Gate truth table

 */
class CNandGate :public CGate
{   
  protected:
    /**
     * @brief determines the logic output of the NAND gate
     * 
     */
    void compute_output();
};

//---COrGate Interface----------------------------------------
/**
 * COrGate is used as a logic device which has 2 inputs and an output
 * It computes the output according to a standard OR Gate truth table

 */
class COrGate :public CGate
{   
  protected:
    /**
     * @brief determines the logic output of the OR gate
     * 
     */
    void compute_output();
};

//---CNorGate Interface----------------------------------------
/**
 * COrGate is used as a logic device which has 2 inputs and an output
 * It computes the output according to a standard NOR Gate truth table

 */
class CNorGate :public CGate
{   
  protected:
    /**
     * @brief determines the logic output of the NOR gate
     * 
     */
    void compute_output();
};

//---CXorGate Interface----------------------------------------
/**
 * COrGate is used as a logic device which has 2 inputs and an output
 * It computes the output according to a standard XOR Gate truth table

 */
class CXorGate :public CGate
{   
  protected:
    /**
     * @brief determines the logic output of the XOR gate
     * 
     */
    void compute_output();
};

//---CNotGate Interface----------------------------------------
/**
 * COrGate is used as a logic device which has 2 inputs and an output
 * It computes the output according to a standard NOT Gate truth table

 */
class CNotGate: public CGate{
  public:
    CNotGate();
    // ~CNot();
  protected:

    /**
     * @brief determines the logic output of the NOT gate
     * 
     */
    void compute_output();
};

#endif