# 21-42sh [![Build Status](https://travis-ci.com/cbcercas/21-42sh.svg?token=MVpT9pWnUSbCfBPKvyfA&branch=master)](https://travis-ci.com/cbcercas/21-42sh)

## Introduction

**21sh-42sh** is a Linux CLI (Command Line Interface) thought, designed, and made by *chbravo-*, *gpouyat*, *jlasne* and *mleroy* for the school 42 as the last project before their first internship.

Final grade for 21sh: `100`

Final grade for 42sh: `74`

## Installation | Compilation
To compile **21-42sh**, clone the project with the submodules, get in the folder and then type `make`.  **21-42sh** auto-configures the build process, so no further intervention should be necessary.  **21-42sh**
builds with `clang` by default if it is available.  If you want to use `gcc` instead, type `make CC=gcc`


## Reporting bugs

Bug reports for **21-42sh** should be reported in the issues section on our [Github page](https://github.com/cbcercas/21-42sh) along with:
* the version number (if available, else the commit used by the last build)
* the machine and OS that it is running on
* a list of the compilation flags
* a list of the flags passed to the shell
* a description of the bug
* a recipe for recreating the bug reliably
* a fix for the bug if you have one!

## Features

- [x] Line editing
  - [x] Simple and advanced line editing
  - [x] Edit the line where the cursor is positionned
  - [x] Move cursor left or right
  - [x] Up and Down arrows to navigate in the history
  - [x] Enter Insert mode with `alt+i` and exit it with `alt+i`
  - [x] Copy and paste with `alt+C` `alt+v`
  - [x] Move word per word left or right `alt+LEFT` `alt+RIGHT`
  - [x] Go to beginning or end of a line. `home` `end`
  - [x] Move to top or bottom line. `alt+UP` `alt+DOWN`
  - [x] Waits for the end of a quote or double quote.
  - [x] ctrl+D and ctrl+C usable when editing a line or in multi-line.
  - [x] Multiline line editing
  - [ ] TODO : ctrl+h === backspace, ctrl+w == clear avant cursor, ctrl+k == clear apres cursor
  

- [x] Builtins with their POSIX options
  - [x] `cd` | `chdir`
  - [x] `echo`
  - [x] `exit`
  - [x] `env`
  - [x] `setenv`
  - [x] `unsetenv`
  - [x] `unset`
  - [x] `export`
  - [x] `history`

- [x] Exec
  - [x] Executing commands stored in path with their parameters
  - [x] Error handling and return value handling
  - [x] Smiley face based on return value from previous command (`^_^` or `X_X`)
  - [x] Redirections handled : `>`, `<`, `<<` and `>>`
  - [x] Pipes `|`
  - [x] Logical operators `&&` and `||`
  - [ ] Backquotes "‘" (TODO)
  - [x] Ihibitors """ (double quote), "’" (simple quote) et "\" (backslash).
  - [x] `;`
  - [x] `\n` handling where `\n` can be used as a `;`. Example: `ls \n ls` == `ls ; ls`

- [x] Prompt
  - [x] Multi line editing
  - [ ] TODO

- [x] Shell
  - [x] options: v d t c C l
  - [ ] TODO

- [x] Signals 
  - [x] We kill all childs when we get a signal that kill the program so no zombie process is left behind
  - [ ] TODO
  
- [x] Autocompletion
  - [x] Dynamic autocompletion
  - [x] Autocompletes binaries from `PATH`
  - [x] Autocompletes files and paths
  - [x] Autorefreshing with a new input from the user: modification of the list of possibility. TODO WIP
  
- [x] Environ
  - [x] Local Variables
  - [x] env
  - [x] Uses = syntax
  - [ ] `unsetenv *` TODO WIP
  - [x] Default env is given when **21-42sh** is started with env -i (TODO to be customized)
  - [x] Message to warn the User when **21-42sh** is started without an env

- [x] Bonuses
  - [x] Heredocs "<<".
  - [x] File descriptors aggregation

- [x] Structure
  - [x] Init
  - [x] Input
  - [x] Lexer
  - [x] Parser
  - [x] Expand
  - [x] Ast
  - [x] Execution

- [x] History
  - [x] A menu is printed when the history fil is to big
  - [x] The history is printed in the log when exiting the program
  - [x] History research `ctrl+R.`
  

*To be put here, result of cloc*
- [x] Tests: **21-42sh** contains automated tests found in the `tests/` folder
  - [x] Tests for the lexer
  - [x] Tests for the parser
  - [x] Tests for the ast
  - [x] Tests for the expand
  - [x] Tests for the exec
  - [x] Tests for the builtins
  - [x] Tests for the env
  - [x] Tests for the local vars

- [x] Miscellaneous
  - [x] Logger
  - [x] Doc

```
	-h Used to display help about the options
  	-v Verbose mode, displays what the user typed. Displayed in red when the -C option is given to (-Cv or -C -v)
	-d [0-7] Debug mode (need debug level):
			0: no log
			1: fatal
			2: error
			3: warning
			4: info
			5: debug level 1
			6: debug level 2
			7: debug level 3
	-t Testing mode:
		env: test env module
			set VAR=value ... : set variable(s) and displayenv
			del VAR ... : delete variable(s) and display env
		lexer: test lexer module
		parser: test parser module
		expand: test expand module
	-c [string] If the -c option is present, then commands are read from string.
	-C Allows color in builtins. default in testing is true, otherwise by default is false
```
