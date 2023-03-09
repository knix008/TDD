#include "gmock/gmock.h"

#include "PlaceDescriptionService.h"
#include "Http.h"

using namespace std;
using namespace testing;

class APlaceDescriptionService : public Test
{
public:
   static const string ValidLatitude;
   static const string ValidLongitude;
};

const string APlaceDescriptionService::ValidLatitude("38.005");
const string APlaceDescriptionService::ValidLongitude("-104.44");

class HttpStub : public Http
{
public:
   string returnResponse;
   string expectedURL;
   void initialize() override {}

   std::string get(const std::string &url) const override
   {
      verify(url);
      return returnResponse;
   }

   void verify(const string &url) const
   {
      ASSERT_THAT(url, Eq(expectedURL));
   }
};

TEST_F(APlaceDescriptionService, ReturnsDescriptionForValidLocation)
{
   HttpStub httpStub;
   httpStub.returnResponse = R"({"address": {
      "road":"Drury Ln", 
      "city":"Fountain", 
      "state":"CO", 
      "country":"US" }
      }
   )";
   
   string urlStart{"http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"};
   httpStub.expectedURL = urlStart +
                          "lat=" + APlaceDescriptionService::ValidLatitude + "&" +
                          "lon=" + APlaceDescriptionService::ValidLongitude;
   PlaceDescriptionService service{&httpStub};
   auto description = service.summaryDescription(ValidLatitude, ValidLongitude);
   ASSERT_THAT(description, Eq("Drury Ln, Fountain, CO, US"));
}