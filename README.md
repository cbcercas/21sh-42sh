# 21-42sh [![Build Status](https://travis-ci.com/cbcercas/21-42sh.svg?token=MVpT9pWnUSbCfBPKvyfA&branch=master)](https://travis-ci.com/cbcercas/21-42sh)

By *chbravo-*, *jlasne*, *gpouyat* and *mleroy*
Final grade : To be determined

*To be put here, result of cloc*


- Prompt without line edition.
- Builtins `cd`, `echo`, `exit`, `env`, `setenv`, `unsetenv` with their POSIX options.
- Executing simple commands with there parameters using `PATH`.
- Support for redirection `>`, `>>`, `<`and `|`.
- Logical operand `&&`and `||`.
- Separator `;`.

- Inhibitors `"`, `'`and `\`.
- Advanced redirections: aggregation of file output and heredoc `<<`.
- Backquotes \`.
- Local variable and builtin `unset` and `export`.
- History with builtin `history`and `!` with options.
- Advanced line edition.

## Line editing

Keys|Functions|
:-:|:--
<kbd>Alt</kbd>+<kbd>C</kbd><br><kbd>Alt</kbd>+<kbd>X</kbd><br><kbd>Alt</kbd>+<kbd>V</kbd>|Copy<br>Cut (WIP)<br>Paste
<kbd>Alt</kbd>+<kbd><</kbd><br><kbd>Alt</kbd>+<kbd>></kbd>|Move a words (left or right).
<kbd>Opt</kbd>+<kbd>^</kbd><br><kbd>Opt</kbd>+<kbd>v</kbd>|Move a line (up or down).
<kbd>Ctrl</kbd>+<kbd>L</kbd>|Clear screen.
<kbd>Ctrl</kbd>+<kbd>C</kbd>|Terminate/Kill current foreground process.

## History

Keys|Functions|
:-:|:--
<kbd>^</kbd><br><kbd>v</kbd>|Browse the history.
<kbd>Ctrl</kbd>+<kbd>R</kbd>|Research function.
`!!`|Retype the last command.
`!n`|Retype the `n`(numerical value) command from the begin of history.
`!-n`|Retype the `-n`(numerical value) command from the last command.
`!name`|Search for a command beginning with `name` WIP #53.
`!?name`|Search for a command which contain `name` WIP #53.

## Autocompletion

Autocompletion works with binary, path
Autorefreshing with a new input from the user: modification of the list of possibility.

Commands|Functions|
:-:|:--
`$> l[tab]`|Search for binary.
`$> ls s[tab]`|Search for path/files.