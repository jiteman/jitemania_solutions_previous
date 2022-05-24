### Working with submodules in your repository
- Create the submodule:
  ```bash
  git submodule add -b master <git@github.com:MYSUBMODULE.git> <path/to/MYSUBMODULE>
  ```
  This creates the submodule and makes it track submodule's `master` branch. You can change the branch name if you want to track a different branch.

- Change some settings. In the parent repo:
  ```bash
  # make it so that git status will include changes to submodules.
  git config status.submodulesummary 1 
  
  # make it so that git diff will show a list of submodule commit messages 
  # instead of just the previous and current commit hashes.
  git config diff.submodule log
  ```
  Either one of these can take the `--global` flag.

- Make sure the submodule is on the correct branch and not in a detached head. 
  ```bash
  cd <MYSUBMODULE>
  git checkout master
  ```

- Pulling submodule remote changes:
  ```bash
  # to merge remote changes on top of your local ones
  git submodule update --remote --merge
  # Or to rewind your changes, apply remote changes, then replay your changes afterward
  git submodule update --remote --rebase
  ```
  If you don’t specify either `--merge` or `--rebase` options, your changes will live on in whatever branch of the submodule you made them in, but the submodule will revert to detached head state before applying the remote changes.
  
- Pushing submodule local changes
  ```bash
  cd <MYSUBMODULE>
  git add <stuff>
  git commit -m "comment"
  git push
  ```
  And then to update the parent repo to track the updated verison of your submodule:
  ```bash
  cd ..
  git add <MYSUBMODULE>
  git commit -m "updated my submodule"
  git push
  ```
  In the parent repo, you can also use `git push --recurse-submodules=check` which prevents pushing the parent repo if the submodule(s) are not pushed first. Another option is `git push --recurse-submodules=on-demand` which will try to push the submodules automatically (if necessary) before pushing the parent repo.

### Detached Head
- If ended up with a detached HEAD, it can be pushed to a remote 
  repository (without the need to creating a new local branch) by the following command:

  ```bash
  git push <remote name> HEAD:<remote branch name>
  ```
  E.g.
  ```bash
  git push origin HEAD:master
  ```
### Unadvertised Object Error
if got this error:
```bash
Server does not allow request for unadvertised object 1234...
```
Do this:
```bash
git submodule sync
```
  
### Un-submodule a submodule
- NOTE: You will lose your submodule’s git history if you follow this solution!
  If you value the submodule history and won’t accept this compromise, do not follow these instructions!

  1. Move the files and deinit the submodule
  ```bash
  mv yoursubmodule yoursubmodule_tmp
  git submodule deinit yourSubmodule
  git rm --cached yourSubmodule
  mv yoursubmodule_tmp yoursubmodule
  git add yoursubmodule
  ```

  2. Git submodules metadata is stored in the .gitmodules file as shown below.
     Remove the submodule from that file:
  ```bash
  [submodule "yoursubmodule"]
    path = path/to/yoursubmodule
    url = git@github.com/exampleUser/models
  ```
  3. .git/config has a similar entry, remove the submodule from that as well.

  4. Cleanup the .git/modules directory
  ```bash
  rm -rf .git/modules/yoursubmodule
  ```
----
### Rename a branch locally and remotely

  1. Switching to the local branch you want to rename and rename it:
  ```bash
  git checkout <old_name>
  git branch -m <new_name>
  ```
  
  2. If the <old_name> branch has been pushed to the remote repository, delete it from remote:
  ```bash
  git push origin --delete <old_name>
  ```

  3. Push the <new_name> branch and reset the upstream branch:
  ```bash
  git push origin -u <new_name>
  ```