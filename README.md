# 🛡️ Scanner-CC++

A fast, minimal, and modular file scanner written in modern C++. Built for performance, extensibility, and clean CLI interaction.

> 🔍 Scan directories, analyze file structures, and handle system-level traversal with efficient C++17 code.

---

## ✨ Features

- ⚡ High-speed directory traversal
- 📁 Recursive file scanning
- 📊 Simple and readable CLI output
- 🧱 Modular C++ design (organized in `/scanner`)
- 🧩 Easily extensible for virus/malware scanning, file type filtering, etc.

---

## 🧠 Tech Stack

- **Language**: C++17
- **Build Tool**: CMake (recommended)
- **Standard Libs**: `<filesystem>`, `<iostream>`, `<vector>`, etc.
- **OS Support**: Linux, macOS, Windows

---

## 🚀 Getting Started

### 🧰 Prerequisites

- C++17 compatible compiler (e.g., `g++`, `clang++`)
- Git
- CMake (optional but recommended)

### 📦 Build & Run

<details>
<summary><strong>🔧 Using CMake (Recommended)</strong></summary>

```bash
git clone https://github.com/AwaisCodeBase/Scanner-CC-.git
cd Scanner-CC-
mkdir build && cd build
cmake ..
make
./scanner



git clone https://github.com/AwaisCodeBase/Scanner-CC-.git
cd Scanner-CC-
g++ -std=c++17 -I./scanner main.cpp scanner/scanner.cpp -o scanner
./scanner
./scanner /home/user/documents

Scanner-CC-/
├── main.cpp               # Entry point
├── scanner/
│   ├── scanner.h          # Scanner class/interface
│   └── scanner.cpp        # Scanner implementation
├── CMakeLists.txt         # (if using CMake)
└── README.md              # This file

