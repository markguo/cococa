#include <stdlib.h>
#include <string.h>
#include <stdexcept>
#include <fstream>
#include <boost/shared_ptr.hpp>
#include <iostream>

#include "Configuration.hpp"

bool ConfigurationSection::ReadValue(const char* name, std::string& value) const
{
	std::string key(name);
	std::map<std::string,std::string>::const_iterator it = container_.find(key);
	if (it != container_.end())
	{
		value = it->second;
		return true;
	}
	return false;
}

bool ConfigurationSection::ReadValue(const char* name, bool& value) const
{
	// try string format
	std::string key(name);
	std::map<std::string,std::string>::const_iterator it = container_.find(key);
	if (it != container_.end())
	{
		const std::string str(it->second);
		if (str=="y" || str=="Y" || str=="yes" || str == "Yes" || str=="true" || str == "True" || str == "1")
		{
			value = true;
			return true;
		}
		else if (str=="n" || str=="N" || str=="no" || str == "No" || str=="false" || str == "False" || str == "0")
		{
			value = false;
			return true;
		}
		else
		{
			BadFormat(name, str.c_str());
		}
	}

	return false;
}

bool ConfigurationSection::ReadList(const char* name, char delimiter, std::vector<std::string>& result) const
{
	std::string s;
	return ReadValue(name, s) && ParseList(s, delimiter, result);
}

bool ConfigurationSection::ParseList(const std::string& str, char delimiter, std::vector<std::string>& result)
{
	size_t begin = 0;
	size_t end;
	std::string element;
	result.clear();
	while ((end = str.find(delimiter, begin)) != std::string::npos)
	{
		element.assign(str, begin, end-begin);
		result.push_back(element);
		begin = end + 1;
	}
	
	if (begin < str.length())
	{
		element.assign(str, begin, str.size()-begin);
		result.push_back(element);
	}
	
	return true;
}

void ConfigurationSection::MissingValue(const char* name) const
{
	std::string message = "Missing configuration value: ";
	message += name;
	throw ConfigurationValueError(message);
}

void ConfigurationSection::BadFormat(const char* name, const char* value) const
{
	std::string message = "Bad configuration format: ";
	message += name;
	message += "=";
	message += value;
	throw ConfigurationValueError(message);
}

bool ConfigurationSection::GetSection(const char* name, ConfigurationSection& section) const
{
	if (root_.get())
	{
		std::string section_name;
		if (m_name.empty())
		{section_name = std::string(name);}
		else
		{section_name = m_name + "/" + std::string(name);}
		std::map<std::string,ConfigurationSection>::const_iterator it = root_->find(section_name);
		if (it != root_->end())
		{
			section = it->second;
			return true;
		}
	}
	return false;
}

void ConfigurationSection::MissingSection(const char* name) const
{
	std::string message = "Missing configuration section: ";
	message += name;
	throw ConfigurationValueError(message);
}

void ConfigurationSection::appendToString(std::string& s)
{
	ValueContainer::const_iterator it = container_.begin();
	ValueContainer::const_iterator ite = container_.end();
	while (it != ite)
	{
		s += "\"" + it->first + "\"=\"" + it->second +"\"\n";
		++ it;
	}
}

ConfigurationFile::ConfigurationFile()
{
}

ConfigurationFile::ConfigurationFile(const char* filename)
{
	loadFromFile(filename);
}

ConfigurationFile::ConfigurationFile(const std::string& filename)
{
	loadFromFile(filename.c_str());
}

