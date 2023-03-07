#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

class FloatingPoint: public Test {
public:
   double x{4.0};
   double y{0.56};
};

TEST_F(FloatingPoint, IsSame) {
   ASSERT_THAT(x + y, DoubleEq(4.56));
}