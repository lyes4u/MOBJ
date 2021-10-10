#include "Net.h"

namespace Netlist{
    
using namespace std;
// CTOR & DTOR 
Net::Net     ( Cell*, const std::string&, Term::Type ){}
Net::~Net     (){}
// Accesseurs
        Cell*                     Net::getCell       () const {}
        const std::string&        Net::getName       ()const {}
        unsigned int              Net::getId         ()const {}
        Term::Type                Net::getType       ()const {}
        const std::vector<Node*>& Net::getNodes      ()const {}
        size_t                    Net::getFreeNodeId ()const {}
// Modificateurs
        void  Net::add    ( Node* ){}
        bool  Net::remove ( Node* ){}
}
