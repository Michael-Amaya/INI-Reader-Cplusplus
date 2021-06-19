# C++ Basic INI Reader
I made this INI Reader for fun because I was bored and I wanted to work on my C++, Cmake, and GTest skills. I'm sure there are a variety of bugs. Known bugs are below. I'll fix them whenever I get a chance. Feel free to use any of the code or improve on the code. I only ask that I be credited if the code is used or modified. The code was written for C++ 20 because it makes use of the std::map.contains() method.

## Basic Usage Example:
Add the folder to your project and follow the [main CMakeLists.txt](CMakeLists.txt) file and the [library CMakeLists.txt](IniReader/CMakeLists.txt) in the [IniReader folder](IniReader/) to link the library to your project.

### Include / Preprocessor Directive:
```cpp
#include <IniReader/ini_reader.h>
```

### Initialization and getting data
Example INI File called testing.ini:
```ini
[Database]
Host = 127.0.0.1
Username = mike
Password = testing

[Debug]
Build = Version 1.0.0
Type = DEBUG
Installed-By = Michael Amaya

[Random]
Rsa-Key = 239523425923952394d2h34h2h4gg52g5
Rsa-Directory = /users/michaela/Desktop/testing
Random-Mode = 15
```

Example code usage:
```cpp
IniReader reader {"testing.ini"};
std::cout << "Rsa-Directory: " << reader.getSection("Random")->at("Rsa-Directory") << '\n';
std::cout << "Installed-By: " << reader.getSection("Debug")->at("Installed-By") << '\n';

// Prints:
// /users/michaela/Desktop/testing
// Michael Amaya
```

## Known Bugs
This is supposed to be a fun project so I won't work on this too much. I'll get around to fixing my bugs when I'm bored and get a chance.

:white_check_mark: means issue is fixed.

:white_large_square: means issue needs to be fixed.

- :white_large_square: Equal signs in the value of a key/value pair cause program to crash/act unexpectedly.
- :white_large_square: On Windows (10), string trimmer does not work properly. Probably has something to do with the fact they use \r\n to make newlines. It causes the sections, keys, and values to have an extra character. 

