#pragma once
#include <string>
#include <iostream>
namespace tme2{
class Box{
    private:
        std::string name;
        long x1_;
        long y1_;
        long x2_;
        long y2_;
        // Counting instances
        static int counter;
    public:
        
        // CTOR
        Box();
        Box(const std::string name, long x1, long y1, long x2, long y2);
        Box(const Box & box);

        // DTOR
        inline ~Box();

        
        // Accesseurs
        inline std::string getName() const {return this->name;}
        inline long getX1() const {return this->x1_;}
        inline long getY1() const {return this->y1_;}
        inline long getX2() const {return this->x2_;}
        inline long getY2() const {return this->y2_;}
        inline long getWidth() const { return (long) (this->x2_ - this->x1_);}
        inline long getHeight() const { return (long) (this->y2_ - this->y1_);}
        inline int getAllocated() const { return counter;}
        inline bool isEmpty() const {return ((this->x1_ > this->x2_)||(this->y1_ > this->y2_)? true : false);}
        bool intersect(const Box&);
        void print(std::ostream& o);

        // Modificateurs
        void makeEmpty();
        void inflate(long dxy);
        void inflate(long dx, long dy);
        void inflate(long dx1, long dy1, long dx2, long dy2);
        Box getIntersection(const Box&);

        
};

}
std::ostream& operator<<(std::ostream& os,const tme2::Box& box );
tme2::Box operator&&(tme2::Box& b1, tme2::Box&b2);
// std::ostream operator<<(std::ostream os,const Box& box );



