#ifndef _PERSON_H
#define _PERSON_H

#include "types.h"

#include <vector>

class CCircuit;
class CSoftCircuit;

//---CPerson Interface----------------------------------------
class CPerson{
    public:
        CPerson();
        ~CPerson();

        /**
         * @brief tests a circuit at a particular index with the specified 
         * input values
         * 
         * @param a_circui_idx is the target circuit index in a person's array
         * @param In[0:4] is the input bits to be compared. If 2 given, then
         * they are compared as A and B. If 4 given then In0 and In1 are A; 
         * In2 and In3 are B
         */
        void test_circuit(int a_circuit_idx);

        /**
         * @brief adds a circuit to the array of circuits owned by a Person
         * 
         * @param a_new_circuit pointer to the circuit to be tested
         */
        void add_circuit(CSoftCircuit* a_new_circuit);

    private:
        // //dynamic array of circuits owned by person
        std::vector<CSoftCircuit*> m_circuits_owned;        
};

#endif