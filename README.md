## C++、Python项目：PDF文件过滤

### 1. 简介
分别使用C++和Python两种方式对PDF文档进行过滤。
 - 使用 `PyMuPDF`（也称作 `fitz`）来提取 PDF 中的文本，并根据一些典型的学术论文关键字进行判断。
 - 使用 **Poppler**（推荐），它提供了一个命令行工具 `pdftotext`，可以调用它来提取 PDF 内容，另外Poppler 提供了 C/C++ API ，可用于直接开发。

C++ 标准库本身 **不支持直接读取 PDF 文件内容**，需要依赖第三方库来提取 PDF 文本。以下是几种常用的 PDF 解析库：

| 库名称 | 简介 |
|--------|------|
| **Poppler** | 开源、跨平台、功能强大，常用于 PDF 渲染和文本提取 |
| **PoDoFo** | 另一个开源 PDF 操作库，适合生成和解析简单结构 |
| **PDFium** | Google 维护的 PDF 引擎，性能好但集成较复杂 |

### 2. 🌍环境

```bash
# c++
sudo apt-get install poppler-utils
# python
pip install pymupdf
```

### 3. 📁项目结构
    .
    |-- CMakeLists.txt
    |-- PMID1831959.pdf
    |-- README.md
    |-- include
    |   `-- pdf_utils.hpp
    `-- src
        |-- cpp
        |   |-- main.cpp
        |   `-- pdf_utils.cpp
        `-- python
            `-- paper_classifier.py

#### 3.1 🚀 C++
```bash
# 🧱 编译
cd PDFFilter
mkdir build 
cd build
cmake ..
make

# ▶️ 运行
./paper_classifier
```

#### 3.2 🚀 python
```bash
cd PDFFilter/src/python
# ▶️ 运行
python paper_classifier.py
```

