/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:06:08 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 20:39:14 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main(){
    // todo: ShrubberyCreationForm
    // ! test higher
    std::cout << GREEN << "ShrubberyCreationForm:" << std::endl;
    std::cout << BLUE;
    try {
        Bureaucrat akhnouch("akhnouch", 2);
        std::cout << akhnouch << std::endl;
        
        ShrubberyCreationForm form("garden");

        form.beSigned(akhnouch);

        std::cout << "========================================================================" << std::endl;
        std::cout << form << std::endl;
        std::cout << "========================================================================" << std::endl;
        
        std::cout << "========================================================================" << std::endl;
        form.execute(akhnouch);
        std::cout << "========================================================================" << std::endl;
    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }
    
    // ! test lower
    std::cout << RED;
    try {
        Bureaucrat citizen("citizen", 145);
        std::cout << citizen << std::endl;
        
        ShrubberyCreationForm form("health");
        
        form.beSigned(citizen);
        
        std::cout << "========================================================================" << std::endl;
        citizen.signForm(form);
        std::cout << "========================================================================" << std::endl;
        
        std::cout << "========================================================================" << std::endl;
        std::cout << form << std::endl;
        std::cout << "========================================================================" << std::endl;
        
        std::cout << "========================================================================" << std::endl;
        form.execute(citizen);
        std::cout << "========================================================================" << std::endl;
    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }


    // todo: RobotomyRequestForm
    // ! test higher
    std::cout << GREEN << "RobotomyRequestForm:" << std::endl;
    std::cout << BLUE;
    try {
        Bureaucrat akhnouch("akhnouch", 2);
        std::cout << akhnouch << std::endl;
        
        RobotomyRequestForm form("garden");

        form.beSigned(akhnouch);

        std::cout << "========================================================================" << std::endl;
        std::cout << form << std::endl;
        std::cout << "========================================================================" << std::endl;
        
        std::cout << "========================================================================" << std::endl;
        form.execute(akhnouch);
        std::cout << "========================================================================" << std::endl;
    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }
    
    // ! test lower
    std::cout << RED;
    try {
        Bureaucrat citizen("citizen", 140);
        std::cout << citizen << std::endl;
        
        RobotomyRequestForm form("robot");
        
        form.beSigned(citizen);
        
        std::cout << "========================================================================" << std::endl;
        citizen.signForm(form);
        std::cout << "========================================================================" << std::endl;
        
        std::cout << "========================================================================" << std::endl;
        std::cout << form << std::endl;
        std::cout << "========================================================================" << std::endl;
        
        std::cout << "========================================================================" << std::endl;
        form.execute(citizen);
        std::cout << "========================================================================" << std::endl;
    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }
}
