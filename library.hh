#ifndef H_REASON_TO
#define H_REASON_TO

#pragma once
#include <vector>
#include <string_view>
#include <string>
#include <variant>

class ReasonTo {
public:
    inline explicit ReasonTo() noexcept = default;
    virtual inline ~ReasonTo() noexcept = default;
    constexpr inline explicit ReasonTo(ReasonTo const& other) noexcept = delete;
    constexpr inline explicit ReasonTo(ReasonTo&& other) noexcept = delete;
    constexpr inline auto operator=(ReasonTo const& other) noexcept -> ReasonTo& = delete;
    constexpr inline auto operator=(ReasonTo&& other) noexcept -> ReasonTo& = delete;

public:
    [[nodiscard("c++🤮")]] 
    virtual inline auto getReason(std::size_t index) const noexcept -> std::string_view {
        if (std::holds_alternative<std::vector<std::string>>(m_reasons)) {
            return std::get<std::vector<std::string>>(m_reasons)[index];
        }
        std::unreachable();
    }

    [[nodiscard("c++🤮")]] 
    virtual inline auto canProceed() const noexcept -> bool {
        if (std::holds_alternative<std::size_t>(m_reasons)) {
            return std::get<std::size_t>(m_reasons) == 0;
        }
        return std::get<std::vector<std::string>>(m_reasons).empty();
    }

    virtual inline void addAnyReason() const noexcept {
        if (!std::holds_alternative<std::size_t>(m_reasons)) {
            m_reasons = std::size_t{1};
        } else {
            std::get<std::size_t>(m_reasons) += 1;
        }
    }

    virtual inline void removeAnyReason() const noexcept {
        if (std::holds_alternative<std::size_t>(m_reasons)) {
            std::get<std::size_t>(m_reasons) -= std::get<std::size_t>(m_reasons) > 1;
        }
    }

    virtual inline void addSpecificReason(std::string_view reasonName) const noexcept {
        if (!std::holds_alternative<std::vector<std::string>>(m_reasons)) {
            m_reasons = std::vector<std::string>{std::string(reasonName)};
        } else {
            std::get<std::vector<std::string>>(m_reasons).emplace_back(reasonName);
        }
    }

    virtual inline void removeSpecificReason(std::string_view reasonName) const noexcept {
        if (std::holds_alternative<std::vector<std::string>>(m_reasons)) {
            auto& reasons = std::get<std::vector<std::string>>(m_reasons);
            reasons.erase(std::remove_if(reasons.begin(), reasons.end(),
                                         [&reasonName](const std::string& str) {
                                             return str == reasonName;
                                         }),
                          reasons.end());
        }
    }
    
    virtual inline auto clear() const noexcept -> void {
        m_reasons = std::monostate{};
    };

private:
    mutable std::variant<std::monostate, std::vector<std::string>, std::size_t> m_reasons{std::monostate{}};
};

// Ekhmm this is actually correct version of ur code written in c++🤓☝️

#endif
