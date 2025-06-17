#include "pdf_utils.hpp"
#include <poppler/cpp/poppler-document.h>
#include <poppler/cpp/poppler-page.h>
#include <stdexcept>
#include <algorithm>
#include <cctype>

std::string extract_text_from_pdf(const std::string& pdf_path) {
    auto document = poppler::document::load_from_file(pdf_path);
    if (!document || document->is_locked()) {
        throw std::runtime_error("无法加载或打开PDF文件: " + pdf_path);
    }

    std::string full_text;
    for (int i = 0; i < document->pages(); ++i) {
        auto page = document->create_page(i);
        if (!page) continue;

        auto text = page->text().to_utf8();
        full_text.insert(full_text.end(), text.begin(), text.end());
    }

    return full_text;
}

// 将字符串转为小写
std::string to_lower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return result;
}

bool is_likely_paper(const std::string& text) {
    static const std::vector<std::string> keywords = {
        "abstract", "introduction", "methods",
        "results", "discussion", "conclusion", "references"
    };

    std::string lower_text = to_lower(text);
    int match_count = 0;

    for (const auto& keyword : keywords) {
        if (lower_text.find(keyword) != std::string::npos) {
            ++match_count;
        }
    }

    return match_count >= 2;
}
