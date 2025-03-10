# Song-Starter

### Do you have writers block? Do you struggle to come up with ideas for music? This program might be able to help you out!

https://github.com/user-attachments/assets/3467c9b4-759b-4ce0-b72a-fdbd926bce0d

> Track made using parameters given as a base for it

---
## How to use
- run this command for Linux and MacOS users
```
curl -sSL https://raw.githubusercontent.com/gatlanit/Song-Starter/master/install.sh | bash
```

<br>

- Run ```song-starter``` in your terminal to use program
  - ```q``` will quit the program once run
  - ```r``` or any other key will rerun it
  - ```song-starter -h``` or ```song-starter help``` for more commands

```
user@computer ~ % song-starter
BPM: 160
Key: F
Modes: Minor
Chord Progression: { 1 4 6 7 }

Run again? Type anything to refresh (or "q" to exit): r
BPM: 175
Key: D♯
Modes: Major
Chord Progression: { 1 7 1 1 4 6 1 6 }

Run again? Type anything to refresh (or "q" to exit): q
Exiting song starter...
user@computer ~ %
```
> MacOS zsh example usage
---
### Roadmap:
  - Feel free to create an issue for any suggestions you may have (bug, feature, formatting, etc.)

---

### TODO:

### WIP:
  - [ ] CLI arguments (flags)

### DONE:
  - [x] v1.0.0 Release 
  - [x] Intelligent chord progression generator
  - [x] BPM randomizer (75-200)
  - [x] Key randomizer
  - [x] Mode randomizer (Major and Minor)
