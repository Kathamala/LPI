#include <string>

class clientePJ{
    private:
    std::string RazaoSocial;
    std::string CNPJ;

    public:
    std::string getRazaoSocial();
    void setRazaoSocial(std::string r);
    std::string getCNPJ();
    void setCNPJ(std::string c);
};