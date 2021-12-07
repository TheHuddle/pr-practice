# Making a Feature Branch
While you can freely develop on the `main` branch of your fork, it is best-practice to create and develop on a *feature branch*.
A feature branch is the general term for whatever code you are going to introduce via pull request.

*Especially* when contributing to a project with lots of contributors, it's important to make your pull request easy to find.
Convention varies when it comes to exactly how to name a branch; however, **as a rule** branches are named in *kabob-case*.
Kabob case means `all-lowercase-with-dashes-between-words`.

As a *suggestion*, I typically follow something like the following (provided there is no style-guide):
```
<ME>-<TICKETNUMBER>-<DESCRIPTION>
```

Suppose I, **E**ren **Y**eager, am submitting a feature for `issue 3: user input dialog needed!`, I would commit all my code in a git branch:
```console
git checkout -b ey-3-user-input-dialog
```

Of course, I would then put the appropriate commit(s) on my feature branch, and push it to my fork.

<br><br>
Try to avoid excessively long branch names.
There's no hard rule on what's *too long*, so just play it smart.
