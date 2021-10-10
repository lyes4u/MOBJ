#include "Vect.h"
#include "GPL_2_test.h"
#include "timer.h"

// #define TEST1 
// #define TEST2
// #define TEST3
// #define TEST4
#define TEST5
// #define TEST6

void display(std::vector<std::string > data){
     // print all elements 
        for(auto v: data){
            std::cout << v << " ";
        } std::cout<< std::endl; // new line for beauty 
}
int main ( int argc, char* argv[] )
{

    // Prologue : TIMER
    Timer timer;

   
    
#ifdef TEST1
    // Test BackInsert Vector
    using namespace vector_bench;

    // Vecteur de test 
    std::vector <std::string> data;

    int i = 0;
    timer.start(); // START CHRONO
    while(GPL_2_text[i]!=NULL)
        {
            backInsert    (data,GPL_2_text[i]);
            ++i;
        }
    timer.stop(); // START CHRONO
    std::cout << timer;
#endif

#ifdef TEST2
 // Test Frontnsert Vector
    using namespace vector_bench;

    int i = 0;
    timer.start(); // START CHRONO
    while(GPL_2_text[i]!=NULL)
        {
            frontInsert    (data,GPL_2_text[i]);
            ++i;
        }
    timer.stop(); // START CHRONO
    display(data);
    std::cout << timer << std::endl;
#endif

   
#ifdef TEST3
    // Test BackInsert list
    using namespace list_bench;

    std::list<std::string> data;
    int i = 0;
    timer.start(); // START CHRONO
    while(GPL_2_text[i]!=NULL)
        {
            backInsert    (data,GPL_2_text[i]);
            ++i;
        }
    timer.stop(); // START CHRONO
    std::cout << timer;
#endif
#ifdef TEST4
    // Test frontInsert list
    using namespace list_bench;

    std::list<std::string> data;
    int i = 0;
    timer.start(); // START CHRONO
    while(GPL_2_text[i]!=NULL)
        {
            frontInsert    (data,GPL_2_text[i]);
            ++i;
        }
    timer.stop(); // START CHRONO
    std::cout << timer;
#endif

#ifdef TEST5
    // Test frontInsert list
    using namespace map_bench;

    std::map<std::string, int> data;
    timer.start(); // START CHRONO
        map_func    ();
    timer.stop(); // START CHRONO
    std::cout << timer;
#endif
#ifdef TEST6
    // Test frontInsert list
    using namespace map_bench;

    timer.start(); // START CHRONO
        map_func    ();
    timer.stop(); // START CHRONO
    std::cout << timer;
#endif
    
  return 0;
}