# Table of Contents

- always use the name of the branch if you have multiple branches and you are creating files and pushing stuff and commits to a certain branch
- upstream is the main repo from which the repo is forked for mods in my own account.
- syncing the forked repo's main with the upstream url repo's main if the forked repo's main branch is a few commits behind the upstream main due to merged commits from the forked repo`s other branch.
- git fetch --all --prune.
  - `--all` here pulls all the branches , commits and other stuff created
  - `--prune` here includes (fetches) the deleted stuff which `--all` doesn't pull maybe
- git reset --hard upstream/main.
  - this resets the origin/main branch of the forked repo with the upstream/main branch of the main repo so as to sync the repo fully
    - then push in the origin/main branch in the local system or.
- to reduce the 2 commands above you can use.
  - git pull upstream main
- upstream here pulls from the upstream url and main means from the main branch of the upstream url.
  - then you can push the changes to the origin/main branch so as to make the forked repo's main branch in sync with the upstream branch`s main.
- if you want to merge all the commits in one commit without doing a reset and then try git adding all the files aaaaaaand then commiting.
  - then use the `git rebase -i _file_` (-i means interactive type i.e in nvim vim type and in the underline use the hash of the commit messaeg from the git log ).
  - you will get option pick and squash written in the front of the half hash of the file with the file names.
    - pick means taking the commit and squash/s means that it`ll merge its commit( i.e the file where it is written as s ) from the bottom till the top until the first pick comes.
