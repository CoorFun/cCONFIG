# cCONFIG

[![MIT License](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/CoorFun/cCONFIG/blob/master/LICENSE)

A config file parser written in C. Super light weight.

## APIs

#### ```int cCONFIG_Parse_Config(const char *DIR)```

```
@brief: Load a config file

@param[in] DIR: Config file

@returns: int\ The number of loaded config items
           -1\ Error
```

#### ```const char *cCONFIG_Value_Raw(const char *key)```

```
@brief: Get a value by key (string)

@param[in] key: Config key

@returns: const char *\ The pointer of target string
          NULL\ No correspond value
```

#### ```int cCONFIG_Value_Is_True(const char *key)```

```
@brief: Check if value is true

@param[in] key: Config key

@returns:  0\ False
           1\ True
          -1\ No correspond value or not true/false string
```

#### ```void cCONFIG_Dump(void)```

```
@brief: Print all the key-value options
```

#### ```void cCONFIG_Delete_List(void)```

```
@brief: Free the memory of saved options

@returns:  0\ Done
          -1\ Error
```

## Usage example

The following is an example of the `config.ini` file. We will use `cCONFIG` to parse this file.

```bash
led_number=12
led_model=APA102
on_idle=true
on_listen=false
```

**1.** Copy the `cCONFIG.h` and `cCONFIG.c` to your project folder.

**2.** Include the head file from where you would use this library.

```c
#include "cCONFIG.h"
```

**3.** Call `cCONFIG_Parse_Config("your_config_file")` function with the config.ini file name as input.

```c
cCONFIG_Parse_Config("config.ini.test");
```
**4.** Call `cCONFIG_Dump()` function to check if all the config option is correctly loaded.

```c
cCONFIG_Dump();
```

You should see the following output if you are using the example config content.

```bash
--------------------------------------
| No. | KEY             | VALUE      |
|-----|-----------------|------------|
| 1   | led_number      | 12         |
| 2   | led_model       | APA102     |
| 3   | on_idle         | true       |
| 4   | on_listen       | false      |
--------------------------------------
```

**5. [Important] Delete the config list before your program is terminated.**

```c
cCONFIG_Delete_List();
```

*(All the loaded config info is save in a dynamic link list, without calling this function, your program will cause a memory leakage)*
## How to Contribute

Contributions are welcome! Not familiar with the codebase yet? No problem!

There are many ways to contribute to open source projects: reporting bugs, helping with the documentation, spreading the word and of course, adding new features and patches.

### Getting Started

- Make sure you have a GitHub account.
- Open a [new issue](https://github.com/CoorFun/cCONFIG/issues), assuming one does not already exist.
- Clearly describe the issue including steps to reproduce when it is a bug.

### Making Changes

- Fork this repository.
- Create a feature branch from where you want to base your work.
- Make commits of logical units (if needed rebase your feature branch before submitting it).
- Check for unnecessary whitespace with `git diff --check` before committing.
- Make sure your commit messages are well formatted.
- If your commit fixes an open issue, reference it in the commit message (f.e. `#15`).
- Run all the tests (if existing) to assure nothing else was accidentally broken.

These guidelines also apply when helping with documentation.

### Submitting Changes

- Push your changes to a feature branch in your fork of the repository.
- Submit a `Pull Request`.
- Wait for maintainer feedback.