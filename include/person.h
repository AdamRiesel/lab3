#ifndef _PERSON_H
#define _PERSON_H

#include "types.h"
#include <vector>
class CCircuit;

//---CPerson Interface----------------------------------------
class CPerson{
    public:
        CPerson();
        ~CPerson();

        /**
         * @brief tests all combinations for a given circuit. e.g. 00, 01, 
         * 10, 11 At this point, it is only configured to test inputs for a 
         * 2 bit comprator 
         *
         * @param a_idx this is the index of the desired circuit
         * found in the Person's array of circuits
         */
        void test_all_combs(int a_idx);

        /**
         * @brief tests a circuit at a particular index with the specified 
         * input values
         * 
         * @param a_circui_idx is the target circuit index in a person's array
         * @param In[0:4] is the input bits to be compared. If 2 given, then
         * they are compared as A and B. If 4 given then In0 and In1 are A; 
         * In2 and In3 are B
         */
        void test_circuit(int a_circuit_idx, eLogicLevel In0, eLogicLevel In1);
        void test_circuit(int a_circuit_idx, eLogicLevel In0, eLogicLevel In1, 
            eLogicLevel In2, eLogicLevel In3);

        /**
         * @brief adds a circuit to the array of circuits owned by a Person
         * 
         * @param a_new_circuit pointer to the circuit to be tested
         */
        void add_circuit(CCircuit* a_new_circuit);

    private:
        int m_num_circuits;
        int m_max_circuits = 4;
        std::vector<CCircuit*> m_circuits_owned;

        
};


#endif