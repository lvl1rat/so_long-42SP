# so\_long

Simple 2D game project made with C and MiniLibX for the 42 school curriculum.

## 🎯 Objective

Build a small top-down game where the player:

- Moves around using WASD.
- Collects all collectibles ('C').
- Reaches the exit ('E') to win.

## 🧩 Map Rules

- Must be `.ber` file extension.
- Rectangular shape.
- Only valid characters:
  - `1`: Wall (impassable)
  - `0`: Floor (walkable)
  - `C`: Collectible
  - `E`: Exit (used to win after collecting all items)
  - `P`: Player start position
- The map must:
  - Be surrounded by walls on all sides
  - Contain exactly one `P`
  - Have at least one `C`
  - Have at least one `E`

Example map:

```
11111
1P0C1
10001
1C0E1
11111
```

## ⚙️ Building the Game

Make sure MiniLibX is cloned into the `mlx/` folder:

```bash
make
```

## 🚀 Running the Game

```bash
./so_long_bonus maps/green_hill.ber
```

## 🎮 Controls

- **W/A/S/D**: Move player.
- **ESC/Q**: Exit game.
- Window close button also exits the game.

## 🖼️ Features

- Renders a map with walls, player, floor, collectibles, and exit.
- Counts moves and displays in the terminal.
- Game exits when player collects all items and reaches the exit.

## 🧼 Cleanup

- All memory is freed properly.
- Graceful error messages on invalid map files.

## 🛠️ Bonus Suggestions

- Display move count in-game.
- Add animations or sounds.
- Enemies or time-based challenges.

## 📜 License

Educational project for 42 School. Do not distribute as your own.

