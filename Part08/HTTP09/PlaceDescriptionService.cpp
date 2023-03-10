#include <string>
#include "PlaceDescriptionService.h"
#include "Http.h"
#include "AddressExtractor.h"
#include "Address.h"

using namespace std;

PlaceDescriptionService::PlaceDescriptionService(Http *http) : http_(http) {}

string PlaceDescriptionService::summaryDescription(const string &latitude, const string &longitude) const
{
    string server{"http://open.mapquestapi.com/"};
    string document{"nominatim/v1/reverse"};
    string url = server + document + "?" +
                 keyValue("format", "json") + "&" +
                 keyValue("lat", latitude) + "&" +
                 keyValue("lon", longitude);
    auto response = http_->get(url);
    AddressExtractor extractor;
    auto address = extractor.addressFrom(response);
    return address.summaryDescription();
}

string PlaceDescriptionService::keyValue(const string &key, const string &value) const
{
    return key + "=" + value;
}