#ifndef GERENTE
#define GERENTE

#include "funcionario.hpp"

class gerente : public funcionario{
    public:
    double mediaSalarial;
    std::string relatorioDiario;
};

#endif