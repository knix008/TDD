#include <string>
#include "PlaceDescriptionService.h"
#include "Http.h"
#include "AddressExtractor.h"
#include "Address.h"

using namespace std;

PlaceDescriptionService::PlaceDescriptionService(Http *http) : http_(http) {}

string PlaceDescriptionService::summaryDescription(const string &latitude, const string &longitude) const
{
    auto request = createGetRequestUrl(latitude, longitude);
    auto response = get(request);
    return summaryDescription(response);
}

string PlaceDescriptionService::summaryDescription(const string &response) const
{
    AddressExtractor extractor;
    auto address = extractor.addressFrom(response);
    return address.summaryDescription();
}

string PlaceDescriptionService::get(const string &requestUrl) const
{
    return http_->get(requestUrl);
}

string PlaceDescriptionService::createGetRequestUrl(const string &latitude, const string &longitude) const
{
    string server{"http://open.mapquestapi.com/"};
    string document{"nominatim/v1/reverse"};
    return server + document + "?" +
           keyValue("format", "json") + "&" +
           keyValue("lat", latitude) + "&" +
           keyValue("lon", longitude);
}

string PlaceDescriptionService::keyValue(const string &key, const string &value) const
{
    return key + "=" + value;
}
