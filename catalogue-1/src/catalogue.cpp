#include "catalogue.hpp"
#include <sstream>
#include <iomanip>
#include <algorithm>

std::string to_string(const Product& product) {
    std::ostringstream oss;
    oss << product.get_name() << " [" << product.get_id() << "] : "
        << std::setprecision(2) << std::fixed << "$" << product.get_price();
    return oss.str();
}

std::vector<Product> Catalogue::get_products_with_appropriate_price(std::function<bool(double)> predicate) const {
    std::vector<Product> products;

    for (const auto& entry : inventory_) {
        const auto& product = entry.second;
        if (predicate(product.get_price())) {
            products.push_back(product);
        }
    }


    return products;
}

std::vector<Product> Catalogue::get_products_by_name_part(std::string substr, bool is_case_sensitive) const {
    std::vector<Product> products;

    for (const auto& entry : inventory_) {
        const auto& product = entry.second;
        std::string name = product.get_name();

        std::string name_transformed = name;
        std::string chunk_transformed = substr;

        if (!is_case_sensitive) {
            std::transform(name.begin(), name.end(), name_transformed.begin(), ::tolower);
            std::transform(substr.begin(), substr.end(), chunk_transformed.begin(), ::tolower);
        }

        bool contains_substr = (name_transformed.find(chunk_transformed) != std::string::npos);
        if (contains_substr) {
            products.push_back(product);
        }
    }

    return products;
}
