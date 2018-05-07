//
// Strelka - Small Variant Caller
// Copyright (c) 2009-2018 Illumina, Inc.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
//

#include "boost/test/unit_test.hpp"

#include "logSumUtil.hh"


BOOST_AUTO_TEST_SUITE( logSumUtilTestSuite )

static
void
twoTermLogSumTest(
    const double x1,
    const double x2)
{
    static const double eps(0.00001);

    const double expect(std::log(x1+x2));

    const double logx1(std::log(x1));
    const double logx2(std::log(x2));

    BOOST_REQUIRE_CLOSE(getLogSum(logx1, logx2), expect, eps);

    std::initializer_list<double> ilist = {logx1, logx2};
    BOOST_REQUIRE_CLOSE(getLogSumSequence(ilist), expect, eps);

    std::vector<double> vec = ilist;
    BOOST_REQUIRE_CLOSE(getLogSumSequence(vec), expect, eps);
    BOOST_REQUIRE_CLOSE(getLogSumSequence(std::begin(vec), std::end(vec)), expect, eps);
}


BOOST_AUTO_TEST_CASE( testGetLogSum2 )
{

    twoTermLogSumTest(0.5, 0.2);
    twoTermLogSumTest(0.00001, 0.00000001);
    twoTermLogSumTest(1, 1);
}



static
void
threeTermLogSumTest(
    const double x1,
    const double x2,
    const double x3)
{
    static const double eps(0.00001);

    const double expect(std::log(x1+x2+x3));

    const double logx1(std::log(x1));
    const double logx2(std::log(x2));
    const double logx3(std::log(x3));

    BOOST_REQUIRE_CLOSE(getLogSum(logx1, logx2, logx3), expect, eps);

    std::initializer_list<double> ilist = {logx1, logx2, logx3};
    BOOST_REQUIRE_CLOSE(getLogSumSequence(ilist), expect, eps);

    std::vector<double> vec = ilist;
    BOOST_REQUIRE_CLOSE(getLogSumSequence(vec), expect, eps);
    BOOST_REQUIRE_CLOSE(getLogSumSequence(std::begin(vec), std::end(vec)), expect, eps);
}


BOOST_AUTO_TEST_CASE( testGetLogSum3 )
{
    threeTermLogSumTest(0.5, 0.2, 0.01);
    threeTermLogSumTest(0.00001, 0.00000001, 0.00000001);
    threeTermLogSumTest(1, 1, 1);
}


static
void
fourTermLogSumTest(
    const double x1,
    const double x2,
    const double x3,
    const double x4)
{
    static const double eps(0.00001);

    const double expect(std::log(x1+x2+x3+x4));

    const double logx1(std::log(x1));
    const double logx2(std::log(x2));
    const double logx3(std::log(x3));
    const double logx4(std::log(x4));

    BOOST_REQUIRE_CLOSE(getLogSum(logx1, logx2, logx3, logx4), expect, eps);

    std::initializer_list<double> ilist = {logx1, logx2, logx3, logx4};
    BOOST_REQUIRE_CLOSE(getLogSumSequence(ilist), expect, eps);

    std::vector<double> vec = ilist;
    BOOST_REQUIRE_CLOSE(getLogSumSequence(vec), expect, eps);
    BOOST_REQUIRE_CLOSE(getLogSumSequence(std::begin(vec), std::end(vec)), expect, eps);
}


BOOST_AUTO_TEST_CASE( testGetLogSum4 )
{
    fourTermLogSumTest(0.5, 0.2, 0.01, 0.1);
    fourTermLogSumTest(0.00001, 0.00000001, 0.00000001, 0.00001);
    fourTermLogSumTest(1, 1, 1, 1);
}


BOOST_AUTO_TEST_SUITE_END()

