# City of the Forgotten (Beta)

The Beta Of my Game City of the Forgotten A Point and Click Detective Game with Inspirations Of: Fallout, The Game Grim Fandago, Batman Animated Series and The Comic WatchMen

---

## The World

- The world of the game is a Alternative Universe set in 1946 In this World The Great Depresion Never Happend and Germany Developed The Nuclear Bomb before the USA and the USSR in a Desparate Attempt They droped Their Only Nuclear Bomb on Moscou Making Central Russia a Nuclear Frozen WasteLand Shortly After Germany Defeat The USA Goverment Devoloped Their Own Nuclear Bomb. In the Pacific Campain The American Goverment Made Japan Surrunder After Droping The nuclear Bomb on Hiroshima and Nagazaki. After the Collapse of The USSR The American Goverment Became The Solo Super Power but the Intensive Consumism,The Market Speculation and The Domestic Backlash Caused By The Intensive Campain On the Pacific Campaign Severly Cripeled The US Economy and Made The American Citizens Wake Up From the American Dream.
---
### Santa Ceniza
- The Local where The Game takes place A Unforgiven City once the Heart of the Economy tecnology and arts of the United States Now it's Just a Corpse of the Once prosperous City

---
### The Factions

- **The Liberty Crusaders:** On the surface, a kind-hearted militia that preaches free knowledge and transparency. In reality, a morally grey militia willing to sacrifice any of its members for the upper hand in their fight for "freedom". Their leader, **Flavio MacKaye**, is a tragic and paranoid man who believes the Result justify the Ways.
- **Inc Corp:** A massive tech corporation dominating information and manufacturing everything from street spy cameras to military anti Riot robots for the US Army. Their leader, **X Veidt**, is an eccentric, Educated and Lonely man who wants full, silent control over **Santa Ceniza** and the Liberty of it's Citizens by monopolizing media and information. He believes in a state where only the capable and educated Truly govern society.

---

## The Case

You play as **Robert Bogart**, a depressed private investigator running a detective agency. Robert is a man haunted by his past in the WWII Pacific Campaign Carrying a paranoia that never stops, and a severe tobacco dependency.

The story begins on a foggy night. **Mr. Lee** — Chief Administrator of the libraries of Santa Ceniza and an influential, beloved member of the Liberty Crusaders — dies in a massive fire caused by a series of mysterious attacks on the city's public libraries. His wife, **Mrs. Lee** (at first look a soft-spoken and sweet woman who hides her true persona), along with the Liberty Crusaders, hires you to investigate his mysterious death.

What starts as an odd case quickly escalates, forcing Robert into a maze of corporate manipulation, paranoia, secrets, whispers of the past, and questions of Liberty and Morals:
* *Who murdered Mr. Lee?*
* *Who is truly right?*
* *Is Mrs. Lee manipulating you?*

All these questions will be answered in **The City of the Forgotten**.

---

## Key Features

- **Interactive Terminal Hacking:** Access encrypted network nodes, recover deleted file headers, and piece together fragmented logs.
- **3D Office Environment:** Explore Bogart's atmospheric, cigar-smelling office built with a custom 3D stage and dynamic camera logic.
- **Functional Inventory and Note Menu:** Use the Persona-inspired menu with details on Bogart's mental state and case files.

---

## Gameplay Demo & Media

- **Itch.io Page:** [Play / Download on Itch.io](https://miyamoto-web.itch.io/city-of-the-forgotten)
- **Gameplay Video:** [Watch the Demo Video Here](https://youtu.be/EAttLvAmuyM)
- **Supported Platforms:** Linux / SteamOS (Steam Deck) & Windows (x86_64)

> **Note for Reviewers:** If you are testing on macOS or don't want to install standard dependencies, please check the gameplay video or test the build on itch.io!

---

## AI Use

I used AI for debugging and learning Raylib concepts (this project is my first time coding in Raylib with C).

---

## Tech Stack

- **Language:** C
- **Framework:** Raylib
- **Asset Pipeline:** Blender (3D Greyboxing & Models)
- **Version Control:** Git / GitHub

---

## Credits & Assets Attribution

- **3D Models & Textures:** Sourced from free community assets on [Sketchfab](https://sketchfab.com) and [Poly Pizza](https://poly.pizza) under Creative Commons licenses.
- **Audio & Music:** Public domain and royalty-free noir jazz audio tracks sourced from [Free Music Archive](https://freemusicarchive.org) / [Pixabay](https://pixabay.com).
- **Engine & Code:** Built using [Raylib](https://www.raylib.com/) in C.

---

## How to Download & Play (For Players)

No compilers or extra dependencies required!

1. Download the executable package from our **[Itch.io Page](https://miyamoto-web.itch.io/city-of-the-forgotten)**  section.
2. Click the button play game.
---

## Controls

| Action | Keyboard & Mouse | Steam Deck / Controller |
| :--- | :--- | :--- |
| **Movement** | `W` `A` `S` `D` / Arrow Keys | Left Analog Stick |
| **Interact / Examine** | `E` / Left Click | `A` Button |
| **Terminal Hacking / Type** | Keyboard | On-Screen Keyboard / Touchscreen |
| **Open Inventory & Notes** | `Tab` / `I` | `Y` Button / Select |
| **Pause / Menu** | `Esc` | Start Button |

---

## How to Build from Source (For Developers)

If you want to modify the C code or compile the binary yourself directly from the source code:

### Prerequisites
- A working C compiler (`gcc`)
- [Raylib](https://www.raylib.com/) library installed on your system

### 1. Clone the repository
```bash
git clone [https://github.com/Miyamoto-web/City-Of-the-Forgoten-Beta-.git](https://github.com/Miyamoto-web/City-Of-the-Forgoten-Beta-.git)
cd City-Of-the-Forgoten-Beta-
```
### Linux
`gcc main.c -o SantaCeniza -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./SantaCeniza`
### Windows
`gcc main.c -o SantaCeniza.exe -lraylib -lopengl32 -lgdi32 -lwinmm
.\SantaCeniza.exe`


