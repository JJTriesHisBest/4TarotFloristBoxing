#pragma once

#include <vector>
#include <memory>

template <typename T>
class vu : public std::vector<std::unique_ptr<T>> {};

