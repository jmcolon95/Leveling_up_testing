### Leveling_Up_System

This code hows the use of C++ and a default test of a simple leveling up system.

## Class Unit

This constructor uses a private function for stats, stat growth, level, max level and current exp. This is to make sure that these variable names are not messed with and keeps their names. A varaiable that I use here as well is mt19937 rng, to provide a more modern randomization of numbers when calculating the growth of a stat through a random chance. 

Now the public function it where the variables hold information in them that will be manipulated by the game when a character levels up or has different growth percentages that allows the the character to get stronger. One thing that is important here is that maxHp is determined through (constitution * 4) + level. This provides an hp to be different for different characters depending on the character used.
