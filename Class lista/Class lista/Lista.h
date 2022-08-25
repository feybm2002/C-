//
//  Header.h
//  Class lista
//
//  Created by Fer on 03/02/22.
//  Copyright © 2022 Fey . All rights reserved.
//

#ifndef Header_h
#define Header_h

class list{
private:
    int data[500];
    int last;
    
public:
    void initialize();
    
    bool isEmpty() const;
    bool isFull() const;
    
    void  insertData(const int&, const int&);
    void deleteData(const int&);
    
    int getfirstPos() const;
    int getLastPos() const;
    int getPrevPos(const int&);
    int getNextPos(const int&);
    
    int findData(const int&);
    
    int retrieveData(const int&);
    
    void sortData();
    
    void printData();
    
    void deleteAll();
    
};

#endif /* Header_h */
