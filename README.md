# City of the Forgotten (Beta)

A dark and dystopian atmospheric noir detective adventure heavily inspired by Batman: The Animated Series, Grim Fandango, the political themes of Fallout, and the philosophy of the Frankfurt School and Mass Culture, built purely in C using **Raylib**.

---

## The World

The year is **1946**. The city is **Santa Ceniza** — a sour city with deep WWII wounds and a suffocating urban nightmare. Once a hopeful and prosperous city, it now hosts the rotten scum of the country while drowning in endless rain, fog, and nuclear fear. In Santa Ceniza, peace is a distant and foggy memory, and history is just another thing that can be erased and reshaped.

---

### The Factions

- **The Liberty Crusaders:** On the surface, a kind-hearted militia that preaches free knowledge and transparency. In reality, a morally grey militia willing to sacrifice any of its members for the upper hand in their fight for "freedom". Their leader, **Flavio MacKaye**, is a tragic and paranoid man who believes the ends justify the means.
- **Inc Corp:** A massive tech corporation dominating information and manufacturing everything from street spy cameras to military robots for the US Army. Their leader, **X Veidt**, is an eccentric and power-hungry man who wants full, silent control over **Santa Ceniza** and the free will of its citizens by monopolizing media and information. He believes in a state where only the capable and educated govern society.

---

## The Case

You play as **Robert Bogart**, a depressed private investigator running a bottom-tier detective agency. Robert is a man haunted by his past in the WWII Pacific Campaign, carrying memories that the rain cannot wash away, a paranoia that never sleeps, and a severe tobacco dependency.

The story begins on a foggy night. **Mr. Lee** — Chief Administrator of the libraries of Santa Ceniza and an influential, beloved member of the Liberty Crusaders — dies in a massive fire caused by a series of mysterious attacks on the city's public libraries. His wife, **Mrs. Lee** (at first look a soft-spoken and sweet woman who hides her true persona), along with the Liberty Crusaders, hires you to investigate his mysterious death.

What starts as an odd case quickly escalates, forcing Robert into a maze of corporate manipulation, paranoia, secrets, whispers of the past, and questions of free will:
* *Who murdered Mr. Lee?*
* *Who is truly in the right?*
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
- **GitHub Releases:** [Download Binaries](https://github.com/Miyamoto-web/City-Of-the-Forgoten-Beta-/releases)
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

1. Download the executable package from our **[Itch.io Page](https://miyamoto-web.itch.io/city-of-the-forgotten)** or from the **[GitHub Releases](https://github.com/Miyamoto-web/City-Of-the-Forgoten-Beta-/releases)** section.
2. Extract the archive to any folder.
3. Run the executable:
   - **Linux / Steam Deck:** Double-click `./city_of_the_forgotten` (or run `./SantaCeniza` in terminal).
   - **Windows:** Double-click `SantaCeniza.exe`.

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


