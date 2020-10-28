# More about Git
Authored by Nicholas Christanto
Contact : nchristanto@connect.ust.hk
### Branch
- Run git branch to see which branch you’re currently working on, which will have an asterisk to the left of its name.
- To make a new branch, we’ll run **git checkout -b <new branch name>**
- Switch between branches using the command **git checkout <branch name>** and commit any changes to each branch.
- run the command **git merge <other branch name>** to merge all the branch

### Other GitHub useful features
- Forking: As a GitHub user, you have the ability to fork any repository that you have access to, 
which creates a copy of the repository that you are the owner of. 
We do this by clicking the “Fork” button in the top-right.
- Pull Requests: Once you’ve forked a repository and made some changes to your version, 
you may want to request that those changes be added to the main version of the repository. 
For example, if you wanted to add a new feature to Bootstrap, you could fork the repository, 
make some changes, and then submit a pull request. This pull request could then be evaluated and 
possibly accepted by the people who run the Bootsrap repository. This process of people making a 
few edits and then requesting that they be merged into a main repository is vital for what is known as 
open source software, or software that created by contributions from a number of developers.

### gitignore
When you make commits in a git repository, you choose which files to stage and commit by using git add FILENAME and then git commit. But what if there are some files that you never want to commit? It's too easy to accidentally commit them (especially if you use git add . to stage all files in the current directory). That's where a .gitignore file comes in handy. It lets Git know that it should ignore certain files and not track them.

- A .gitignore file is a plain text file where each line contains a pattern for files/directories to ignore. 
- You can put it in any folder in the repository and you can also have multiple .gitignore files. 
```
.DS_STORE
```
- This will ignore any files named .DS_Store, which is a common file on macOS.

#### Directories
- You can ignore entire directories, just by including their paths and putting a / on the end
```
node_modules/
logs/
```
#### Wildcards
The ```*``` matches 0 or more characters (except the ```/```). So, for example, ```*.log``` matches any file ending with the ```.log``` extension.
Another example is ```*~```, which matches any file ending with ```~```, such as index.html~
You can also use the ```?```, which matches any one character except for the ```/```.

#### Negation
You can use a prefix of ```!``` to negate a file that would be ignored.
```
*.log
!example.log
```
In this example, ```example.log``` is not ignored, even though all other files ending with ```.log``` are ignored.
But be aware, you can't negate a file inside of an ignored directory:
```
logs/
!logs/example.log
```
Due to performance reasons, git will still ignore ```logs/example.log``` here because the entire ```logs``` directory is ignored.

#### Double Asterisk
```**``` can be used to match any number of directories.

- ```**/logs``` matches all files or directories named logs (same as the pattern logs)
- ```**/logs/*.log``` matches all files ending with .log in a logs directory
- ```logs/**/*.log``` matches all files ending with .log in the logs directory and any of its subdirectories
- ```**``` can also be used to match all files inside of a directory, so for example logs/** matches all files inside of logs.

#### Comments
Any lines that start with ```#``` are comments:
```
# macOS Files
.DS_Store
```
