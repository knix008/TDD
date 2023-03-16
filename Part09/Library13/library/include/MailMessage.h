/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include <string>
#include <vector>

class MailMessage
{
public:
	MailMessage(const std::string& subject, const std::string& content, const std::string& from);
	~MailMessage(void);

    void AddRecipient(const std::string& toAddress);
    std::string Subject() const;
    std::string Content() const;
    std::vector<std::string> To() const;
    std::string From() const;

private:
	std::string mSubject;
	std::string mContent;
    std::vector<std::string> mTo;
    std::string mFrom;
};
