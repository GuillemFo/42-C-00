/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 01:18:21 by gforns-s          #+#    #+#             */
/*   Updated: 2024/10/23 14:19:18 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Form.hpp"
// #include <string>
// #include <stdexcept>

class Form;

class Bureaucrat
{
	protected:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const std::string nm, int i);
		~Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);

		const std::string getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();
		void signForm(Form &form);
		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw();		
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw();		
		};
};
std::ostream &operator<<(std::ostream &val, const Bureaucrat &grade);
