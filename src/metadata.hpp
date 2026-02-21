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

        int generateNewMetadata(string key, string value);
        int addExistingMetadata(string key, string value);

public:
        Metadata(string title = "",
                 string author = "",
                 string subject = "",
                 string creatonDate = "",
                 string modificationDate = "",
                 string creator = "",
                 string toolProducer = "MaDarkDown Parser",
                 string PDFVersion = "",
                 int pageCount = 0,
                 lang language = lang::en_US);

        ~Metadata();


        /**
         * @brief get all metadata, and set the input to the first line "after metadata"
         * 
         * @param input 
         * @return int 0 if everything got good, 
         */
        int generateMetadata(ifstream *input);

};
