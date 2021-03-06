# MacroHTML
Generate HTML using the C Preprocessor.

I thought this project would be a fun exploitation of the C preprocessor.

### [Here is an larger example at my personal Github Page](https://github.com/garrettsickles/garrettsickles.github.io)
## Usage
``` bash
# Specify which source files
./MacroHTML.sh example.html.h

# All source file in working directory
./MacroHTML.sh
```
## Basic
`example.html.h`
``` c
#include "MacroHTML.h"

// Specify the doctype
DOCTYPE(html)

// Build the page
HTML(
    // Header
    HEAD(
        TITLE(MacroHTML)
    )
    
    // Body
    BODY(
        TEXT(You just generated HTML from the C Preprocessor. Yuck.)
    )
)
```

We can run `./MacroHTML.sh example.html.h` or just `./MacroHTML.h` in the same directory and generate

``` html
<!DOCTYPE html>
<html>
    <head>
        <title>MacroHTML</title>
    </head>
    <body>
        You just generated HTML from the C Preprocessor. Yuck.
    </body>
</html>
```

## Attributes

We can add attributes to HTML elements too!
``` c
#include "MacroHTML.h"

// Specify the doctype
DOCTYPE(html)

// Build the page
HTML(
    // Header
    HEAD(
        TITLE(MacroHTML)
    )
    
    // Body
    BODY(
        TEXT(You just generated HTML from the C Preprocessor. Yuck.),
        ATTRIBUTE(id,    "iAmAThing")
        ATTRIBUTE(style, "color:red;background-color:powderblue;")
    ),

    // This page is in US English
    ATTRIBUTE(lang, "en-US")
)
```

This produces

``` html
<!DOCTYPE html>
<html lang="en-US">
    <head>
        <title>MacroHTML</title>
    </head>
    <body id="iAmAThing" style="color:red;background-color:powderblue;">
        You just generated HTML from the C Preprocessor. Yuck.
    </body>
</html>
```
