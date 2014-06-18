/*
 * File:   newtestclass1.hpp
 * Author: alexander
 *
 * Created on Apr 27, 2014, 8:46:20 PM
 */

#ifndef NEWTESTCLASS1_HPP
#define	NEWTESTCLASS1_HPP

#include <cppunit/extensions/HelperMacros.h>

class newtestclass1 : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass1);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass1();
    virtual ~newtestclass1();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
};

#endif	/* NEWTESTCLASS1_HPP */

