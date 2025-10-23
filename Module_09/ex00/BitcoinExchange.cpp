#include "BitcoinExchange.hpp"
#include <sstream>

// Orthodox Canonical Form
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}

// Helper: Trim whitespace
std::string BitcoinExchange::trim(const std::string &str) const
{
    size_t first = str.find_first_not_of(" \t\n\r");
    if (first == std::string::npos)
        return "";
    size_t last = str.find_last_not_of(" \t\n\r");
    return str.substr(first, last - first + 1); //first points to the first char, so it includes it
}

// Load database from CSV
void BitcoinExchange::loadData(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open Data file." << std::endl;
        return;
    }
    
    std::string line;
    // Skip header line
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;
        
        std::string date = trim(line.substr(0, pos));
        std::string rateStr = trim(line.substr(pos + 1));
        
        // Simple conversion for database (trust it's valid)
        float rate = std::atof(rateStr.c_str());
        _data[date] = rate;
    }
    file.close();
}

// Process input file
void BitcoinExchange::processInput(const std::string &filename) const
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open Input file." << std::endl;
        return;
    }
    
    std::string line;
    // Skip header line
    std::getline(file, line);
    
    while (std::getline(file, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        
        std::string dateStr = trim(line.substr(0, pos));
        std::string valueStr = trim(line.substr(pos + 1));
        
        // Validate date
        if (!isValidDate(dateStr))
        {
            std::cerr << "Error: bad input => " << dateStr << std::endl;
            continue;
        }
        
        // Validate and parse value
        float value;
        if (!isValidValue(valueStr, value))
            continue;
        
        // Get exchange rate
        float rate = getExchangeRate(dateStr);
        if (rate < 0)
        {
            std::cerr << "Error: no data available for this date." << std::endl;
            continue;
        }
        
        // Calculate and output result
        float result = value * rate;
        std::cout << dateStr << " => " << value << " = " << result << std::endl;
    }
    
    file.close();
}

// Validate date format (already correct!)
bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.empty())
        return false;

    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    
    char *endptr;
    
    long year = std::strtol(yearStr.c_str(), &endptr, 10);
    if (*endptr != '\0') return false;
    
    long month = std::strtol(monthStr.c_str(), &endptr, 10);
    if (*endptr != '\0') return false;
    
    long day = std::strtol(dayStr.c_str(), &endptr, 10);
    if (*endptr != '\0') return false;
    
    if (year < 2009 || year > 9999)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;
    
    return true;
}

// Validate value (C++98 compatible)
bool BitcoinExchange::isValidValue(const std::string &valueStr, float &value) const
{
    if (valueStr.empty())
        return false;
    
    char *endptr;
    value = std::strtof(valueStr.c_str(), &endptr);
    
    
    if (*endptr != '\0')
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }

    if (value < 0.0f || value > 1000.0f)
    {
        if (value < 0.0f)
            std::cerr << "Error: not a positive number." << std::endl;
        else
            std::cerr << "Error: too large a number." << std::endl;
        return false;
    }
    
    return true;
}

// Get exchange rate (already correct!)
float BitcoinExchange::getExchangeRate(const std::string &date) const
{
    if (_data.empty())
        return -1.0f;
    
    std::map<std::string, float>::const_iterator it = _data.lower_bound(date);
    
    // Exact match
    if (it != _data.end() && it->first == date)
        return it->second;
    
    // Use closest lower date
    if (it == _data.begin())
        return -1.0f;
    
    --it;
    return it->second;
}