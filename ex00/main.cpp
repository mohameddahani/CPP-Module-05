/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdahani <mdahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 18:06:08 by mdahani           #+#    #+#             */
/*   Updated: 2025/10/24 18:16:41 by mdahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
    // ! test lower
    try {
        Bureaucrat akhnouch("akhnouch", 2);
        akhnouch.incrementBureaucrat();   
        // akhnouch.incrementBureaucrat();
        std::cout << akhnouch << std::endl;
    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }
    
    // ! test higher
    try {
        // Bureaucrat citizen("genZ", 150);
        Bureaucrat citizen;
        citizen.decrementBureaucrat();
        std::cout << citizen << std::endl;
    }
    catch (const std::exception &e){
        std::cout << "========================================================================" << std::endl;
        std::cout << e.what() << std::endl;
        std::cout << "========================================================================" << std::endl;
    }
}
