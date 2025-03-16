#include <iostream>
#include <memory>
#include <string>

// Step 1: Base Class (Document)
class Document
{
public:
    virtual void open() = 0;
    virtual void save() = 0;
    virtual ~Document() = default;
};

// Step 2: Concrete Document Types
class PDFDocument : public Document
{
public:
    void open() override
    {
        std::cout << "Opening PDF Document..." << std::endl;
    }
    void save() override
    {
        std::cout << "Saving PDF Document..." << std::endl;
    }
};

class WordDocument : public Document
{
public:
    void open() override
    {
        std::cout << "Opening Word Document..." << std::endl;
    }
    void save() override
    {
        std::cout << "Saving Word Document..." << std::endl;
    }
};

class ExcelDocument : public Document
{
public:
    void open() override
    {
        std::cout << "Opening Excel Document..." << std::endl;
    }
    void save() override
    {
        std::cout << "Saving Excel Document..." << std::endl;
    }
};

// Step 3: Factory Class
class DocumentFactory
{
public:
    static std::unique_ptr<Document> createDocument(const std::string &type)
    {
        // convert type to upper case
        std::string typeUpper = type;
        for (auto &c : typeUpper)
        {
            c = toupper(c);
        }
        if (typeUpper == "PDF")
        {
            return std::make_unique<PDFDocument>();
        }
        else if (typeUpper == "WORD")
        {
            return std::make_unique<WordDocument>();
        }
        else if (typeUpper == "EXCEL")
        {
            return std::make_unique<ExcelDocument>();
        }
        return nullptr;
    }
};
