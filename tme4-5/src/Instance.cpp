#include "Instance.h"
#include <iostream>
#include <string>
#include "Term.h"
#include "Point.h"

namespace Netlist{
Instance::Instance      ( Cell* owner, Cell* model, const std::string& ){}
Instance::~Instance      (){}
// Accesseur{}
const std::string&        Instance::getName       () const{}
Cell*                     Instance::getMasterCell () const{}
Cell*                     Instance::getCell       () const{}
const std::vector<Term*>& Instance::getTerms      () const{}
Term*                     Instance::getTerm       ( const std::string& )const{}
Point                     Instance::getPosition   () const{}
// Modificateur{}
bool  Instance::connect       ( const std::string& name, Net* ){}
void  Instance::add           ( Term* ){}
void  Instance::remove        ( Term* ){}
void  Instance::setPosition   ( const Point& ){}
void  Instance::setPosition   ( int x, int y ){}
}