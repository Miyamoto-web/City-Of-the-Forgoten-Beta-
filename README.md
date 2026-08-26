# City of the Forgotten (Beta)

A dark,and dystopian atmospheric noir detective adventure Heavly inspireted by Batman The Animated Series Grim Fandango and the Political Themes of Fallout built in  purely on C using **Raylib**. 

---

##  The World

The year is **1946**. The city is **Santa Ceniza**- A Sour City With Deep WW2 wounds and suffocating urban nightmare, once a Hopeful and prosperus City now hosts the rotten scum of the contry while drowning in endless Rains fog and Nuclear Fear, In Santa Ceniza Peace is a distant a foggy Memory and history is just a another thing that can be erased and reshapeted 

---

### The Factions

The **Libery Crusaders** Are in the surface a Kind hearted Militia That Preaches Free knowlage and Trasparancy but in reality they are moralty grey miltia that will sacrifice any one of their members for the upper hand in their fighting

---

##  The Case

You play as **Robert Bogart**, a depresseed private and independent investigator running a bottom Private Detective agency . Robert is a man haunted by his past in the WWII Pacific Campaign, carrying memories that the rain can't wash away a paranoia that never quite sleeps and a Severe dependency to Tabaco.

The story begins on a foggy night **Mr lee

What starts as a routine missing records case quickly forces Bogart into a maze of encrypted terminals, underground radio whispers, and conflicting motives where no one—neither the corporate regime nor the armed resistance—can be fully trusted.

---

##  Key Features

- **Interactive Terminal Hacking:** Access encrypted network nodes, recover deleted file headers, and piece together fragmented logs.
- **3D Office Environment:** Explore Bogart's atmospheric, rain-soaked headquarters built with a custom 3D stage and dynamic camera logic.
- **Cinematic Narrative Engine:** Branching dialogue choices and a grim, hardboiled story where every clue shifts the balance of paranoia.
- **Classic Noir Aesthetics:** Stylized lighting, immersive rain effects, and a moody original soundtrack.

---
## AI Use

 I used Ai for debugging and Learning things that i didn't Know(this project is my first time coding in Raylib)

##  Tech Stack

- **Language:** C
- **Framework:** Raylib
- **Asset Pipeline:** Blender (3D Greyboxing & Models)
- **Version Control:** Git / GitHub

---
## 🎨 Credits & Assets Attribution

- **3D Models & Textures:** Sourced from free community assets on [Sketchfab](https://sketchfab.com) and [Poly Pizza](https://poly.pizza) under Creative Commons licenses.
- **Audio & Music:** Public domain and royalty-free noir jazz audio tracks sourced from [Free Music Archive](https://freemusicarchive.org) / [Pixabay](https://pixabay.com).
- **Engine & Code:** Built using [Raylib](https://www.raylib.com/) in C.
##  How to Build & Run

### Prerequisites
You need a **C compiler (GCC or MSVC/MinGW)** and **Raylib** installed on your system.

---

###  Linux (Steam Deck / Ubuntu / Debian)

1. **Install dependencies & Raylib:**
   ```bash
   sudo apt update
   sudo apt install build-essential libraylib-dev libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev
   
   

#### Windows : Using w64devkit / MinGW (Recommended for Terminal)
1. Install [w64devkit](https://github.com/skeeto/w64devkit) or MinGW-w64 configured with Raylib binaries.
2. Open **Command Prompt / PowerShell** in the project directory:
   ```cmd
   gcc main.c -lraylib -lopengl32 -lgdi32 -lwinmm -o city_of_the_forgotten.exe
   city_of_the_forgotten.exe


