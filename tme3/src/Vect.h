#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <map>
#include "GPL_2_test.h"
namespace vector_bench{
    void backInsert(std::vector<std::string >& data, std::string n_element){
        // Ajout du dernier element
        data.push_back(n_element);
        // Affiche le n d'elements
        // std::cout << "\nNombre d'elements : " << data.size() << "element(s)\n";
        // Sort elements
        std::sort(data.begin(), data.begin()+data.size()-1 );
        // print all elements 
        // for(auto v: data){
        //     std::cout << v << " ";
        // } std::cout<< std::endl; // new line for beauty 
    }

    auto frontInsert(std::vector<std::string >& data, std::string n_element) -> void{
      data.push_back(n_element);

    auto it = data.begin();
    std::string s = *it;

    for(;it != data.end()-1; it++){
        *it = s;
        s = *(it+1); 
    }
        // std::cout << "\nNombre d'elements : " << data.size() << "element(s)\n";
        std::sort(data.begin(), data.begin()+data.size()-1 );
        
    }
}
namespace list_bench{
    void backInsert(std::list<std::string >& data, std::string n_element){
        // Ajout du dernier element
        data.push_back(n_element);
        // Affiche le n d'elements
        // std::cout << "\nNombre d'elements : " << data.size() << "element(s)\n";
        // Sort elements
        data.sort();
    }
    auto frontInsert(std::list<std::string >& data, std::string n_element) -> void{
        data.push_front(n_element);
        data.sort();

    }

}

class CompareStrings{
    public:
        bool operator ()(const std::string& a,const std::string& b ){
        // if(a.back() < b.back())
        // if(*a.rbegin() <= *b.rbegin())
        if(a.front() < b.front())
            return true;
        else
            return false;
        }
    };

namespace map_bench{
    
    void map_func(){
        std::map<std::string, int, CompareStrings> MAP;

        int i = 0;
        while(GPL_2_text[i] != NULL){
            MAP[GPL_2_text[i]] +=  1; 
            i++;
        }
        for(auto v: MAP)
        {
            std::cout << "\"" << v.first << "\" -> " << v.second << std::endl; 
        }
        long wordCount = 0;
        for(auto x: MAP)
        {
            wordCount += x.second;
            
        }
        std::cout << "MAP contains : " << wordCount << " words" << std::endl;
    }   

}


