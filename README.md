# MacroHTML
Generate HTML using the C Preprocessor

## Syntax
Using the file `example.html.h`
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
        You just generated HTML from the C Preprocessor. Yuck.
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
