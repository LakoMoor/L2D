# **Commit Guidelines**

When making commits to the **L2D** project, please follow the guidelines below. Each commit message should start with an emoji, followed by the issue number (if applicable) and a brief description of the commit.

Here is the template for the commit message:

```
EMOJI <commit_message> (#number)
```

Use one of the following emojis to represent the type of commit:

- 🚀 `:rocket:` - New feature
- 🐛 `:bug:` - Bug fix
- 📚 `:books:` - Documentation
- ♻️ `:recycle:` - Refactoring code
- 🚧 `:construction:` - Work in progress
- ⚙️ `:gear:` - Configuration or build-related changes
- 🌱 `:seedling:` - Adding or updating dependencies
- ✅ `:white_check_mark:` - Adding or updating tests
- 🎨 `:art:` - Code style or formatting changes
- 📝 `:memo:` - Updating README or documentation
- 🚚 `:truck:` - Moving or renaming files
- 🔄 `:arrows_counterclockwise:` - Updating or improving existing feature
- 🔧 `:wrench:` - Configuration files or tooling changes
- 🎉 `:tada:` - Initial commit or project setup
- 🐾 `:paw_prints:` - Adding or updating assets (e.g., images, audio)

For example, a commit message could look like this:

```
🚀 Added player movement feature (#1337)
```

This guideline helps maintain a consistent commit history and makes it easier to track changes in the project over time.

# **Git Client Guide**

If you are new to using Git or need a refresher on common Git commands, here's a quick guide to get you started.

## **Initializing a Repository**

To start using Git in your project, navigate to your project directory in the command line and run the following command to initialize a new Git repository:

```shell
git init
```

## **Adding Files**

To add files to your commit, use the following command:

```shell
git add <file_path>
```

You can also use `git add .` to add all files in the current directory.

## **Committing Changes**

To commit your changes with a descriptive message, use the following command:

```shell
git commit -m "Your commit message"
```

Make sure to follow the commit message guidelines mentioned earlier.

## **Fetching Changes**

To fetch changes from a remote repository, use the following command:

```shell
git fetch
```

This retrieves the latest changes from the remote repository without merging them into your local branch.

## **Pulling Changes**

To pull the latest changes from a remote repository and merge them into your current branch, use the following command:

```shell
git pull
```

## **Pushing Changes**

To push your local commits to a remote repository, use the following command:

```shell
git push origin <branch_name>
```

Replace `<branch_name>` with the name of the branch you want to push.

## **Branching**

To create a new branch, use the following command:

```shell
git branch <branch_name>
```

To switch to a different branch, use the following command:

```shell
git checkout <branch_name>
```

## **Merging Branches**

To merge a branch into the current branch, use the following command:

```shell
git merge <branch_name>
```

This combines the changes from `<branch_name>` into the current branch.

## **Additional Resources**

If you want to learn more about using Git, here are some useful resources:

- [Git Documentation](https://git-scm.com/doc)
- [GitHub Guides: Git Handbook](https://guides.github.com/introduction/git-handbook/)
- [Atlassian Git Tutorial](https://www.atlassian.com/git/tutorials)
- [Git Cheat Sheet](https://education.github.com/git-cheat-sheet-education.pdf)

Feel free to refer to these resources to deepen your understanding of Git and its various features.

Remember to always create descriptive and meaningful commit messages, follow best practices, and collaborate effectively with your team. Happy coding!
