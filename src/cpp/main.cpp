#include <iostream>
#include <string>
#include <chrono>
#include "pdf_utils.hpp"

int main(int argc, char* argv[]) {
    std::string pdf_path;
    if (argc != 2) {
        std::cerr << "用法: " << argv[0] << " <pdf文件路径>" << std::endl;
        pdf_path = "/mnt/d/wsl_workspace/PDFFilter/PMID1831959.pdf";
        // return 1;
    }else{
        pdf_path = argv[1];
    }
    // 定义开始时间点
    auto start_time = std::chrono::high_resolution_clock::now();
    for(int i=0 ;i<100;++i){
        try {
            std::string text = extract_text_from_pdf(pdf_path);
            if (is_likely_paper(text)) {
                std::cout << "✅ 该文档 \"" << pdf_path << "\" 很可能是一篇论文。\n";
            } else {
                std::cout << "❌ 该文档 \"" << pdf_path << "\" 不像是论文。\n";
            }
        } catch (const std::exception& ex) {
            std::cerr << "错误: " << ex.what() << std::endl;
            return 1;
        }
    }
    // 定义结束时间点并计算总耗时
    auto end_time = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout << "✅ 总共耗时: " << duration/1000.0 << " 秒" << std::endl;

    return 0;
}
