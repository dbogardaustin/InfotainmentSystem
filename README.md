# InfotainmentSystem
C2C ES1 Car infotainment project

## Git

### General Workflow
This section gives an overview of what a typical git workflow would look like in this repository. Specific terms will be described in greater detail in the other subsections. When updating the repository there are a few steps that need to be done:
- Before changing any files locally, use `git pull origin <branch>` to update your local files in step with the remote files. Replace `<branch>` with the name of the branch you are working on, in most cases it will be `main`.
- Make your desired changes in the project.
- Stage all the changes you want to keep. This can be done with `git add <file>` to stage changes from a specific file, or `git add .` to stage all changes in the repository. Unstaged changes will not be deleted, but the will also not be included in the commit.
- Commit the staged changes with a message using `git commit -m "<message>"`. This will "save" your changes and let you update the remote files.
- Push your changes to the remote repository so that others can pull your changes. Use `git push origin <branch>` to push, it may ask for git credentials when doing this.

An example of what this my look like is below
```
 // Grab any commits from the remote repository and add them locally
> git pull origin main

// Make changes to the files, say main.cpp

// Stage the changed file, unstaged changes will not be included in the commit
> git add main.cpp

// Create a commit with a useful message
> git commit -m "Update main.cpp to include copyright header"

// Update the remote repository with the commits made locally
> git push origin main 
```

### Commits


### Staged VS Unsaged Changes


### Local VS Remote Repository


### Branches

