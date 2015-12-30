#pragma once

#include <vector>
#include <memory>

template <typename T>
class vu : public std::vector<std::unique_ptr<T>>
{
public:
	std::unique_ptr<T> extract(int aIndex) {
		std::unique_ptr<T> up;
		auto it = this->begin() + aIndex;
		std::swap(up, *it);
		this->erase(it);
		return up;
	}
};

