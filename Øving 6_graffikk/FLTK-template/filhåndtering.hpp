//
//  filhåndtering.hpp
//  std_lib_facilities_mac
//
//  Created by Silje Anfindsen on 15/02/2019.
//  Copyright © 2019 Lars Musaus. All rights reserved.
//

#ifndef filha_ndtering_hpp
#define filha_ndtering_hpp
#import "std_lib_facilities.h"

#include <stdio.h>


void countchar(string filnavn);

//definerer en klasse CourseCatalog

class CourseCatalog {
private:
    map <string, string> CourseMap;
    
    
public:
    friend ostream& operator<<(ostream& os, const CourseCatalog& c);
    void addCourse(string emnekode, string emnenavn);
    void removeCourse(string emnekode);
    string getCourse(string emnekode);
    void uploadFile(string filnavn);
    void downloadFile(string filnavn);
};



#endif /* filha_ndtering_hpp */
