/*
 * File:   newtestclass1.cpp
 * Author: alexander
 *
 * Created on Apr 27, 2014, 8:46:20 PM
 */

#include "newtestclass1.hpp"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass1);

newtestclass1::newtestclass1() {
}

newtestclass1::~newtestclass1() {
}

void newtestclass1::setUp() {
}

void newtestclass1::tearDown() {
}

void newtestclass1::testMethod() {
    CPPUNIT_ASSERT(true);
}

void newtestclass1::testFailedMethod() {
    CPPUNIT_ASSERT(false);
}

