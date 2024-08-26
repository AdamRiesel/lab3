#ifndef _SIMULATOR_H
#define _SIMULATOR_H

class CCircuit;
class CPerson;

class CSimulator{
    public:
        CSimulator();
        ~CSimulator();
        void read_circuit_file();


    private:
        CCircuit* m_created_circuit;
        CPerson* m_test_subject;


};


#endif