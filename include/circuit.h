#ifndef _CIRCUIT_H
#define _CIRCUIT_H
#include <vector>

#include "types.h"
class CGate;
class CWire;

//---CCircuit Interface----------------------------------------
class CCircuit{
    public:

        /**
         * @brief Circuit constructor assigns the number of gates, wires,
         * inputs, and outputs which a circuit will have
         * 
         * @param a_num_gates the number of gates the circuit has
         * @param a_num_wires the number of wires the circuit has
         * @param a_num_ins the number of inputs to the circuit
         * @param a_num_outs the number of the number of outputs from
         * the circuit
         */
        CCircuit(int a_num_gates, int a_num_wires, int a_num_ins,
            int a_num_outs);
        ~CCircuit();


        void add_component();

        /**
         * @brief pure virtual method for arranging gates and wires to build
         * a desired circuit
         */
        virtual void build_circuit() = 0;

        /**
         * @brief initialise all gates and wires in a circuit
         */
        void collect_components();

        /**
         * @brief Dynamically assigns the length of each array: 
         * m_gates_in_circuit, m_wires_in_circuit, m_ins, m_circuit_outputs
         */
        void expand_component_lists();

        /**
         * @brief retrieves m_circuit_outputs into an array
         * 
         * @param outputs an empty array of size 3 which can store the outputs
         * of the circuit
         */
        void get_outputs(eLogicLevel outputs[3]);
        
        /**
         * @brief sets the inputs of a circuit 
         * 
         * @param a_ins an array of input values
         */
        virtual void set_inputs(eLogicLevel* a_ins);

    protected:
        

        int m_num_NAND;    
        int m_num_AND;   
        int m_num_OR;  
        int m_num_NOR; 
        int m_num_XOR;
        int m_num_NOT;


        int m_num_gates;
        int m_num_wires;
        int m_num_ins;
        int m_num_outs;


        // std::vector<CGate*> m_gates_in_circuit;
        // std::vector<CWire*> m_wires_in_circuit;
        std::vector<CGate*> m_gates_in_circuit;
        std::vector<CWire*> m_wires_in_circuit;
        std::vector<eLogicLevel> m_circuit_outputs;
        std::vector<eLogicLevel> m_ins;

};

//---C1BitComp Interface----------------------------------------
class C1BitComp: public CCircuit{
    public:
        C1BitComp();
        ~C1BitComp();

        /**
         * @brief builds a 1 bit comparator circuit
         */
        void build_circuit() override;

    protected:
};

//---C2BitComp Interface----------------------------------------
class C2BitComp: public CCircuit{
    public:
        C2BitComp(CCircuit* a_1bit_0, CCircuit* a_1bit_1);
        ~C2BitComp();

        /**
         * @brief sets the inputs of a circuit 
         * 
         * @param a_ins an array of input values
         */
        void set_inputs(eLogicLevel* a_Ins) override;

        /**
         * @brief builds the 2 bit comparator circuit
         */
        void build_circuit() override;

    protected:
        CCircuit* m_sub_circuits[2];
};

#endif