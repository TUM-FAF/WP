# Windows Programming Laboratory Work #1

## Title
Window. Window handling. Basic window’s form elements

## Contents
* Win32 API
* GIT
* Programming Style Guidelines
* Window
* Button
* Text Input
* Text

## Prerequisites

### IDE and compiler
You can use whatever IDE/Text editor/CLI you want, but you'll have to write code by your own.
I recommend [CodeBlocks](http://www.codeblocks.org/) as it is cross platform, it has a version which contains a compiler and it is less tempting to try drag-n-drop features.

#### If you chose CodeBlocks, here is how you start a project with it:
* Download. Better choose a version which has compiler. Also it is a good idea to take last stable version (12.11), but it is not mandatory as 8.X is also good one.
* Install. After installation it will ask you to choose a default compiler. Do it wisely.
* File -> New -> Project -> Win32 GUI project -> Next...
* In order to see only GUI window without console, in Project properties, set Build targets -> Type -> GUI Application (project may need a rebuild)

#### Using VCS (GIT or SVN) and GitHub
You should be familiar with GIT, if not then take a look at [IDE Lab nr.1](https://github.com/TUM-FAF/IDE/blob/master/MIDPS_LAB_1.md).

Main purposes of GIT/GitHub are:
* Proof of your work
* Analyzing your progress and understanding of course
* Safe place to keep your work
* Delimiting development and ready work

By default you have one branch - master. I'll review only work from that branch.

Initially master branch should have two files: .gitignore and README.md.
* I recommend to copy .gitignore file from [WP Labs master branch](https://github.com/TUM-FAF/WP). Add additional rules in order not to submit unnecessary files to repository.
* README.md (can be any other flavoured by GitHub extension) should contain at least the name of course and your name.

Later you'll have one folder per laboratory work. Use **lab#X** format (where X is laboratory work number). More about this you can find on [Submission Process page](https://github.com/TUM-FAF/WP/wiki/Submission-Process).

Before submission you can use other branches to work on your projects. You can use other branches in order to require help from me or other classmates.

#### Programming Style Guidelines (PSG)
It is a good practice to have a PSG. And a good solution is to take and use one available PSG.
For example:
* [Google C++ Style Guide](http://google-styleguide.googlecode.com/svn/trunk/cppguide.xml)
* [Geotechnical Software Services C++ Programming Style Guidelines](http://geosoft.no/development/cppstyle.html)
* [USC Aerial Robotics Programming Style Guide (C++)](https://github.com/uscrs-art/uscrs-art/wiki)
* [C style guide](https://github.com/nickbjohnson4224/rhombus/wiki/C-style-guide)
* or write your own PSG

Whatever you choose, add a link to it in your master's branch readme file.
If you are going to write your own PSG, do not forget to add it into your master branch.

## Mandatory Objectives
* Create a Windows application
* Choose Programming Style Guidelines that you'll follow
* Add 2 buttons to window: one with default styles, one with custom styles (size, background, text color, font family, font size)
* Add 2 text inputs to window: one with default styles, one with custom styles (size, background, text color, font family, font size)
* Add 2 text elements to window: one with default styles, one with custom styles (size, background, text color, font family, font size)

## Objectives With Points
* Make elements to fit window on resize **(1 pt)**
_(hint: you can limit minimal window width and height)_
* Make elements to interact or change other elements (1 pt for 2 different interactions) **(0-2 pt)** _(ex. on button click, change text element color or position)_
* Change behavior of different window actions (at least 3). For ex.: on clicking close button, move window to a random location on display working space **(1 pt)**
* Write your own PSG (you can take existent one and modify it) and argue why it is better (for you) **(1 pt)**

## References
* Programming Windows by Charlez Petzold, 5th edition:
  * Section I, Chapter 1
  * Section I, Chapter 2
  * Section I, Chapter 3
  * Section I, Chapter 4
  * Section I, Chapter 9
