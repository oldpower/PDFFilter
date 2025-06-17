#ifndef PDF_UTILS_HPP
#define PDF_UTILS_HPP

#include <string>

/**
 * @brief 提取PDF文件中的纯文本内容
 * 
 * @param pdf_path PDF文件路径
 * @return std::string 提取出的文本内容
 * @throws std::runtime_error 如果加载失败
 */
std::string extract_text_from_pdf(const std::string& pdf_path);

/**
 * @brief 判断给定文本是否可能是学术论文
 * 
 * @param text 提取的文本内容
 * @return true 是论文
 * @return false 不是论文
 */
bool is_likely_paper(const std::string& text);

#endif // PDF_UTILS_HPP
