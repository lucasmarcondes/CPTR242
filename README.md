# CPTR 242: Homework Checkpoint Repository

Welcome to the Walla Walla University Sequential and Parallel Data Structures and Algorithms git repository for homework assignments.
Below you will find instructions on setting up that environment and keeping it up-to-date.

## Set-Up
Setting up your repository is a two-step process.
You must first fork your own version of the repository on the WWU Computer Science GitLab server and then set up your local environment.


### Forking the Repository
To set up a fork of this repository, click on the *fork* button on the original repository at <https://gitlab.cs.wallawalla.edu/cptr242/homework>.
Copy the URL of your forked repository by clicking the clipboard icon next to it.
The URL should look something like:

```
git@gitlab.cs.wallawalla.edu:YourUsername/homework.git
```

If you have taken a CS before that also used a homework repository, first you must rename this repository.
Navigate to the previous homework repository and click on project settings.
Under advanced setting you will find the option to rename the repository.
_Make sure to also change the URL._


### Setting Up Your Local Workspace
Use your favorit git client to clone your repository to your local workspace.
You can use terminal or download a [git client](https://git-scm.com/downloads/guis).
One option that cross platform is [gitkraken](https://www.gitkraken.com/).

Finally, to make sure that you can receive updates easily, by adding an upstream remote.
Use the following remote details:
```
git@gitlab.cs.wallawalla.edu:cptr242/homework.git
```

If you are using a terminal, type the following command.

```
git remote add upstream git@gitlab.cs.wallawalla.edu:cptr242/homework.git
```

### Saving your Homework Assignment

You will need to _commit_ your changes to the repository and _push_ them to gitlab.
Review the cheatsheet for the specifics.

### Getting the next Homework Assignment

You will need to pull down the latest assignment using the following commands:

```
git pull --no-edit
git fetch upstream
git checkout master
git merge upstream/master -m "automerging"
```

## Git Cheatsheet
A basic [cheat sheet](https://www.git-tower.com/blog/git-cheat-sheet/) for command on [git](https://git-scm.com/).

