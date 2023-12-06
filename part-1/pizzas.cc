// Umer Anwar
// UmerAnwar@csu.fullerton.edu
// @UmerAnwar05
// Partners: @HiepSolivan

#include "pizzas.h"

#include <fstream>
#include <iostream>

std::vector<std::vector<std::string>> ReadCSV(const std::string& csv_filename,
                                              int columns) {
  std::vector<std::vector<std::string>> table;
  std::ifstream file(csv_filename);

  // read each row
  while (file.good()) {
    std::vector<std::string> row;
    // read each column
    for (int i = 0; i < columns; ++i) {
      std::string cell;
      file.ignore(1, '"');  // leading quote
      std::getline(file, cell, '"');
      if (i < (columns - 1)) {
        file.ignore(1, ',');  // comma
      }
      row.push_back(cell);
    }
    if (file.good()) {
      table.push_back(row);
    }
  }
  // Return the vector of strings that contains the data from the CSV file
  return table;
}

Pizza::Pizza(std::string pizza_id, double price, int calories)
    : pizza_id_(pizza_id), price_(price), calories_(calories) {}
Pizza::Pizza() : price_(0.0), calories_(0) {}
std::string Pizza::PizzaID() const { return pizza_id_; }
double Pizza::Price() const { return price_; }
int Pizza::Calories() const { return calories_; }
double Pizza::PricePer2000Calories() const {
  return ((price_ / calories_) * 2000);
}
std::vector<Pizza> ReadPizzas(const std::string& csv_filename) {
  std::vector<Pizza> pizzas;
  std::vector<std::vector<std::string>> pizza_table = ReadCSV(csv_filename, 9);
  int count{2};
  for (int j = 1; j < pizza_table.size(); ++j) {
    std::string string_pizza_id(pizza_table[j][1]);
    std::string string_price(pizza_table[j][3]);
    std::string string_calories(pizza_table[j][4]);
    count++;
    double price = std::stod(string_price);
    int calories = std::stoi(string_calories);
    Pizza new_pizza(string_pizza_id, price, calories);
    std::cout << count << std::endl;
    std::cout << "Name: " << new_pizza.PizzaID() << std::endl;
    std::cout << "Calories: " << new_pizza.Calories() << std::endl;
    pizzas.push_back(new_pizza);
  }
  // - Read the vector of strings at row j
  // - Retrieve the pizza_id (as a string) from column 1
  // - Retrieve the price (as a string) from column 3
  // - Retrieve the calories (as a string) from column 4
  // - Convert the string at column 3 into a double
  // - Convert the string at column 4 into an integer
  // - Create an object of class Pizza with the data from columns 1, 3, and 4
  // - Add the object with push_back to the vector of objects of class Pizza
  return pizzas;
}