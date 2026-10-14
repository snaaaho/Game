# 💻 1d Game(Hangman, TicTacToe)

Those games are written in **C**.



---


## ⚙️ Prerequisites

To run any C program from these branches, ensure you have a C compiler installed:

* **macOS**: Installed via Xcode Command Line Tools (`xcode-select --install`).
* **Linux**: GCC Compiler (`sudo apt install build-essential`).
* **Windows**: [MinGW-w64](https://www.mingw-w64.org/) / VS Code C/C++ Extensions / WSL.

---

## 🚀 How to Clone a Specific Branch

You can clone either track directly using the branch flag (`-b`):

### 1. Clone the Branch (`1d-game`)
```bash
git clone -b 1d-game https://github.com/snaaaho/Game.git
```

---

## 🛠️ Compilation & Execution Commands

Open terminal inside any downloaded branch directory and run these commands to compile and execute C programs:

### 1. Single Program Compilation & Execution

**Standard Compilation:**
```bash
gcc filename.c -o output_name
```

**Compile with strict warnings enabled (Recommended):**
```bash
gcc -Wall filename.c -o output_name
```

**Run on macOS / Linux:**
```bash
./output_name
```

**Run on Windows (CMD / PowerShell):**
```cmd
output_name.exe
```

**Compile & Run in a Single Command:**
```bash
gcc filename.c -o output_name && ./output_name
```

---

### 2. Batch Compilation (Compile All `.c` Files)

```bash
for file in *.c; do gcc "$file" -o "${file%.c}"; done
```

---

### 3. Cleanup Compiled Executables

```bash
rm -f *.out *.exe a.out
```

---
