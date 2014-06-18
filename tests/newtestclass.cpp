/*
 * File:   newtestclass.cpp
 * Author: alexander
 *
 * Created on Apr 27, 2014, 8:41:30 PM
 */

#include "newtestclass.hpp"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {
}

newtestclass::~newtestclass() {
}

void newtestclass::setUp() {
}

void newtestclass::tearDown() {
}

void newtestclass::testMethod() {
    CPPUNIT_ASSERT(true);
}

void newtestclass::testFailedMethod() {
    CPPUNIT_ASSERT(false);
}

