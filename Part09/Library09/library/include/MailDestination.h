/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include "Endpoint.h"
#include "MailMessage.h"

#include <string>
#include <stdexcept>

class MailDestinationException: public std::runtime_error
{
public:
    MailDestinationException()
       : std::runtime_error("unable to connect to LDAP server") {}
};

class MailDestination
{
public:
    MailDestination(const std::string& address);
    ~MailDestination(void);

    static Endpoint CreateEndpoint(const std::string& address);
    static Endpoint CreateEndpoint(MailDestination& destination);
    static void Send(MailMessage&);

    std::string Address() const;

private:
    std::string mAddress;
};
