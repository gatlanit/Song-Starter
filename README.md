# Song-Starter

A Python CLI tool to generate random music paramaters to help musicians create a base from.

## Project Goals

- Give musicians a completely random base to start a song off of, potentially curing writer's block.

## MVP Scope

- Random BPM Generator (80-200)
- Randomly pick between a list of keys and modes.
- Selects a instrument or source of sound to start with
- Pick a common progression from a list of chord progressions
- Ability to re-roll paramaters

<img width="481" height="532" alt="song-starter_system-diagram drawio" src="https://github.com/user-attachments/assets/4757109d-9352-4ec2-bac3-5a94d9377434" />

## Future Plans

- Filter by genre
- CLI arguments to customize randomization paramaters (i.e BPM: 120-140 instead of default ranges)
- Image to MIDI - Upload an image you are inspired by, parse colors with ```numpy```` to map colors from color wheel to circle of fifths, and generate MIDI to use in music programs (Maybe using```Mido``` or ```pretty_midi``` python module)

## Tech Stack

- Language: Python 3
- Libraries: ```random```
- Data Structures: Python lists
