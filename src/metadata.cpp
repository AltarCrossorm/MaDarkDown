#include "metadata.hpp"

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

Metadata::~Metadata()
{}

int Metadata::generateNewMetadata(string key, string value)
{
        return 0;
}

int Metadata::addExistingMetadata(string key, string value)
{
        return 0;
}

int Metadata::generateMetadata(ifstream *input)
{
        return 0;
}