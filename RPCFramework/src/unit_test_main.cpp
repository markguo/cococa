/**
 *    \file   unit_test_main.cpp
 *    \brief  Unit test main entry.
 *    \date   04/28/11
 *    \author guoshiwei (guoshiwei@gmail.com)
 */

#include <boost/version.hpp>

#if BOOST_VERSION <= 103301
#   define BOOST_AUTO_TEST_MAIN
#   include <boost/test/auto_unit_test.hpp>
#else
#   define BOOST_TEST_DYN_LINK
#   define BOOST_TEST_MAIN
#   include <boost/test/unit_test.hpp>
#endif

#if BOOST_VERSION <= 103301
#   include <boost/test/auto_unit_test.hpp>
#else
#   include <boost/test/unit_test.hpp>
#endif

#include <map>
#include <string>

using namespace std;
using namespace sogourank;

BOOST_AUTO_TEST_CASE(dummy)
{
}
