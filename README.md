# Glow Hockey by SNAHO

A fast-paced 2D Glow Hockey game built in C using the **Raylib** library.

---

## 📸 Screenshots

| Gameplay | Result Screen |
| :---: | :---: |
| ![Gameplay](game.png) | ![Result Screen](result.png) |

---

## 🎮 Game Controls

### Player 1 (Green)
* **W** - Move Up
* **S** - Move Down
* **A** - Move Left
* **D** - Move Right

### Player 2 (Red)
* **Up Arrow** - Move Up
* **Down Arrow** - Move Down
* **Left Arrow** - Move Left
* **Right Arrow** - Move Right

### General
* **R** - Restart Game (on Result Screen)

---

## ⚙️ Prerequisites & Raylib Installation

Before compiling and running the game, ensure you have a C compiler (`gcc` or `clang`) and the **Raylib** library installed on your system.

#### <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" width="22" height="22"/> 1. Linux Setup

##### Ubuntu / Debian / Mint
```bash
sudo apt update
sudo apt install build-essential libraylib-dev -y
```

##### Fedora
```bash
sudo dnf install gcc raylib-devel -y
```

##### Arch Linux / Manjaro
```bash
sudo pacman -S gcc raylib --noconfirm
```

---

#### <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/apple/apple-original.svg" width="22" height="22"/> 2. macOS Setup

Make sure you have [Homebrew](https://brew.sh/) installed, then run:

```bash
# Install Command Line Tools (if not installed)
xcode-select --install

# Install Raylib via Homebrew
brew install raylib
```

---

#### <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/windows8/windows8-original.svg" width="22" height="22"/> 3. Windows Setup

##### Method A: Using MSYS2 / MinGW-w64 (Recommended)
1. Install [MSYS2](https://www.msys2.org/).
2. Open the **MSYS2 UCRT64** terminal and install `gcc` and `raylib`:
   ```bash
   pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-raylib
   ```
3. Add `C:\msys64\ucrt64\bin` to your System Environment Variables (PATH).

##### Method B: Standalone w64devkit
1. Download the lightweight [w64devkit + Raylib bundle](https://www.raylib.com/).
2. Extract the folder and use `w64devkit.exe` to compile directly.

---

## 🚀 How to Clone, Build, and Run

### 1. Clone the Repository

Clone the project from the `Pong` branch:

```bash
git clone -b Pong [https://github.com/snaaaho/Game.git](https://github.com/snaaaho/Game.git)
cd Game
```

---

### 2. Compile and Run

#### <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/linux/linux-original.svg" width="22" height="22"/> Linux

```bash
# Compile
gcc main.c -o glow_hockey -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Run
./glow_hockey
```
#### <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/windows8/windows8-original.svg" width="22" height="22"/> Windows (MinGW / Command Prompt)
```cmd
# Compile
gcc main.c -o glow_hockey.exe -lraylib -lopengl32 -lgdi32 -lwinmm

# Run
glow_hockey.exe
```
#### <img src="https://raw.githubusercontent.com/devicons/devicon/master/icons/apple/apple-original.svg" width="22" height="22"/> macOS
```bash
# Compile
clang main.c -o glow_hockey -lraylib -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

# Run
./glow_hockey
```