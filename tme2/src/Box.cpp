#include "Box.h"
using namespace tme2;
int Box::counter = 0;

Box::Box(){
    this->name = "Unknown";
    this->x1_ = 0;
    this->y1_ = 0;
    this->x2_ = 0;
    this->y2_ = 0;
    ++counter;
std::cout << "Debug: Box::Box() : "; this->print(std::cout);

}

Box::Box(const std::string name, long x1, long y1, long x2, long y2){
    this->name = name;
    this->x1_ = x1;
    this->y1_ = y1;
    this->x2_ = x2;
    this->y2_ = y2;
    ++counter;

std::cout << "Debug: Box::Box(const std::string ...) : "; this->print(std::cout);

}

Box::Box(const Box & box){
    this->name = box.name + "_c";
    this->x1_ = box.x1_;
    this->y1_ = box.y1_;
    this->x2_ = box.x2_;
    this->y2_ = box.y2_;
    ++counter;


std::cout << "Debug: Box::Box(const Box & box) : "; this->print(std::cout);

}

inline Box::~Box (){
    std::cout << "Debug: Box::~Box() : "; this->print(std::cout);
    --counter;
}

void Box::print(std::ostream& o){
    o << "<\"" << this->name << "\" "<< this->x1_ << " " << this->y1_  << " " << this->x2_ << " " << this->y2_  << ">\n";
}
auto Box::intersect(const Box& box)-> bool{
    Box intersect;

    intersect.name = "intersect";
    intersect.x1_ = std::max(this->x1_, box.x1_);
    intersect.y1_ = std::min(this->y1_, box.y1_);
    intersect.x2_ = std::max(this->x2_, box.x2_);
    intersect.y2_ = std::min(this->y2_, box.y2_);
    
    if(intersect.isEmpty()) return false;
    return true;

    // TODO : Add a shorter version
}

auto Box::makeEmpty() -> void {
    this->x1_ = 0;
    this->y1_ = 0;
    this->x2_ = 0;
    this->y2_ = 0;
}

auto Box::inflate(long dxy)->void{
    this->x1_ += dxy;
    this->y1_ += dxy;
    this->x2_ += dxy;
    this->y2_ += dxy;
}

auto Box::inflate(long dx1, long dy1, long dx2, long dy2) -> void{
    this->x1_ += dx1;
    this->y1_ += dy1;
    this->x2_ += dx2;
    this->y2_ += dy2;
}

auto Box::getIntersection(const Box& box)->Box {
    Box intersect;

    intersect.name = "intersect";
    intersect.x1_ = std::max(this->x1_, box.x1_);
    intersect.y1_ = std::min(this->y1_, box.y1_);
    intersect.x2_ = std::max(this->x2_, box.x2_);
    intersect.y2_ = std::min(this->y2_, box.y2_);
    
    if(intersect.isEmpty()) intersect.name = "Empty";

    return intersect;
}

std::ostream& operator<<(std::ostream& os,const Box& box ){
    os << "<\"" << box.getName() << "\" "<< box.getX1() << " " << box.getY1()  << " " << box.getX2() << " " << box.getY2() << ">\n";
    return os;
}
tme2::Box operator&&(tme2::Box& b1, tme2::Box& b2){
    tme2::Box intersect;
    intersect = b1.getIntersection(b2);
    return intersect;
}
