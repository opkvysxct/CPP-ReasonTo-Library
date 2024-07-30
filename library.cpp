#include "library.h"

#include <iostream>
#include <vector>

class ReasonTo {
public:
	int anyReasons;
	std::vector<std::string> specificReasons;
	bool CanProceed();
	void AddAnyReason();
	void AddSpecificReason(std::string reasonName);
	void RemoveAnyReason();
	void RemoveSpecificReason(std::string reasonName);
};

bool ReasonTo::CanProceed() {
	if (this->anyReasons == 0 && this->specificReasons.size() == 0) {
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

void ReasonTo::AddSpecificReason(std::string reasonName) {
	this->specificReasons.push_back(reasonName);
}

void ReasonTo::RemoveSpecificReason(std::string reasonName) {
	this->specificReasons.erase(std::find(
			this->specificReasons.begin(),
			this->specificReasons.end(),
			reasonName));
}