static int is_comment_line(const char *line, size_t line_len)
{
	const char *p = line;
	const char *pe = line + line_len;
	while (p < pe)
	{
		char ch = *p;
		if (ch == '#')
		{
			return 1;
		}
		else if (ch == ' ' || ch == '\t')
		{
			++ p;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

//static boost::regex g_section_line_regex("\\[(\\w+(?:/\\w+)*)\\]");

//static bool isSectionLine(const std::string& line,std::string& section_name)
//{
////	if (line.length() < 3)
////	{return false;}
////	if (line[0] == '[' && line[line.length() - 1] == ']')
////	{
////		section_name = line.substr(1,line.length() - 2);
////		return true;
////	}
//	boost::smatch m;
//	if (boost::regex_search(line,m,g_section_line_regex))
//	{
//		section_name = m.str(1);
//		//std::cerr << "Section:\t" << section_name << std::endl;
//		return true;
//	}
//	return false;
//}

static int is_section_line(const char *line, size_t line_len, size_t *pos_out, size_t *len_out)
{
	const char *p = line;
	const char *pe = line + line_len;
	size_t pos = 0;
	size_t len = 0;
	int valid = 1;
	while (p < pe)
	{
		char ch = *p;
		if (ch == '[')
		{
			++ p;
			pos = (size_t)(p - line);
			break;
		}
		else if (ch == ' ' || ch == '\t')
		{
			++ p;
		}
		else 
		{
			valid = 0;
			break;
		}
	}
	if (!valid)
	{
		goto out;
	}
	while (p < pe)
	{
		char ch = *p;
		if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z' || ch >= '0' && ch <= '9' || ch == '_' || ch == '/')
		{
			p ++;
		}
		else
		{
			break;
		}
	}
	if (p < pe)
	{
		if (*p != ']')
		{
			valid = 0;
		}
		else
		{
			len = (size_t)(p - (line + pos));
		}
	}
	p = line + pos + len + 1;
	valid = is_comment_line(p, pe - p);
out:
	*pos_out = pos;
	*len_out = len;
	return valid;
}

static bool isSectionLine(const std::string& line, std::string& section_name)
{
	size_t section_pos = 0;
	size_t section_len = 0;
	bool b = (bool)is_section_line(line.c_str(), line.length(), &section_pos, &section_len);
	if (b)
	{
		section_name = line.substr(section_pos, section_len);
	}
	return b;
}

//static boost::regex g_key_value_line_regex("\"((?:[^\"]|\\\")+)\"=\"((?:[^\"]|\\\")+)\"");
////static boost::regex g_key_value_line_regex("\"((?:[^\"]|\\\")+)\"\\s+=\\s+\"((?:[^\"]|\\\")+)\"");

//static bool isKeyValueLine(const std::string& line,std::string& key,std::string& value)
//{
////	if (line.length() < 7)
////	{return false;}
////	if (line[0] == '"' && line[line.length() - 1] == '"')
////	{
////		std::string::size_type loc = line.find("\"=\"");
////		if (loc != std::string::npos)
////		{
////			key = line.substr(1,loc - 1);
////			value = line.substr(loc + 3,line.length() - loc - 4);
////			return true;
////		}
////	}
////	return false;
//	boost::smatch m;
//	if (boost::regex_search(line,m,g_key_value_line_regex))
//	{
//		key = m.str(1);
//		value = m.str(2);
//		//std::cerr << "Key-Value:\t" << key << "\t" << value << std::endl;
//		return true;
//	}
//	return false;
//}

static int is_key_value_line
(
 const char *line, size_t line_len,
 size_t *key_pos_out, size_t *key_len_out,
 size_t *value_pos_out, size_t *value_len_out
 )
{
	const char *p = line;
	const char *pe = p + line_len;
	const char *key_end = NULL; 
	const char *value_end = NULL;
	size_t key_pos = 0;
	size_t key_len = 0;
	size_t value_pos = 0;
	size_t value_len = 0;
	int valid = 1;
	while (p < pe)
	{
		char ch = *p;
		if (ch == '"')
		{
			++ p;
			key_pos = (size_t)(p - line);
			break;
		}
		else if (ch == ' ' || ch == '\t')
		{
			++ p;
		}
		else 
		{
			valid = 0;
			break;
		}
	}
	if (!valid)
	{
		goto out;
	}
	key_end = (const char *)memmem(p,pe - p,"\"=\"",3);
	if (!key_end)
	{
		valid = 0;
		goto out;
	}
	key_len = key_end - p;
	value_pos = key_end + 3 - line;
	value_end = (const char *)memmem(key_end + 3, pe - key_end - 3, "\"", 1);
	if (!value_end)
	{
		valid = 0;
		goto out;
	}
	value_len = value_end - (line + value_pos);
	valid = is_comment_line(value_end + 1, pe - value_end - 1);
out:
	*key_pos_out = key_pos;
	*key_len_out = key_len;
	*value_pos_out = value_pos;
	*value_len_out = value_len;
	return valid;
}

static bool isKeyValueLine(const std::string& line,std::string& key,std::string& value)
{
	size_t key_pos = 0;
	size_t key_len = 0;
	size_t value_pos = 0;
	size_t value_len = 0;
	bool b = (bool)is_key_value_line(line.c_str(),line.length(),&key_pos,&key_len,&value_pos,&value_len);
	if (b)
	{
		key = line.substr(key_pos,key_len);
		value = line.substr(value_pos,value_len);
	}
	return b;
}

//static boost::regex g_comment_line_regex("^\\s*#");

//static bool isCommentLine(const std::string& line)
//{
//	if (boost::regex_search(line,g_comment_line_regex))
//	{
//		//std::cerr << "Comment:\t" << line << std::endl;
//		return true;
//	}
//	return false;
//}

static bool isCommentLine(const std::string& line)
{
	return (bool)is_comment_line(line.c_str(),line.length());
}

void ConfigurationFile::loadFromFile(const char *file_name)
{
	std::ifstream ifs(file_name);
	if (!ifs.is_open())
	{
		throw ConfigurationError("File does not exists");
		return;
	}
	std::string line;
	ConfigurationSection section;
	std::string section_name;
	root_ = SectionContainerRefPtr(new SectionContainer);
	while (getline(ifs,line))
	{
		std::string new_section_name;
		std::string key;
		std::string value;
		if (isCommentLine(line))
		{
			continue;
		}
		if (isSectionLine(line,new_section_name))
		{
			if (!section_name.empty())
			{
				section.setRoot(section_name,root_);
				root_->insert(std::make_pair(section_name,section));
				section_name.clear();
			}
			section_name = new_section_name;
			section.clear();
		}
		else if (isKeyValueLine(line,key,value))
		{
			section.insert(key,value);
		}
	}

	if (!section_name.empty())
	{
		section.setRoot(section_name,root_);
		root_->insert(std::make_pair(section_name,section));
		section_name.clear();
	}

	//std::cerr << "After Building " << (unsigned long long )root_.get() << "\t" <<root_.use_count() << std::endl;
}
