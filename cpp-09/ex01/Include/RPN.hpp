/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gforns-s <gforns-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 08:38:29 by gforns-s          #+#    #+#             */
/*   Updated: 2025/02/06 11:07:54 by gforns-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cstdlib>


class RPN
{
	protected:
		std::stack<int> val;
		int result;
	public:
		RPN();
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		void checkInput(const std::string& in); //add a try catch in main func so it can opt the error std::logic_error &e!!
		bool isAllowed(const char c);
		void solve(const std::string &in);
};
