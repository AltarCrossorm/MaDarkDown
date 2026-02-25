#pragma once
#include "constants.hpp"
#include <map>
#include <string>
using namespace std;

using lang = LanguagesList;

class Metadata
{
private:
        string _title;
        string _author;
        string _subject;
        string _creatonDate;
        string _modificationDate;
        string _creator;
        string _toolProducer;
        string _PDFVersion;
        map<string, string> _otherMetadata;
        int _pageCount;
        lang _language;

        int Metadata::generateNewMetadata(string key, string value)
        {
                return 0;
        }

        int Metadata::addExistingMetadata(string key, string value)
        {
                return 0;
        }

public:
        Metadata::Metadata(string title,
                           string author,
                           string subject,
                           string creatonDate,
                           string modificationDate,
                           string creator,
                           string toolProducer,
                           string PDFVersion,
                           int pageCount,
                           lang language)
                           : _title(title),               _author(author),                     _subject(subject),
                _creatonDate(creatonDate),   _modificationDate(modificationDate), _creator(creator), 
                _toolProducer(toolProducer), _PDFVersion(PDFVersion)            , _pageCount(pageCount),
                _language(language)
                {}

        /**
         * @brief get all metadata, and set the input to the first line "after metadata"
         * 
         * @param input 
         * @return int 0 if everything got good, 
         */
        int Metadata::generateMetadata(ifstream *input)
        {
                return 0;
        }
};
