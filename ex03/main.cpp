/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:06:08 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/28 14:25:01 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(){
    // ! Good test
    std::cout << BLUE;
    try {
        Bureaucrat akhnouch("akhnouch", 2);
        std::cout << akhnouch << std::endl;
        
        Intern intern;
        AForm *form = intern.makeForm("ShrubberyCreationForm", "garden");
        // AForm *form2 = intern.makeForm("ShrubberyCreationForm", "garden");

        form->beSigned(akhnouch);
        // form2->beSigned(akhnouch);
        
        std::cout << "========================================================================" << std::endl;
        form->execute(akhnouch);
        std::cout << "========================================================================" << std::endl;
        // std::cout << "========================================================================" << std::endl;
        // form2->execute(akhnouch);
        // std::cout << "========================================================================" << std::endl;
    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }
    
    // ! Bad test
    std::cout << RED;
    try {

        Bureaucrat citizen("citizen", 145);
        std::cout << citizen << std::endl;
    
        Intern intern;
        AForm *form = intern.makeForm("test", "health");
        if (!form){
            throw std::bad_alloc();
        }
        
        
        form->beSigned(citizen);
        
        std::cout << "========================================================================" << std::endl;
        citizen.signForm(*form);
        std::cout << "========================================================================" << std::endl;
        
        std::cout << "========================================================================" << std::endl;
        form->execute(citizen);
        std::cout << "========================================================================" << std::endl;

    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }
}
