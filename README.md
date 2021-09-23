# The GREAT site generator

The GREAT site generator is actually just another simple site generator that can generate static sites based off of text data.

## Tool Setup

Please use C++17 to compile this project on any linux or mac system.

Open Terminal in the directory containing main.cpp and your text file or folder.

Enter the following command:

`g++ main.cpp -std=c++17 -o tgsg`

Then type `./tgsg -i` follwoed by the name of your text file or folder.

Voilà!

## Features

### Markdown

This feature allows the user to input markdown files for conversion into HTML. As of right now the only supported markdown feature is the #/h1 element.

#### Example

Navigate to the folder with the main.cpp through terminal. Enter the following command to allow for Markdown processing.

```
./tgsg -m ./PATH_TO_MARKDOWN_FILE
```

In the file, have the proper syntax for Markdown for header one components:

```
# HELLO WORLD
```
