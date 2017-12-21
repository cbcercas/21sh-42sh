# 21sh-42sh [![Build Status](https://travis-ci.com/cbcercas/21-42sh.svg?token=MVpT9pWnUSbCfBPKvyfA&branch=master)](https://travis-ci.com/cbcercas/21-42sh)
[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.png?v=103)](https://github.com/ellerbrock/open-source-badges/)
 [![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg?style=flat-square)](http://makeapullrequest.com) 
 
## Introduction

**21sh-42sh** is a Linux CLI (Command Line Interface) thought, designed, and made by *chbravo-*, *gpouyat*, *jlasne* and *mleroy* for the school 42 as the last project before their first internship.

Final grade for 21sh: `100`

Final grade for 42sh: `74`

## Installation | Compilation
To compile **21sh-42sh**, clone the project with the submodules, get in the folder and then type `make`.  **21-42sh** auto-configures the build process, so no further intervention should be necessary.  **21-42sh**
builds with `clang` by default if it is available.  If you want to use `gcc` instead, type `make CC=gcc`


## Reporting bugs

Bug reports for **21sh-42sh** should be reported in the [issues](https://github.com/cbcercas/21sh-42sh/issues) section on our [Github page](https://github.com/cbcercas/21sh-42sh) along with:
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
  - [x] `pwd`

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
  - [x] Multi line editing with `\`, `'` and `"`
  - [x] History handles the multi-line editing

- [x] Shell
  - [x] This shell proposes multiple options to enhance user experience
  - [x] `h` This option will display help for all options as described here
  - [x] `v` Verbose mode
  - [x] `d` Debug mode (Enables the logger). A log file will be created where the binary exists. This option requires a log level from 0 to 7
  - [x] `t` Test mode. This mode will test the module `X` with `Y` parameter as follows : `-t X Y`. Can be used with modules `env` `ast` `parser` `lexer` `ast`
  - [x] `c` Command. Use this option to send a command to the shell and get it's output
  - [x] `C` Color. Use this option to enable color in the shell
  - [x] `l` Disables the termcaps. This is a debug option and not a feature ! To be used lightly

- [x] Signals
  - [x] We kill all childs when we get a signal that kills the program so no zombie process is left behind
  
- [x] Autocompletion
  - [x] Dynamic autocompletion
  - [x] Autocompletes binaries from `PATH`
  - [x] Autocompletes files and paths
  - [x] Autorefreshing with a new input from the user: modification of the list of possibility. TODO WIP
  - [ ] Known bug: Autocompletion displays the full path (see [#124](https://github.com/cbcercas/21sh-42sh/issues/124))
  - [ ] Known bug: Autocompletion doesnt work with relative paths (for example `~/`)
  
- [x] Environ
  - [x] Local Variables are available
  - [x] Normal environment is used when the shell is started
  - [x] Uses the `=` syntax (`VAR=VALUE`)
  - [x] Default env is given when **21sh-42sh** is started with env -i (TODO to be customized)
  - [x] Message to warn the User when **21sh-42sh** is started without an env

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
  
- [x] Tests: **21sh-42sh** contains automated tests found in the `tests/` folder ([README](https://github.com/cbcercas/21sh-42sh/blob/master/tests/README.md))
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
        465 text files.
        449 unique files.
         48 files ignored.
   
   http://cloc.sourceforge.net v 1.60  T=15.82 s (26.4 files/s, 1756.4 lines/s)
   --------------------------------------------------------------------------------
   Language                      files          blank        comment           code
   --------------------------------------------------------------------------------
   C                               321           2005           6128          12895
   C/C++ Header                     63            713           2244           1644
   Bourne Shell                     25            161             80            794
   make                              3            132            111            374
   CMake                             3             38              5            336
   Bourne Again Shell                1             16              4             61
   YAML                              1             10              0             33
   --------------------------------------------------------------------------------
   SUM:                            417           3075           8572          16137
   --------------------------------------------------------------------------------
```