# FAANGORITHM

Faangorithm is a study group for algorithm.

You can refer [here](https://www.notion.so/FAANG-4a74457b08224695828f1daeeeca0b15) to see a general timetable for study and a rule-set for pull-requests and commits of this repository.

## 1. Directory structure

``` 
    meetings/
    └── yyyy-mm-dd(x group(s))
        ├── group 1(name1, name2, name3)
        │   ├── name1.cpp
        │   ├── name2.py
        │   └── name3.java
        ├── group 2(name4, name5, name6)
        └── readme.md
```
You must keep this directory structure.

- date

    - group

        Study meetings will be divided into multiple groups.

        Each group contains 3~4 people.

        **If the total number of members is too small to divide meetings into groups, you don't have to create group directory.**

    - readme file

        Each readme file in the meetings must contain problem information(URL, text, etc...) and meeting report(evaluation, approaches, etc...).

## 2. Source file

You have to write comments on the top of the source code file.

\[Required\] Author	

\[Required\] Date

\[Optional\] Problem URL(OR Name)

\[Optional\] Approaches

Example code.

```cpp
    /*
        Author: Seokho Song
        Date  : YYYY-MM-DD
        URL   : https://example.com
        Approach: Two-Pointer, Greedy 
    */

    int main()
    {
            
        return 0;
    }
```

## 3. Commit

Commits must be written in English. 

## 4. Pull-request

Rule of pull-requests is not different from other projects.

Just fork the project, add a new file, and send a PR to the master branch.

Accepted PRs will be merged by rebase.

