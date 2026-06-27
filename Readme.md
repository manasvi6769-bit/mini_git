# MiniGit

A lightweight Git-inspired version control system implemented in **C++17** to understand the internal architecture of Git. MiniGit supports repository initialization, staging, commits, branching, checkout, status tracking, and commit history while storing repository metadata in a custom `.mgit` directory.

---

## Features

* Initialize a repository
* Stage files recursively
* Create snapshot-based commits
* View commit history
* Display repository status
* Create and list branches
* Checkout commits
* Checkout branches
* Recursive directory support
* Git-inspired repository layout using `HEAD` and `refs/heads`

---

## Project Structure

```
MiniGit/
│
├── Project/               # Working directory
│   ├── hello.txt
│   └── .mgit/             # Repository metadata
│       ├── commits/
│       ├── index/
│       ├── refs/
│       │   └── heads/
│       ├── objects/
│       ├── HEAD
│       └── config
│
├── include/
├── src/
├── compile.sh
└── README.md
```

---

## Building

```
chmod +x compile.sh
./compile.sh
```

This generates the executable:

```
./minigit
```

---

## Supported Commands

### Initialize Repository

```
./minigit init
```

---

### Add Files

```
./minigit add hello.txt

./minigit add docs/readme.md
```

---

### Commit Changes

```
./minigit commit "Initial commit"
```

---

### View Commit History

```
./minigit log
```

---

### Repository Status

```
./minigit status
```

---

### Create a Branch

```
./minigit branch feature
```

---

### List Branches

```
./minigit branch
```

Example:

```
* main
  feature
```

---

### Checkout a Commit

```
./minigit checkout 2
```

Restores the working directory and staging area to the selected commit snapshot.

---

### Checkout a Branch

```
./minigit checkout feature
```

Updates `HEAD` to the selected branch and restores its latest snapshot.

---

## Repository Design

MiniGit stores all repository metadata inside the `.mgit` directory.

```
.mgit/
├── commits/
├── index/
├── refs/
│   └── heads/
├── objects/
├── HEAD
└── config
```

* **HEAD** stores the currently checked-out branch.
* **refs/heads/** stores branch pointers.
* **index/** acts as the staging area.
* **commits/** stores snapshot-based commits.

---

## Current Limitations

MiniGit is designed as an educational implementation and currently does **not** support:

* Merge
* Rebase
* Remote repositories
* Stash
* Tags
* Conflict resolution

---

## Technologies

* C++17
* STL
* `<filesystem>`
* Object-Oriented Design

---

## Learning Objectives

This project was built to understand the core ideas behind Git, including:

* Repository organization
* Snapshot-based version control
* Branch management
* Staging area design
* Commit metadata
* Recursive filesystem traversal
* Command-line application development
