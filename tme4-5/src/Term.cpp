 #include <iostream>
 #include <string>
#include "Term.h"
#include "Cell.h"
#include "Point.h"
 namespace Netlist{

  
   Term::Term ( Cell*  cell  , const std::string& name, Direction direction ){
     this->name_ = name;
     this->direction_ = direction;
     this->owner_ = (void*) cell; 


   }
   Term::Term ( Instance*, const Term* modelTerm ){}
   Term::~Term (){}
   std::string  Term::toString    ( Type x){std::string s("ss");return s;}
   std::string  Term::toString    ( Direction x){std::string s("s");return s;}
   Term::Direction    Term::toDirection ( std::string ){Term::Direction s; return s;}
  
bool Term::isInternal () const {}
bool Term::isExternal () const {}
const std :: string & Term::getName () const {}
Node * Term::getNode (){}
Net *  Term::getNet () const {}
Cell * Term::getCell () const {}
Cell * Term::getOwnerCell () const {}
Instance * Term::getInstance () const {}
Term::Direction Term::getDirection () const {}

Point Term::getPosition () const {}
Term::Type Term::getType () const {}
void Term::setNet ( Net * ){}
void Term::setNet ( const std :: string & ){}
void Term::setPosition ( const Point & ){}
void Term::setPosition ( int x , int y ){}
void Term::setDirection ( Direction ){}
        

 }
 