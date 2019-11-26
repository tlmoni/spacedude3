# Review form for project Dungeon Crawler

**Name of project to be reviewed: dungeon-crawler-2019-6**

**Names of reviewers: Toni Ojala, Toni Lyttinen, Mikko Suhonen, Simo Hakanummi**

Provide short comments (2-4 sentences) for each item below.

## 1. Overall design and functionality (0-6p) -> 4p

  * 1.1: The implementation corresponds to the selected topic and scope.
The extent of project is large enough to accommodate work for everyone (2p)

The implementation seems to correspond the selected topic and scope.
The extent of project seems large enough to accommodate work for everyone
**(2p)**


  * 1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2p)

The structure is mainly appropriate, but in some files there are no comments/descriptions at all.
There seems to be some documentation about the software structure.
**(1p)**


  * 1.3: Use of external libraries is justified and well documented. (2p)

Use of external libraries is justified, but incredibly poorly documented.
There is no documentation how to utilize the libraries.
**(1p)**


## 2. Working practices (0-6p) -> 4p

  * 2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2 p)

Git is used appropriately, commits are logical and descriptive, but in some cases they are quite large.
The commits could be a bit more frequent.
**(2p)**


  * 2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2p)

The workload is distributed to an extent (categories).
Although at this point it seems that the workload is not distributed evenly based on commit history.
The roles seem unclear.
**(1p)**


  * 2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (2p)

It seems that testing has taken place, but the principles are not specified.
As for quality assurance, using branches for implementing is logical.
The documentation on this matter requires further attention.
**(1p)**


## 3. Implementation aspects (0-8p) -> 4p

  * 3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (2p)

Building is not easy. There is no documentation or instructions to build the software from scratch (apart from "make game" command).
"make game" does not work, because the libraries used need to be installed in a matter we could not solve in reasonable time.
**(0p)**


  * 3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (2p)

Memory management seems basic but not documented at all.
There is no need to use RO3 because there are no explicit implementations.
**(1p)**


  * 3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2
p)

Standard libraries are used where appropriate (but also where innecessary, libraries not used at times)
Containers are used when needed.
**(2p)**


  * 3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (2p)

There is no exception handling when loading from files.
Otherwise implementation seems fine.
**(1p)**


## 4. Project extensiveness (0-10p) -> 7p

  * Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. Project topic descriptions
give a rough guideline about how these points are awarded on different
topics, but note that this will be always case-by-case estimation by
the supervisor, depending on the actual implementation and its
characteristics. (0-10p)

The basic features are under implementation and the additional features seem to be planned.
The score is based on that the additional features will be implemented.
**(7p)**
