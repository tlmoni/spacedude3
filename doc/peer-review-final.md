# Review form for project Dungeon Crawler

**Name of project to be reviewed: dungeon-crawler-2019-6**

**Names of reviewers: Toni Ojala, Toni Lyttinen, Mikko Suhonen, Simo Hakanummi**

Provide short comments (2-4 sentences) for each item below.

## 1. Overall design and functionality (0-6p) -> 5p

* 1.1: The implementation corresponds to the selected topic and scope.
The extent of project is large enough to accommodate work for everyone (2p)

- The implementation includes all the basic features required as stated in the project description.
The extent is large enough especially when considering  the size of the group. **2p**


* 1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2p)

- Based on the documentation the structure is clear enough and justified accordingly.
Inheritance seems to be applied where reasonable (e.g. game objects).
The code itself is a bit messy since there seems to be commented, unnecessary code and the coding style alters from file to file. **2p**


* 1.3: Use of external libraries is justified and well documented. (2p)

- Use of external libraries is not justified but it is documented by mentioning the names of the libraries. **1p**

## 2. Working practices (0-6p) -> 4p

* 2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2 p)

- The commit log is appropriate and the commits are logical. The commits could be more frequent.
The use branches is questionable since the old and outdated branches have not been deleted. **1p**


* 2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2p)

- Work distribution is well documented but alarmingly unbalanced. Some have contributed far more than others. **1p**


* 2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (2p)

- Quality assurance has been taken care of. Based on documentation, the software has been tested manually continusouly throughout the development process. **2p**


## 3. Implementation aspects (0-8p) -> 3p

* 3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (2p)

- Building the software is not easy. This is due to non-existent instructions on how to install the dependencies.
The user has to figure out how to install the mentioned libraries oneself. Make is used for building. **1p**


* 3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (2p)

- Memory management is concerning. There are multiple pointer members in the classe, but it seems that the allocated dynamic memory is not freed.
There are no explicit destructors where they would be deleted. There are no implementations of RO3 even though the software would most likely need it. **0p**


* 3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2p)

- C++ standard library is used where appropriate. **2p**


* 3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (2p)

- When running the software with instructed inputs, the game tends to freeze and refuses to cooperate (read: it does not close without killing the process forcibly, Ctrl+C does not work). There is no exception handling for failed file loads, for instance, which is concerning. **0p**


## 4. Project extensiveness (0-10p) -> 3p

* Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. Project topic descriptions
give a rough guideline about how these points are awarded on different
topics, but note that this will be always case-by-case estimation by
the supervisor, depending on the actual implementation and its
characteristics. (0-10p)

- There is additional UI features implemented (potion inventory, stamina bar). There seems to be an attempt to create a base for randomly generated maps. **3p**
