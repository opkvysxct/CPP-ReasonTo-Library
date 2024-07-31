#include "library.h"

#include <iostream>
#include <vector>

class ReasonTo {
public:
	int anyReasons;
	std::vector<std::string> specificReasons;
	[[nodiscard]] bool CanProceed() const;
	void AddAnyReason();
	void AddSpecificReason(const std::string& reasonName);
	void RemoveAnyReason();
	void RemoveSpecificReason(const std::string& reasonName);
	void Clear();
};

bool ReasonTo::CanProceed() const {
	if (this->anyReasons == 0 && this->specificReasons.empty()) {
		return true;
	}
	return false;
}

void ReasonTo::AddAnyReason() {
	this->anyReasons++;
}

void ReasonTo::RemoveAnyReason() {
	if (this->anyReasons>1)	this->anyReasons--;
}

void ReasonTo::AddSpecificReason(const std::string& reasonName) {
	this->specificReasons.push_back(reasonName);
}

void ReasonTo::RemoveSpecificReason(const std::string& reasonName) {
	this->specificReasons.erase(std::find(
			this->specificReasons.begin(),
			this->specificReasons.end(),
			reasonName));
}

void ReasonTo::Clear() {
	this->specificReasons.clear();
	this->anyReasons = 0;
}