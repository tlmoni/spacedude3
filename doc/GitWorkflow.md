# Git workflow for software project

ELEC-A7151 - Object oriented programming with C++


Git Cheat Sheet: https://github.github.com/training-kit/downloads/github-git-cheat-sheet.pdf

**Basic workflow**

1. Create your own branch to keep feature development apart from master
    * git checkout -b <branch name> (this creates a new branch and checkouts to it)

2. Implement the feature, push it to your own branch
    * git add <files> (in case the file is not yet under version control, . = all, this is best to do in root of src)
    * git commit -m "<Feature/class etc. name>: <description>" (e.g. "MapEditor: fixed item positioning bug")
    * git push

3. Merge your branch to master

    * Your branch is up to date with master
        * git checkout master (change current branch to master)
        * git merge <your branch> (merge the changes in your branch to master)

    * Your branch is behind master
        * git checkout master (change current branch to master)
        * git pull (pull master branch)
        * git checkout <your branch's name> (change current branch back to your branch)
        * git merge master (update your own branch so that it does not overwrite newer files in master)
        * git push
        * git checkout master
        * git merge <your branch> (merge the changes in your branch to master)
        * git push

4. Delete your branch (when it is obsolete)
    * git checkout master (if you're still in your own branch)
    * git branch -d <branch name>
