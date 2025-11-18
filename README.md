# so_long

`so_long` is a small 2D game written in C using the **MiniLibX** graphical library.  
You control a player on a tile-based map, collect all collectibles, avoid enemies (if any), and reach the exit to win.

This project is typically done as part of the 42 curriculum and focuses on:
- Basic 2D rendering with MiniLibX
- Event handling (keyboard, window close, etc.)
- Map parsing and validation
- Simple game loop and state management

---

## Features

- 2D top-down view using sprites.
- Map loaded from a `.ber` file:
  - Walls
  - Floor
  - Collectibles
  - Player start position
  - Exit (and maybe enemies, depending on your version)
- Move counter displayed in the terminal (or on screen, depending on your implementation).
- Window closes gracefully by:
  - Clicking the close button.
  - Pressing ESC (or another bound key).

---

## Preview (GIFs)

> Replace these URLs with your own GIFs (e.g. from your GitHub repo, Imgur, or a local `/assets` folder in the project).

### Gameplay Overview

![Gameplay Overview](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExeWxkNmZqaHk2cnM1cDgydHVvZHV3OTdmc2Y1YnN6M3hhaTRlM3docCZlcD12MV9naWZzX3NlYXJjaCZjdD1n/GYxLx2zF5mK6A/giphy.gif)

### Collecting Items

![Collectibles Demo](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExZ3NmMnZyaWxuY2l2cHNpb3Z0dXN0bzc3eHlydGFwMWpqbHV4N2o5dCZlcD12MV9naWZzX3NlYXJjaCZjdD1n/LmNwrBhejkK9EFP504/giphy.gif)

### Reaching the Exit

![Exit Demo](https://media.giphy.com/media/v1.Y2lkPTc5MGI3NjExZmpycml4bGhlc3NyYm5jOG1rN292eXhjdHB2bzI2cDVteGpoY2ZrOSZlcD12MV9naWZzX3NlYXJjaCZjdD1n/kEKcOWl8RMLde/giphy.gif)

*(If you have your own recordings, export them as GIFs and update the links above.)*

---

## Installation

```bash
# clone the repo
git clone https://github.com/yu-joseph/so.long.git
cd so.long

# build (usually via Makefile)
make
```

> Make sure MiniLibX and any required dependencies (X11, etc.) are installed on your system.

---

## Usage

Run the game with a valid `.ber` map:

```bash
./so_long maps/example.ber
```

Common controls (adjust this section if your keys differ):

- `W / ↑` – Move up  
- `S / ↓` – Move down  
- `A / ←` – Move left  
- `D / →` – Move right  
- `ESC` – Quit the game

Game rules:

1. Collect all collectibles.
2. Reach the exit.
3. Avoid invalid moves (e.g. walking into walls).

---

## Map Format

Maps are stored as `.ber` files and must be **rectangular** and **closed** (surrounded by walls).

Basic characters (adapt to your implementation):

- `1` – Wall  
- `0` – Empty space / floor  
- `P` – Player start position (exactly one)  
- `C` – Collectible (at least one)  
- `E` – Exit (at least one)  
- `X` – Enemy (optional, if implemented)

Example:

```text
1111111
1P0C0E1
1000001
1111111
```

---

## Project Structure

> Adjust to match your actual tree.

```text
so.long/
├─ Makefile
├─ src/
│  ├─ main.c
│  ├─ game_loop.c
│  ├─ render.c
│  ├─ input.c
│  ├─ map_parsing.c
│  └─ ...
├─ include/
│  ├─ so_long.h
│  └─ ...
├─ assets/
│  ├─ player.xpm
│  ├─ wall.xpm
│  ├─ floor.xpm
│  ├─ collectible.xpm
│  └─ exit.xpm
└─ maps/
   ├─ example.ber
   └─ ...
```

---

## Known Issues / TODO

- [ ] Add more levels
- [ ] Improve sprite animations
- [ ] Add sound effects
- [ ] Add enemies / more game mechanics

---

## License

Specify your license here (for example, MIT):

```text
MIT License
Copyright (c) <year> <your-name>
```

---

## Author

- `Youssef SouHail` – [[your GitHub link](https://github.com/yu-joseph)]
