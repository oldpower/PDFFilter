cmake_minimum_required(VERSION 3.14)

project(PaperClassifier)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
        "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
    )
endif()

# 查找 Poppler
find_package(PkgConfig REQUIRED)
pkg_check_modules(POPPLER REQUIRED IMPORTED_TARGET poppler-cpp)

# # 添加可执行文件
# add_executable(paper_classifier src/cpp/main.cpp src/cpp/pdf_utils.cpp)

# # 链接 Poppler
# target_link_libraries(paper_classifier PRIVATE PkgConfig::POPPLER)

# # 包含头文件目录
# target_include_directories(paper_classifier PRIVATE ${PROJECT_SOURCE_DIR}/include)

# # 设置输出路径
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)


# 动态库:将 pdf_utils.cpp 编译为动态库或者静态库 libpdf_utils.so 或者 libpdf_utils.a
add_library(pdf_utils SHARED src/cpp/pdf_utils.cpp)
# add_library(pdf_utils STATIC src/cpp/pdf_utils.cpp)

# 包含头文件目录
target_include_directories(pdf_utils PUBLIC ${PROJECT_SOURCE_DIR}/include)

# 链接 Poppler 到库中
target_link_libraries(pdf_utils PUBLIC PkgConfig::POPPLER)

# 添加主程序
add_executable(paper_classifier src/cpp/main.cpp)

# 将主程序链接到 pdf_utils 库
target_link_libraries(paper_classifier PRIVATE pdf_utils)

# 设置输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

