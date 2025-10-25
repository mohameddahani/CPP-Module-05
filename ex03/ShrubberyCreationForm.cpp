/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 08:49:06 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/25 13:13:00 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// ! Definitions of Orthodox Canonical Form, Member functions, and Setters, Getters

// * Default constructor
ShrubberyCreationForm::ShrubberyCreationForm():
        // ! A constructor of a base class can be called even if it is abstract, because it is part of the derived object.
        AForm("ShrubberyCreationForm", 145, 137), target("unknown target"){
    std::cout << "Default constructor of ShrubberyCreationForm is called" << std::endl;
}

// * Parametrised constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    // ! A constructor of a base class can be called even if it is abstract, because it is part of the derived object.
    : AForm("ShrubberyCreationForm", 145, 137), target(target){
    std::cout << "Parametrised constructor of ShrubberyCreationForm is called" << std::endl;
}

// * Copy constructor with initializer list
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target){
    std::cout << "Copy constructor of ShrubberyCreationForm is called" << std::endl;
}

// * Copy assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other){
    (void)other;

    std::cout << "Copy assignment operator of ShrubberyCreationForm is called" << std::endl;
    
    return *this;
}

// * Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm is destroyed" << std::endl;
}

// * Setters & Getters
std::string ShrubberyCreationForm::getTarget() const{
    return this->target;
}

// * Methods
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (!getIsSigned()){
        throw GradeTooLowException();
    }
    
    // * check if he can excute it
    if (executor.getGrade() > getGradeExecute()){
        throw GradeTooLowException();
    }

    // * Create a file
    std::string fileName = getTarget() + "_shrubbery";
    std::ofstream outputFile(fileName.c_str());
    
    if (!outputFile.is_open()){
        throw ErrorCreateFile();
    }

    
    outputFile << "              _{\\ _{\\{/}/}/}__\n"
            "             {/{/\\}{/{/\\}(\\}{/\\} _\n"
            "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n"
            "         {\\{/()\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n"
            "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n"
            "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n"
            "      {/{/{\\{\\{(/}{\\{\\/}/}{\\}(_){\\/}\\}\n"
            "      _{\\{/{\\{/(_)/}/}{/{/{/\\}\\})\\}{/\\}\n"
            "     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\n"
            "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/\n"
            "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n"
            "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{(/}/}\\}/}\n"
            "       {/{\\{\\/}(_){\\{\\{(/}/}{\\(_)/}/}\\}\n"
            "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n"
            "          (_){/{\\/}{\\{\\/}/}{\\{)/}/}(_)\n"
            "            {/{/{\\{\\/}{/{\\{\\{(_)/}\n"
            "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n"
            "              {){/ {\\/}{\\/} \\}\\}\n"
            "              (_)  \\.-'.-/\n"
            "          __...--- |'-.-'| --...__\n"
            "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n"
            " -\"    ' .  . '    |.'-._| '  . .  '   dahani\n"
            " .  '-  '    .--'  | '-.'|    .  '  . '\n"
            "          ' ..     |'-_.-|\n"
            "  .  '  .       _.-|-._ -|-._  .  '  .\n"
            "              .'   |'- .-|   '.\n"
            "  ..-'   ' .  '.   `-._.-'   .'  '  - .\n"
            "   .-' '        '-._______.-'     '  .\n"
            "        .      ~,\n"
            "    .       .   |\\   .    ' '-.\n"
            "    ___________/  \\____________\n"
            "   /  i wish i had another chance \\\n"
            "   \\___________________________/\n";

            std::cout << executor.getName() << " executed " << getName() << std::endl;
            outputFile.close();
}

// * Nested Class
const char * ShrubberyCreationForm::ErrorCreateFile::what() const throw() {
    return "Cannot Create output file!";
}

// * Insertion operator
std::ostream &operator<<(std::ostream &output, const ShrubberyCreationForm &other){
    return output << other.getTarget()
        << ", sign grade: " << other.getGradeSign()
        << ", exec grade: " << other.getGradeExecute();
}
