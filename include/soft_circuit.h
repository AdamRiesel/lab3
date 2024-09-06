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

        void build_circuit();

        void set_inputs(std::vector<std::string> names, std::vector<eLogicLevel> values);
        void get_outputs(std::vector<std::string> names, std::vector<eLogicLevel> &outs);

    private:
        std::unordered_map<std::string, CGate*> m_gates_in_circuit;
        std::unordered_map<std::string, CWire*> m_wires_in_circuit;
};

#endif