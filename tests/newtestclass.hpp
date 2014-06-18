/*
 * File:   newtestclass.hpp
 * Author: alexander
 *
 * Created on Apr 27, 2014, 8:41:29 PM
 */

#ifndef NEWTESTCLASS_HPP
#define	NEWTESTCLASS_HPP

#include <cppunit/extensions/HelperMacros.h>

class newtestclass : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(newtestclass);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testFailedMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    newtestclass();
    virtual ~newtestclass();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testFailedMethod();
};

#endif	/* NEWTESTCLASS_HPP */

