# City of the Forgotten (Beta)

A dark, atmospheric noir detective adventure built in C using **Raylib**. Set in an alternate 1947 post-WWII dystopia, the game combines 3D environment exploration with interactive terminal investigation and hardboiled narrative systems.

---

##  The World

The year is **1947**. The city is **Angela**—a rain-slicked, suffocating urban nightmare drowning in smog, neon glare, and the unhealed scars of the Second World War.

In Angela, memory is a commodity and history is fragile. As physical archives mysteriously burn to ashes across the city, the populace is pushed into total reliance on proprietary electronic terminals controlled by monolithic corporate interests. Truth is no longer recorded on paper; it is managed, encrypted, and wiped at will.

---

##  The Case

You play as **Robert Bogart**, a cynical private investigator running a bottom-tier agency in the bruised heart of Angela. Bogart is a man haunted by his past in the WWII Pacific Campaign, carrying memories that the rain can't wash away and a paranoia that never quite sleeps.

The story begins on a cold evening when **Mrs. Lee** walks into Bogart's office. Her husband, a quiet library administrator, was officially pronounced dead in a devastating facility fire. But as clinical databases are wiped clean overnight and conflicting stories emerge from the ashes, Mrs. Lee needs an outsider to dig through the digital clutter.

What starts as a routine missing records case quickly forces Bogart into a maze of encrypted terminals, underground radio whispers, and conflicting motives where no one—neither the corporate regime nor the armed resistance—can be fully trusted.

---

##  Key Features

- **Interactive Terminal Hacking:** Access encrypted network nodes, recover deleted file headers, and piece together fragmented logs.
- **3D Office Environment:** Explore Bogart's atmospheric, rain-soaked headquarters built with a custom 3D stage and dynamic camera logic.
- **Cinematic Narrative Engine:** Branching dialogue choices and a grim, hardboiled story where every clue shifts the balance of paranoia.
- **Classic Noir Aesthetics:** Stylized lighting, immersive rain effects, and a moody original soundtrack.

---

##  Tech Stack

- **Language:** C
- **Framework:** Raylib
- **Asset Pipeline:** Blender (3D Greyboxing & Models)
- **Version Control:** Git / GitHub

---

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
