#include "String.hpp"

String::String()
{
	// Initialize an empty string
}

String::String(const char* data)
{
    setText(data);    
}

String::~String()
{
    delete[] m_data; // Release dynamically allocated memory
}

String::String(const String& obj)
{
    setText(obj.m_data);
}

String& String::operator=(const String &obj)
{
    setText(obj.m_data);

    return *this;
}

String::String(String&& obj)
{
    setText(obj.m_data);
    
    m_data = obj.m_data;
    obj.m_data = nullptr;
    obj.m_length = 0;
}

String& String::operator=(String&& obj)
{
    //setText(obj.m_data);
    m_data = obj.m_data;
    obj.m_data = nullptr;
    obj.m_length = 0;

    return *this;
}

String String::operator+(const String &obj) const
{    
    String temp;
    temp.m_length = m_length + obj.m_length;
    temp.m_data = new char[temp.m_length + 1];

    size_t i = 0;
    for(; i < m_length; ++i) {
        temp.m_data[i] = m_data[i];
    }

    for(size_t j = 0; j <= obj.m_length; ++j, ++i) {
        temp.m_data[i] = obj.m_data[j];
    }


    return temp;
}

bool String::operator==(const String& obj) const
{
    if(this == &obj) {
        return true; // Same object
    }

    if(m_length != obj.m_length) {
        return false; // Different lengths
    }

    for(size_t i = 0; i < m_length; ++i) {
        if(m_data[i] != obj.m_data[i]) {
            return false; // Characters at the same position are different
        }         
    }
    
    return true; // Strings are equal
    
}

bool String::operator!=(const String& obj) const
{
    return !(*this == obj);
}

char& String::operator[](const size_t index) const
{
    return m_data[index];
}

void String::setText(const char* text)
{
    if(m_data != nullptr) {
        delete[] m_data;
    }
    
    m_length = length(text);
    m_data = new char[m_length];

    for(size_t i = 0; i < m_length; ++i) {
        m_data[i] = text[i];
    }
    m_data[m_length] = '\0'; // Null-terminate the string
    
} 

void String::print() const
{
    std::cout << m_data;
}

char* String::text() const
{
    return m_data;
}

size_t String::length() const
{
    return m_length;
}

size_t String::length(const char* text) const
{
    size_t i = 0;
    while(text[i] != '\0') {
        ++i;
    }

    return i;
}
