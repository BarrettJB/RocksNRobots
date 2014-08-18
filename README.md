Rocks & Robots
============

Initial Setup
============
1. Set the directory you want to use using the commands cd and ls

2. Create a copy of the repository on your computer using the command git clone and paste the url in 

There will now be a folder on your computer that is linked with the repository

Add New Files
============
1. Place the file in the folder you created earlier. You can check to see it is there by using the command git status it will be listed under untracked files

2. Use the command git add followed by the file name.

3. To commit the changes you the command git commit followed by the file name. By also adding -m and a note in quotations a message will be added to the commit.


4. Finally to upload your changes to the master repository (hosted on github) by using the command git push

Now if you check the GitHub your files should be added

Example of this
```ruby
C:\Users\Barrett\Documents\tutorial [master]> git status
# On branch master
nothing to commit, working directory clean
C:\Users\Barrett\Documents\tutorial [master]> git status
# On branch master
# Untracked files:
#   (use "git add <file>..." to include in what will be committed)
#
#       Words.txt
nothing added to commit but untracked files present (use "git add" to track)
C:\Users\Barrett\Documents\tutorial [master +1 ~0 -0 !]> git add Words.txt
C:\Users\Barrett\Documents\tutorial [master +1 ~0 -0]> git status
# On branch master
# Changes to be committed:
#   (use "git reset HEAD <file>..." to unstage)
#
#       new file:   Words.txt
#
C:\Users\Barrett\Documents\tutorial [master +1 ~0 -0]> git commit -m "added more words"
[master 2a718d7] added more words
 1 file changed, 1 insertion(+)
 create mode 100644 Words.txt
C:\Users\Barrett\Documents\tutorial [master]> git push
Counting objects: 4, done.
Delta compression using up to 4 threads.
Compressing objects: 100% (2/2), done.
Writing objects: 100% (3/3), 298 bytes | 0 bytes/s, done.
Total 3 (delta 0), reused 0 (delta 0)
To https://github.com/BarrettRnR/Tutorial.git
   b9f4bdd..2a718d7  master -> master
C:\Users\Barrett\Documents\tutorial [master]>
```

Commands
========
git status    (checks status of your files compared to the cloud)
git add       (Adds new files to repository)
git commit    (commits changes or additions to permanent record)
git push      (Updates cloud from your files)
git pull      (Updates your files from cloud)

More Help
=========
This youtube video has a very good example of how to use all the basic commands: https://www.youtube.com/watch?v=0fKg7e37bQE&list=WL&index=14
