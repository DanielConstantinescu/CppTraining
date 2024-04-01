#define BOOST_TEST_MODULE Power_Database
#include <boost/test/included/unit_test.hpp>
#include "SafeSingleton.h"

BOOST_AUTO_TEST_SUITE( test_suite )

/* Test 1 will check the power for all existing cars */
BOOST_AUTO_TEST_CASE( test_case_1 )
{
    SingletonDatabase &db = SingletonDatabase::get();
    BOOST_CHECK_EQUAL(db.get_horse_power("Lotus Evija"), 2012);
    BOOST_TEST_MESSAGE("TEST CASE 1: Valid power for Lotus Evija");

    BOOST_CHECK_EQUAL(db.get_horse_power("Bugatti Chiron"), 1578);
    BOOST_TEST_MESSAGE("TEST CASE 1: Valid power for Bugatti Chiron");

    BOOST_CHECK_EQUAL(db.get_horse_power("Aston Martin Valkyrie"), 1160);
    BOOST_TEST_MESSAGE("TEST CASE 1: Valid power for Aston Martin Valkyrie");

    BOOST_CHECK_EQUAL(db.get_horse_power("Dodge Challenger"), 1025);
    BOOST_TEST_MESSAGE("TEST CASE 1: Valid power for Dodge Challenger");

    BOOST_CHECK_EQUAL(db.get_horse_power("McLaren Sabre"), 824);
    BOOST_TEST_MESSAGE("TEST CASE 1: Valid power for McLaren Sabre");

    BOOST_CHECK_EQUAL(db.get_horse_power("Ferrari 296 GTB"), 819);
    BOOST_TEST_MESSAGE("TEST CASE 1: Valid power for Ferrari 296 GTB");

    BOOST_CHECK_EQUAL(db.get_horse_power("Lamborghini Sian"), 807);
    BOOST_TEST_MESSAGE("TEST CASE 1: Valid power for Lamborghini Sian");

    BOOST_TEST_MESSAGE("TEST CASE 1: All checks are vaid");
}

/* Test 2 will check the power returned for a non existent car is 0 */
BOOST_AUTO_TEST_CASE( test_case_2 )
{
    SingletonDatabase &db = SingletonDatabase::get();
    BOOST_CHECK_EQUAL(db.get_horse_power("Tesla"), 0);
    BOOST_TEST_MESSAGE("TEST CASE 2: Valid power 0 for non existing car Tesla");
}

/* Test 3 will check if an incomplete name will pass as non-existent */
BOOST_AUTO_TEST_CASE( test_case_3 )
{
    SingletonDatabase &db = SingletonDatabase::get();
    BOOST_CHECK_EQUAL(db.get_horse_power("Aston Martin"), 0);
    BOOST_TEST_MESSAGE("TEST CASE 3: Incomplete name pass as non-existent");
}

/* Test 4 will check the singleton feature. All objects must point to the same instance */
BOOST_AUTO_TEST_CASE( test_case_4 )
{
    SingletonDatabase &db_1 = SingletonDatabase::get();
    SingletonDatabase &db_2 = SingletonDatabase::get();

    BOOST_CHECK_EQUAL(&db_1, &db_2);
    BOOST_TEST_MESSAGE("TEST CASE 4: All objects point to the same instance");
}

BOOST_AUTO_TEST_SUITE_END()