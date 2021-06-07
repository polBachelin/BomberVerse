/*
** EPITECH PROJECT, 2021
** B-YEP-400-REN-4-1-indiestudio-pol.bachelin
** File description:
** File
*/

#ifndef FILE_HPP_
#define FILE_HPP_

#include <fstream>
#include <unistd.h>
#include <sys/stat.h>
#include <string>
#include <stdexcept>
#include <iostream>

class File
{
    public:
        File(const std::string &path);
        ~File();

        //getter
            [[nodiscard]] std::string getPath() const noexcept;

            //is equalt to paht if file is not accesible
            [[nodiscard]] std::string getName() const noexcept;


        //return all file content
        //did nothing if file allready accessible
        void create();
        bool isAccessible() const noexcept;

        bool compareConent(const File &file) const noexcept;

        //throw exception if file is not accessible
        std::string read() const;
        void clear() const;
        void write(const std::string &to_append) const;
        struct stat getStat() const;


    private:
        std::string _path = "";
        std::string _name = "";

    private:
        std::string getNameFromPath(const std::string &path) const noexcept;
};

std::ostream& operator<<(std::ostream& out, const File &file);


#endif /* !FILE_HPP_ */