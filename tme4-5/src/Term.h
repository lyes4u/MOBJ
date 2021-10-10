#pragma once
#include <string>
// #include "Node.h"

namespace Netlist
{

class Cell;
class Instance;
class Net;
class Node;
class Point;

class Term
{
public:
        enum  Type      { Internal=1, External=2 };
        enum  Direction { In=1, Out=2, Inout=3, Tristate=4, Transcv=5, Unknown=6 };
private:
        void*         owner_;
        std::string   name_;
        Direction     direction_;
        Type          type_;
        Net*          net_;
        Node*          node_;

       
public:

   
   // CTOR & DTOR
        Term ( Cell*    , const std::string& name, Direction );
        Term ( Instance*, const Term* modelTerm );
        ~Term ();

        // Accesseurs
        bool isInternal () const ;
        bool isExternal () const ;
        const std :: string & getName () const ;
        Node * getNode ();
        Net * getNet () const ;
        Cell * getCell () const ;
        Cell * getOwnerCell () const ;
        Instance * getInstance () const ;
        Direction getDirection () const ;
        Point getPosition () const ;
        Type getType () const ;
        // Modificateurs
        void setNet ( Net * );
        void setNet ( const std :: string & );
        void setPosition ( const Point & );
        void setPosition ( int x , int y );
        void setDirection ( Direction );

    static std::string  toString    ( Type );
    static std::string  toString    ( Direction );
    static Direction    toDirection ( std::string );
}; // Class Term

} // namespace Netslist
