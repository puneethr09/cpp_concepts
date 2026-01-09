#include <iostream>
#include <memory>
#include <string>

// The Factory Pattern is a creational design pattern that provides an interface for creating objects in a superclass,
// but allows subclasses to alter the type of objects that will be created.
// It promotes loose coupling by eliminating the need to bind application-specific classes into the code.
// The Factory Pattern is useful when the exact type of the object to be created is determined at runtime.

// below example explained:
//  Document is the base class with virtual methods open() and save()
//  PDFDocument, WordDocument, ExcelDocument are concrete classes derived from Document implementing the open() and save() methods
//  DocumentFactory is the factory class with a static method createDocument() that takes a string parameter to determine the type of document to create
//  Example usage:
//  auto pdfDoc = DocumentFactory::createDocument("PDF");
//  pdfDoc->open();
//  pdfDoc->save();
//  Output: Opening PDF Document...
//          Saving PDF Document...
//  This demonstrates the Factory Pattern by allowing the creation of different document types without specifying the exact class of the object that will be created.
//  Note: Remember to include necessary headers and use appropriate namespaces in your actual implementation.
//  This code is written in C++14 standard.

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
