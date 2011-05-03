#ifndef CONFIG_H_INCLUDED
#define CONFIG_H_INCLUDED

#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <boost/shared_ptr.hpp>
#include <limits.h>
#include <stdio.h>

class ConfigurationError : public std::runtime_error
{
public:
	ConfigurationError(const std::string& message) : 
		std::runtime_error(message)
	{
	}
};

class ConfigurationSectionError : public ConfigurationError
{
public:
	ConfigurationSectionError(const std::string& message) : 
		ConfigurationError(message)
	{
	}
};

class ConfigurationValueError : public ConfigurationError
{
public:
	ConfigurationValueError(const std::string& message) : 
		ConfigurationError(message)
	{
	}
};

#include <iostream>

class ConfigurationSection
{
public:
	ConfigurationSection(){}
	virtual ~ConfigurationSection()	{}
	bool ReadValue(const char* name, std::string& value) const;
	bool ReadValue(const char* name, bool& value) const;
	bool ReadValue(const char* name, short& value) const
	{
		return ReadIntegralValue(name, value);
	}
	bool ReadValue(const char* name, unsigned short& value) const
	{
		return ReadIntegralValue(name, value);
	}
	bool ReadValue(const char* name, int& value) const
	{
		return ReadIntegralValue(name, value);
	}
	bool ReadValue(const char* name, unsigned int& value) const
	{
		return ReadIntegralValue(name, value);
	}
	bool ReadValue(const char* name, long& value) const
	{
		return ReadIntegralValue(name, value);
	}
	bool ReadValue(const char* name, unsigned long& value) const
	{
		return ReadIntegralValue(name, value);
	}
	bool ReadValue(const char* name, long long& value) const
	{
		return ReadIntegralValue(name, value);
	}
	bool ReadValue(const char* name, unsigned long long& value) const
	{
		return ReadIntegralValue(name, value);
	}
	bool ReadList(const char* name, char delimiter, std::vector<std::string>& va) const;

	template <typename Type>
	Type Value(const char* name) const
	{
		Type value = Type();
		if (!ReadValue(name, value))
			MissingValue(name);
		return value;
	}
	template <typename Type, typename DefaultValueType>
	Type Value(const char* name, const DefaultValueType& default_value) const
	{
		Type value = Type();
		if (ReadValue(name, value))
			return value;
		else
			return default_value;
	}
	template <typename Type>
	void GetValue(const char* name, Type& value) const
	{
		if (!ReadValue(name, value))
			MissingValue(name);
	}
	template <typename Type, typename DefaultValueType>
	bool GetValue(const char* name, Type& value, const DefaultValueType& default_value) const
	{
		if (!ReadValue(name, value))
		{
			value = default_value;
			return false;
		}
		return true;
	}

	const std::string& Name() const
	{
		return m_name;
	}
private:
	static void strtoint(const char* str, char** endpos, int base, short &value)
	{
		long v = strtol(str, endpos, base);
		if (v > SHRT_MAX || v < SHRT_MIN)
			throw std::domain_error("");
		value = v;

	}
	static void strtoint(const char* str, char** endpos, int base, unsigned short &value)
	{
		value = strtoul(str, endpos, base);
	}
	static void strtoint(const char* str, char** endpos, int base, int &value)
	{
		value = strtol(str, endpos, base);
	}
	static void strtoint(const char* str, char** endpos, int base, unsigned int &value)
	{
		value = strtoul(str, endpos, base);
	}
	static void strtoint(const char* str, char** endpos, int base, long &value)
	{
		value = strtol(str, endpos, base);
	}
	static void strtoint(const char* str, char** endpos, int base, unsigned long &value)
	{
		value = strtoul(str, endpos, base);
	}
	static void strtoint(const char* str, char** endpos, int base, long long &value)
	{
		value = strtoll(str, endpos, base);
	}
	static void strtoint(const char* str, char** endpos, int base, unsigned long long &value)
	{
		value = strtoull(str, endpos, base);
	}
	template <typename T>
	bool ReadIntegralValue(const char* name, T& value) const
	{
		// try string format
		std::string key(name);
		std::map<std::string,std::string>::const_iterator it = container_.find(key);
		if (it != container_.end())
		{
			std::string str(it->second);
			char* endpos;
			if (str.length() > 2 && str[0]=='0' && (str[1]=='x' || str[1]=='X'))
			{
				strtoint(str.c_str()+2, &endpos, 16, value);
			}
			else
			{
				strtoint(str.c_str(), &endpos, 10, value);
			}
			if (*endpos)
				BadFormat(name, str.c_str());
			return true;
		}
		return false;
	}

	static bool ParseList(const std::string& str, char delimiter, std::vector<std::string>& result);
	void MissingValue(const char* name) const;
	void BadFormat(const char* name, const char* value) const;
	void MissingSection(const char* name) const;

protected:
	typedef std::map<std::string,std::string> ValueContainer;
	typedef std::map<std::string,ConfigurationSection> SectionContainer;
	typedef boost::shared_ptr<SectionContainer> SectionContainerRefPtr;

	ValueContainer container_;
	SectionContainerRefPtr root_;
	std::string m_name;

public:
	void insert(const std::string& key,const std::string& value)
	{
		container_.insert(make_pair(key,value));
	}
	void insert(const std::string& key, const char* value)
	{
		std::string value_s = value;
		insert(key, value_s);
	}
	void insert(const std::string& key, bool value)
	{
		char buff[256];
		sprintf(buff, "%s", value ? "Y" : "N" );
		insert(key, buff);
	}
	void insert(const std::string& key, unsigned int value)
	{
		char buff[256];
		sprintf(buff, "%u", value);
		insert(key, buff);
	}
	void insert(const std::string& key, unsigned long value)
	{
		char buff[256];
		sprintf(buff, "%lu", value);
		insert(key, buff);
	}
	void clear()
	{
		container_.clear();
	}
	void setRoot(const std::string& name, SectionContainerRefPtr root)
	{
		m_name = name;
		root_ = root;
	} 
	void appendToString(std::string& s);
public:
	bool GetSection(const char* name, ConfigurationSection& section) const;
	ConfigurationSection Section(const char* name) const
	{
		ConfigurationSection section;
		if (!GetSection(name, section))
			MissingSection(name);
		return section;
	}
};

class ConfigurationFile : public ConfigurationSection
{
public:
	ConfigurationFile();
	ConfigurationFile(const char* filename);
	ConfigurationFile(const std::string& filename);
	virtual ~ConfigurationFile(){}
//protected:
	void loadFromFile(const char *file_name);
};

#endif
