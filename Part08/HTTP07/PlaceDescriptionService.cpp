#include <string>
#include "PlaceDescriptionService.h"
#include "Http.h"
#include "AddressExtractor.h"
#include "Address.h"

using namespace std;

PlaceDescriptionService::PlaceDescriptionService(Http *http) : http_(http) {}

string PlaceDescriptionService::summaryDescription(const string &latitude, const string &longitude) const
{
   return "";
}