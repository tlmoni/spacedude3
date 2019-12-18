# Review form for project Laser Squad/Brawl Stars

**Name of project to be reviewed: laser-squad-20119-3**

**Names of reviewers: Toni Ojala, Toni Lyttinen, Mikko Suhonen, Simo Hakanummi**

Provide short comments (2-4 sentences) for each item below.

## 1. Overall design and functionality (0-6p) -> 6p

1.1: The implementation corresponds to the selected topic and scope.
The extent of project is large enough to accommodate work for everyone (2p)

- The implementation corresponds to the selected topic and scope. There definitely was enough work for everyone. **2p**


1.2: The software structure is appropriate, clear and well
documented. e.g. class structure is justified, inheritance used where
appropriate, information hiding is implemented as appropriate. (2p)

- The structure is appropriate and clear. There is a UML chart in the documentation describing our class hierarchy.
Information hiding has been implementd properly. **2p**


1.3: Use of external libraries is justified and well documented. (2p)

- The use of SFML is justified and documented. **2p**


## 2. Working practices (0-6p) -> 6p

2.1: Git is used appropriately (e.g., commits are logical and
frequent enough, commit logs are descriptive). (2 p)

- Git commits are very frequent and logical. Branches have been utilized smartly during development. **2p**


2.2: Work is distributed and organised well. Everyone contributes to
the project and has a relevant role that matches his/her skills. The
distribution of roles is described well enough. (2p)

- The work was distributed mostly according to everyone's intrests and everyone had their own area that they developed. We could've described the final role distribution more comprehensively in the documentation, but it can largely be seen from the git commit log. **2p**


2.3: Quality assurance is appropriate. Implementation is tested
comprehensively and those testing principles are well documented. (2p)

- We tested our implementation throughout the development process. We have documented our testing principles in the documentation. **2p**


## 3. Implementation aspects (0-8p) -> 7.5p

3.1: Building the software is easy and well documented. CMake or
such tool is highly recommended. (2p)

- Building the software is easy and it is instructed in the README file and project documentation. We were able to build and run the software out of the box in the project demo according to the instructions we have written. We used Make to build our software. **2p**


3.2: Memory management is robust, well-organised and
coherent. E.g., smart pointers are used where appropriate or RO3/5 is
followed. The memory management practices should be documented. (2p)

- Memory management has been implemented as well as we could. We used RO3 where needed.
The memory management practices are documented in the documentation. **2p**


3.3: C++ standard library is used where appropriate. For example,
containers are used instead of own solutions where it makes sense. (2
p)

- C++ standard library has been used extensively where it made sense. Especially vectors where utilized. **2p**


3.4: Implementation works robustly also in exceptional
situations. E.g., functions can survive invalid inputs and exception
handling is used where appropriate. (2p)

- Exception handling has been implemented to an extent. Most of the functions can survive invalid inputs but seldom errors occur. Some functions are more fragile than others. Even though the software might survive invalid inputs, it will most likely lead to the game being pretty much unplayable, since textures could bbe missing etc. **1.5p**


## 4. Project extensiveness (0-10p) -> 10p

Project contains features beyond the minimal requirements: Most of
the projects list additional features which can be implemented for
more points. Teams can also suggest their own custom features, though
they have to be in the scope of the project and approved by the course
assistant who is overseeing the project. Project topic descriptions
give a rough guideline about how these points are awarded on different
topics, but note that this will be always case-by-case estimation by
the supervisor, depending on the actual implementation and its
characteristics. (0-10p)

- We have implemented the following additional features:
    - Multiple maps to choose from **2p**
    - Multiple objective types to choose from (typically map specific) **2p**
    - Sounds **2p**
    - Computer AI opponents **1p**
    - Real-time variant of the game (possibly something similar to Brawl Stars). This implies either networked play or AI. **2p**
    - Animations, projectiles and all the other extra features **1p**
