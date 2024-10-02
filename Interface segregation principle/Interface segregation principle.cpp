#include <iostream>

// Спеціалізовані інтерфейси для окремих функцій
class IPrinter
{
public:
    virtual void print() = 0;
};

class IScanner
{
public:
    virtual void scan() = 0;
};

class IFax
{
public:
    virtual void fax() = 0;
};

// Принтер, який реалізує тільки інтерфейс друку
class SimplePrinter : public IPrinter
{
public:
    void print() override
    {
        std::cout << "Друк документа...\n";
    }
};

// Сканер, який реалізує тільки інтерфейс сканування
class SimpleScanner : public IScanner
{
public:
    void scan() override
    {
        std::cout << "Сканування документа...\n";
    }
};

// Мультифункціональний пристрій, який реалізує всі три інтерфейси
class MultiFunctionMachine : public IPrinter, public IScanner, public IFax
{
public:
    void print() override
    {
        std::cout << "Друк документа через мультифункціональний пристрій...\n";
    }

    void scan() override
    {
        std::cout << "Сканування документа через мультифункціональний пристрій...\n";
    }

    void fax() override
    {
        std::cout << "Відправка факсу через мультифункціональний пристрій...\n";
    }
};

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    SimplePrinter printer;
    SimpleScanner scanner;
    MultiFunctionMachine mfm;

    printer.print(); // Використання спеціалізованого принтера
    scanner.scan();  // Використання спеціалізованого сканера
    mfm.print();     // Використання мультифункціонального пристрою
    mfm.scan();
    mfm.fax();

    return 0;
}
