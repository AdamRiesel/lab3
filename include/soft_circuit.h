#ifndef _SOFT_CIRCUIT_H
#define _SOFT_CIRCUIT_H

#include <string>
#include <unordered_map>

class CGate;

class CSoftCircuit{
    public:
        CSoftCircuit();
        ~CSoftCircuit();

        void build_circuit();

    private:
        std::unordered_map<std::string, CGate*> m_gates_in_circuit;
        std::unordered_map<std::string, CWire*> m_wires_in_circuit;
};

#endif