#pragma once

#include <iostream>
#include <vector>
#include "Point.h"
#include "Term.h"
namespace Netlist{

class Cell;

    class Instance{
        private:
            Cell*               owner_;
            Cell*               masterCell_;
            std::string         name_;
            std::vector<Term*>  terms_;
            Point               position_;
        public:
        // CTOR & DTOR
        Instance      ( Cell* owner, Cell* model, const std::string& );
        ~Instance      ();
        // Accesseurs
            const std::string&        getName       () const;
            Cell*                     getMasterCell () const;
            Cell*                     getCell       () const;
            const std::vector<Term*>& getTerms      () const;
            Term*                     getTerm       ( const std::string& ) const;
            Point                     getPosition   () const;
        // Modificateurs
            bool  connect       ( const std::string& name, Net* );
            void  add           ( Term* );
            void  remove        ( Term* );
            void  setPosition   ( const Point& );
            void  setPosition   ( int x, int y );
            
    };
}