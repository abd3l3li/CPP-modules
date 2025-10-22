#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, float> _data;
        
        std::string trim(const std::string &str) const;
        bool isValidDate(const std::string &date) const;
        bool isValidValue(const std::string &valueStr, float &value) const;
        float getExchangeRate(const std::string &date) const;

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        
        void loadData(const std::string &filename);
        void processInput(const std::string &filename) const;
};

#endif