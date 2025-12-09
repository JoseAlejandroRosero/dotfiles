#ifndef CONFIG_H
#define CONFIG_H

// Helper function for the status bar scripts
#define SC(script) "$HOME/.local/src/dwmblocks-async/scripts/" #script


// String used to delimit block outputs in the status.
#define DELIMITER ""

// Maximum number of Unicode characters that a block can output.
#define MAX_BLOCK_OUTPUT_LENGTH 45

// Control whether blocks are clickable.
#define CLICKABLE_BLOCKS 1

// Control whether a leading delimiter should be prepended to the status.
#define LEADING_DELIMITER 1

// Control whether a trailing delimiter should be appended to the status.
#define TRAILING_DELIMITER 0

// Define blocks for the status feed as X(icon, cmd, interval, signal).
#define BLOCKS(X)                   \
    X("", SC("musicplayer"), 0, 6)        \
    X("", SC("sysstats"), 30, 5)        \
    X("", SC("reloj"), 1, 10)
#endif  // CONFIG_H
 /*   X("", "source ssb-disk /", 1800, 0)     \
    X("", "source sb-disk /home", 1800, 0) \ */
