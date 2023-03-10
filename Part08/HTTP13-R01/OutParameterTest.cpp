#include "gmock/gmock.h"

using namespace ::testing;

class DifficultCollaborator
{
public:
   virtual bool calculate(int *result)
   {
      throw 1;
   }
};

class Target
{
public:
   int execute(DifficultCollaborator *calculator)
   {
      int i;
      if (!calculator->calculate(&i))
         return 0;
      return i;
   }
};

class DifficultCollaboratorMock : public DifficultCollaborator
{
public:
   MOCK_METHOD1(calculate, bool(int *));
};

TEST(ATarget, ReturnsAnAmountWhenCalculatePasses)
{
   DifficultCollaboratorMock difficult;
   Target calc;
   EXPECT_CALL(difficult, calculate(_))
       .WillOnce(DoAll(
           SetArgPointee<0>(3),
           Return(true)));

   auto result = calc.execute(&difficult);
   //std::cout << result << std::endl;

   ASSERT_THAT(result, Eq(3));
}
