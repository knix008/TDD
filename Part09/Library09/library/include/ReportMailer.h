/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include "MailMessage.h"
#include "MailDestination.h"
#include "Transport.h"
#include "Report.h"
#include "EndpointValidator.h"

#include <vector>
#include <stdexcept>

class ReportMailerException: public std::runtime_error
{
public:
    ReportMailerException(const std::string& message)
        : std::runtime_error(message) {}
};

template <typename ENDPOINT_VALIDATOR>
class ReportMailerImpl
{
public:
    ReportMailerImpl(std::vector<MailDestination> destinations)
        : mDestinations(destinations)
    {
        if (mDestinations.empty())
        {
            throw ReportMailerException("destinations required");
        }
        ENDPOINT_VALIDATOR validator;
        for (std::vector<MailDestination>::iterator it = mDestinations.begin();
            it != mDestinations.end();
            it++)
        {
            MailDestination destination = *it;
            // verify all endpoints
            if (!validator.IsValid(&destination))
            {
                throw ReportMailerException("invalid endpoint");
            }
        }
    }

	virtual ~ReportMailerImpl() 
    {
	}

    void MailReport(Report* report) 
    {
        for (std::vector<MailDestination>::iterator it = mDestinations.begin();
            it != mDestinations.end();
            it++)
        {
            MailDestination destination = *it;
            std::string toAddress = destination.Address();
            MailMessage message = ConstructMailMessage(toAddress, report);
            Send(message);
        }
    }

    virtual void Send(MailMessage& message)
    {
        MailDestination::Send(message);
    }
    
    MailMessage ConstructMailMessage(const std::string& toAddress, Report* report) const
    {
        return ReportMailerImpl::ConstructMailMessageTo(toAddress, report);
    }

    static MailMessage ConstructMailMessageTo(const std::string& toAddress, Report* report)
    {
        std::string content = report->Text();
        std::string subject = report->Name();

        MailMessage message(
            subject, 
            content, 
            "Joe@example.com");
        
        message.AddRecipient(toAddress);

        return message;
    }

private:
    std::vector<MailDestination> mDestinations;
};

typedef ReportMailerImpl<EndpointValidator> ReportMailer;
