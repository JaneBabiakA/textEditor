#include <iostream>

#ifndef DOCUMENT_H
#define DOCUMENT_H

class Document{
public:
    Document(std::string name){
        std::cout << "Document Created";
    }
};

#endif // DOCUMENT_H
