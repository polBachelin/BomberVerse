/*
** EPITECH PROJECT, 2021
** B-OOP-400-REN-4-1-arcade-arthur.jourdan
** File description:
** Directory
*/

#include "Directory.hpp"
#include "Path.hpp"
#include <string.h>

Directory::Directory(const std::string &dirpath, bool force_creation)
{
    this->_dirPath = dirpath;
    this->_directory = std::filesystem::is_directory(_dirPath);

    if (!this->_directory && !force_creation)
        throw std::invalid_argument(
            std::string("Read Dir: fail to open directory ") + _dirPath);
    else if (!this->_directory && force_creation)
        std::filesystem::create_directory(_dirPath);
    for (const auto & file : std::filesystem::directory_iterator(_dirPath.c_str()))
        std::cout << file.path() << std::endl;
}

Directory::~Directory()
{
}

File &Directory::loadFile(const std::string &filename, bool force_creation)
{

    for (auto &i : this->_dir_content) {
        if (filename == i.getName())
            return i;
    }
    if (!force_creation) {
        _dir_content.push_back(File(Path::getOSPath(this->_dirPath + "/" + filename), force_creation));
        return _dir_content.back();
    }
    if (force_creation) {
        _dir_content.push_back(File(Path::getOSPath(this->_dirPath + "./" + filename), force_creation));
        return _dir_content.back();
    }
    throw std::runtime_error("File not found and doesn't want to be created");
}

std::vector<std::string> Directory::getSubDirNames()
{
    std::vector<std::string> names;

    for (const auto it : std::filesystem::directory_iterator(_dirPath)) {
        if (it.is_directory()) {
            names.push_back(it.path().string());
        }
    }
    return names;
}

std::vector<File> Directory::getAllDirFiles() noexcept
{
    std::string path;

    for (const auto &file : std::filesystem::directory_iterator(_dirPath)) {
        path = std::string(file.path().string());
        this->_dir_content.push_back(File(path));
    }
    return this->_dir_content;
}
