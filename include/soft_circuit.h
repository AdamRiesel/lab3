#ifndef _SOFT_CIRCUIT_H
#define _SOFT_CIRCUIT_H

#include <string>
#include <unordered_map>
#include <vector>

class CGate;
class CWire;

class CSoftCircuit{
    public:
        CSoftCircuit();
        ~CSoftCircuit();

        /**
         * @brief builds the circuit from the standard input. The user can
         * create any circuit to their hearts desire
         */
        void build_circuit();

        /**
         * @brief defines the input values to the circuit
         * 
         * @param names the keys for each input wire which should be set
         * @param values the value to be assigned to each input wire
         * 
         * @note value[0] is assigned to name[0] and so on
         */
        void set_inputs(std::vector<std::string> names, 
                        std::vector<eLogicLevel> values);

        /**
        * @brief gives the output values of each specified output wire
        * 
        * @param names the keys for each output wire which should be read
        * @param outs the value of each output wire specified. Should be
        * parsed empty and with 0 size
        */
        void get_outputs(std::vector<std::string> names, std::vector<eLogicLevel> &outs);

    private:
        //hash map of all gates in the circuit
        std::unordered_map<std::string, CGate*> m_gates_in_circuit;
        //hash map of all wires in the circuit
        std::unordered_map<std::string, CWire*> m_wires_in_circuit;
};

#endif