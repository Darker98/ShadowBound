# Shadowbound: A Text-Based Adventure Game

## Project Overview

Shadowbound is a captivating text-based adventure game set in the mystical kingdom of *Shadowvale*. Players will navigate through a dark realm, solving puzzles, making strategic decisions, and battling enemies. The core gameplay mechanic revolves around toggling between the human and shadow realms, each offering different perspectives and abilities.

**Target Audience**: Individuals who enjoy immersive storytelling, puzzle-solving, and strategic gameplay.

---

## Table of Contents

1. [Game Concept](#game-concept)
2. [Design](#design)
3. [Technical Requirements](#technical-requirements)
4. [Code Overview](#code-overview)
5. [Use Cases](#use-cases)
6. [Challenges Faced](#challenges-faced)
7. [Learning Objectives Achieved](#learning-objectives-achieved)
8. [Conclusion](#conclusion)
9. [Acknowledgments](#acknowledgments)
10. [References](#references)

---

## Game Concept

### Storyline

In *Shadowbound*, players take on the role of a protagonist capable of switching between the human and shadow realms. The journey begins in the kingdom of *Shadowvale*, uncovering mysteries and navigating through obstacles as the player learns about a parallel dimension, *Nox Aeterna*. This realm is inhabited by mysterious shadow beings, and the protagonist must uncover the secrets of both realms to bring balance or chaos to the kingdom.

### Gameplay Mechanics

The game features dynamic transitions between the human and shadow worlds. Key mechanics include:

- **Shadow Vision**: Use the shadow realm to solve puzzles and uncover hidden paths.
- **Combat**: Engage in strategic turn-based battles, utilizing choices like *Attack*, *Defend*, and *Rest*.
- **Puzzles**: Solve riddles and puzzles using clues found in both realms.
- **Narrative Impact**: Every decision made by the player shapes the unfolding story, leading to multiple potential endings.

---

## Design

### Architecture

The game follows a modular design with clearly separated components for different aspects of gameplay. This structure ensures maintainability and scalability. Key modules include:

- **Player Mechanics**
- **Puzzle Logic**
- **Combat System**
- **Narrative Flow**

### User Interface

Players interact with the game through a text-based interface. Commands are typed in and responses appear in the console. Each command drives the story forward, such as moving through rooms, solving puzzles, or battling enemies.

---

## Technical Requirements

### Programming Language

- **C++**: The game is developed in C++ for its performance and efficiency in handling real-time game mechanics like combat and puzzle solving.

### Platform Compatibility

- Designed to run on **Windows** for a consistent and accessible player experience.

---

## Use Cases

### Player Interactions

1. **Combat**: The player must choose between *Attack*, *Defend*, or *Rest*, which affect the player's and opponent's health and mana.
2. **Puzzle Solving**: The player faces riddles and puzzles, answering them correctly to proceed or face consequences.
3. **Room Exploration**: Players can choose which areas to explore, revisiting previous locations if needed.

### Edge Cases

- **Returning to an Area**: If the player returns to an already-visited area, they can continue solving puzzles or re-engage with previous decisions.
- **Unsolved Puzzles**: If a player exits an area with unsolved puzzles, they can return and resume solving at any time.

---

## Challenges Faced

### Technical Challenges

- **Combat AI**: Developing an opponent that could autonomously decide actions based on its state (e.g., attacking or defending based on mana levels).
- **Puzzle State Management**: Ensuring puzzle states are saved properly so the player can revisit them without losing progress.

### Design Challenges

- **Narrative Integration**: Balancing the story's progression with gameplay mechanics.
- **Puzzle Design**: Creating puzzles that are challenging but not frustrating, while maintaining immersion in the game's theme.

---

## Learning Objectives Achieved

### Programming Skills

- Implementing random events with `rand()`.
- Mastery of ANSI codes for dynamic console manipulation.
- Understanding of modularity and structuring larger C++ projects.

### Problem Solving

- Breaking down complex systems like combat and puzzles into smaller, manageable components.
- Iterative development and continuous refinement of mechanics.

### Collaboration and Communication

- Effective task distribution and team communication for optimal productivity.

---

## Conclusion

### Summary

*Shadowbound* successfully combines storytelling, strategic decision-making, and puzzle-solving to deliver an immersive experience. It serves as a testament to the development team's ability to overcome technical challenges and create a captivating narrative-driven game.

### Future Enhancements

- **Combat System**: Improve to allow scalable difficulty.
- **Room Design**: Add more dynamic interactions and objects.
- **Puzzle Generation**: Introduce randomized puzzles for greater replayability.
