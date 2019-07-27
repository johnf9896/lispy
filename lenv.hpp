#ifndef LENV_HPP
#define LENV_HPP

#include <string>
#include <vector>
#include <map>
#include "builtin.hpp"

struct lval;

struct lenv {
    using table_type = std::map<std::string, lval*>;

    lenv *parent;
    table_type symbols;

    lenv();
    lenv(const lenv &other);
    explicit lenv(const lenv *const other);
    ~lenv();

    std::vector<std::string> keys() const;
    std::vector<const std::string*> keys(const std::string &prefix) const;
    lval* get(const std::string &sym) const;
    void put(const std::string &sym, const lval *const val);
    void def(const std::string &sym, const lval *const val);
    void add_builtin(const std::string &name, lbuiltin func);
};

#endif // LENV_HPP
