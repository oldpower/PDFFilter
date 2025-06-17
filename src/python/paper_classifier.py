import fitz  # PyMuPDF
import time 

def extract_text_from_pdf(pdf_path):
    """
    提取给定PDF文件中的所有文本。
    
    :param pdf_path: PDF文件路径
    :return: PDF中的所有文本内容
    """
    doc = fitz.open(pdf_path)
    text = ""
    for page_num in range(len(doc)):
        page = doc.load_page(page_num)  # loads page number 'page_num'
        text += page.get_text()  # 获取页面文本并添加到结果字符串
    return text

def is_likely_paper(text, keywords=None):
    """
    根据提供的关键字列表判断给定的文本是否可能属于一篇学术论文。
    
    :param text: 要分析的文本
    :param keywords: 用于识别学术论文的关键字列表，默认包含常见的几个
    :return: 如果文本符合学术论文特征，则返回True；否则返回False
    """
    if keywords is None:
        keywords = ["abstract", "introduction", "methods", "results", "discussion", "conclusion", "references"]
    
    text_lower = text.lower()
    matches = [kw for kw in keywords if kw.lower() in text_lower]
    
    # 假设至少需要匹配两个关键词才能认为是论文
    return len(matches) >= 2

def main(pdf_path):
    # 从PDF中提取文本
    pdf_text = extract_text_from_pdf(pdf_path)
    
    # 判断是否为论文
    if is_likely_paper(pdf_text):
        print(f"The document at {pdf_path} is likely a research paper.")
    else:
        print(f"The document at {pdf_path} does not seem to be a research paper.")

if __name__ == "__main__":
    # 示例：替换为你想要检测的PDF文件路径
    pdf_path = "../../PMID1831959.pdf"
    start = time.time()
    for i in range(100):
        main(pdf_path)
    end = time.time()
    cast = end - start 
    print(f"✅ 总共耗时: {cast} 毫秒")
