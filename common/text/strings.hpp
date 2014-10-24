#ifndef STRINGS
#define STRINGS
#include <vector>
#include <memory>
#include <iostream>
#include<map>

#include <common/handle.hpp>

template <class T>
class Strings
: virtual public virtual_handle
{
public:
    Strings():has_space(false),counter(0){
    };
    void add(std::string & string){
        this->current_string = this->shared_from_this();
        this->current_part = string;
        this->addString();
        /*
        example:
        string:technology
        tree:
        strings >
            ...
            t
               ...
               e
                    st
                    chnology
                    sting
               ...
            steps:
                iterate strings
                get to t(first letter of word)
                if it has space
                    make String str with echnology
                    push the str to String t
                if it does not have space
                    if it has String e
                        if String e has space
                            create String str chnology
                            push str to String e
                        if String e does not have space
                            get first letter of remaining(echnology -> e)
                            see if String c is present in String e
                            if it is present in e
                                if it has space

                                if it does not have space
                            if it is not present in e

                    if it does not have String e
                        Create String e
                        create String str chnology
            ...
        */

    };
    bool has_space;
    std::map<std::string, std::shared_ptr<Strings> > strings;
    std::string current_part;
    std::shared_ptr<Strings> current_string;
    int counter;
    void addString(){
        if(this->current_part.size()){

            std::string letter = this->current_part.substr(0,1);

            if(this->current_string->has_space){
                if ( this->current_string->strings.find(letter) == this->current_string->strings.end() ) {
                    if(this->current_string->counter > 2){
                        this->has_space=false;
                    }
                    this->current_string->counter++;
                    std::shared_ptr<Strings> str = std::make_shared<Strings>();
                    this->current_string->strings.insert(std::pair<std::string,std::shared_ptr<Strings> >(letter,str));
                    this->current_string = str;

                } else {
                    this->current_string = this->strings[letter];
                }
            } else {

                this->current_part = this->current_part.substr(1,this->current_part.size());
                if ( this->current_string->strings.find(letter) == this->current_string->strings.end() ) {
                    std::shared_ptr<Strings> str = std::make_shared<Strings>();
                    this->current_string->strings.insert(std::pair<std::string,std::shared_ptr<Strings> >(letter,str));
                    if(this->current_string->counter > 2){
                        this->has_space=false;
                    }
                    this->current_string->counter++;
                }
                this->current_string = this->current_string->strings[letter];
                this->addString();
            }
        }
    }
    std::shared_ptr<T> shared_from_this();
};

template <class T>
std::shared_ptr<T> Strings<T>::shared_from_this() {
    return std::dynamic_pointer_cast<T>(virtual_handle::shared_from_this());
}

class StringsExpanded
: public Strings<StringsExpanded> {
public:

    StringsExpanded() {};
};

#endif
