# City of the Forgotten

The beta of my game, City of the Forgotten, is a point-and-click detective game inspired by Fallout, Grim Fandango, Batman: The Animated Series, and the Watchmen comic.

---

## About the Game

The City of the Forgotten is a 3D noir point-and-click detective game set in an alternate 1946.

This release is a **short** demonstration of the game's current development in Godot, featuring an explorable detective office, point-and-click interactions, a terminal puzzle, and a short narrative sequence.

It is not the complete game. Many planned gameplay systems, animations, environments, and narrative elements are still under development.

---

## The World

The world of The City of the Forgotten is an alternate universe where the Great Depression never happened. During World War II, Germany developed the first nuclear bomb and, in a desperate attempt to turn the tide of the war, dropped its only bomb on Moscow, turning Central Russia into a frozen nuclear wasteland.

Following Germany's defeat and the collapse of the Soviet Union, the United States became the world's sole superpower. During the Pacific Campaign, the United States invaded Japan in 1940 and bombed Hiroshima and Nagasaki in 1941, forcing Japan's surrender.

In 1943, Europe began to rebuild and formed a large economic and technological bloc. However, the economic burden of the Pacific Campaign, combined with rampant consumerism and market speculation, gradually weakened the American economy. The American Dream began to crumble, leaving behind a nation struggling with the consequences of its own prosperity.

## Timeline

- **1937:** Germany develops the first nuclear bomb.
- **1937:** Germany drops its only nuclear bomb on Moscow, devastating Central Russia.
- **1938:** Germany is defeated, ending World War II in Europe.
- **1939:** The Soviet Union collapses.
- **1940:** The United States invades Japan during the Pacific Campaign.
- **1941:** The United States bombs Hiroshima and Nagasaki, forcing Japan's surrender.
- **1943:** Europe begins to rebuild and forms a large economic and technological bloc.
- **1946:** The events of *The City of the Forgotten* take place.

---

## Santa Ceniza

Santa Ceniza is a dystopian city inspired by Los Angeles. It was once considered the heart of American entertainment, technology, culture, and economic power. Its streets were once filled with ambition and hope, Art Deco architecture, cinemas, luxurious buildings, and the promise of the American Dream. However, years of economic decline, political corruption, cultural decay, rampant consumerism, social tensions, unrest, and corporate influence have transformed the city into a shadow of its former glory.

---

### The Factions

- **The Liberty Crusaders:** On the surface, a kind-hearted militia that preaches free knowledge and transparency. In reality, a morally grey militia willing to sacrifice any of its members for the upper hand in their fight for "freedom." Their leader, **Flavio MacKaye**, is a tragic and paranoid man who believes the results justify the means.
- **Inc Corp:** A massive tech corporation dominating information and manufacturing everything from surveillance cameras to military anti-riot robots for the US Army. Its leader, **X Veidt**, is an eccentric, educated, and lonely man who wants full, silent control over **Santa Ceniza** and the liberty of its citizens by monopolizing media and information. He believes in a state where only the capable and educated truly govern society.

---

## The Case

You play as **Robert Bogart**, a cynical private investigator running his own detective agency. Haunted by his past in the WWII Pacific Campaign, Robert is plagued by constant paranoia, a severe tobacco dependency, and a strong desire to uncover the truth.

The story begins on a foggy night. **Mr. Lee** — chief administrator of the libraries of Santa Ceniza and an influential, beloved member of the Liberty Crusaders — dies in a massive fire caused by a series of mysterious attacks on the city's public libraries. His wife, **Mrs. Lee** (at first glance, a soft-spoken and sweet woman who hides her true persona), along with the Liberty Crusaders, hires you to investigate his mysterious death.

What starts as an odd case quickly escalates, forcing Robert into a maze of corporate manipulation, paranoia, secrets, whispers of the past, and questions of liberty and morality:

- *Who murdered Mr. Lee?*
- *Who is truly right?*
- *Is Mrs. Lee manipulating you?*

All these questions will be answered in **The City of the Forgotten**.

---

## Key Features

**3D Noir Environment:** Explore Robert Bogart's detective office in a dark, atmospheric setting.

**Point-and-Click Interaction:** Interact with specific objects in the environment.

**Terminal Puzzle:** Discover the password to access the detective's terminal.

**Narrative Progression:** Investigate the case through the terminal and progress toward the demo's ending.

