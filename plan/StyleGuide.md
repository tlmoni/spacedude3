ELEC-A7151 - Object oriented programming with C++

Style guide for software project


1. Naming conventions

    Variables                       some_variable
    Constants                       SOME_CONSTANT
    Class members                   member_
    Function names                  SomeFunction
    Function parameters             some_parameter
    Class/struct/namespace names	SomeClass / SomeStruct / SomeNamespace

    Pointers                        typename* ptr

    File names                      some_header (.hpp)
                                    some_file (.cpp)

2. General style

    #pragma once

    #include <abc>
    #include <def>
    #include "my_header.hpp"

    using namespace ThatNamespace;

    /* Description of the namespace */
    namespace MyNamespace {
        /* Description of the class */
        class MyClass : public SomeClass {
        public:
            /* Description of the function */
            void SomeFunction(typename parameter) {
                int ans = 1 + 2;
            }

            /* Description of getter */
            std::string GetStr() { return str_; }

        private:
            std::string str_; // Description of the member if needed
        };
    }


(Header's) First line should be a headerguard
Includes should be in alphabetical order, local files should be included after the built in ones.
Using directives should be after the includes.
Includes should be declared outside of namespaces.
There should be 1 empty line between different structures (classes, functions, structs etc.)

Generally, headers should be interfaces and the implementation should be done in .cpp files (excl. getters)
