#pragma once
#include <string>
#include "Term.h"
#include <vector>
namespace Netlist
{
    class Cell;
    class Net
    {
    private:
        Cell*               owner_;
        std::string         name_;
        unsigned int        id_;
        Term::Type          type_;
        std::vector<Node*>  nodes_;
    public:
        Net     ( Cell*, const std::string&, Term::Type );
        ~Net     ();

    // Accesseurs
        Cell*                     getCell       () const;
        const std::string&        getName       () const;
        unsigned int              getId         () const;
        Term::Type                getType       () const;
        const std::vector<Node*>& getNodes      () const;
        size_t                    getFreeNodeId () const;
    // Modificateurs
        void  add    ( Node* );
        bool  remove ( Node* );
    };
    
    
    
} // namespace Netlist