**Atmospheric Soundtrack:** Background music that reinforces the noir atmosphere.

**Narrative Investigation:** Uncover details about Robert's case through documents and notes.

---

## Gameplay Demo & Media

- **Itch.io Page:** [Play / Download on Itch.io](https://miyamoto-web.itch.io/city-of-the-forgotten)
- **Gameplay Video:** [Watch the Demo Video Here](https://youtu.be/yjwaz1NtY1I)
- **Supported Platforms:** Linux / SteamOS (Steam Deck) & Windows (x86_64)

> **Note for Reviewers:** If you don't want to install the game, you can check the gameplay video or test the build on itch.io!

---

## Development Journey

### The Beginning

I built this project because I really wanted to make a point-and-click noir game. I started developing it with Raylib. The game was inspired by *Grim Fandango* and its gameplay, as well as Art Deco aesthetics. Its lore and world were also inspired by games such as *Fallout 1* and *Cyberpunk*.

### The First Prototype

My first prototype was built with Raylib, a C-based library. At the beginning of the project, I didn't know any C and had no experience with 3D asset modeling.

When I started the project, I didn't want to model my own assets, so I used free 3D models from online sources. I kept the game very simple: the gameplay consisted of decrypting a terminal through a minigame, picking up a key, and using it to open the door.

### Learning Through Problems

#### Raylib

The first prototype had lots of bugs. The wall textures were bugged and didn't load properly. Also, the code was too messy, and the models were pretty basic and ugly. I wanted to make a really cool game, but I had to learn everything from the ground up.

In many parts, I couldn't even understand what I was doing. Sometimes, a small mistake was enough to make the hitboxes stop working properly.

While making this prototype, I learned the basics of Raylib and code organization. I also learned not to make my game overly complex, with lots of missing features and bugs, when a smaller game with fewer features but a playable experience would be better.

#### Godot

The Godot version was also very buggy. The buttons often stopped functioning. The cinematic camera was also buggy, especially the hitboxes, which were a mess to deal with. My code often didn't work properly, and the UI was complicated to use when implementing certain features.

In this version, I learned to research problems, investigate bugs, and learn from my mistakes. I had to learn how to use Raycasts in Godot for the point-and-click mechanic, as well as how to use global variables. I also learned 3D modeling in Blender to create assets for the game and the protagonist model.

### What I Learned with This Project

This project taught me much more than just how to make a game. I learned how to program, solve problems, research things I didn't understand, and learn from my own mistakes.

I learned the basics of C and Raylib, and later GDScript and Godot. I also learned 3D modeling in Blender and how to create assets for my own game.

One of the most important things I learned was how to deal with problems. Many times, something didn't work and I didn't know why. Instead of just giving up, I learned how to research the problem, understand my code, test different solutions, and learn from my mistakes.

I also learned that making a game is not only about adding more features. A smaller game with fewer features but a playable experience is better than a game with many unfinished or buggy features.

Most importantly, I learned how to start a project without knowing everything beforehand and improve my skills while building it.

---

## Tech Stack

- **Game Engine:** Godot 4.7.2
- **Programming Language:** GDScript
- **3D Modeling:** Blender
- **Version Control:** Git / GitHub

### Previous Prototype

The project originally started as a C and Raylib prototype before being rebuilt in Godot.

---

## Controls

- **Left Click:** Interact with UI elements, the terminal, and the door.
- **Right Click:** Move around the office.
- **Esc:** Exit the game.

---

## AI Use

I used AI to help me debug problems and learn Godot. However, there were some bugs that even ChatGPT couldn't figure out how to fix, so I had to investigate and solve them myself.

---

## Credits & Asset Attribution

The following assets were obtained from external sources and were not created by me:

- **Desk 3D Model:** [Free3D](https://free3d.com/3d-models/desk)
- **Fallout Monitor 3D Model:** [CGTrader](https://www.cgtrader.com/free-3d-models/electronics/computer/fallout-monitor)
- **Music:** "Jazz Rainy Night" by Alex Morgan — [Source](https://pixabay.com/)

---

## Future Development

Some of the planned improvements for the project include:

- Expanding the game world and environments.
- Adding more characters and animations.
- Developing the investigation mechanics.
- Expanding the story and its narrative elements.
- Improving the existing gameplay systems.
