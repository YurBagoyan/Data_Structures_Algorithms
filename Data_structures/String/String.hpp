#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>

class String 
{
public:
    String();
    String(const char* data);
    ~String();

    // Copy semantics
    String(const String& obj);
    String& operator=(const String& obj);

    // Move semantics
    String(String&& obj);
    String& operator=(String&& obj);


    String operator+(const String& obj) const;
    bool operator==(const String& obj) const;
    bool operator!=(const String& obj) const;
    char& operator[](const size_t index) const;
    

    void setText(const char* text);
    void print() const;
    char* text() const;
    size_t length() const;



private: // Helpers
    size_t length(const char* text) const;


private:
    char* m_data = nullptr;
    size_t m_length = 0;
};


#endif // STRING_HPP
