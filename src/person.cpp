#include "../include/person.h"
#include "soft_circuit.h"

#include <iostream>
#include <unordered_map>
#include <string>
//---CPerson Implementation------------------------------------------
CPerson::CPerson(){
}

//--
CPerson::~CPerson(){

}

//--
void CPerson::add_circuit(CSoftCircuit* a_new_circuit){
    //TODO
    /**
     * choose what type of circuit: 1 bit, 2 bit, etc.
     */
    m_circuits_owned.push_back(a_new_circuit);
}

//--
void CPerson::test_circuit(int a_circuit_idx){

    
    std::vector<std::string> in_names;
    std::vector<eLogicLevel> in_vals;

    std::vector<std::string> out_names;
    std::vector<eLogicLevel> out_vals;

    std::cout << "Enter the names of the input wires (seperate with spaces, "
                <<"indicate finished with #): " << std::endl;

    std::string request = "";


    while (request.compare("#") != 0){
        std::cin >> request;

        if (request.compare("#") == 0){
            break;
        }

        in_names.push_back(request);
    }

    std::cout << "great, now enter the values for each of those wires" << std::endl;
    request = "";
    while (request.compare("#") != 0){
        std::cin >> request;

        if (request.compare("#") == 0){
            break;
        }

        eLogicLevel val;


        if (request.compare("-1") == 0){
            val = LOGIC_UNDEFINED;
        }
        else if (request.compare("0") == 0){
            val = LOGIC_LOW;
        }
        else if (request.compare("1") == 0){
            val = LOGIC_HIGH;
        }
        else {
            std::cout<<"invalid value given, expect unexpected output"<<std::endl;
        }

        in_vals.push_back(val);
    }

    std::cout << "great, now enter the names of the output wires" << std::endl;
    request = "";
    while (request.compare("#") != 0){
        std::cin >> request;

        if (request.compare("#") == 0){
            break;
        }

        out_names.push_back(request);
    }


    m_circuits_owned[a_circuit_idx]->set_inputs(in_names, in_vals);
    m_circuits_owned[a_circuit_idx]->get_outputs(out_names, out_vals);

    std::cout << "IN: ";
    for (int i = 0; i < int(in_vals.size()); i++){
        std::cout << in_vals[i];
    }
    std::cout << "--OUT: ";
    for (int i = 0; i < int(out_vals.size()); i++){
        std::cout << out_vals[i];
    }
    std::cout << std::endl;

    request = "";
    while (true){
        /*
        //Use this line if building directly from terminal
        std::cout <<"test more vals? [y/n]"<<std::endl;
        */
        std::cin>>request;
        if (request.compare("n") == 0){
            break;
        }
        else if (request.compare("y") == 0){
            out_vals.resize(0);
            /*
            //Use this line if building directly from terminal
            std::cout<<"Enter new vals followed by #"<<std::endl;
            */
            for (int i = 0; i < int(in_vals.size()); i++){
                std::cin >> request;

                if (request.compare("#") == 0){
                    break;
                }

                eLogicLevel val;


                if (request.compare("-1") == 0){
                    val = LOGIC_UNDEFINED;
                }
                else if (request.compare("0") == 0){
                    val = LOGIC_LOW;
                }
                else if (request.compare("1") == 0){
                    val = LOGIC_HIGH;
                }
                else {
                    std::cout<<"invalid value given, expect unexpected output"<<std::endl;
                }

                in_vals[i] = val;
            }
        m_circuits_owned[a_circuit_idx]->set_inputs(in_names, in_vals);
        m_circuits_owned[a_circuit_idx]->get_outputs(out_names, out_vals);

        std::cout << "IN: ";
        for (int i = 0; i < int(in_vals.size()); i++){
            std::cout << in_vals[i];
        }
        std::cout << "--OUT: ";
        for (int i = 0; i < int(out_vals.size()); i++){
            std::cout << out_vals[i];
        }
        std::cout << std::endl;

        }
        else {
            continue;
        }
    }

}

